<?php
session_start();
include 'config.php';

$errors = [];

if (empty($_POST['name'])) {
    $errors['name'] = "Name is required";
}
if (empty($_POST['fathers_name'])) {
    $errors['fathers_name'] = "Father's name is required";
}
if (empty($_POST['mothers_name'])) {
    $errors['mothers_name'] = "Mother's name is required";
}
if (empty($_POST['gender'])) {
    $errors['gender'] = "Gender is required";
}
if (empty($_POST['address'])) {
    $errors['address'] = "Address is required";
}
if (empty($_POST['dob'])) {
    $errors['dob'] = "Date of Birth is required";
}
if (empty($_POST['roll'])) {
    $errors['roll'] = "Roll Number is required";
}
if (empty($_POST['reg'])) {
    $errors['reg'] = "Registration number is required";
}
if (empty($_POST['session'])) {
    $errors['session'] = "Session is required";
}
if (empty($_POST['department_name'])) {
    $errors['department_name'] = "Department name is required";
}
if (empty($_POST['faculty_name'])) {
    $errors['faculty_name'] = "Faculty name is required";
}
if (empty($_POST['university_name'])) {
    $errors['university_name'] = "University name is required";
}

if (!empty($errors)) {
    $_SESSION['errors'] = $errors;
    $_SESSION['form_data'] = $_POST;
    header("Location: index.php");
    exit;
}

extract($_POST);

$sql = "INSERT INTO students (name, fathers_name, mothers_name, gender, address, dob, roll, reg, session, department_name, faculty_name, university_name)
        VALUES ('$name', '$fathers_name', '$mothers_name', '$gender', '$address', '$dob', '$roll', '$reg', '$session', '$department_name', '$faculty_name', '$university_name')";

if (mysqli_query($conn, $sql)) {
    $_SESSION['student_id'] = mysqli_insert_id($conn);
    header("Location: result.php");
} else {
    echo "Error: " . mysqli_error($conn);
    echo "<br><a href='index.php'>Go back</a>";
}

mysqli_close($conn);
?>