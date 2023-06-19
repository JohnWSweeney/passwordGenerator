# passwordGenerator

A console app for generating secure passwords. 

The app returns passwords using upper and lowercase letters, numbers (0-9), and special characters (!, @, #, $, %, ^, &, *). Passwords are generated using the <strong><code>rand</code></strong>, <strong><code>rand_s</code></strong>, <strong><code>mt19937</code></strong>, and <strong><code>mt19937_64</code></strong> pseudorandom number generators (PRNGs). Passwords will not have duplicate back-to-back characters or character types and must be at least 8 characters long.

While <strong><code>mt19937</code></strong> and <strong><code>mt19937_64</code></strong> are the superior PRNGs, <strong><code>rand</code></strong> and <strong><code>rand_s</code></strong> are included for illustration purposes.

## Function
The app opens a console window on startup. At the prompt, enter a postive integer of at least 8 for your desired password length. Passwords with 12 or more characters generated with <strong><code>mt19937</code></strong> or <strong><code>mt19937_64</code></strong> are recommended. 

You can check the strength of your password [here](https://www.security.org/how-secure-is-my-password/).

## App Control
To exit the app, enter:
> *exit*

## Download
[passwordGenerator v1.3.0](https://github.com/JohnWSweeney/passwordGenerator/releases/download/v1.3.0/passwordGenerator_v1_3_0.exe) [32 kB]

## ChangeLog <br/>
v1.3.0
- Updated random class:
	- Moved all functions to private except *setSeed* and *getNum*.
	- Added <strong><code>mt19937_64</code></strong> support.
- Moved Wall-of-Text function to [randomDemo](https://github.com/JohnWSweeney/randomDemo) repo.

v1.2.0
- Added random class with multiple PRNGs and related functions.
	- Functions returning random numbers have distribution min/max input parameters.
- Added <strong><code>mt19937</code></strong> support.
 
v1.1.0
- Added <strong><code>rand_s</code></strong> support.
- Added wall of text function.

v1.0.1
- Changed arrays in characters header to vectors.
- Added minimum password length exception to startMenu function.
- Updated generatePassword function to prevent duplicate back-to-back characters or character types.
- Added README.