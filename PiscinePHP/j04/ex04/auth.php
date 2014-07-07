<?php
function auth($login, $passwd){
	$file = '../private/passwd';
	$cont = file_get_contents($file);
	$array = unserialize($cont);
	foreach ($array as $value){
		if ($value['login'] == $login AND $value['passwd'] == hash('whirlpool',$passwd))
			return (TRUE);
	}
	return (FALSE);
}
?>
