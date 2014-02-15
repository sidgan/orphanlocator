<html>
<head>

<script type='text/javascript' src='//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js'></script>
<script>
$.getJSON('fakeData.php?first_name=<?=$_POST[first_name]?>&last_name=<?= $_POST[last_name]?>&year_birth=<?= $_POST[year_birth]?>&year_missing=<?= $_POST[year_missing]?>&gender=<?= $_POST[gender]?>&height=<?= $_POST[height]?>&location=<?= $_POST[location]?>&additional_information=<?= $_POST[additional_information] ?>',function(data){

var xhr = Ti.Network.createHTTPClient();
xhr.open("POST", "show_results.php");
xhr.setRequestHeader('Content-Type', 'application/json; charset=utf-8');
 
var postData = {
    object: { child1:data}
}
xhr.send(postData);

});

</script>
</head>
</html>

