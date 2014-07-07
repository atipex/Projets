<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
<?php
session_start();
$file = '../private/chat';
echo $_SESSION['loggued_on_user'];
if ($_SESSION['loggued_on_user'] != "")
{
	$ret = file_get_contents($file);
	$array = unserialize($ret);
	$tab['login'] = $_SESSION['loggued_on_user'];
	$tab['time'] = time();
	$tab['msg'] = $_POST['msg'];
	$array[] = $tab;
	$fp = fopen($file, "r+");
	if (flock($fp, LOCK_EX))
		file_put_contents($file, serialize($array));
	else
    	echo "Couldn't get the lock!";
   	fclose($fp);
	?>
<form ation="speak.php" method="POST">
	<input type="text" name="msg" size="20">
</form>
<?php 
}
else
	echo "ERROR";
?>