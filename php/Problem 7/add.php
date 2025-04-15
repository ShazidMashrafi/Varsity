<?php
include 'config.php';

if (!file_exists('uploads')) {
    mkdir('uploads', 0777, true);
}

$teacher = [
    'id' => '',
    'teacherId' => '',
    'teacherName' => '',
    'department' => '',
    'email' => '',
    'phone' => '',
    'image' => ''
];
$action = "add";
$pageTitle = "Add New Teacher";
$buttonText = "Add Teacher";

$errors = [];
$success_message = '';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $teacherId = mysqli_real_escape_string($conn, $_POST['teacherId']);
    $teacherName = mysqli_real_escape_string($conn, $_POST['teacherName']);
    $department = mysqli_real_escape_string($conn, $_POST['department']);
    $email = mysqli_real_escape_string($conn, $_POST['email']);
    $phone = mysqli_real_escape_string($conn, $_POST['phone']);
    
    $image = '';
    $uploadOk = 1;
    
    if (isset($_FILES['image']) && $_FILES['image']['error'] == 0) {
        $file_tmp = $_FILES['image']['tmp_name'];
        $file_name = $_FILES['image']['name'];
        $imageFileType = strtolower(pathinfo($file_name, PATHINFO_EXTENSION));
        
        $image = $teacherId . '_' . time() . '.' . $imageFileType;
        $target_file = "uploads/" . $image;
        
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
            if (!move_uploaded_file($file_tmp, $target_file)) {
                $errors[] = "Sorry, there was an error uploading your file.";
                $image = '';
            }
        } else {
            $image = '';
        }
    }
    
    if (empty($errors)) {
        $sql = "INSERT INTO teacher (teacherId, teacherName, department, email, phone, image) 
                VALUES ('$teacherId', '$teacherName', '$department', '$email', '$phone', '$image')";
        
        if (mysqli_query($conn, $sql)) {
            echo "<script>
                    alert('Teacher added successfully');
                    window.location.href = 'index.php';
                  </script>";
        } else {
            $errors[] = "Error: " . mysqli_error($conn);
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