<?php
session_start();
include 'config.php';

extract($_POST);

$sql = "INSERT INTO employees (id, name, fathersName, mothersName, gender, department, number, NIDnumber, email, join_date, address) 
        VALUES ('$id', '$name', '$fathersName', '$mothersName', '$gender', '$department', '$number', '$NIDnumber', '$email', '$join', '$address')";

if (mysqli_query($conn, $sql)) {
    $_SESSION['success'] = "Employee added successfully";
    header("Location: index.php");
} else {
    echo "Error: " . mysqli_error($conn);
    echo "<br><a href='form.php'>Go back</a>";
}

mysqli_close($conn);
?>