<?php

namespace Atipex\Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Session\Session;
use atipex\Bundle\Entity\member;
use atipex\Bundle\Entity\newsletter;
use Symfony\Component\HttpFoundation\Request;

class AtipexController extends Controller
{
	public function menuAction()
	{
		return $this->render('atipexBundle:atipex:menu.html.twig');
	}
	public function startAction()
	{
		return $this->render('atipexBundle:atipex:index.html.twig');
	}
	
	public function subscribeAction()
	{
		return $this->render('atipexBundle:atipex:subscribe.html.twig');
	}
	public function mailAction()
	{
		$session = $this->getRequest()->getSession();
		$p1 = $session->get('login');
		$p2 = $session->get('admin');
		if ($p1 === 'root' && $p2 === 'on')
		{
			return $this->render('atipexBundle:atipex:mail.html.twig');
		}
		else
			return $this->redirect('index');
	}
	public function loginAction()
	{
		return $this->render('atipexBundle:atipex:login.html.twig');
	}

	public function lostAction()
	{
		return $this->render('atipexBundle:atipex:lost.html.twig');
	}

	public function modifAction()
	{
		return $this->render('atipexBundle:atipex:modif.html.twig');
	}

	public function logadminAction()
	{
		return $this->render('atipexBundle:atipex:logadmin.html.twig');
	}
	public function logoutaAction()
	{
		$session = $this->getRequest()->getSession();
		$session->set('login', '');			
		$session->set('admin', '');			
		return $this->render('atipexBundle:atipex:index.html.twig');
	}
	public function logoutAction()
	{
		$session = $this->getRequest()->getSession();
		$session->set('login', '');			
		return $this->render('atipexBundle:atipex:index.html.twig');
	}
	public function addnAction(Request $req)
	{
		$email = mysql_real_escape_string(htmlspecialchars(trim($req->request->get('mail'))));
		if (isset($email) && strlen($email)> 5 && strlen($email) < 30)
		{
			if (!($try = $this->getDoctrine()->getManager()->getRepository('atipexBundle:newsletter')->findBy(array('email'=>$email))))
			{
				$mail = new newsletter();
				$mail->setEmail($email);
				$em = $this->getDoctrine()->getManager();
				$em->persist($mail);
				$em->flush();
				return $this->render('atipexBundle:atipex:index.html.twig');
			}
			return $this->render('atipexBundle:atipex:index.html.twig');
		}
		return $this->render('atipexBundle:atipex:index.html.twig');
	}
	public function addAction(Request $req)
	{
		$mail = trim($req->request->get('mail'));
		$login = trim($req->request->get('Login'));
		$pass = trim($req->request->get('Password'));
		$pass2 = trim($req->request->get('Password2'));
		if (isset($mail) && isset($login) && isset($pass) && isset($pass2) && ($pass == $pass2) && strlen($pass) > 2 && strlen($login) > 2)
		{
			if (!($try = $this->getDoctrine()->getManager()->getRepository('atipexBundle:member')->findBy(array('login'=>$login))))
			{
				$pass = hash('whirlpool', $pass);
				$member = new Member();
				$member->setLogin($login);
				$member->setPassword($pass);
				$member->setEmail($mail);
				$em = $this->getDoctrine()->getManager();
				$em->persist($member);
				$em->flush();
				return $this->render('atipexBundle:atipex:login.html.twig');
			}
			return $this->render('atipexBundle:atipex:subscribe.html.twig');
		}
		return $this->render('atipexBundle:atipex:subscribe.html.twig');
	}
	public function modifaAction(Request $req)
	{
		$session = $this->getRequest()->getSession();
		$login = $session->get('login');
		$mail = mysql_real_escape_string(htmlspecialchars(trim($req->request->get('mail'))));
		$oldpw = mysql_real_escape_string(htmlspecialchars(trim($req->request->get('oldpassword'))));
		$newp1 = mysql_real_escape_string(htmlspecialchars(trim($req->request->get('newpass'))));
		$newp2 = mysql_real_escape_string(htmlspecialchars(trim($req->request->get('newpass2'))));
		$check = $req->request->get('die');
		if ($login === "")
		{
			return $this->redirect('subscribe');
		}
		else if ($check != 0 && isset($oldpw) && strlen($oldpw) > 2 && $login != 'root'){
			if (($try = $this->getDoctrine()->getManager()->getRepository('atipexBundle:member')->findBy(array('login'=>$login, 'password'=>hash('whirlpool', $oldpw))))){
				$em = $this->getDoctrine()->getManager();
				$conn = $this->get('database_connection');
				$conn->executeUpdate("DELETE FROM `member` WHERE login ='".$login."';");
				return $this->redirect('logout');
			}

		}
		else if ((isset($newp1) && isset($newp2) && isset($oldpw) && strlen($oldpw) > 2 && strlen($newp1) > 2 && $newp1 === $newp2)){
			if (($try = $this->getDoctrine()->getManager()->getRepository('atipexBundle:member')->findBy(array('login'=>$login, 'password'=>hash('whirlpool', $oldpw))))){
				$pass = hash('whirlpool',$newp1);
				$em = $this->getDoctrine()->getManager();
				$conn = $this->get('database_connection');
				$conn->executeUpdate("UPDATE `member` SET password ='".$pass."' WHERE login LIKE'".$login."';");
				return $this->redirect('logout');
			}
			return $this->render('atipexBundle:atipex:modif.html.twig');

		}
		else if (isset($mail) && strlen($mail) > 2 && strlen($mail) < 25)
		{
			$conn = $this->get('database_connection');
			$conn->executeUpdate("UPDATE `member` SET email ='".$mail."' WHERE login LIKE'".$login."';");
			return $this->render('atipexBundle:atipex:modif.html.twig');
		}
		return $this->render('atipexBundle:atipex:index.html.twig');

	}
	public function authAction(Request $req)
	{
		$session = $this->getRequest()->getSession();
		$login = trim($req->request->get('login'));
		$pass = trim($req->request->get('password'));
		if (isset($login) && isset($pass) && strlen($login)  > 2 && strlen($pass) > 2)
		{
			if (($try = $this->getDoctrine()->getManager()->getRepository('atipexBundle:member')->findBy(array('login'=>$login, 'password'=>hash('whirlpool',$pass)))))
			{
				$session->set('login', $login);			
				return $this->render('atipexBundle:atipex:index.html.twig');
			}
			return $this->redirect('login');
		}
		return $this->render('atipexBundle:atipex:login.html.twig');
	}

