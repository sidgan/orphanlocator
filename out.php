<html>
<head>

<script type='text/javascript' src='//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js'></script>
<script>
$.getJSON('fakeData.php?first_name=<?=$_POST[first_name]?>&last_name=<?= $_POST[last_name]?>&year_birth=<?= $_POST[year_birth]?>&year_missing=<?= $_POST[year_missing]?>&gender=<?= $_POST[gender]?>&height=<?= $_POST[height]?>&location=<?= $_POST[location]?>&additional_information=<?= $_POST[additional_information] ?>',function(data){
$.ajax({
    type: 'POST',
    url: 'show_results.php',
    data: {'myData': data}})

});

</script>
</head>
</html>

