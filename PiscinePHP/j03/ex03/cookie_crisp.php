<?php

foreach ($_GET as $key => $value) {
	if ($key === 'action') {
		if ($value === 'set') {
			$val = 1;
		}
		else if ($value === 'get') {
			$val = 2;
		}
		else if ($value === 'del') {
			$val = 3;
		}
	}
}
if ($val == 1) {
	foreach ($_GET as $key => $value) {
		if ($key === 'name')
			$title = $value;
		else if ($key === 'value') {
			$content = $value;
		}
	}
	setcookie($title, $content, (time() + 3600));
}
else if ($val == 2) {
	foreach ($_GET as $key => $value) {
		if ($key === 'name') {
			$name = $value;
		}
	}
	echo $_COOKIE[$name]."\n";

}
else if ($val == 3) {
	foreach ($_GET as $key => $value) {
		if ($key === 'name') {
			$name = $value;
		}
	}
	setcookie($name, "", time()-3600);
}

?>