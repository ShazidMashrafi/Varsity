<?php
session_start();

$name = $fathers_name = $mothers_name = $gender = $address = $dob = '';
$roll = $reg = $session = $department_name = $faculty_name = $university_name = '';

if (isset($_SESSION['form_data'])) {
    extract($_SESSION['form_data']);
    unset($_SESSION['form_data']);
}

$errors = isset($_SESSION['errors']) ? $_SESSION['errors'] : [];
unset($_SESSION['errors']);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student details</title>
    <style>
        .error { color: red; }
    </style>
</head>
<body>
    <h3>Enter student details</h3>
    <form action="process.php" method="post">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" value="<?php echo $name; ?>">
        <?php if (isset($errors['name'])) echo "<span class='error'>" . $errors['name'] . "</span>"; ?>
        <br><br>
        
        <label for="fathers_name">Father's Name:</label>
        <input type="text" id="fathers_name" name="fathers_name" value="<?php echo $fathers_name; ?>">
        <?php if (isset($errors['fathers_name'])) echo "<span class='error'>" . $errors['fathers_name'] . "</span>"; ?>
        <br><br>

        <label for="mothers_name">Mother's Name:</label>
        <input type="text" id="mothers_name" name="mothers_name" value="<?php echo $mothers_name; ?>">
        <?php if (isset($errors['mothers_name'])) echo "<span class='error'>" . $errors['mothers_name'] . "</span>"; ?>
        <br><br>

        <label>Gender:</label>
        <input type="radio" id="male" name="gender" value="male" <?php if($gender == 'male') echo 'checked'; ?>>
        <label for="male">Male</label>
        <input type="radio" id="female" name="gender" value="female" <?php if($gender == 'female') echo 'checked'; ?>>
        <label for="female">Female</label>
        <?php if (isset($errors['gender'])) echo "<span class='error'>" . $errors['gender'] . "</span>"; ?>
        <br><br>
        
        <label for="address">Address:</label>
        <textarea id="address" name="address"><?php echo $address; ?></textarea>
        <?php if (isset($errors['address'])) echo "<span class='error'>" . $errors['address'] . "</span>"; ?>
        <br><br>
        
        <label for="dob">Date of Birth:</label>
        <input type="date" id="dob" name="dob" value="<?php echo $dob; ?>">
        <?php if (isset($errors['dob'])) echo "<span class='error'>" . $errors['dob'] . "</span>"; ?>
        <br><br>
        
        <label for="roll">Roll Number:</label>
        <input type="text" id="roll" name="roll" value="<?php echo $roll; ?>">
        <?php if (isset($errors['roll'])) echo "<span class='error'>" . $errors['roll'] . "</span>"; ?>
        <br><br>
        
        <label for="reg">Registration number:</label>
        <input type="text" id="reg" name="reg" value="<?php echo $reg; ?>">
        <?php if (isset($errors['reg'])) echo "<span class='error'>" . $errors['reg'] . "</span>"; ?>
        <br><br>
        
        <label for="session">Session:</label>
        <input type="text" id="session" name="session" value="<?php echo $session; ?>">
        <?php if (isset($errors['session'])) echo "<span class='error'>" . $errors['session'] . "</span>"; ?>
        <br><br>

        <label for="department_name">Department name:</label>
        <input type="text" id="department_name" name="department_name" value="<?php echo $department_name; ?>">
        <?php if (isset($errors['department_name'])) echo "<span class='error'>" . $errors['department_name'] . "</span>"; ?>
        <br><br>

        <label for="faculty_name">Faculty name:</label>
        <input type="text" id="faculty_name" name="faculty_name" value="<?php echo $faculty_name; ?>">
        <?php if (isset($errors['faculty_name'])) echo "<span class='error'>" . $errors['faculty_name'] . "</span>"; ?>
        <br><br>

        <label for="university_name">University name:</label>
        <input type="text" id="university_name" name="university_name" value="<?php echo $university_name; ?>">
        <?php if (isset($errors['university_name'])) echo "<span class='error'>" . $errors['university_name'] . "</span>"; ?>
        <br><br>
        
        <input type="submit" value="Submit">
    </form>
</body>
</html>