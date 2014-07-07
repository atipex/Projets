<?php
include("../includes/conf.php");

if (isset($_POST["login"]) and isset($_POST["pass"])){
	$login = $_POST["login"];
	$pass = $_POST["pass"];
	$sql = "SELECT * FROM client";
	$req = mysqli_query($link, $sql);
	while($data = mysqli_fetch_array($req)){
		if ($login == $data['login_client']){
			if (hash("whirlpool",$pass)== $data['mdp_client']){
				$good = 1;
				$_SESSION["sid"] = hash("whirlpool",$key.$login);
				$_SESSION["login"] = $login;
				header("Location: index.php");
			}
		}
	}
	if (!$good)
		echo "Login/password incorecte.";
}


else
	header("index.php?id=1");
?>

