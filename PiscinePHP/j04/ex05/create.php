<?php
function test_login($array, $test){
	foreach($array as $value){
		foreach ($value as $key_2 => $value_2){
			if ($key_2 == "login"){
				if ($value_2 == $test)
					return (0);
			}
		}
	}
	return (1);
}

if ($_POST['submit'] === "OK"){
	$tab['login'] = $_POST['login'];
	if ($_POST['passwd'] != "" AND  $_POST['login'] != "" ){
		$tab['passwd'] = hash('whirlpool',$_POST['passwd']);
		mkdir ("../private");
		if (!file_exists("../private/passwd")){
			$array[] = $tab;
			file_put_contents("../private/passwd", serialize($array));
			echo "OK\n";
			header("Location: index.html");
		}
		else{
			$ret = file_get_contents("../private/passwd");
			$array = unserialize($ret);
			if (test_login($array, $_POST['login'])){
				$array[] = $tab;
				file_put_contents("../private/passwd", serialize($array));
				echo "OK\n";
				header("Location: index.html");
			}
			else
				echo "ERROR\n";
		}
	}
	else
		echo "ERROR\n";
}
else{
	echo "ERROR\n";
}
?>