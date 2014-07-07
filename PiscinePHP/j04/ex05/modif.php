<?php
function test_mdp($login, $old_user, $array){
	foreach ($array as $value){
		if ($value['login'] == $login AND $value['passwd'] == hash('whirlpool',$old_user))
			return (1);
	}
	return (0);
}

function new_mdp($login, $old_user, $newpw, $array){
	foreach ($array as $value){
		if ($value['login'] == $login AND $value['passwd'] == hash('whirlpool',$old_user))
			$value['passwd'] = hash('whirlpool', $newpw);
		$tab[] = $value;
	}
	return ($tab);

}

$login = $_POST['login'];
$oldpw = $_POST['oldpw'];
$newpw = $_POST['newpw'];
$s = $_POST['submit'];
$file = '../private/passwd';

if ($login === "" || $oldpw === "" || $newpw === "" || $s != "OK" || !file_get_contents($file)){
	echo "ERROR\n";
}
else {
	$cont = file_get_contents($file);
	$array = unserialize($cont);
	if (test_mdp($login, $oldpw, $array)){
		$tab = new_mdp($login, $oldpw, $newpw, $array);
		file_put_contents($file, serialize($tab));
		echo "OK.\n";
		header("Location: index.html");
	}
	else
		echo "ERROR\n";
}
?>