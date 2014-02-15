<?php
header('Content-Type: application/json ; charset=utf-8');

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
  

$output=array();
$output[0]["first_name"]="Anirudh";
$output[0]["last_name"]="Koul";
$output[0]["year_birth"]="1985";
$output[0]["year_missing"]="1999";
$output[0]["gender"]="m";
$output[0]["height"]="";
$output[0]["location"]="New Delhi, India";
$output[0]["additional_information"]="Brown Eyes";
$output[0]["photo_url"]="http://m.c.lnkd.licdn.com/media/p/1/000/00d/0a9/1581aed.jpg";
$output[0]["match_probability"]="0.8";
$output[1]["first_name"]="Happy";
$output[1]["last_name"]="Joe";
$output[1]["year_birth"]="1993";
$output[1]["year_missing"]="2001";
$output[1]["gender"]="f";
$output[1]["height"]="";
$output[1]["location"]="abu dhabi";
$output[1]["additional_information"]="";
$output[1]["photo_url"]="http://m.c.lnkd.licdn.com/mpr/mpr/shrink_200_200/p/3/000/2a1/0c6/2a46767.jpg";
$output[1]["match_probability"]="0.5";
$json_output=json_encode($output);
echo $json_output;
?>
