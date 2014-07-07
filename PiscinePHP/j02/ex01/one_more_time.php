#!/usr/bin/php
<?PHP

function is_maj($str){
	$i = 0;
	$tmp = str_split($str);
	foreach ($tmp as $item){
		if ($i == 0){
			if (!preg_match("/^[a-zA-Z]/",$item))
				return FALSE;
		}
		else if ($i != 0){
			if (preg_match("/^[A-Z]/",$item)){
				return FALSE;
			}
		}
	}
	return TRUE;
}

function is_month($str){
	if (strcmp("janvier",$str) == 0)
		return 1;
	else if (strcmp("février",$str) == 0)
		return 2;
	else if (strcmp("fevrier",$str) == 0)
		return 2;
	else if (strcmp("mars",$str)== 0)
		return 3;
	else if (strcmp("avril",$str) == 0)
		return 4;
	else if (strcmp("mai",$str) == 0)
		return 5;
	else if (strcmp("juin",$str) == 0)
		return 6;
	else if (strcmp("juillet",$str) == 0)
		return 7;
	else if (strcmp("août",$str) == 0)
		return 8;
	else if (strcmp("aout",$str) == 0)
		return 8;
	else if (strcmp("septembre",$str) == 0)
		return 9;
	else if (strcmp("octobre",$str) == 0)
		return 10;
	else if (strcmp("novembre",$str) == 0)
		return 11;
	else if (strcmp("décembre",$str) == 0)
		return 12;
	else if (strcmp("decembre",$str) == 0)
		return 12;
	else
		return 0;
}

function is_day($str){
	if (strcmp("lundi",$str) == 0)
		return (true);
	else if (strcmp("mardi",$str) == 0)
		return (true);
	else if (strcmp("mercredi",$str) == 0)
		return (true);
	else if (strcmp("jeudi",$str) == 0)
		return (true);
	else if (strcmp("vendredi",$str) == 0)
		return (true);
	else if (strcmp("samedi",$str) == 0)
		return (true);
	else if (strcmp("dimanche",$str) == 0)
		return (true);
	else
		return (false);
}

function is_number($str){
	if (is_numeric($str)){
		if ($str >= 0 AND $str <= 31)
			return TRUE;
		return FALSE;
	}
	return FALSE;
}

$error = "Wrong Format\n";
if ($argc > 1){
	$i = 0;
	foreach ($argv as $item){
		if ($i++ == 1)
			$tmp = $item;
	}
	$tab = explode(" ",$tmp);
	$c = 0;
	foreach ($tab as $elem){
		$elem = trim($elem);
		if ($elem != ""){
			$tab1[] = $elem;
			$c++;
		}
	}
	if ($c == 5){
		if (is_maj($tab1[0]) AND is_maj($tab1[2])){
			if (is_day(strtolower($tab1[0])) AND is_number(trim($tab1[1])) AND (is_month(strtolower($tab1[2])) > 0) AND preg_match("/(0[1-9]|1[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]/", $tab1[4])){
				date_default_timezone_set("Europe/Paris");
				$ref = strtotime("1970-01-01 00:00:00");
				$reff = $tab1[3]."-".is_month(strtolower($tab1[2]))."-".$tab1[1]." ".$tab1[4];
				$date = strtotime($reff);
				$diff = abs($date - $ref) - 3600;
				echo $diff."\n";
			}
			else
				echo $error."1";
		}
		else
			echo $error;
	}
	else
		echo $error;

}

?>
