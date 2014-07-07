<?php
include("../includes/conf.php");


if (isset($_POST["login"]) AND isset($_POST["pass"])){
	$login = $_POST["login"];
	$pass = $_POST["pass"];
	$sql = "SELECT * FROM client";

	$req = mysqli_query($link, $sql);

	while($data = mysqli_fetch_array($req)){
		if ($login == $data['login_client']){
			if (hash("whirlpool",$pass)== $data['mdp_client']){

				if ($data["id_droit"] == 1){
					$good = 1;
					$_SESSION["sid"] = hash("whirlpool",$key.$login);
					$_SESSION["login"] = $login;
					$_SESSION['uid'] = hash("whirlpool",$passadmin.$login);
					header("Location: index1.php");
				}
			}
		}
	}
	if (!$good)
		header("Location: index.php");
}


else
	header("Location: index.php");


?>

