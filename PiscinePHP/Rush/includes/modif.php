<?php

if (isset($_SESSION["login"])){
	$login = $_SESSION["login"];

	if ($_SESSION["sid"] == hash("whirlpool",$key.$login)){

		$sql = "SELECT * FROM client WHERE client.login_client = '".$login."'";
		$req = mysqli_query($link, $sql);

		while($data = mysqli_fetch_array($req))
		{
			$name = $data["nom"];
			$subname = $data["prenom"];
			$mdp = $data["mdp_client"];
			$bdate = $data["date_naiss"];
			$add = $data["adresse1"];
		}
		?>
<form method="post" action="index.php?id=10">
<table>
	<tr>
		<td>Login :</td>
		<td><b><?php echo $login;?></b></td>
	</tr>
	<tr>
		<td>Nom :</td>
		<td><input type="text" name="name" value="<?php echo $name;?>" maxlength="10" size="10"></td>
	</tr>	
	<tr>
		<td>Prenom :</td>
		<td><input type="text" name="subname" value="<?php echo $subname;?>" maxlength="10" size="10"></td>
	</tr>
	<tr>
		<td>Date de naissance :</td>
		<td><input type="text" name="bdate" value="<?php echo $bdate;?>" maxlength="10" size="10"></td>
	</tr>
		<tr>
		<td>&nbsp;</td>
		<td><i>yyyy/mm/dd</i></td>
	</tr>
	<tr>
		<td>Adresse </td>
		<td><input type="text" name="add" value="<?php echo $add;?>" maxlength="15" size="10"></td>
	</tr>
	<tr>
		<td>Ancien mot de passe :</td>
		<td><input type="password" name="pass1" size="10"></td>
	</tr>
	<tr>
		<td>Noueau mot de passe :</td>
		<td><input type="password" name="pass2" size="10"></td>
	</tr>	
	<tr>
		<td>Confirmer mot de passe :</td>
		<td><input type="password" name="pass3" size="10"></td>
	</tr>	
	<tr>
		<td>Effacer </td>
		<td><input type="checkbox" name="delete[]" value="<?php echo $login ?>"/> </td>
	</tr>	
	<tr>
		<td align="right"><input type="Submit" value="Send"></td>
		<td><input type="Reset" value="Reset"></td>
	</tr>	
</table>
</form>
		
<?php		
	}
}
else
	header("Location: index.php?id=1");
?>