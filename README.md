# passwordGenerator

A Windows console app for generating pseudorandom character passwords of varying length. The app uses upper and lowercase letters, numbers (0-9), and special characters (!, @, #, $, %, ^, &, *). The app returns passwords generated with the <strong><code>rand</code></strong> and <strong><code>rand_s</code></strong> pseudorandom number generators (PRNGs). Passwords will not have duplicate back-to-back characters or character types.

## Function
The app opens a console window on startup. At the prompt, enter a postive integer of at least 8 for your desired password length. Passwords with 12 or more characters are recommended.

You can check the strength of your password [here](https://www.security.org/how-secure-is-my-password/).

### Wall of Text
Just for fun, enter *wall* to generate a wall of random characters.
> *wall*
## App Control
To exit the app, enter:
> *exit*

## Future Updates
- Add <strong><code>mt19937</code><strong>, other PRNGs.

## Download
[passwordGenerator v1.1.0](https://github.com/JohnWSweeney/passwordGenerator/releases/download/v1.1.0/passwordGenerator_v1_1_0.exe) [31 kB]

## ChangeLog <br/>
v1.1.0
- Added <strong><code>rand_s</code></strong> support.
- Added wall of text function.

v1.0.1
- Changed arrays in characters header to vectors.
- Added minimum password length exception to startMenu function.
- Updated generatePassword function to prevent duplicate back-to-back characters or character types.
- Added README.