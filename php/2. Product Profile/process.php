<?php
session_start();
include 'config.php';

extract($_POST);

$sql = "INSERT INTO products (productId, productName, description, price, quantity, manufacturer, category) 
        VALUES ('$productId', '$productName', '$description', '$price', '$quantity', '$manufacturer', '$category')";

if (mysqli_query($conn, $sql)) {
    $_SESSION['success'] = "Product added successfully";
    header("Location: index.php");
} else {
    echo "Error: " . mysqli_error($conn);
    echo "<br><a href='form.php'>Go back</a>";
}

mysqli_close($conn);
?>