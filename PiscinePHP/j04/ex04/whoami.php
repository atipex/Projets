<?php 
session_start();
$try = $_SESSION['loggued_on_user'];
if ($try){
	echo $try."\n";
}
else
	echo "ERROR\n";
?>