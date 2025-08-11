<?php
session_start();
include 'config.php';

extract($_POST);

if (isset($_POST['id']) && $_POST['id'] !== '') {
    $id = intval($_POST['id']);
    $sql = "UPDATE students_crud SET name='$name', gender='$gender', roll='$roll', department_name='$department_name' WHERE id=$id";
    if (mysqli_query($conn, $sql)) {
        $_SESSION['success'] = "Student updated successfully.";
    } else {
        $_SESSION['error'] = "Error updating student: " . mysqli_error($conn);
    }
} else {
    $sql = "INSERT INTO students_crud (name, gender, roll, department_name) VALUES ('$name', '$gender', '$roll', '$department_name')";
    if (mysqli_query($conn, $sql)) {
        $_SESSION['success'] = "Student added successfully.";
    } else {
        $_SESSION['error'] = "Error adding student: " . mysqli_error($conn);
    }
}

header('Location: index.php');
mysqli_close($conn);
exit;
