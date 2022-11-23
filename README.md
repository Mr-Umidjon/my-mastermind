# My Mastermind<br>
### Description<br>
### SPECIFICATIONS<br>
Write a program called mastermind; it will be an implementation of the famous game.<br>
<br>
### NAME<br>
my_mastermind<br>
<br>
### SYNOPSIS<br>
my_mastermind [-ct]<br>
<br>
### DESCRIPTION<br>
Mastermind is a game composed of 8 pieces of different colors.<br>
A secret code is then composed of 4 distinct pieces.<br>
<br>
The player has 10 attempts to find the secret code.<br>
After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.<br>
<br>
Pieces will be '0' '1' '2' '3' '4' '5' '6' '7' '8'.<br>
<br>
If the player finds the code, he wins, and the game stops.<br>
A misplaced piece is a piece that is present in the secret code butthat is not in a good position.<br>
<br>
You must read the player's input from the standard input.<br>
<br>
Your program will also receive the following parameters:<br>
-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.<br>
-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.<br>
