<?php include("../includes/conf.php");

$login = $_SESSION["login"];
if ($_SESSION["sid"] == hash("whirlpool",$key.$login) && $_SESSION['uid'] == hash("whirlpool",$passadmin.$login))
	header("Location: index1.php");
else
{
?>
<!DOCTYPE html>
<html>
<head>
	<title>Administration</title>
	<link rel="stylesheet" type="text/css" href="../image/index.css" />
</head>
<body bgcolor="#00BFFF">
<div id="block" >
	
</div>
<form method="post" action="auth.php">
<tr>
<td>
<div style="position:absolute;left:494px; top:278px; font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)">
	Login: <input type="text" name="login">
</div>
</td>
</tr>
<br>
<tr>
<td>
<div style="position:absolute; top:359px; left:455px; font-family:courier new; font-size: 150%; font-weight:bold; text-shadow:1px 3px 2px rgb(8, 8, 138)">
	Password: <input type="password" name="pass">
</div>
</td>
</tr>
<input style="position:absolute; left:702px; top:417px" type="Submit" value="Envoyer">
</form>
<?php } ?>
</body>
</html>