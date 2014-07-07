<!DOCTYPE html>
<?php include("includes/conf.php");
$_SESSION["bid"] = hash("whirlpool",$key.$_SERVER["REMOTE_ADDR"]);
if (isset($_GET["id"]))
	$id = $_GET["id"];	
 ?>
<html>
<head>
		<title>Welcome</title>
	<link rel="stylesheet" type="text/css" href="image/indexl.css">
</head>
<body bgcolor="#00BFFF">
<div id="block"></div>
<?php
if (isset($_SESSION["login"])){
	$login = $_SESSION["login"];
	if ($_SESSION["sid"] == hash("whirlpool",$key.$login))
		include("includes/head2.php");
	else
		include("includes/head.php");
}
else
	include("includes/head.php");
?>
<div id="blue">
	<img style="left:457px; position: absolute; height:387px; top: -1px" src="image/blue-horse-hi.png">
	<p style="position: absolute; left: 594px; top: 150px; color: black; font-family:cursive; font-size: 29px; width: 151px; font-style: italic; text-shadow: 1px 1px 4px blue">Blue Horse</p>
</div>
<?php 
if (isset($id)){
	if ($id == '1')
		include("includes/login.php");
	else if ($id == '2')
		include ("includes/subscribe.php");
	else if ($id == '3')
		include ("includes/logout.php");
	else if ($id == '4')
		include ("includes/modif.php");
	else if ($id == '5')
		include ("includes/ba.php");
	else if ($id == '9')
		include ("includes/auth.php");
	else if ($id == '10')
		include ("includes/mod.php");
	else if ($id == '11')
		include ("includes/confirm.php");
	else if ($id == '12')
		include ("includes/success.php");
	else if ($id == '13')
		include ("includes/pa.php");
	else if ($id == '15')
		include ("includes/valid.php");
	else
		include("includes/main.php");
}
else
	include("includes/main.php");
 ?>
<?php include ("includes/bot.php");?>	
</body>
</html>
