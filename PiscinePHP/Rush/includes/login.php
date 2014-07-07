<?php

$login = $_SESSION["login"];
if ($_SESSION["sid"] == hash("whirlpool",$key.$login))
	header("Location: index.php");
else
{
?>


<form style="height:450px" method="post" action="index.php?id=9">
<table>
<tbody style="position:absolute; top:250px; left:67px;">
<div id="block5">
</div>

<table>
	<tr>
		<td>Login :</td>
		<td><input type="text" name="login" size="10"></td>
	</tr>	
	<tr>
		<td>Mot de passe :</td>
		<td><input type="password" name="pass" size="10"></td>
	</tr>	
	<tr>
		<td align="right"><input type="Submit" value="Send"></td>
		<td><input type="Reset" value="Reset"></td>
	</tr>	
</table>
</form>
<?php
}
?>