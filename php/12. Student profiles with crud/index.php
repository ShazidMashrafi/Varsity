<?php
session_start();
include 'config.php';

$sql = "SELECT * FROM students_crud ORDER BY name ASC";
$result = mysqli_query($conn, $sql);
?>
<!DOCTYPE html>
<html>
<head>
	<title>Student Profiles with CRUD</title>
</head>
<body>
	<h2>Student Profiles (CRUD)</h2>
	<?php if (isset($_SESSION['success'])): ?>
		<div class="success"><?php echo $_SESSION['success']; unset($_SESSION['success']); ?></div>
	<?php endif; ?>
	<?php if (isset($_SESSION['error'])): ?>
		<div class="error"><?php echo $_SESSION['error']; unset($_SESSION['error']); ?></div>
	<?php endif; ?>
	<p><a href="form.php" class="btn add">Add New Student</a></p>
	<table>
		<tr>
			<th>Name</th>
			<th>Father's Name</th>
			<th>Mother's Name</th>
			<th>Gender</th>
			<th>Address</th>
			<th>DOB</th>
			<th>Roll</th>
			<th>Reg</th>
			<th>Session</th>
			<th>Department</th>
			<th>Faculty</th>
			<th>University</th>
			<th>Actions</th>
		</tr>
		<?php
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
			echo "<td>" . $row['name'] . "</td>";
			echo "<td>" . $row['fathers_name'] . "</td>";
			echo "<td>" . $row['mothers_name'] . "</td>";
			echo "<td>" . $row['gender'] . "</td>";
			echo "<td>" . $row['address'] . "</td>";
			echo "<td>" . $row['dob'] . "</td>";
			echo "<td>" . $row['roll'] . "</td>";
			echo "<td>" . $row['reg'] . "</td>";
			echo "<td>" . $row['session'] . "</td>";
			echo "<td>" . $row['department_name'] . "</td>";
			echo "<td>" . $row['faculty_name'] . "</td>";
			echo "<td>" . $row['university_name'] . "</td>";
            echo "<td>"
                . "<a href='form.php?id=" . $row['id'] . "' class='btn edit'>Edit</a> "
				. "<a href='delete.php?id=" . $row['id'] . "' class='btn delete'>Delete</a>"
                . "</td>";
            echo "</tr>";
        }
		?>
	</table>
</body>
</html>
<?php mysqli_close($conn); ?>
