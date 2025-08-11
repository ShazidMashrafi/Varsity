<?php
session_start();
if (isset($_POST['logout'])) {
	session_destroy();
	header('Location: index.php');
	exit;
}
?>
<!DOCTYPE html>
<html>
<head>
	<title>Welcome</title>
</head>
<body>
	<h2>Welcome to the User System</h2>
	<?php if (isset($_SESSION['user'])): ?>
		<p>Hello, <b><?php echo $_SESSION['user']['name']; ?></b>! You are logged in.</p>
		<form method="post">
			<input type="submit" name="logout" value="Logout">
		</form>
	<?php else: ?>
		<p>You are not logged in.</p>
		<a href="login.php">Login</a> | <a href="register.php">Register</a>
	<?php endif; ?>
</body>
</html>
