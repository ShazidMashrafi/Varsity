<?php
session_start();
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
	$_SESSION['admission_data'] = [
		'name' => $_POST['name'] ?? '',
		'email' => $_POST['email'] ?? '',
		'phone' => $_POST['phone'] ?? '',
		'dob' => $_POST['dob'] ?? '',
		'ssc' => $_POST['ssc'] ?? '',
		'hsc' => $_POST['hsc'] ?? '',
	];
	header('Location: result.php');
	exit;
}
?>
<!DOCTYPE html>
<html>
<head>
	<title>Graduation Admission Form</title>
</head>
<body>
	<h2>Graduation Admission Form</h2>
	<form method="post">
		<label>Name:</label><br>
		<input type="text" name="name" required><br><br>
		<label>Email:</label><br>
		<input type="email" name="email" required><br><br>
		<label>Phone:</label><br>
		<input type="text" name="phone" required><br><br>
		<label>Date of Birth:</label><br>
		<input type="date" name="dob" required><br><br>
		<label>SSC Result:</label><br>
		<input type="text" name="ssc" required><br><br>
		<label>HSC Result:</label><br>
		<input type="text" name="hsc" required><br><br>
		<input type="submit" value="Apply">
	</form>
</body>
</html>
