<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST["name"];
    $email = $_POST["email"];
    $message = $_POST["message"];

    // Save the form data to a text file (you can use a database in a real-world scenario)
    $data = "Name: $name\nEmail: $email\nMessage: $message\n\n";
    file_put_contents("form_submissions.txt", $data, FILE_APPEND);

    // Redirect back to the main page or display a thank you message
    header("Location: index.html");
    exit();
}

?>