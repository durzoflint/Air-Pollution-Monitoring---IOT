<?php 
    $connect = mysqli_connect('localhost','onedirect_admin','onedirect_pass','onedirect_flightsystem');
    if(!$connect)
    {
        echo "Error while connecting to Database.".mysqli_errno($connect) ;
    }
    $db=mysqli_select_db($connect, 'onedirect_flightsystem');
?>