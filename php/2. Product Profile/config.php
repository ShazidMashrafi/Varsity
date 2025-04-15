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

$sql = "CREATE TABLE IF NOT EXISTS products (
    id INT(6) AUTO_INCREMENT PRIMARY KEY,
    productId VARCHAR(30) NOT NULL UNIQUE,
    productName VARCHAR(100) NOT NULL,
    description TEXT,
    price DECIMAL(10,2) NOT NULL,
    quantity INT NOT NULL,
    manufacturer VARCHAR(100) NOT NULL,
    category VARCHAR(50) NOT NULL
)";

if (!mysqli_query($conn, $sql)) {
    die("Error creating table: " . mysqli_error($conn));
}
?>