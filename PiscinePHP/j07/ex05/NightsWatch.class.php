<?php

Class 	NightsWatch{
	public  $array;

	public function recruit($obj){
		if (method_exists($obj, "fight"))
			$this->array[] = $obj;
	}

	public function fight(){
		foreach ($this->array as $value){
			$value->fight();
		}
	}
}

?>