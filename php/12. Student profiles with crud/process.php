<?php
session_start();
include 'config.php';

extract($_POST);

if (isset($_POST['id']) && $_POST['id'] !== '') {
    $id = intval($_POST['id']);
    $sql = "UPDATE students_crud SET name='$name', fathers_name='$fathers_name', mothers_name='$mothers_name', gender='$gender', address='$address', dob='$dob', roll='$roll', reg='$reg', session='$session', department_name='$department_name', faculty_name='$faculty_name', university_name='$university_name' WHERE id=$id";
    if (mysqli_query($conn, $sql)) {
        $_SESSION['success'] = "Student updated successfully.";
    } else {
        $_SESSION['error'] = "Error updating student: " . mysqli_error($conn);
    }
} else {
    $sql = "INSERT INTO students_crud (name, fathers_name, mothers_name, gender, address, dob, roll, reg, session, department_name, faculty_name, university_name) VALUES ('$name', '$fathers_name', '$mothers_name', '$gender', '$address', '$dob', '$roll', '$reg', '$session', '$department_name', '$faculty_name', '$university_name')";
    if (mysqli_query($conn, $sql)) {
        $_SESSION['success'] = "Student added successfully.";
    } else {
        $_SESSION['error'] = "Error adding student: " . mysqli_error($conn);
    }
}

header('Location: index.php');
mysqli_close($conn);
exit;
