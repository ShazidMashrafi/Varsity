<?php
session_start();
include 'config.php';

if (isset($_GET['id'])) {
    $id = intval($_GET['id']);
    $sql = "DELETE FROM students_crud WHERE id=$id";
    if (mysqli_query($conn, $sql)) {
        $_SESSION['success'] = "Student deleted successfully.";
    } else {
        $_SESSION['error'] = "Error deleting student: " . mysqli_error($conn);
    }
}

header('Location: index.php');
mysqli_close($conn);
exit;
