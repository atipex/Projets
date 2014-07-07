<?php
if (!$_SESSION['login'])
	header("Location: index.php?id=1");
else{
	$sql = "SELECT * FROM `client`";
	$req = mysqli_query($link, $sql);

	while ($data = mysqli_fetch_array($req))
	{
		if ($data["login_client"] == $_SESSION["login"])
			$id = $data["id_client"];
	}
	$choix = $_POST['choix'];
	foreach ($choix as $item=>$val){
		if ($val > 0){
			$sql = "UPDATE ".$dbname.".articles SET stock = stock -'".$val."' WHERE articles.id_article ='".$item."'";
			mysqli_query($link, $sql);
			$sql = "INSERT ".$dbname.".panier  VALUES (NULL, '".$id."','".$item."', '".$val."')";
			mysqli_query($link, $sql);
		}
	
	}
}

?>