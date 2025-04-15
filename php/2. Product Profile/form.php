<?php
session_start();
$form_data = isset($_SESSION['form_data']) ? $_SESSION['form_data'] : [];
unset($_SESSION['form_data']);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Add Product</title>
    <style>
        .error { color: red; }
    </style>
</head>
<body>
    <h2>Add New Product</h2>
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
        <input type="number" id="price" name="price" step="0.01" value="<?php echo $form_data['price'] ?? ''; ?>">
        <br><br>
        
        <label for="quantity">Stock Quantity:</label>
        <input type="number" id="quantity" name="quantity" value="<?php echo $form_data['quantity'] ?? ''; ?>">
        <br><br>
        
        <label for="manufacturer">Manufacturer:</label>
        <input type="text" id="manufacturer" name="manufacturer" value="<?php echo $form_data['manufacturer'] ?? ''; ?>">
        <br><br>
        
        <label for="category">Category:</label>
        <select id="category" name="category">
            <option value="">Select a category</option>
            <option value="electronics" <?php if(($form_data['category'] ?? '') == 'electronics') echo 'selected'; ?>>Electronics</option>
            <option value="clothing" <?php if(($form_data['category'] ?? '') == 'clothing') echo 'selected'; ?>>Clothing</option>
            <option value="books" <?php if(($form_data['category'] ?? '') == 'books') echo 'selected'; ?>>Books</option>
            <option value="furniture" <?php if(($form_data['category'] ?? '') == 'furniture') echo 'selected'; ?>>Furniture</option>
        </select>
        <br><br>
        
        <input type="submit" value="Add Product">
        <a href="index.php"><button type="button">Cancel</button></a>
    </form>
</body>
</html>