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

$sql = "CREATE TABLE IF NOT EXISTS teacher (
    id INT(6) AUTO_INCREMENT PRIMARY KEY,
    teacherId VARCHAR(30) NOT NULL UNIQUE,
    teacherName VARCHAR(50) NOT NULL,
    department VARCHAR(50) NOT NULL,
    email VARCHAR(50) NOT NULL,
    phone VARCHAR(30) NOT NULL,
    image VARCHAR(255)
)";

if (!mysqli_query($conn, $sql)) {
    die("Error creating table: " . mysqli_error($conn));
}
?>