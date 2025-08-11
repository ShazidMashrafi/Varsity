<?php
include 'config.php';
$msg = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_FILES['image']) && isset($_POST['title'])) {
    $title = $_POST['title'];
    $file = $_FILES['image'];
    $newname = uniqid('img_', true) . '_' . $file['name'];
    $target = __DIR__ . '/uploads/' . $newname;
    if (move_uploaded_file($file['tmp_name'], $target)) {
        $sql = "INSERT INTO gallery_images (title, filename) VALUES ('$title', '$newname')";
        if (mysqli_query($conn, $sql)) {
            $msg = 'Image uploaded!';
        } else {
            $msg = 'DB error: ' . mysqli_error($conn);
        }
    } else {
        $msg = 'Upload failed.';
    }
}

session_start();
$_SESSION['upload_msg'] = $msg;
header('Location: index.php');
exit;
