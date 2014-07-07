<?php
Class Vertex{
	public static	$verbose = False;
	private			$_x;
	private			$_y;
	private			$_z;
	private			$_w;
	private			$_color;

	public static function doc(){
		$ret = file_get_contents('Vertex.doc.txt');
		echo $ret;
		return ;
	}

	public function __construct( array $kwargs ){
		require_once('Color.class.php');
		self::setX($kwargs['x']);
		self::setY($kwargs['y']);
		self::setZ($kwargs['z']);
		if (array_key_exists('w', $kwargs))
			self::setW($kwargs['w']);
		else
			self::setW(1.0);
		if (array_key_exists('color', $kwargs))
			self::setColor($kwargs['color']);
		else{
			$white = new Color( array( 'red' =>  0xff   , 'green' =>  0xff   , 'blue' => 0xff ) );
			self::setColor($white);
		}
		if (self::$verbose === True)
		{
			$space_r = str_pad($this->_x, 3, " ", STR_PAD_LEFT);
			$space_g = str_pad($this->_y, 3, " ", STR_PAD_LEFT);
			$space_b = str_pad($this->_z, 3, " ", STR_PAD_LEFT); 
			$space_h = str_pad($this->_w, 3, " ", STR_PAD_LEFT);
			return ("Vertex( x: ".$space_r.", y: ".$space_g.", z: ".$space_b.", w: ".$space_h.", ".$this->_color." )constructed."."\n");
		}
	}

	private function setX($value){
		$this->_x = floatval($value);
	}

	private function setY($value){
		$this->_y = floatval($value);
	}

	private function setZ($value){
		$this->_z = floatval($value);
	}

	private function setW($value){
		$this->_w = floatval($value);
	}

	private function setColor($value){
		$this->_color = $value;
	}

	public function getX(){
		return ($this->_x);
	}

	public function getY(){
		return ($this->_y);
	}

	public function getZ(){
		return ($this->_z);
	}

	public function getW(){
		return ($this->_w);
	}

	public function getColor(){
		return ($this->_color);
	}

	public function __destruct(){
		if (self::$verbose === TRUE)
		{
			$space_r = str_pad($this->_x, 3, " ", STR_PAD_LEFT);
			$space_g = str_pad($this->_y, 3, " ", STR_PAD_LEFT);
			$space_b = str_pad($this->_z, 3, " ", STR_PAD_LEFT); 
			$space_h = str_pad($this->_w, 3, " ", STR_PAD_LEFT);
			print("Vertex( x: ".$space_r.", y: ".$space_g.", z: ".$space_b.", w: ".$space_h.", ".$this->_color." ) destructed."."\n");
		}
	}

	public function __toString(){
		$space_r = str_pad($this->_x, 3, " ", STR_PAD_LEFT);
		$space_g = str_pad($this->_y, 3, " ", STR_PAD_LEFT);
		$space_b = str_pad($this->_z, 3, " ", STR_PAD_LEFT); 
		$space_h = str_pad($this->_w, 3, " ", STR_PAD_LEFT);
		if (self::$verbose === TRUE)
			return "Vertex( x: ".$space_r.", y: ".$space_g.", z: ".$space_b.", w: ".$space_h.", ".$this->_color." )constructed.";
		else
			return "Vertex( x: ".$space_r.", y: ".$space_g.", z: ".$space_b.", w: ".$space_h." )";
	}
}
?>
