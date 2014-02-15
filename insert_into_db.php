<?php
// Create connection
$con=mysqli_connect("localhost","root","","iAnon");

// Check connection
if (mysqli_connect_errno($con))
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }

//$date = date("Y-m-d","1989-7-21");

mysqli_query($con,"INSERT INTO user (firstName, lastName, username,pw,sex)
VALUES ('Zahra', 'Ashktorab','zashktorab', 'test','F')");




?>