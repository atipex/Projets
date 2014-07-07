<?php include("../includes/conf.php");

if (isset($_POST['ref']) and isset($_POST['stock']) and isset($_POST['prix'])){
	$ref = $_POST['ref'];
	$stock = $_POST['stock'];
	$prix = $_POST['prix'];
	$req = "INSERT INTO ".$dbname.".articles VALUES (NULL , '1', '1', '".$ref."', '".$stock."', NULL , '".$prix."')";
	echo $req;
	mysqli_query($link, $req);
}

header("Location: index.php");
?>