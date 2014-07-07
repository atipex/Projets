#!/usr/bin/php
<?PHP

function try_char($str){
	if (preg_match("/^[a-zA-Z]|/",$str) or $str == '/')
		return TRUE;
	return False;
}

if ($argc > 1){
	$i = 0;
	foreach($argv as $item){
		if ($i++ == 1)
			$file = trim($item);
	}
	if ($handle = fopen($file,'r')){
		while (!feof($handle)){
			$line[] = fgets($handle);
		}
		fclose($handle);
		$i = 0;
		foreach ($line as $token){
			if (preg_match("/^.*<a.*$/", $token) or preg_match("/^.*<\/a>*$/", $token)){
				$real[] = $token;
			}
		}
		foreach ($real as $real1){
			$tab[] = str_split($real1);
		}
		$flag = 0;
		$flagb = 0;
		$j = 0;
		$str[] = "";
		foreach ($tab as $tab1){
			$i = 0;
			$str[$j] = "";
			foreach ($tab1 as $tab2){
				if ($tab2 == '=' and strtolower($tab1[$i -1]) == 'e' and strtolower($tab1[$i - 2]) == 'l' ){
					$str[$j] .= $tab2;
					$flag = 1;
				}
				else if ($flag == 1){
					if (($tab2 == '"' or $tab2 == '\'') and ($tab1[$i + 1] == '>')){
						$flag = 0;
						$str[$j] .= $tab2;
					}
					else
						$str[$j] .= strtoupper($tab2);
				}
				else
					$str[$j] .= $tab2;
				$i++;
			}
			$j++;
		}
		foreach ($str as $sstr){
			$newss[] = str_split($sstr);
		}
		$j = 0;
		foreach ($newss as $str2){
			$i = 0;
			$new[$j] = "";
			foreach($str2 as $str3){
				if ($str3 == 'a' and $str2[$i - 1] == '<'){
					$new[$j] .= $str3;
					$flagb = 1;
				}
				else if ($flagb == 1){
					if ($str3 == '>')
						$flagb = 2;
					$new[$j] .= $str3;
				}
				else if ($flagb == 2){
					if ($str3 == '<'){
						$flagb = 0;
						$new[$j] .= $str3;
					}
					else
						$new[$j] .= strtoupper($str3);
				}
				else
					$new[$j] .= $str3;
				$i++;
			}
			$j++;
		}
		$j = 0;
		$i = 0;
		foreach ($line as $lines){
			$ret[$i] = "";
			if (preg_match("/^.*<a.*$/", $lines) or preg_match("/^.*<\/a>*$/", $lines)){
				$ret[$i] .= $new[$j++];
			}
			else
				$ret[$i] .= $lines;
			$i++;
		}
		foreach($ret as $rett){
			echo $rett;
		}
	}
	else
		echo "Can't open this file.\n";
}

?>
