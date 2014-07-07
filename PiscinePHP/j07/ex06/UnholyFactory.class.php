<?php
Class UnholyFactory{
	public static $verif1 = 0;
	public static $verif2 = 0;
	public static $verif3 = 0;

	public function absorb($obj){
		if ($obj->type == "foot soldier"){
			if ($this->verif1 == 0){
				print ("(Factory absorbed a fighter of type foot soldier)\n");
				$this->verif1 = 1;
			}
			else{
				print ("(Factory already absorbed a fighter of type foot soldier)\n");
			}

		}
		elseif ($obj->type == "archer"){
			if ($this->verif2 == 0){
				print ("(Factory absorbed a fighter of type foot soldier)\n");
				$this->verif2 = 1;
			}
			else{
				print ("(Factory already absorbed a fighter of type foot soldier)\n");
			}

		}
		elseif ($obj->type == "assassin"){
			if ($this->verif3 == 0){
				print ("(Factory absorbed a fighter of type foot soldier)\n");
				$this->verif3 = 1;
			}
			else{
				print ("(Factory already absorbed a fighter of type foot soldier)\n");
			}

		}
		else{
			print ("(Factory can't absorb this, it's not a fighter)\n");
		}

	}

	public function check_str($str){
		if ($str != "foot soldier" AND $str != "archer" AND $str != "assassin")
			return 0;
		else
			return 1;
	}

	public function fabricate($str){
		if (!$this->check_str($str))
			print("(Factory hasn't absorbed any fighter of type ".$str.")\n");
		else{
			print("(Factory fabricates a fighter of type ".$str.")\n");
			if ($str == "foot soldier")
				return (new Footsoldier);
			if ($str == "archer")
				return (new Archer);
			if ($str == "assassin")
				return (new Assassin);
		}
	}
}
?>
