<?php
include 'config.php';

$sql = "SELECT * FROM employees";
$result = mysqli_query($conn, $sql);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee List</title>
</head>
<body>
    <h2>Employee List</h2>
    <a href="form.php">Add New Employee</a>
    <br><br>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Father's Name</th>
            <th>Mother's Name</th>
            <th>Gender</th>
            <th>Department</th>
            <th>Phone</th>
            <th>NID</th>
            <th>Email</th>
            <th>Join Date</th>
            <th>Address</th>
        </tr>
        <?php
        if (mysqli_num_rows($result) > 0) {
            while($row = mysqli_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>" . $row['id'] . "</td>";
                echo "<td>" . $row['name'] . "</td>";
                echo "<td>" . $row['fathersName'] . "</td>";
                echo "<td>" . $row['mothersName'] . "</td>";
                echo "<td>" . $row['gender'] . "</td>";
                echo "<td>" . $row['department'] . "</td>";
                echo "<td>" . $row['number'] . "</td>";
                echo "<td>" . $row['NIDnumber'] . "</td>";
                echo "<td>" . $row['email'] . "</td>";
                echo "<td>" . $row['join_date'] . "</td>";
                echo "<td>" . $row['address'] . "</td>";
                echo "</tr>";
            }
        } else {
            echo "<tr><td colspan='11' style='text-align: center;'>No employees found</td></tr>";
        }
        ?>
    </table>
</body>
</html>
<?php
mysqli_close($conn);
?>
