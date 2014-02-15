<?php

$host="localhost"; // Host name 
$username="root"; // Mysql username 
$password=""; // Mysql password 
$db_name="iAnon"; // Database name 
$tbl_name="user"; // Table name 
// Connect to server and select databse.
mysql_connect("$host", "$username", "$password")or die("cannot connect"); 
mysql_select_db("$db_name")or die("cannot select DB");

// username and password sent from form 
$myusername=$_POST['myusername']; 
$mypassword=$_POST['mypassword']; 
$myemail=$_POST['myemail'];
$mybd=$_POST['mybd'];
$mygender = $_GET["mygender"];

$myfirstname=$_POST['myfirstname'];
$mylastname=$_POST['mylastname'];









// To protect MySQL injection (more detail about MySQL injection)
$myusername = stripslashes($myusername);
$mypassword = stripslashes($mypassword);
$myusername = mysql_real_escape_string($myusername);
$mypassword = mysql_real_escape_string($mypassword);

$myfirstname = stripslashes($myfirstname);
$mylastname = stripslashes($mylastname);
$myfirstname = mysql_real_escape_string($myfirstname);
$mylastname = mysql_real_escape_string($mylastname);

$myemail = stripslashes($myemail);
$mygender = stripslashes($mygender);
$myemail = mysql_real_escape_string($myemail);
$mygender = mysql_real_escape_string($mygender);



$sql="INSERT INTO user (id,firstname, lastname, username,email,pw,birth) VALUES (NULL,'$myfirstname', '$mylastname','$myusername', '$myemail','$mypassword','$mybd')";

mysql_query($sql) or die(mysql_error());



// Mysql_num_row is counting table row


// If result matched $myusername and $mypassword, table row must be 1 row


// Register $myusername, $mypassword and redirect to file "login_success.php"
session_register("myusername");
session_register("mypassword"); 
session_register("myfirstname");


header("location:home.php");

?>









