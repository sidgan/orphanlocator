<pre>
<?php 
$first_name="";
$last_name="";
$year_birth="";
$year_missing="";
$gender="";
$height="";
$location="";
$additional_information="";
 
if(isset($_REQUEST['first_name']))
{
  $first_name= trim($_REQUEST['first_name']);
   
 }
 if(isset($_REQUEST['last_name']))
 {
   $last_name= trim($_REQUEST['last_name']);
 }
 if(isset($_REQUEST['year_birth']))
 {
   $year_birth= trim($_REQUEST['year_birth']);
 }
 if(isset($_REQUEST['year_missing']))
 {
   $year_missing= trim($_REQUEST['year_missing']);
 }
 if(isset($_REQUEST['gender']))
 {
   $gender= trim($_REQUEST['gender']);
 }
 if(isset($_REQUEST['height']))
{
  $height= trim($_REQUEST['height']);
}
if(isset($_REQUEST['location']))
{
  $location= trim($_REQUEST['location']);
}
if(isset($_REQUEST['additional_information']))
{
  $additional_information= trim($_REQUEST['additional_information']);
}
  

echo $first_name."\n";
echo $last_name."\n";
echo $year_birth."\n";
echo $year_missing."\n";
echo $gender."\n";
echo $height."\n";
echo $location."\n";
echo $additional_information."\n";

?>
</pre>
