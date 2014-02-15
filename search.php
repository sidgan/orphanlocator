<?php 
$first_name="";
if(isset($_REQUEST['first_name']))
{
  $first_name= trim($_REQUEST['first_name']);
  
}


echo   $first_name;


?>
