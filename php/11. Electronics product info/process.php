<?php
session_start();
include 'config.php';

extract($_POST);

$sql = "INSERT INTO electronics_products (productId, productName, description, price, quantity, manufacturer) 
        VALUES ('$productId', '$productName', '$description', '$price', '$quantity', '$manufacturer')";

if (mysqli_query($conn, $sql)) {
    $_SESSION['success'] = "Electronics product added successfully";
    header("Location: index.php");
} else {
    echo "Error: " . mysqli_error($conn);
    echo "<br><a href='form.php'>Go back</a>";
}

mysqli_close($conn);
?>
