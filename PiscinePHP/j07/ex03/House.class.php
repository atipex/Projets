<?php
abstract CLass House{

	public function introduce() {
		print("House ".static::getHouseName()." of ".static::getHouseSeat()." : \"".static::getHouseMotto()."\"\n");
	}

	abstract function getHouseName(); 
	abstract function getHouseMotto();
	abstract function getHouseSeat();
}
?>
