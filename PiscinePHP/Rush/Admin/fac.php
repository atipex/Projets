<?php include("../includes/conf.php");

$login = $_SESSION["login"];
if ($_SESSION["sid"] == hash("whirlpool",$key.$login) && $_SESSION['uid'] == hash("whirlpool",$passadmin.$login)){
	$ref = $_POST['ref'];
	$stock = $_POST['stock'];
	$prix = $_POST['prix'];
?>
<!DOCTYPE html>
<html>
<head>
	<title>Administration</title>
	<link rel="stylesheet" type="text/css" href="../image/index4.css" />
</head>
<body bgcolor="#00BFFF">
<form method="post" action="mod.php">
<CAPTION ><p style="width: 421px; font-size: 253%; position: absolute; top: 99px; left: 426px; font-family: fantasy; color: rgb(88,130,250); text-shadow:5px 5px 5px black;">Listing des factures: </p></CAPTION>
<table style="position: absolute; left: 413px;top: 240px; font-size:12px" align="center">
<tr>
	<th style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)">ID panier</th>
	<br>
	<th style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"> ID client </th>
	<br>
	<th style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"> ID article </th>
	<br>
	<th style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"> Nombre </th>
	<td>&nbsp;</td>
</tr>
<div id="block" >
	
</div>
<div id="block3">
	
</div>
<div style="height: 100px; width: 100px; background-color: #2E64FE; left:1127px; top:114px; position: absolute; border: 5px double blue; border-radius: 30px 0 30px 30px;" id="block4">
	
</div>
<div id="link1" >
	<a href="index1.php"><p>Article</p></a>
</div>
<div style="font-family:monospace; font-size:70px; position:absolute; left:352px; top:-47px; color:#088A08; text-shadow:1px 3px 2px black" id="title">
	<p style="color: blue">Administration</p>
</div>
<div id="link">
<a href="../index.php?id=3"><font color="#5882fa"><p>Logout</p></a>
</div>
<?php 
$sql = "SELECT * FROM `panier`";

$req = mysqli_query($link, $sql);

while($data = mysqli_fetch_array($req))
    {
    	if ($data['id_panier'] > 0)
    		echo '<tr><td style="font-family:courier new; font-size: 110%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)">'.$data['id_panier'].'</td><td style="font-family:courier new; font-size: 110%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)">'.$data['id_client'].'	</td><td style="font-family:courier new; font-size: 110%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"><center>'.$data['id_article'].'</center></td><td style="font-family:courier new; font-size: 110%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"><center>'.$data['qte'].'</center></td><td><input type="checkbox" name="choix[]" value ="'.$data['id_panier'].'"/></td></tr>'."\n";
    } 
 ?><tr>
 <td>&nbsp;</td>
 <td>&nbsp;</td>
 <td>&nbsp;</td>
 <td>&nbsp;</td>
 <td><input type="Submit" name="ok" value="Validation"><br><input type="Submit" name="del" value="Effacer"></td>
 </tr>
 </table>
</form>
<?php }
else
	header("Location: index.php");
?>
</body>
</html>