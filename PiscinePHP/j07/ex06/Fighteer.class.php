<?php
abstract Class Fighter{
 	protected    $type;

    abstract public function fight($target);

    protected function __construct($var){
        $this->type = $var;
      }
}
?>
