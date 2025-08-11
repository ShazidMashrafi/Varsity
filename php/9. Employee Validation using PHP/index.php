<?php
session_start();

$id = $name = $fathersName = $mothersName = $gender = $department = $number = $NIDnumber = $email = $join = $address = '';

if (isset($_SESSION['form_data'])) {
    extract($_SESSION['form_data']);
    unset($_SESSION['form_data']);
}

$errors = isset($_SESSION['errors']) ? $_SESSION['errors'] : [];
unset($_SESSION['errors']);
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add Employee</title>
    <style>
        .error {
            color: red;
            font-size: 12px;
            margin-left: 5px;
        }
    </style>
</head>
<body>
    <h3>Enter Employee Details</h3>
    
    <?php if (isset($errors['database'])): ?>
        <p style="color: red;"><?php echo $errors['database']; ?></p>
    <?php endif; ?>
    
    <form action="validate.php" method="post">
      <label for="id">ID:</label>
      <input type="text" id="id" name="id" value="<?php echo htmlspecialchars($id); ?>" required>
      <?php if (isset($errors['id'])): ?>
        <span class="error"><?php echo $errors['id']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="name">Name:</label>
      <input type="text" id="name" name="name" value="<?php echo htmlspecialchars($name); ?>" required>
      <?php if (isset($errors['name'])): ?>
        <span class="error"><?php echo $errors['name']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="fathersName">Father's Name:</label>
      <input type="text" id="fathersName" name="fathersName" value="<?php echo htmlspecialchars($fathersName); ?>" required>
      <?php if (isset($errors['fathersName'])): ?>
        <span class="error"><?php echo $errors['fathersName']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="mothersName">Mother's Name:</label>
      <input type="text" id="mothersName" name="mothersName" value="<?php echo htmlspecialchars($mothersName); ?>" required>
      <?php if (isset($errors['mothersName'])): ?>
        <span class="error"><?php echo $errors['mothersName']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label>Gender:</label>
      <input type="radio" id="male" name="gender" value="male" <?php if($gender === 'male') echo 'checked'; ?> required>
      <label for="male">Male</label>
      <input type="radio" id="female" name="gender" value="female" <?php if($gender === 'female') echo 'checked'; ?>>
      <label for="female">Female</label>
      <?php if (isset($errors['gender'])): ?>
        <span class="error"><?php echo $errors['gender']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="department">Select Department:</label>
      <select id="department" name="department" required>
        <option value="" <?php if($department === '') echo 'selected'; ?>>Select a department</option>
        <option value="marketing" <?php if($department === 'marketing') echo 'selected'; ?>>Marketing</option>
        <option value="sales" <?php if($department === 'sales') echo 'selected'; ?>>Sales</option>
        <option value="operator" <?php if($department === 'operator') echo 'selected'; ?>>Operator</option>
        <option value="inventory" <?php if($department === 'inventory') echo 'selected'; ?>>Inventory</option>
      </select>
      <?php if (isset($errors['department'])): ?>
        <span class="error"><?php echo $errors['department']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="number">Phone Number:</label>
      <input type="text" id="number" name="number" value="<?php echo htmlspecialchars($number); ?>" required>
      <?php if (isset($errors['number'])): ?>
        <span class="error"><?php echo $errors['number']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="NIDnumber">NID number:</label>
      <input type="text" id="NIDnumber" name="NIDnumber" value="<?php echo htmlspecialchars($NIDnumber); ?>" required>
      <?php if (isset($errors['NIDnumber'])): ?>
        <span class="error"><?php echo $errors['NIDnumber']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="email">Email:</label>
      <input type="email" id="email" name="email" value="<?php echo htmlspecialchars($email); ?>" required>
      <?php if (isset($errors['email'])): ?>
        <span class="error"><?php echo $errors['email']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="join">Join Date:</label>
      <input type="date" id="join" name="join" value="<?php echo htmlspecialchars($join); ?>" required>
      <?php if (isset($errors['join'])): ?>
        <span class="error"><?php echo $errors['join']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <label for="address">Address:</label>
      <textarea id="address" name="address" required><?php echo htmlspecialchars($address); ?></textarea>
      <?php if (isset($errors['address'])): ?>
        <span class="error"><?php echo $errors['address']; ?></span>
      <?php endif; ?>
      <br><br>
      
      <input type="submit" value="Submit">
      <a href="index.php"><button type="button">Cancel</button></a>
    </form>
</body>
</html>