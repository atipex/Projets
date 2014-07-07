<?php
Class Color{

	public static		$verbose = False;
	public				$red = 0;
	public				$green = 0;
	public				$blue = 0;

	public function __construct( array $kwargs ){
		if (array_key_exists('rgb', $kwargs)) {
			$this->red = intval(($kwargs['rgb'] >> 16) & 255);
			$this->green = intval(($kwargs['rgb'] >> 8) & 255);
			$this->blue = intval(($kwargs['rgb']) & 255);
		}
		else {
			if (array_key_exists('red', $kwargs))
				$this->red = intval($kwargs['red']);
			if (array_key_exists('green', $kwargs))
				$this->green = intval($kwargs['green']);
			if (array_key_exists('blue', $kwargs))
				$this->blue = intval($kwargs['blue']);
		}
		if (self::$verbose === TRUE)
		{
			$space_r = str_pad($this->red, 3, " ", STR_PAD_LEFT);
			$space_g = str_pad($this->green, 3, " ", STR_PAD_LEFT);
			$space_b = str_pad($this->blue, 3, " ", STR_PAD_LEFT);    
			print("Color( red: $space_r, green: $space_g, blue: $space_b ) constructed."."\n");
		}
	}

	public static function doc(){
		$ret = file_get_contents('Color.doc.txt');
		echo $ret;
		return ;
	}

	public function aff_tranz($tranz){
		if (self::$verbose === TRUE)
		{
			$space_r = str_pad($tranz->red, 3, " ", STR_PAD_LEFT);
			$space_g = str_pad($tranz->green, 3, " ", STR_PAD_LEFT);
			$space_b = str_pad($tranz->blue, 3, " ", STR_PAD_LEFT);    
			print("Color( red: $space_r, green: $space_g, blue: $space_b ) constructed."."\n");
		}
	}

	public function test_tranz($tranz){
		if ($tranz->red < 0)
			$tranz->red = 0;
		if ($tranz->green < 0)
			$tranz->green = 0;
		if ($tranz->blue < 0)
			$tranz->blue = 0;
		return $tranz;
	}

	public function __clone(){
		return ;
	}

	public function add($couleur){
		$tranz = clone $this;
		$tranz->red += $couleur->red;
		$tranz->blue += $couleur->blue;
		$tranz->green += $couleur->green;
		$tranz = self::test_tranz($tranz);
		self::aff_tranz($tranz);
		return $tranz;
	}

	public function sub($couleur){
		$tranz = clone $this;
		$tranz->red -= $couleur->red;
		$tranz->blue -= $couleur->blue;
		$tranz->green -= $couleur->green;
		$tranz =  self::test_tranz($tranz);
		self::aff_tranz($tranz);
		return $tranz;
	}

	public function mult($fact){
		$tranz = clone $this;
		$tranz->red *= $fact;
		$tranz->blue *= $fact;
		$tranz->green *= $fact;
		$tranz =  self::test_tranz($tranz);
		self::aff_tranz($tranz);
		return $tranz;
	}

	public function __toString(){
		$space_r = str_pad($this->red, 3, " ", STR_PAD_LEFT);
		$space_g = str_pad($this->green, 3, " ", STR_PAD_LEFT);
		$space_b = str_pad($this->blue, 3, " ", STR_PAD_LEFT); 
		return "Color( red: ".$space_r.", green: ".$space_g.", blue: ".$space_b." )";
	}

	public function __destruct(){
		if (self::$verbose === TRUE)
		{
			$space_r = str_pad($this->red, 3, " ", STR_PAD_LEFT);
			$space_g = str_pad($this->green, 3, " ", STR_PAD_LEFT);
			$space_b = str_pad($this->blue, 3, " ", STR_PAD_LEFT); 
			print("Color( red: ".$space_r.", green: ".$space_g.", blue: ".$space_b." ) destructed."."\n");
		}
	}
}
?>
