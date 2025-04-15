<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add Employee</title>
</head>
<body>
    <h3>Enter Employee Details</h3>
    <form action="process.php" method="post">
      <label for="id">ID:</label>
      <input type="text" id="id" name="id" required>
      <br><br>
      
      <label for="name">Name:</label>
      <input type="text" id="name" name="name" required>
      <br><br>
      
      <label for="fathersName">Father's Name:</label>
      <input type="text" id="fathersName" name="fathersName" required>
      <br><br>
      
      <label for="mothersName">Mother's Name:</label>
      <input type="text" id="mothersName" name="mothersName" required>
      <br><br>
      
      <label>Gender:</label>
      <input type="radio" id="male" name="gender" value="male" required>
      <label for="male">Male</label>
      <input type="radio" id="female" name="gender" value="female">
      <label for="female">Female</label>
      <br><br>
      
      <label for="department">Select Department:</label>
      <select id="department" name="department" required>
        <option value="">Select a department</option>
        <option value="marketing">Marketing</option>
        <option value="sales">Sales</option>
        <option value="operator">Operator</option>
        <option value="inventory">Inventory</option>
      </select>
      <br><br>
      
      <label for="number">Phone Number:</label>
      <input type="text" id="number" name="number" required>
      <br><br>
      
      <label for="NIDnumber">NID number:</label>
      <input type="text" id="NIDnumber" name="NIDnumber" required>
      <br><br>
      
      <label for="email">Email:</label>
      <input type="email" id="email" name="email" required>
      <br><br>
      
      <label for="join">Join Date:</label>
      <input type="date" id="join" name="join" required>
      <br><br>
      
      <label for="address">Address:</label>
      <textarea id="address" name="address" required></textarea>
      <br><br>
      
      <input type="submit" value="Submit">
      <a href="index.php"><button type="button">Cancel</button></a>
    </form>
</body>
</html>