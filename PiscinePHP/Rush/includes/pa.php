<?php
$login = $_SESSION["login"];
if (isset($_SESSION["login"])){

	if ($_SESSION["sid"] == hash("whirlpool",$key.$login)){
?>

<table>
<tr>
	<td>Nom du produit</td>
	<td>Quantit&eacute;</td>
	<td>Prix</td>
</tr>
<?php

	$sql = "SELECT * FROM `client`";
	$req = mysqli_query($link, $sql);

	while ($data = mysqli_fetch_array($req))
	{
		if ($data["login_client"] == $_SESSION["login"])
			$id = $data["id_client"];
	}

	$sql = "SELECT * FROM `panier`";
	$req = mysqli_query($link, $sql);
	while($data = mysqli_fetch_array($req)){
		if ($data['id_client'] == $id){
			$tmp[$data['id_article']] = $data['qte'];
			foreach ($tmp as $prod=>$nbr){
				$sql = "SELECT * FROM `articles`";
				$req = mysqli_query($link, $sql);
				while ($dat = mysqli_fetch_array($req)){
					$prix = $nbr*$dat['prix'];
					if ($dat['id_article'] == $prod){
						echo "<tr><td>".$dat['ref']."</td><td>".$nbr."</td><td>".$prix."</td></tr>";
					}
				}
			}
		}
	}
?>
</table>	
<?php
	}
}
else
	header("Location: index.php?id=1");
?>
