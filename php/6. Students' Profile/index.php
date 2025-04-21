<?php
include 'config.php';

$sql = "SELECT * FROM students";
$result = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html>

<head>
    <title>Student's Profile</title>
</head>

<body>
    <h1>Students' Profile List</h1>

    <?php
    if (mysqli_num_rows($result) > 0) {
        echo "<table border = '1' >
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Father's Name</th>
                <th>Mother's Name</th>
                <th>Gender</th>
                <th>Address</th>
                <th>Date of Birth</th>
                <th>Roll Number</th>
                <th>Registration Number</th>
                <th>Session</th>
                <th>Department</th>
                <th>Faculty</th>
                <th>University</th>
            </tr>";

        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>";
            echo "<td>" . $row['id'] . "</td>";
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
        }
        echo "</table>";
    } else {
        echo "<p> No student profiles found in the database.</p>";
    }
    ?>

</body>

</html>

<?php
mysqli_close($conn);
?>
