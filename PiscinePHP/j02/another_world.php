#!/usr/bin/php
<?PHP
function is_space($truc){
	foreach ($truc as $item){
		if ($item !=  " " && $item != "\t" && $item != "\n" && $item != "")
			return True;
	}
	return False;
}

$i = 0;
if ($argc > 1){
	foreach ($argv as $item){
		if ($i++ == 1)
			$tab = $item;
	}
	if (isset($tab)){
		if (is_space($tab))
		{
			$tmp = explode(" ", $tab);
			foreach ($tmp as $token){
				$token = trim($token);
				if ($token != "")
					$tab1[] = $token;
			}
			$str = implode(" ", $tab1);
			echo $str."\n";
		}
		else $tab."\n";
	}
	else
		echo $tab."\n";
}
?>
