<html>
<head>

<script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script>
$.getJSON("fakeData.php?firstName=<?= $_POST[first_name]?>",function(data){
alert(data)

});

</script>
</head>
</html>