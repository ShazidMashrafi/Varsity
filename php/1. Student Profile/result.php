<?php
session_start();
include 'config.php';

if (!isset($_SESSION['student_id'])) {
    header("Location: index.php");
    exit;
}

$student_id = $_SESSION['student_id'];
$sql = "SELECT * FROM students WHERE id = $student_id";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) == 0) {
    header("Location: index.php");
    exit;
}

$student = mysqli_fetch_assoc($result);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Profile</title>
</head>
<body>
    <h1>Student Profile Information</h1>
    
    <p><strong>Name:</strong> <?php echo $student['name']; ?></p>
    <p><strong>Father's Name:</strong> <?php echo $student['fathers_name']; ?></p>
    <p><strong>Mother's Name:</strong> <?php echo $student['mothers_name']; ?></p>
    <p><strong>Gender:</strong> <?php echo $student['gender']; ?></p>
    <p><strong>Address:</strong> <?php echo $student['address']; ?></p>
    <p><strong>Date of Birth:</strong> <?php echo $student['dob']; ?></p>
    <p><strong>Roll Number:</strong> <?php echo $student['roll']; ?></p>
    <p><strong>Registration No:</strong> <?php echo $student['reg']; ?></p>
    <p><strong>Session:</strong> <?php echo $student['session']; ?></p>
    <p><strong>Department:</strong> <?php echo $student['department_name']; ?></p>
    <p><strong>Faculty:</strong> <?php echo $student['faculty_name']; ?></p>
    <p><strong>University:</strong> <?php echo $student['university_name']; ?></p>
    
    <a href="index.php">Back to Form</a>
</body>
</html>
<?php
mysqli_close($conn);
?>