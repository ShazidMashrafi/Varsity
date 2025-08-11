<?php
session_start();
include 'config.php';
$msg = '';
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username']);
    $password = $_POST['password'];
    $email = trim($_POST['email']);
    $name = trim($_POST['name']);
    $contact = trim($_POST['contact']);
    if ($username && $password && $email && $name && $contact) {
        if (strlen($password) < 5) {
            $msg = 'Password must be at least 5 characters.';
        } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $msg = 'Invalid email address.';
        } elseif (!preg_match('/^\d{6,}$/', $contact)) {
            $msg = 'Contact number must be at least 6 digits.';
        } else {
            $password_hash = password_hash($password, PASSWORD_DEFAULT);
            $sql = "INSERT INTO users (username, password, email, name, contact) VALUES ('$username', '$password_hash', '$email', '$name', '$contact')";
            if (mysqli_query($conn, $sql)) {
                $msg = 'Registration successful! <a href="login.php">Login here</a>';
            } else {
                $msg = 'Username already exists or DB error.';
            }
        }
    } else {
        $msg = 'All fields are required.';
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>User Registration</title>
    <script>
    function validateForm() {
        var u = document.forms["regForm"]["username"].value;
        var p = document.forms["regForm"]["password"].value;
        var e = document.forms["regForm"]["email"].value;
        var n = document.forms["regForm"]["name"].value;
        var c = document.forms["regForm"]["contact"].value;
        if (!u || !p || !e || !n || !c) {
            alert("All fields are required.");
            return false;
        }
        if (p.length < 5) {
            alert("Password must be at least 5 characters.");
            return false;
        }
        var emailPattern = /^[^@\s]+@[^@\s]+\.[^@\s]+$/;
        if (!emailPattern.test(e)) {
            alert("Invalid email address.");
            return false;
        }
        return true;
    }
    </script>
</head>
<body>
    <h2>User Registration</h2>
    <?php if ($msg) echo '<p>' . $msg . '</p>'; ?>
    <form name="regForm" method="post" onsubmit="return validateForm();">
        <label>Username:</label><br>
        <input type="text" name="username" required><br><br>
        <label>Password:</label><br>
        <input type="password" name="password" required><br><br>
        <label>Email:</label><br>
        <input type="email" name="email" required><br><br>
        <label>Name:</label><br>
        <input type="text" name="name" required><br><br>
        <label>Contact Number:</label><br>
        <input type="text" name="contact" required><br><br>
        <input type="submit" value="Register">
    </form>
    <p>Already have an account? <a href="login.php">Login here</a></p>
</body>
</html>
<?php mysqli_close($conn); ?>
