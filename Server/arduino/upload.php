<?php
	include 'connect.php';
	$ppm = $_GET['ppm'];
	
	$sql = "UPDATE `arduino` SET `ppm` = '$ppm' WHERE `id` = '1'";
        $retval = mysqli_query($connect, $sql);
    	if($retval===false)
    		echo "error: " .mysqli_error($connect);
    	else
    		echo "success";
?>