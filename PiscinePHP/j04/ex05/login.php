<?php 
session_start();
include("auth.php");
$login = $_POST['login'];
$passwd = $_POST['passwd'];
if (auth($login, $passwd)){
	$_SESSION['loggued_on_user'] = $login;
	?>
		<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>
		<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>
	<?php
}
else{
	$_SESSION['loggued_on_user'] = "";
	header("Location: index.html");
}
?>