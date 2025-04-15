<?php
session_start();
include 'config.php';

$sql = "SELECT * FROM personal_profile LIMIT 1";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    $profile = mysqli_fetch_assoc($result);
    $profile_exists = true;
} else {
    $profile_exists = false;
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Personal Profile</title>
</head>
<body>
    <h2>Personal Profile</h2>
    
    <?php if ($profile_exists): ?>
        <p><strong>Full Name:</strong> <?php echo $profile['fullName']; ?></p>
        <p><strong>Email:</strong> <?php echo $profile['email']; ?></p>
        <p><strong>Phone:</strong> <?php echo $profile['phone']; ?></p>
        <p><strong>Age:</strong> <?php echo $profile['age']; ?></p>
        <p><strong>University:</strong> <?php echo $profile['university']; ?></p>
        <p><strong>Degree:</strong> <?php echo $profile['degree']; ?></p>
        <p><strong>Department:</strong> <?php echo $profile['department']; ?></p>
        <p><strong>Session:</strong> <?php echo $profile['session']; ?></p>
        <p><strong>Address:</strong> <?php echo $profile['address']; ?></p>
    <?php else: ?>
        <p>No profile information available.</p>
    <?php endif; ?>
    
    <br>
    <a href="form.php"><button>
        <?php echo $profile_exists ? 'Edit Profile' : 'Create Profile'; ?>
    </button></a>
</body>
</html>
<?php
mysqli_close($conn);
?>