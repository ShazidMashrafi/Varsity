<?php
session_start();
include 'config.php';
$msg = '';
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username']);
    $password = $_POST['password'];
    $sql = "SELECT * FROM users WHERE username='" . mysqli_real_escape_string($conn, $username) . "'";
    $result = mysqli_query($conn, $sql);
    if ($row = mysqli_fetch_assoc($result)) {
        if (password_verify($password, $row['password'])) {
            $_SESSION['user'] = [
                'id' => $row['id'],
                'username' => $row['username'],
                'name' => $row['name']
            ];
            header('Location: index.php');
            exit;
        } else {
            $msg = 'Invalid password!';
        }
    } else {
        $msg = 'User not found!';
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>User Login</title>
</head>
<body>
    <h2>User Login</h2>
    <?php if ($msg) echo '<p>' . $msg . '</p>'; ?>
    <form method="post">
        <label>Username:</label><br>
        <input type="text" name="username" required><br><br>
        <label>Password:</label><br>
        <input type="password" name="password" required><br><br>
        <input type="submit" value="Login">
    </form>
    <p>Don't have an account? <a href="register.php">Register here</a></p>
</body>
</html>
<?php mysqli_close($conn); ?>