	public function authaAction(Request $req)
	{
		$session = $this->getRequest()->getSession();
		$login = trim($req->request->get('login'));
		$pass = trim($req->request->get('password'));
		$log = trim($session->get('login'));
		$log1 = trim($session->get('admin')); 
		if ($log === 'root' AND $log1 === 'on')
			return $this->render('atipexBundle:atipex:mail.html.twig');
		if (isset($login) && $login === 'root' && isset($pass) && strlen($login)  > 2 && strlen($pass) > 2)
		{
			if (($try = $this->getDoctrine()->getManager()->getRepository('atipexBundle:member')->findBy(array('login'=>$login, 'password'=>hash('whirlpool',$pass)))))
			{
				$session->set('login', $login);			
				$session->set('admin', 'on');			
				return $this->render('atipexBundle:atipex:mail.html.twig');
			}
			return $this->redirect('alogin');
		}
		return $this->render('atipexBundle:atipex:logadmin.html.twig');
	}         
	public function validmAction(Request $req)
	{
		$session = $this->getRequest()->getSession();
		if (($log = $session->get('login')) === 'root' && ($ad = $session->get('admin')) === 'on')
		{
			$sub = trim($req->request->get('subject'));
			$cont = $req->request->get('content');
			if (isset($sub) && isset($cont))
			{
				return $this->redirect('alogin');
			}
		}
		return $this->render('atipexBundle:atipex:logadmin.html.twig');
	}         
}