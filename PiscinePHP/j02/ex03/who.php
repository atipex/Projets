#!/usr/bin/php
<?PHP
exec("who", $tab);
foreach ($tab as $value)
	echo $value."\n";
?>
