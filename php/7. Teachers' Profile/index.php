<?php
include 'config.php';

if (isset($_GET['action']) && $_GET['action'] == 'delete' && isset($_GET['id'])) {
    $id = mysqli_real_escape_string($conn, $_GET['id']);
    
    $sql = "SELECT image FROM teacher WHERE id=$id";
    $result = mysqli_query($conn, $sql);
    
    if ($result && mysqli_num_rows($result) > 0) {
        $row = mysqli_fetch_assoc($result);
        if (!empty($row['image']) && file_exists('uploads/' . $row['image'])) {
            unlink('uploads/' . $row['image']); // Delete the image file
        }
    }
    
    $sql = "DELETE FROM teacher WHERE id=$id";
    if (mysqli_query($conn, $sql)) {
        echo "<script>alert('Teacher deleted successfully');</script>";
    } else {
        echo "<script>alert('Error deleting record: " . mysqli_error($conn) . "');</script>";
    }
}

$sql = "SELECT * FROM teacher";
$result = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>Teacher Profile System</title>
  </head>
  <body>
    <h1>Teacher Management System</h1>
    
    <p>
      <a href="add.php"><button>Add New Teacher</button></a>
    </p>

    <h2>Teachers List</h2>
    <table border="1">
        <tr>
            <th>Image</th>
            <th>Teacher ID</th>
            <th>Name</th>
            <th>Department</th>
            <th>Email</th>
            <th>Phone</th>
            <th>Actions</th>
        </tr>
        <?php
        if ($result && mysqli_num_rows($result) > 0) {
            while ($row = mysqli_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>";
                if (!empty($row['image']) && file_exists('uploads/' . $row['image'])) {
                    echo "<img src='uploads/" . $row['image'] . "' width='50' alt='Teacher Image'>";
                } else {
                    echo "No image";
                }
                echo "</td>";
                echo "<td>" . $row['teacherId'] . "</td>";
                echo "<td>" . $row['teacherName'] . "</td>";
                echo "<td>" . $row['department'] . "</td>";
                echo "<td>" . $row['email'] . "</td>";
                echo "<td>" . $row['phone'] . "</td>";
                echo "<td>
                        <a href='edit.php?id=" . $row['id'] . "'>Edit</a> | 
                        <a href='javascript:void(0);' onclick='confirmDelete(" . $row['id'] . ")'>Delete</a>
                      </td>";
                echo "</tr>";
            }
        }
        ?>
    </table>

    <script>
      function confirmDelete(id) {
        if (confirm("Are you sure you want to delete this teacher?")) {
          window.location.href = "index.php?action=delete&id=" + id;
        }
      }
    </script>
  </body>
</html>

<?php mysqli_close($conn); ?>