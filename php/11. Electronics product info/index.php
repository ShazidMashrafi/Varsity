<?php
session_start();
include 'config.php';

$sql = "SELECT * FROM electronics_products";
$result = mysqli_query($conn, $sql);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Electronics Product List</title>
</head>
<body>
    <h2>Electronics Product List</h2>
    
    <?php if (isset($_SESSION['success'])): ?>
        <p style="color: green;">Electronics product added successfully.</p>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?>
    
    <a href="form.php">Add New Electronics Product</a>
    <br><br>
    
    <table border="1">
        <tr>
            <th>Product ID</th>
            <th>Name</th>
            <th>Description</th>
            <th>Price</th>
            <th>Quantity</th>
            <th>Manufacturer</th>
            <!-- Removed Warranty and Power columns -->
        </tr>
        <?php
        while($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $row['productId'] . "</td>";
            echo "<td>" . $row['productName'] . "</td>";
            echo "<td>" . $row['description'] . "</td>";
            echo "<td>BDT: " . $row['price'] . "</td>";
            echo "<td>" . $row['quantity'] . "</td>";
            echo "<td>" . $row['manufacturer'] . "</td>";
            // Removed Warranty and Power columns
            echo "</tr>";
        }
        ?>
    </table>
</body>
</html>
<?php
mysqli_close($conn);
?>
