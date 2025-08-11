<?php
session_start();
include 'config.php';

$edit = false;
$student = [
    'id' => '', 'name' => '', 'gender' => '', 'roll' => '', 'department_name' => ''
];

if (isset($_GET['id'])) {
    $id = intval($_GET['id']);
    $result = mysqli_query($conn, "SELECT * FROM students_crud WHERE id=$id");
    if ($result && mysqli_num_rows($result) > 0) {
        $student = mysqli_fetch_assoc($result);
        $edit = true;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title><?php echo $edit ? 'Edit' : 'Add'; ?> Student Profile</title>
</head>
<body>
    <h2><?php echo $edit ? 'Edit' : 'Add'; ?> Student Profile</h2>
    <form action="process.php" method="post">
        <?php if ($edit): ?>
            <input type="hidden" name="id" value="<?php echo $student['id']; ?>">
        <?php endif; ?>
        <label>Name:</label><br>
        <input type="text" name="name" value="<?php echo $student['name']; ?>" required><br><br>
        <label>Gender:</label>
        <select name="gender" required>
            <option value="">Select</option>
            <option value="male" <?php if($student['gender']=='male') echo 'selected'; ?>>Male</option>
            <option value="female" <?php if($student['gender']=='female') echo 'selected'; ?>>Female</option>
        </select>
        <br><br>
        <label>Roll:</label><br>
        <input type="text" name="roll" value="<?php echo $student['roll']; ?>" required><br><br>
        <label>Department:</label><br>
        <input type="text" name="department_name" value="<?php echo $student['department_name']; ?>" required><br><br>
        <input type="submit" value="<?php echo $edit ? 'Update' : 'Add'; ?> Student">
        <a href="index.php"><button type="button">Cancel</button></a>
    </form>
</body>
</html>
<?php mysqli_close($conn); ?>
