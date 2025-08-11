<?php
session_start();

$errors = [];

if (empty($_POST['id'])) {
    $errors['id'] = "ID is required";
} elseif (!preg_match('/^[a-zA-Z0-9]+$/', $_POST['id'])) {
    $errors['id'] = "ID must contain only letters and numbers";
}

if (empty($_POST['name'])) {
    $errors['name'] = "Name is required";
} elseif (!preg_match('/^[a-zA-Z\s]+$/', $_POST['name'])) {
    $errors['name'] = "Name must contain only letters";
}

if (empty($_POST['fathersName'])) {
    $errors['fathersName'] = "Father's name is required";
} elseif (!preg_match('/^[a-zA-Z\s]+$/', $_POST['fathersName'])) {
    $errors['fathersName'] = "Father's name must contain only letters";
}

if (empty($_POST['mothersName'])) {
    $errors['mothersName'] = "Mother's name is required";
} elseif (!preg_match('/^[a-zA-Z\s]+$/', $_POST['mothersName'])) {
    $errors['mothersName'] = "Mother's name must contain only letters";
}

if (empty($_POST['gender'])) {
    $errors['gender'] = "Please select a gender";
}

if (empty($_POST['department'])) {
    $errors['department'] = "Please select a department";
}

if (empty($_POST['number'])) {
    $errors['number'] = "Phone number is required";
} elseif (!preg_match('/^[0-9]{11}$/', $_POST['number'])) {
    $errors['number'] = "Phone number must be 11 digits";
}

if (empty($_POST['NIDnumber'])) {
    $errors['NIDnumber'] = "NID number is required";
} elseif (!preg_match('/^[0-9]{10}$|^[0-9]{13}$|^[0-9]{17}$/', $_POST['NIDnumber'])) {
    $errors['NIDnumber'] = "NID number must be 10, 13, or 17 digits";
}

if (empty($_POST['email'])) {
    $errors['email'] = "Email is required";
} elseif (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
    $errors['email'] = "Please enter a valid email address";
}

if (empty($_POST['join'])) {
    $errors['join'] = "Join date is required";
} else {
    $selectedDate = new DateTime($_POST['join']);
    $today = new DateTime();
    
    if ($selectedDate > $today) {
        $errors['join'] = "Join date cannot be in the future";
    }
}

if (empty($_POST['address'])) {
    $errors['address'] = "Address is required";
} elseif (strlen(trim($_POST['address'])) < 5) {
    $errors['address'] = "Address must be at least 5 characters";
}

if (!empty($errors)) {
    $_SESSION['errors'] = $errors;
    $_SESSION['form_data'] = $_POST;
    header("Location: index.php");
    exit;
}

include 'config.php';

extract($_POST);

$sql = "INSERT INTO employees (id, name, fathersName, mothersName, gender, department, number, NIDnumber, email, join_date, address) 
        VALUES ('$id', '$name', '$fathersName', '$mothersName', '$gender', '$department', '$number', '$NIDnumber', '$email', '$join', '$address')";

if (mysqli_query($conn, $sql)) {
    $_SESSION['success'] = "Employee added successfully";
    header("Location: index.php");
} else {
    $_SESSION['errors']['database'] = "Error: " . mysqli_error($conn);
    $_SESSION['form_data'] = $_POST;
    header("Location: index.php");
}

mysqli_close($conn);
?>