<?php
session_start();
$form_data = isset($_SESSION['form_data']) ? $_SESSION['form_data'] : [];
unset($_SESSION['form_data']);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Add Electronics Product</title>
    <style>
        .error { color: red; }
    </style>
</head>
<body>
    <h2>Add New Electronics Product</h2>
    <form action="process.php" method="post">
        <label for="productName">Product Name:</label>
        <input type="text" id="productName" name="productName" value="<?php echo $form_data['productName'] ?? ''; ?>">
        <br><br>
        
        <label for="productId">Product ID:</label>
        <input type="text" id="productId" name="productId" value="<?php echo $form_data['productId'] ?? ''; ?>">
        <br><br>
        
        <label for="description">Description:</label>
        <textarea id="description" name="description"><?php echo $form_data['description'] ?? ''; ?></textarea>
        <br><br>
        
        <label for="price">Price:</label>
        <input type="number" id="price" name="price" step="0.1" value="<?php echo $form_data['price'] ?? ''; ?>">
        <br><br>
        
        <label for="quantity">Stock Quantity:</label>
        <input type="number" id="quantity" name="quantity" value="<?php echo $form_data['quantity'] ?? ''; ?>">
        <br><br>
        
        <label for="manufacturer">Manufacturer:</label>
        <input type="text" id="manufacturer" name="manufacturer" value="<?php echo $form_data['manufacturer'] ?? ''; ?>">
        <br><br>
        
        <input type="submit" value="Add Product">
        <a href="index.php"><button type="button">Cancel</button></a>
    </form>
</body>
</html>
