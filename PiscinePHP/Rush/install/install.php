<html>
<body bgcolor="#00BFFF">
<?php 
if (isset($_POST["dbhost"]) and isset($_POST["dbname"]) and isset($_POST["dblogin"])) {
	$host = $_POST["dbhost"];
	$name = $_POST["dbname"];
	$login = $_POST["dblogin"];
	$pass = $_POST["dbpass"];
	$file = '../includes/conf.php';

	if (filesize($file) === 0){
		if (isset($host) AND isset($name) AND isset($login)){
		$link = mysqli_connect($host, $login, $pass, $name);

		if (!$link OR $host === "" OR $name === "" OR $login === ""){?>
<table align="center">
<tr align="center">
<td align="center">
<img width="50%" src="../image/Sign-Error-icon.png">
</td>
<td align="left">
<font color="red"><p style="text-shadow: 3px 3px 3px #000000; font-family: fantasy; font-size: 500%;font-weight:bold; text-align: center">Error.</p></font>
</td>
</tr>
<tr><td></td></tr>
<tr>
<td align="right">
	<font color="red"><p style="text-shadow: 3px 3px 3px #000000; font-family: fantasy; font-size: 200%;font-weight:bold"><a href="index.php"><u>Go back.</u></p></font></a>
</td>
</tr>
</table>
	<?php exit();
}
	$sql = file_get_contents("my_boutique.sql");
	$sql_array = explode (";\n",$sql);
	foreach ($sql_array as $val) {
		if ($val != "")
			mysqli_query($link,$val)or die("<p>Erreur dans l'injection de la BdD de base!</p>");
	}
	$p = 0;
	$key = 0;
	$size = 8;
	$char_list = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789-_";
	while ( $p < $size ){
		$test .= $char_list[mt_rand(0, strlen($char_list)-1)];
		$p++;
	} 
	while ( $key < $size ){
		$keyy .= $char_list[mt_rand(0, strlen($char_list)-1)];
		$key++;
	} 
	$content = "<?php\n\$key = \"".$keyy."\";\n\$dbhost = \"".$host."\";\n\$dbname = \"".$name."\";\n\$passadmin = \"".$test."\";\n\$dblogin = \"".$login."\";\n\$dbpass = \"".$pass."\";\n\$link = mysqli_connect(\$dbhost, \$dblogin, \$dbpass, \$dbname) or die(\"Error \".mysqli_error(\$link));\nsession_start();\n?>";
	file_put_contents($file,$content);
	$req = "INSERT INTO ".$dbname.".client VALUES (NULL , 'root', 'root', 'root', '".hash("whirlpool",$test)."', NULL , NULL, NULL , NULL , NULL ,NULL , NULL ,'1')";
	mysqli_query($link,$req);
	header("Location: index.php");
	}
}
}
else
	{ ?>
<font color="red"><p style="text-shadow: 0 0 3px #000000; font-family: fantasy; font-size: 200%;font-weight:bold; text-align: center; margin: 15% 27% 0% 0%"> Please remove this folder and find your password in conf.php!</p><font></p>

<?php }
?>
</body>
</html>
