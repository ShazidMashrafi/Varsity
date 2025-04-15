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

$sql = "CREATE TABLE IF NOT EXISTS personal_profile (
    id INT(6) AUTO_INCREMENT PRIMARY KEY,
    fullName VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    phone VARCHAR(20) NOT NULL,
    university VARCHAR(100) NOT NULL,
    degree VARCHAR(100) NOT NULL,
    department VARCHAR(100) NOT NULL,
    session VARCHAR(50) NOT NULL,
    address TEXT NOT NULL
)";

if (!mysqli_query($conn, $sql)) {
    die("Error creating table: " . mysqli_error($conn));
}
?>