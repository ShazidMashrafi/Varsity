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

$sql = "CREATE TABLE IF NOT EXISTS students (
    id INT(6) AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    fathers_name VARCHAR(100) NOT NULL,
    mothers_name VARCHAR(100) NOT NULL,
    gender VARCHAR(10) NOT NULL,
    address TEXT NOT NULL,
    dob DATE NOT NULL,
    roll VARCHAR(50) NOT NULL,
    reg VARCHAR(50) NOT NULL,
    session VARCHAR(50) NOT NULL,
    department_name VARCHAR(100) NOT NULL,
    faculty_name VARCHAR(100) NOT NULL,
    university_name VARCHAR(100) NOT NULL
)";

if (!mysqli_query($conn, $sql)) {
    die("Error creating table: " . mysqli_error($conn));
}
?>