# passwordGenerator

A Windows console app for generating random character passwords of varying length. The app uses upper and lowercase letters, numbers (0-9), and special characters (!, @, #, $, %, ^, &, *). Generated passwords will not have duplicate back-to-back characters or character types.

## Function
The app opens a console window on startup. Enter an integer of at least 8.

You can check the strength of your password [here](https://www.security.org/how-secure-is-my-password/).

Alternatively, enter a really large integer (>10000) to generate a wall of random characters.

## App Control
To exit the app, enter:
> *exit*

## Download ##
[passwordGenerator v1.0.1](https://github.com/JohnWSweeney/passwordGenerator/releases/download/v1.0.1/passwordGenerator_v1_0_1.exe) [29 kB]

## ChangeLog <br/>
v1.0.1
- Changed arrays in characters header to vectors.
- Added minimum password length exception to startMenu function.
- Updated generatePassword function to prevent duplicate back-to-back characters or character types.
- Added README.