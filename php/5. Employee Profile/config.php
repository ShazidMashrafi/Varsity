<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "cse_308";

$conn = mysqli_connect($servername, $username, $password);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$sql = "CREATE DATABASE IF NOT EXISTS $dbname";
if (!mysqli_query($conn, $sql)) {
    die("Error creating database: " . mysqli_error($conn));
}

mysqli_select_db($conn, $dbname);

$sql = "CREATE TABLE IF NOT EXISTS employees (
    id VARCHAR(50) PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    fathersName VARCHAR(100) NOT NULL,
    mothersName VARCHAR(100) NOT NULL,
    gender VARCHAR(10) NOT NULL,
    department VARCHAR(50) NOT NULL,
    number VARCHAR(20) NOT NULL,
    NIDnumber VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL,
    join_date DATE NOT NULL,
    address TEXT NOT NULL
)";

if (!mysqli_query($conn, $sql)) {
    die("Error creating table: " . mysqli_error($conn));
}
?>
