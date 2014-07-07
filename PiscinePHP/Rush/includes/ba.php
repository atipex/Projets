<form style="height: 450px"method="post" action="index.php?id=15"><table>
<tr>
	<td>Nom de l'objet</td>
	<td>Stock</td>
	<td>Prix</td>
	<td>&nbsp;</td>
</tr>
<?php 

	$sql = "SELECT * FROM `articles`";
	$req = mysqli_query($link, $sql);
	$j = 0;
	while($data = mysqli_fetch_array($req)){
	    	$i = 0;
	    	if ($data['stock'] > 0){
	    		echo '<tr><td>'.$data['ref'].'</td><td><center>'.$data['stock'].'</center></td><td><center>'.$data['prix'].'</center></td>';
    			echo "<td><select name=choix[".$data['id_article']."] id= ".$data['id_article'].">";
    			$int = trim($data['stock']);
   				while ($i <= $int){
    				echo "<option value=\"".$i."\">".$i."</option>\n";
    				$i++;
    			}
				echo '</select></td></tr>';
    	}
 	}
?><tr>
	<td>&nbsp;</td>
	<td>&nbsp;</td>
	<td>&nbsp;</td>
	<td><input type="Submit"></td></tr>
</table>
</form>