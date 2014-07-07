<?php
$nick = $_POST["nick"];
$pass = $_POST["password"];
$cpass = $_POST["passwordt"];
$name = $_POST["sname"];
$subname = $_POST["subname"];
$dd = $_POST["dd"];
$mm = $_POST["mm"];
$yy = $_POST["yy"];
$adress = $_POST["adress"];
$city = $_POST["city"];
$zip = $_POST["postal"];
$tel = $_POST["tel"];
$email = $_POST["email"];
$mail = $_POST["email2"];
$carte = $_POST["carte"];
$secu = $_POST["secu"];


if (isset($nick) and isset($pass) and isset($mail) and isset($cpass) and isset($name) and isset($subname) and isset($dd) and isset($mm) and isset($yy) and isset($adress) and isset($city) and isset($zip) and isset($tel) and isset($email) and isset($carte) and isset($secu)){
	if ($pass != $cpass){?>
		Erreur au niveau du mot de passe.<br>
		<a href="index.php?id=2"> Go back</a>
<?php }
	else if (!is_numeric(trim($dd)) or !is_numeric(trim($mm)) or!is_numeric(trim($yy))){?>
		Erreur dans la date de naissance.<br>
		<a href="index.php?id=2"> Go back</a>
	<?php }
	else{
		$bday = $dd."/".$mm."/".$yy;
		$mail = trim($email)."@".trim($email2);
		$add = $adress." ".$city." ".$zip;
		$req = "INSERT INTO ".$dbname.".client VALUES (NULL , '".$name."', '".$subname."', '".$nick."', '".hash("whirlpool",$pass)."', '".$bday."' , '".$add."', NULL , NULL , NULL ,NULL , NULL ,'3')";
		echo $req;
		mysqli_query($link, $req);
		header("Location: index.php?id=12");
	}

}
else
	echo "Remplire tout les champs."


?>