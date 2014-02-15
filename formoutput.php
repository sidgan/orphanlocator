<html>
<head>

<script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script>
$.getJSON("fakeData.php?firstName=<?= $_POST[first_name]?>",function(data){
alert(JSON.stringify(data));
console.log(data);

});

</script>
</head>
</html>
