<!DOCTYPE html>
<?php include("../includes/conf.php");

$login = $_SESSION["login"];
if ($_SESSION["sid"] == hash("whirlpool",$key.$login) && $_SESSION['uid'] == hash("whirlpool",$passadmin.$login)){
	$ref = $_POST['ref'];
	$stock = $_POST['stock'];
	$prix = $_POST['prix'];
?>
<html>
<head>
	<title>Administration</title>
	<link rel="stylesheet" type="text/css" href="../image/index5.css" />
</head>
<body bgcolor="#00BFFF">
<form style="color: black" method="post" action="delete.php">
<table style="position: absolute; left: 208px;top: 254px" align="center">
<CAPTION style="width: 328px; font-size: 253%; position: absolute; top: -98px; left: 26px; font-family: fantasy; color: rgb(88,130,250); text-shadow:5px 5px 5px black;" >Listing des articles :</CAPTION>
<tr>
	<th style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)">ID</th>
	<br>
	<th style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"> Ref </th>
	<br>
	<th style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"> Stock </th>
	<br>
	<th style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"> Prix </th>
	<br>
	<td>&nbsp;</td>
</tr>
<div id="block" >
	
</div>
<div id="block2">
	
</div>
<div id="block3">
	
</div>
<div style="height: 100px; width: 100px; background-color: #2E64FE; left:1127px; top:114px; position: absolute; border: 5px double blue; border-radius: 30px 0 30px 30px;" id="block4">
	
</div>
<div id="link1" >
	<a href="fac.php"><p>Facture</p></a>
</div>
<div style="font-family:monospace; font-size:70px; position:absolute; left:352px; top:-47px; color:#088A08; text-shadow:1px 3px 2px black" id="title">
	<p style="color: blue">Administration</p>
</div>
<div id="link">
<a href="../index.php?id=3"><font color="#5882fa"><p>Logout</p></a>
</div>
<?php 
$sql = "SELECT * FROM `articles`";

$req = mysqli_query($link, $sql);

while($data = mysqli_fetch_array($req))
    {
    echo '<tr><td style="font-family:courier new; font-size: 110%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)">'.$data['id_article'].'</td><td style="font-family:courier new; font-size: 110%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)">'.$data['ref'].'	</td><td style="font-family:courier new; font-size: 110%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"><center>'.$data['stock'].'</center></td><td style="font-family:courier new; font-size: 110%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)"><center>'.$data['prix'].'</center></td><td><input type="checkbox" name="choix[]" value ="'.$data['id_article'].'"/></td></tr>'."\n";
    echo '<div id="gap_form"><tr><td><input type="hidden" name = "id" value = "'.$data['id_article'].'""></td><td><input type="text" name ="ref"></td><td ><input type="text" name = "stock" size = 3></td><td><input type="text" name = "prix" size = 3></td><td><a id="myLink" href="#"><img src="../image/actualiser.png" </a></div></td></form>';
    } 

 ?><tr>
 <td>&nbsp;</td>
 <td>&nbsp;</td>
 <td>&nbsp;</td>
 <td>&nbsp;</td>
 <td><input type="Submit" value="Delete"></td>
 </tr>
 </table>
</form>
<div id="article">
 Add an article :
 </div>
 <div id="add">
 <form method="post" action="add.php">
 <table align="center">
 <tr>
 <div style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)" id="ref">
Ref: <input style="position:absolute; left:39%" type="text" name="ref">
</div>
</tr>
<br>
<tr>
<div style="font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)" id="stock">
Stock: <input style="left:39%; position:absolute" type="text" name="stock">
</div>
</tr>
<br>
<tr>
<div style="width:206%; font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)" id="prix">
Prix: <input style="width: 170.5px; margin-left:30px" type="text" name="prix" >&euro;
</div>
</tr>
<input style="position:absolute; left:53%; top:104%" type="Submit" value="Envoyer">
<input style="left: 86%; position:absolute; top: 104%" type="Reset" value="Reset">
</table>
</div>
</form>
<?php }
else
	header("Location: index.php");
?>
</body>
</html>