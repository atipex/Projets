<?php
Class Jaime{
	public function sleepWith($obj){
	   	$fuck_with = get_class($obj);
	 	if ($fuck_with == "Tyrion")
	 		print("Not even if I'm drunk !\n");
	 	elseif ($fuck_with == "Cersei")
			print("With pleasure, but only in a tower in Winterfell, then.\n");
		else
		print("Let's do this.\n");
	}
}
?>