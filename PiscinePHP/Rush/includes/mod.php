<?
include("../includes/conf.php");
if (isset($_POST['name']) or isset($_POST['subname']) or isset($_POST['bdate']) or isset($_POST['add']) or ((isset($_POST['pass1']) and isset($_POST['pass2']) and isset($_POST['pass3']))))
{
	$name = $_POST['name'];
	$subname = $_POST['subname'];
	$bdate = $_POST['bdate'];
	$add = $_POST['add'];
	$p1 = $_POST['pass1'];
	$p2 = $_POST['pass2'];
	$p3 = $_POST['pass3'];
	$choix = $_POST['delete'];
	foreach ($choix as $id){
		if ($id)
			$g = $id;
	}
	if ($g){
		if ($g === 'root')
			echo "You can't";
		else{
			$req = "DELETE FROM ".$dbname.".client WHERE client.login_client = '".$g."'";
			mysqli_query($link, $req);
			echo "good";
			header("Location: index.php?id=3");
		}
	}
	if ($p1){
		$login = $_SESSION["login"];
		$sql = "SELECT * FROM client";
		$req = mysqli_query($link, $sql);
		while($data = mysqli_fetch_array($req)){
			if ($login == $data['login_client']){
				if (hash("whirlpool",$p1)== $data['mdp_client']){
					$good = 1;
				}
			}
		}
		if ($good){
			if ($p2 === $p3 and $p2)
			{
				$sql = "UPDATE ".$dbname.".client SET mdp_client = '".hash("whirlpool",$p2)."' WHERE client.login_client ='".$login."'";
				mysqli_query($link, $sql);
				header("Location: index.php?id=3");
			}
			else
				echo "Password don't match or empty";
		}
		else
			echo "Old password isn't good.";
	}
	if ($name or $subname or $bdate or $add)
	{
		$sql = "UPDATE ".$dbname.".client SET nom = '".$name."' WHERE client.login_client ='".$login."'";
		mysqli_query($link, $sql);
		$sql = "UPDATE ".$dbname.".client SET prenom = '".$subname."' WHERE client.login_client ='".$login."'";
		mysqli_query($link, $sql);
		$sql = "UPDATE ".$dbname.".client SET date_naiss = '".$bdate."' WHERE client.login_client ='".$login."'";
		mysqli_query($link, $sql);
		$sql = "UPDATE ".$dbname.".client SET adresse1 = '".$add."' WHERE client.login_client ='".$login."'";
		mysqli_query($link, $sql);
	}
	else
		header("Location: index.php?id=3");
}
else
		header("Location: index.php?id=3");
?>