<?php

function test_mdp($array){
	foreach ($array as $value){
		echo date("[H:i]",$value['time']);
		echo " <b>".$value['login']."</b> :";
		echo $value['msg']."<br>";
	}
}
date_default_timezone_set("Europe/Paris");
$f = "../private/chat";
$cont = file_get_contents($f);
$array = unserialize($cont);
test_mdp($array);
?>