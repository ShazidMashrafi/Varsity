<?php
session_start();
include 'config.php';

extract($_POST);

$sql = "SELECT * FROM personal_profile";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    $sql = "UPDATE personal_profile SET 
            fullName = '$fullName',
            email = '$email',
            phone = '$phone',
            university = '$university',
            degree = '$degree',
            department = '$department',
            session = '$session',
            address = '$address'
            WHERE id = 1";
} else {
    $sql = "INSERT INTO personal_profile 
            (fullName, email, phone, university, degree, department, session, address) 
            VALUES 
            ('$fullName', '$email', '$phone', '$university', '$degree', '$department', '$session', '$address')";
}

if (mysqli_query($conn, $sql)) {
    header("Location: index.php");
} else {
    echo "Error: " . mysqli_error($conn);
    echo "<br><a href='form.php'>Go back</a>";
}

mysqli_close($conn);
?>