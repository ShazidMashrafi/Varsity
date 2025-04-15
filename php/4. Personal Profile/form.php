<?php
include 'config.php';

$sql = "SELECT * FROM personal_profile LIMIT 1";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    $profile = mysqli_fetch_assoc($result);
} else {
    $profile = [];
}

mysqli_close($conn);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Personal Profile Form</title>
</head>
<body>
    <h2><?php echo !empty($profile) ? 'Edit' : 'Create'; ?> Your Profile</h2>
    <form action="process.php" method="post">
        <label for="fullName">Full Name:</label>
        <input type="text" id="fullName" name="fullName" value="<?php echo isset($profile['fullName']) ? $profile['fullName'] : ''; ?>" required>
        <br><br>
        
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" value="<?php echo isset($profile['email']) ? $profile['email'] : ''; ?>" required>
        <br><br>
        
        <label for="phone">Phone:</label>
        <input type="text" id="phone" name="phone" value="<?php echo isset($profile['phone']) ? $profile['phone'] : ''; ?>" required>
        <br><br>
        
        <label for="age">Age:</label>
        <input type="number" id="age" name="age" value="<?php echo isset($profile['age']) ? $profile['age'] : ''; ?>" required>
        <br><br>
        
        <label for="university">University:</label>
        <input type="text" id="university" name="university" value="<?php echo isset($profile['university']) ? $profile['university'] : ''; ?>" required>
        <br><br>
        
        <label for="degree">Degree:</label>
        <input type="text" id="degree" name="degree" value="<?php echo isset($profile['degree']) ? $profile['degree'] : ''; ?>" required>
        <br><br>
        
        <label for="department">Department:</label>
        <input type="text" id="department" name="department" value="<?php echo isset($profile['department']) ? $profile['department'] : ''; ?>" required>
        <br><br>
        
        <label for="session">Session:</label>
        <input type="text" id="session" name="session" value="<?php echo isset($profile['session']) ? $profile['session'] : ''; ?>" required>
        <br><br>
        
        <label for="address">Address:</label>
        <textarea id="address" name="address" required><?php echo isset($profile['address']) ? $profile['address'] : ''; ?></textarea>
        <br><br>
        
        <input type="submit" value="Save Profile">
        <a href="index.php"><button type="button">Cancel</button></a>
    </form>
</body>
</html>