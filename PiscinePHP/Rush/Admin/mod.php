<?php include("../includes/conf.php");

if (isset($_POST["choix"])){
	$choix = $_POST["choix"];
	$nok = $_POST["ok"];
	$delok = $_POST["del"];
	if ($nok){
		foreach ($choix as $id){
			if ($id){
				$req = "UPDATE ".$dbname.".panier SET id_panier = '0' WHERE panier.id_panier =".$id;
				mysqli_query($link, $req);
			}
		}
		header("Location: fac.php");
	}
	else if ($delok){
		foreach ($choix as $id){
		if ($id){
			$req = "DELETE FROM ".$dbname.".panier WHERE panier.id_panier = ".$id;
			mysqli_query($link, $req);
			}
		}
		header("Location: fac.php");
	}
	else
		header("Location: fac.php");
}

header("Location: fac.php");
?>