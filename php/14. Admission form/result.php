<?php
session_start();
if (!isset($_SESSION['admission_data'])) {
    header('Location: index.php');
    exit;
}
$data = $_SESSION['admission_data'];
unset($_SESSION['admission_data']);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Admission Result</title>
</head>
<body>
    <h2>Admission Application Submitted</h2>
    <table border="1" cellpadding="8">
        <tr><th>Name</th><td><?php echo $data['name']; ?></td></tr>
        <tr><th>Email</th><td><?php echo $data['email']; ?></td></tr>
        <tr><th>Phone</th><td><?php echo $data['phone']; ?></td></tr>
        <tr><th>Date of Birth</th><td><?php echo $data['dob']; ?></td></tr>
        <tr><th>SSC Result</th><td><?php echo $data['ssc']; ?></td></tr>
        <tr><th>HSC Result</th><td><?php echo $data['hsc']; ?></td></tr>
    </table>
    <br>
    <a href="index.php">Apply Again</a>
</body>
</html>
