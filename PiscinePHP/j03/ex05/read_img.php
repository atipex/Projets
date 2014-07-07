<?php
$file = 'img/42.png';
$type = 'image/png';
header('Content-Type:'.$type);
header('Content-Length: 33450');
readfile($file);
?>