<?php
include 'config.php';

if (!file_exists('uploads')) {
    mkdir('uploads', 0777, true);
}

$action = "edit";
$pageTitle = "Edit Teacher";
$buttonText = "Update Teacher";
$errors = [];

if (isset($_GET['id']) && !empty($_GET['id'])) {
    $id = mysqli_real_escape_string($conn, $_GET['id']);
    
    $sql = "SELECT * FROM teacher WHERE id=$id";
    $result = mysqli_query($conn, $sql);
    
    if (mysqli_num_rows($result) == 1) {
        $teacher = mysqli_fetch_assoc($result);
    } else {
        echo "<script>
                alert('No teacher found with that ID');
                window.location.href = 'index.php';
              </script>";
        exit;
    }
} else {
    echo "<script>
            alert('Invalid request');
            window.location.href = 'index.php';
          </script>";
    exit;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = mysqli_real_escape_string($conn, $_POST['id']);
    $teacherId = mysqli_real_escape_string($conn, $_POST['teacherId']);
    $teacherName = mysqli_real_escape_string($conn, $_POST['teacherName']);
    $department = mysqli_real_escape_string($conn, $_POST['department']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $phone = mysqli_real_escape_string($conn, $_POST['phone']);
    
    $image = $teacher['image'];
    $uploadOk = 1;
    
    if (isset($_FILES['image']) && $_FILES['image']['error'] == 0) {
        $file_tmp = $_FILES['image']['tmp_name'];
        $file_name = $_FILES['image']['name'];
        $imageFileType = strtolower(pathinfo($file_name, PATHINFO_EXTENSION));
        
        $new_image = $teacherId . '_' . time() . '.' . $imageFileType;
        $target_file = "uploads/" . $new_image;
        
        $check = getimagesize($file_tmp);
        if ($check === false) {
            $errors[] = "File is not an image.";
            $uploadOk = 0;
        }
        
        if ($_FILES['image']['size'] > 2000000) {
            $errors[] = "Sorry, your file is too large. Maximum 2MB allowed.";
            $uploadOk = 0;
        }
        
        if ($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg" && $imageFileType != "gif") {
            $errors[] = "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
            $uploadOk = 0;
        }
        
        if ($uploadOk == 1) {
            if (move_uploaded_file($file_tmp, $target_file)) {
                if (!empty($teacher['image']) && file_exists('uploads/' . $teacher['image'])) {
                    unlink('uploads/' . $teacher['image']);
                }
                $image = $new_image;
            } else {
                $errors[] = "Sorry, there was an error uploading your file.";
            }
        }
    }
    
    if (empty($errors)) {
        $sql = "UPDATE teacher SET 
                teacherId='$teacherId', 
                teacherName='$teacherName', 
                department='$department', 
                email='$email', 
                phone='$phone',
                image='$image'
                WHERE id=$id";
        
        if (mysqli_query($conn, $sql)) {
            echo "<script>
                    alert('Teacher updated successfully');
                    window.location.href = 'index.php';
                  </script>";
        } else {
            $errors[] = "Error updating record: " . mysqli_error($conn);
        }
    }
}

if (!empty($errors)) {
    echo "<div style='color:red;margin-bottom:20px;'>";
    foreach ($errors as $error) {
        echo $error . "<br>";
    }
    echo "</div>";
}

include 'form.php';

mysqli_close($conn);
?>