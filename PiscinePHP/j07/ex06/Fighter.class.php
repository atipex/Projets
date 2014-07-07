<?php
abstract Class Fighter{
    public    $type;

    abstract public function fight($target);

    public function __construct($var){
        $this->type = $var;
      }
}
?>
