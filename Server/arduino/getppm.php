<?php
	include 'connect.php';
	
	$sql = "SELECT * FROM arduino";
	$result = mysqli_query($connect, $sql);
	while ($row = mysqli_fetch_array($result))
	{
		echo $row['ppm'];
	}
?>