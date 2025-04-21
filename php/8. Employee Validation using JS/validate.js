function validateForm() {
    const errorElements = document.querySelectorAll('.error');
    errorElements.forEach(element => {
        element.textContent = '';
    });

    let isValid = true;

    const id = document.getElementById('id');
    if (!/^[a-zA-Z0-9]+$/.test(id.value.trim())) {
        document.getElementById('idError').textContent = "ID must contain only letters and numbers";
        isValid = false;
    }

    const name = document.getElementById('name');
    if (!/^[a-zA-Z\s]+$/.test(name.value.trim())) {
        document.getElementById('nameError').textContent = "Name must contain only letters";
        isValid = false;
    }

    const fathersName = document.getElementById('fathersName');
    if (!/^[a-zA-Z\s]+$/.test(fathersName.value.trim())) {
        document.getElementById('fathersNameError').textContent = "Father's name must contain only letters";
        isValid = false;
    }

    const mothersName = document.getElementById('mothersName');
    if (!/^[a-zA-Z\s]+$/.test(mothersName.value.trim())) {
        document.getElementById('mothersNameError').textContent = "Mother's name must contain only letters";
        isValid = false;
    }

    const male = document.getElementById('male');
    const female = document.getElementById('female');
    if (!male.checked && !female.checked) {
        document.getElementById('genderError').textContent = "Please select a gender";
        isValid = false;
    }

    const department = document.getElementById('department');
    if (department.value === "") {
        document.getElementById('departmentError').textContent = "Please select a department";
        isValid = false;
    }

    const phoneNumber = document.getElementById('number');
    if (!/^[0-9]{11}$/.test(phoneNumber.value.trim())) {
        document.getElementById('numberError').textContent = "Phone number must be 11 digits";
        isValid = false;
    }

    const nidNumber = document.getElementById('NIDnumber');
    if (!/^[0-9]{10}$|^[0-9]{13}$|^[0-9]{17}$/.test(nidNumber.value.trim())) {
        document.getElementById('NIDnumberError').textContent = "NID number must be 10, 13, or 17 digits";
        isValid = false;
    }

    const email = document.getElementById('email');
    if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email.value.trim())) {
        document.getElementById('emailError').textContent = "Please enter a valid email address";
        isValid = false;
    }

    const joinDate = document.getElementById('join');
    const selectedDate = new Date(joinDate.value);
    const today = new Date();
    
    if (joinDate.value === "") {
        document.getElementById('joinError').textContent = "Please select a join date";
        isValid = false;
    } else if (selectedDate > today) {
        document.getElementById('joinError').textContent = "Join date cannot be in the future";
        isValid = false;
    }

    const address = document.getElementById('address');
    if (address.value.trim().length < 5) {
        document.getElementById('addressError').textContent = "Address must be at least 5 characters";
        isValid = false;
    }

    return isValid;
}