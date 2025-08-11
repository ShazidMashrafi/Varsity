<?php

include 'config.php';
session_start();
$msg = '';
if (isset($_SESSION['upload_msg'])) {
    $msg = $_SESSION['upload_msg'];
    unset($_SESSION['upload_msg']);
}

$images = [];
$result = mysqli_query($conn, "SELECT * FROM gallery_images ORDER BY uploaded_at DESC");
if ($result) {
    while ($row = mysqli_fetch_assoc($result)) {
        $images[] = $row;
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Simple Image Gallery</title>
</head>
<body>
    <h2>Image Gallery</h2>
    <?php if ($msg): ?><p><?php echo $msg; ?></p><?php endif; ?>
    <form method="post" enctype="multipart/form-data" action="upload.php">
        <label>Title: <input type="text" name="title" required></label>
        <input type="file" name="image" accept="image/*" required>
        <button type="submit">Upload</button>
    </form>
    <hr>
    <div>
        <?php foreach ($images as $img): ?>
            <div style="display:inline-block;margin:10px;text-align:center;">
                <img src="uploads/<?php echo $img['filename']; ?>" alt="" style="max-width:150px;max-height:150px;display:block;">
                <div><?php echo $img['title']; ?></div>
            </div>
        <?php endforeach; ?>
    </div>
</body>
</html>
<?php if (isset($conn)) mysqli_close($conn); ?>
