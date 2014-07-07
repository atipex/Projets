<!DOCTYPE html>
<html>
<head>
	<title>Install</title>
</head>
<body bgcolor="#00BFFF">
<?php
$file = '../includes/conf.php';

if (filesize($file) === 0){
?>
<form action="install.php" method="post">
<table style="margin: 10% 0 0 25%">
<tr align="center">
<td align="right">
Database Hostname(localhost:8080): <td align="right"><input type="text" name="dbhost">
</td>
</tr>
<br>
<tr align="center">
<td align="right">
<p >Database name: </p></td><td align="right"><input type="text" name="dbname">
</td>
</tr>
<tr align="center">
<td align="right">
<p >Database login:</p></td><td align="right"><input type="text" name="dblogin">
</td>
</tr>
<br>
<tr align="center">
<td align="right">
Database password: </td><td align="right"><input type="password" name="dbpass">
</td>
</tr>
<br>
<tr align="left">
<td align="right">
<input type="Submit" value="Ok">
<td align="left">
<input type="Reset" value="Reset">
</td>
</tr>
</table>
</form>
<?php
}
else
{?>

 <font color="red"><p style="text-shadow: 0 0 3px #000000; font-family: fantasy; font-size: 200%;font-weight:bold; text-align: center; margin: 15% 27% 0% 0%"> Please remove this folder and find your password in conf.php!</p><font></p>


<?php
}?>
</body>
</html>