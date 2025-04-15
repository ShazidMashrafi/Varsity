<?php
session_start();
include 'config.php';

$sql = "SELECT * FROM products";
$result = mysqli_query($conn, $sql);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Product List</title>
</head>
<body>
    <h2>Product List</h2>
    
    <?php if (isset($_SESSION['success'])): ?>
        <p style="color: green;"><?php echo $_SESSION['success']; ?></p>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?>
    
    <a href="form.php">Add New Product</a>
    <br><br>
    
    <table border="1">
        <tr>
            <th>Product ID</th>
            <th>Name</th>
            <th>Description</th>
            <th>Price</th>
            <th>Quantity</th>
            <th>Manufacturer</th>
            <th>Category</th>
        </tr>
        <?php
        if (mysqli_num_rows($result) > 0) {
            while($row = mysqli_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>" . $row['productId'] . "</td>";
                echo "<td>" . $row['productName'] . "</td>";
                echo "<td>" . $row['description'] . "</td>";
                echo "<td>BDT: " . $row['price'] . "</td>";
                echo "<td>" . $row['quantity'] . "</td>";
                echo "<td>" . $row['manufacturer'] . "</td>";
                echo "<td>" . $row['category'] . "</td>";
                echo "</tr>";
            }
        } else {
            echo "<tr><td colspan='7'>No products found</td></tr>";
        }
        ?>
    </table>
</body>
</html>
<?php
mysqli_close($conn);
?>