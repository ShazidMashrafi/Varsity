<?php
session_start();
include 'config.php';

$error = '';
if (isset($_POST['login'])) {
    $user = mysqli_real_escape_string($conn, $_POST['username']);
    $pass = $_POST['password'];
    $result = mysqli_query($conn, "SELECT * FROM admin WHERE username='$user'");
    if ($row = mysqli_fetch_assoc($result)) {
        if (password_verify($pass, $row['password'])) {
            $_SESSION['admin_logged_in'] = true;
            $_SESSION['admin_username'] = $user;
            header('Location: admin.php');
            exit;
        } else {
            $error = 'Invalid password!';
        }
    } else {
        $error = 'Invalid username!';
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Admin Login</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 40px; }
        .panel { border: 1px solid #ccc; padding: 20px; max-width: 400px; margin: auto; }
        .error { color: red; }
    </style>
</head>
<body>
    <div class="panel">
        <h2>Admin Login</h2>
        <?php if ($error): ?><div class="error"><?php echo $error; ?></div><?php endif; ?>
        <form method="post">
            <label for="username">Username:</label><br>
            <input type="text" id="username" name="username" required><br><br>
            <label for="password">Password:</label><br>
            <input type="password" id="password" name="password" required><br><br>
            <input type="submit" name="login" value="Login">
        </form>
        <p><b>Demo credentials:</b> admin / admin123</p>
    </div>
</body>
</html>
<?php mysqli_close($conn); ?>
