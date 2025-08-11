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
mysqli_query($conn, $sql);
mysqli_select_db($conn, $dbname);

$sql = "CREATE TABLE IF NOT EXISTS admin (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL
)";
mysqli_query($conn, $sql);

$admin_username = 'admin';
$admin_password = password_hash('admin123', PASSWORD_DEFAULT);
$check = mysqli_query($conn, "SELECT * FROM admin WHERE username='$admin_username'");
if (mysqli_num_rows($check) == 0) {
    mysqli_query($conn, "INSERT INTO admin (username, password) VALUES ('$admin_username', '$admin_password')");
}
