<html>
<head>

<script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script>

$.getJSON("http://orphanlocator.hack-day.net/search.php",function(data){ 

alert(JSON.stringify(data));
console.log(data);

});

</script>
</head>
</html>
