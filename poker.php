<!DOCTYPE html>
<html>
  <head>
    <title>Fluffy Broccoli</title>
  </head>


  <body>

    <h1>Poker</h1>
    <p>Input Reset, Draw, or Stay</p>

    <?php
       // define variables and set to empty values
       $arg1 = $output = $retc = "";
       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         exec("./pokerround " . $arg1 , $output, $retc);
       }
       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Arg1: <input type="text" name="arg1"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
       // only display if return code is numeric - i.e. exec has been called
       if (is_numeric($retc)) {
         foreach ($output as $line) {
           echo "<h2>$line</h2>";
         }
       }
    ?>
    
  </body>
</html>
