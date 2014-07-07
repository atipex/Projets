<?php

namespace atipex\Bundle\Controller;

use Symfony\Component\HttpFoundation\Request;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;

use atipex\Bundle\Entity\member;
use atipex\Bundle\Form\memberType;

/**
 * member controller.
 *
 */
class memberController extends Controller
{

    /**
     * Lists all member entities.
     *
     */
    public function indexAction()
    {
        $em = $this->getDoctrine()->getManager();

        $entities = $em->getRepository('atipexBundle:member')->findAll();

        return $this->render('atipexBundle:member:index.html.twig', array(
            'entities' => $entities,
            ));
    }
    /**
     * Creates a new member entity.
     *
     */
    public function createAction(Request $request)
    {
        $entity = new member();
        $form = $this->createCreateForm($entity);
        $form->handleRequest($request);

        if ($form->isValid()) {
            $em = $this->getDoctrine()->getManager();
            $em->persist($entity);
            $em->flush();

            return $this->redirect($this->generateUrl('admin_show', array('id' => $entity->getId())));
        }

        return $this->render('atipexBundle:member:new.html.twig', array(
            'entity' => $entity,
            'form'   => $form->createView(),
            ));
    }

    /**
    * Creates a form to create a member entity.
    *
    * @param member $entity The entity
    *
    * @return \Symfony\Component\Form\Form The form
    */
    private function createCreateForm(member $entity)
    {
        $form = $this->createForm(new memberType(), $entity, array(
            'action' => $this->generateUrl('admin_create'),
            'method' => 'POST',
            ));

        $form->add('submit', 'submit', array('label' => 'Create'));

        return $form;
    }

    /**
     * Displays a form to create a new member entity.
     *
     */
    public function newAction()
    {
        $entity = new member();
        $form   = $this->createCreateForm($entity);

        return $this->render('atipexBundle:member:new.html.twig', array(
            'entity' => $entity,
            'form'   => $form->createView(),
            ));
    }

    /**
     * Finds and displays a member entity.
     *
     */
    public function showAction($id)
    {
      $em = $this->getDoctrine()->getManager();

      $entity = $em->getRepository('atipexBundle:member')->find($id);

      if (!$entity) {
        throw $this->createNotFoundException('Unable to find member entity.');
    }

    $deleteForm = $this->createDeleteForm($id);

    return $this->render('atipexBundle:member:show.html.twig', array(
        'entity'      => $entity,
        'delete_form' => $deleteForm->createView(),        ));
}

    /**
     * Displays a form to edit an existing member entity.
     *
     */
    public function editAction($id)
    {
        $em = $this->getDoctrine()->getManager();

        $entity = $em->getRepository('atipexBundle:member')->find($id);

        if (!$entity) {
            throw $this->createNotFoundException('Unable to find member entity.');
        }

        $editForm = $this->createEditForm($entity);
        $deleteForm = $this->createDeleteForm($id);

        return $this->render('atipexBundle:member:edit.html.twig', array(
            'entity'      => $entity,
            'edit_form'   => $editForm->createView(),
            'delete_form' => $deleteForm->createView(),
            ));
    }

    /**
    * Creates a form to edit a member entity.
    *
    * @param member $entity The entity
    *
    * @return \Symfony\Component\Form\Form The form
    */
    private function createEditForm(member $entity)
    {
        $session = $this->getRequest()->getSession();
        $log = trim($session->get('login'));
        $log1 = trim($session->get('admin')); 
        if (!($log === 'root' AND $log1 === 'on'))
            return $this->redirect('../login');
        $form = $this->createForm(new memberType(), $entity, array(
            'action' => $this->generateUrl('admin_update', array('id' => $entity->getId())),
            'method' => 'PUT',
            ));

        $form->add('submit', 'submit', array('label' => 'Update'));

        return $form;
    }
    /**
     * Edits an existing member entity.
     *
     */
    public function updateAction(Request $request, $id)
    {
        $em = $this->getDoctrine()->getManager();

        $entity = $em->getRepository('atipexBundle:member')->find($id);

        if (!$entity) {
            throw $this->createNotFoundException('Unable to find member entity.');
        }

        $deleteForm = $this->createDeleteForm($id);
        $editForm = $this->createEditForm($entity);
        $editForm->handleRequest($request);

        if ($editForm->isValid()) {
            $em->flush();

            return $this->redirect($this->generateUrl('admin_edit', array('id' => $id)));
        }

        return $this->render('atipexBundle:member:edit.html.twig', array(
            'entity'      => $entity,
            'edit_form'   => $editForm->createView(),
            'delete_form' => $deleteForm->createView(),
            ));
    }
    /**
     * Deletes a member entity.
     *
     */
    public function deleteAction(Request $request, $id)
    {
        $form = $this->createDeleteForm($id);
        $form->handleRequest($request);

        if ($form->isValid()) {
            $em = $this->getDoctrine()->getManager();
            $entity = $em->getRepository('atipexBundle:member')->find($id);

            if (!$entity) {
                throw $this->createNotFoundException('Unable to find member entity.');
            }

            $em->remove($entity);
            $em->flush();
        }

        return $this->redirect($this->generateUrl('admin'));
    }

    /**
     * Creates a form to delete a member entity by id.
     *
     * @param mixed $id The entity id
     *
     * @return \Symfony\Component\Form\Form The form
     */
    private function createDeleteForm($id)
    {
        return $this->createFormBuilder()
        ->setAction($this->generateUrl('admin_delete', array('id' => $id)))
        ->setMethod('DELETE')
        ->add('submit', 'submit', array('label' => 'Delete'))
        ->getForm()
        ;
    }
}
