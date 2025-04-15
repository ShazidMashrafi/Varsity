<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title><?php echo $pageTitle; ?></title>
  </head>
  
  <body>
    <h2><?php echo $pageTitle; ?></h2>
    
    <form method="post" enctype="multipart/form-data">
        <?php if ($action == "edit"): ?>
            <input type="hidden" name="id" value="<?php echo $teacher['id']; ?>">
            <?php if (!empty($teacher['image'])): ?>
                <p>Current Image:</p>
                <img src="uploads/<?php echo $teacher['image']; ?>" width="100" alt="Teacher Image">
                <br /><br />
            <?php endif; ?>
        <?php endif; ?>
        
        <label for="teacherId">Teacher ID:</label>
        <input type="text" id="teacherId" name="teacherId" value="<?php echo $teacher['teacherId']; ?>" required />
        <br /><br />
        
        <label for="teacherName">Teacher Name:</label>
        <input type="text" id="teacherName" name="teacherName" value="<?php echo $teacher['teacherName']; ?>" required />
        <br /><br />
        
        <label for="department">Department Name:</label>
        <input type="text" id="department" name="department" value="<?php echo $teacher['department']; ?>" required />
        <br /><br />
        
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" value="<?php echo $teacher['email']; ?>" required />
        <br /><br />
        
        <label for="phone">Phone:</label>
        <input type="text" id="phone" name="phone" value="<?php echo $teacher['phone']; ?>" required />
        <br /><br />
        
        <label for="image">Profile Image:</label>
        <input type="file" id="image" name="image" <?php echo ($action == "add") ? "required" : ""; ?> />
        <br /><br />
        
        <input type="submit" value="<?php echo $buttonText; ?>" />
        <a href="index.php"><button type="button">Cancel</button></a>
    </form>
  </body>
</html>