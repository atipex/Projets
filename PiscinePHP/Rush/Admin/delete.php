<?php include("../includes/conf.php");
if (isset($_POST["choix"])){
	$choix = $_POST["choix"];
	foreach ($choix as $id){
		if ($id){
			$req = "DELETE FROM ".$dbname.".articles WHERE articles.id_article = ".$id;
			mysqli_query($link, $req);
		}
	}
}
header("Location: index1.php");
?>