<?php include("../includes/conf.php");
$id = $_POST['id'];
$ref = $_POST['ref'];
$stock = $_POST['stock'];
$prix = $_POST['prix'];
echo $id.$ref.$stock.$prix;
if (isset($ref) and isset($stock) and isset($prix) and isset($id)){
	$req = "UPDATE ".$dbname.".articles SET ref = '".$ref."', WHERE articles.id_article =".$id."";
	echo $req;
	//mysqli_query($link, $req);
}
//$req = "UPDATE `rush`.`articles` SET `ref` = 'Tappette à rat' WHERE `articles`.`id_article` =2";


//UPDATE `rush`.`articles` SET `ref` = 'Tapette à Mathilde.',`stock` = '51', `prix` = '61' WHERE `articles`.`id_article` =4;

//header("Location: index.php");
?>