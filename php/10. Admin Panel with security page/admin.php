
<?php
session_start();
include 'config.php';

// Handle logout
if (isset($_GET['logout'])) {
    session_destroy();
    header('Location: admin.php');
    exit;
}

$error = '';
// Handle login
if (isset($_POST['login'])) {
    $user = mysqli_real_escape_string($conn, $_POST['username']);
    $pass = $_POST['password'];
    $result = mysqli_query($conn, "SELECT * FROM admin WHERE username='$user'");
    if ($row = mysqli_fetch_assoc($result)) {
        if (password_verify($pass, $row['password'])) {
            $_SESSION['admin_logged_in'] = true;
            $_SESSION['admin_username'] = $user;
        } else {
            $error = 'Invalid password!';
        }
    } else {
        $error = 'Invalid username!';
    }
}

$logged_in = isset($_SESSION['admin_logged_in']) && $_SESSION['admin_logged_in'];
?>
<!DOCTYPE html>
<html>
<head>
    <title>Admin Panel Demo</title>
    <style>
        .error { color: red; }
    </style>
</head>
<body>
    <div class="panel">
        <?php if ($logged_in): ?>
            <div class="logout">
                <a href="admin.php?logout=1" class="btn">Logout</a>
            </div>
            <h2>Logged in as admin</h2>
            <p>This is the protected admin panel demo page.</p>
        <?php else: ?>
            <h2>Admin Login</h2>
            <?php if ($error): ?><div class="error"><?php echo $error; ?></div><?php endif; ?>
            <form method="post">
                <label for="username">Username:</label><br>
                <input type="text" id="username" name="username" required><br><br>
                <label for="password">Password:</label><br>
                <input type="password" id="password" name="password" required><br><br>
                <input type="submit" name="login" value="Login" class="btn">
            </form>
            <p><b>Demo credentials:</b> admin / admin123</p>
        <?php endif; ?>
    </div>
</body>
</html>
<?php mysqli_close($conn); ?>
