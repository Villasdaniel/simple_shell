<p align="center">
<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcTLtL_ToHLEo_BWFxD-yf32Ux3zfsH_NPc8Qw&usqp=CAU" width="450" height="350">
<h1> Command interpreter - Simple Shell poject</h1></p>

## BACKGROUND 🐕
This is a colaboration project between two sfotware development students at [Holberton School](https://www.holbertonschool.com/) from Cohort 12, This project is about to create an own simple shell

## SIMPLE SHELL
Is an standard command interpretation for system.

### Flowchart

<p align="center"><img src="https://github.com/Villasdaniel/simple_shell/blob/master/Shell%20flowchart.jpg" width="450" height="350"></p>

### Header

* [holberton.h](https://github.com/Villasdaniel/simple_shell/blob/master/holberton.h)
Where prototypes and global variables are stored.

### Functions
There are some functions used to run our simple shell

* [_myexit](https://github.com/Villasdaniel/simple_shell/blob/master/built-in.c)
Function that check command line to exit shell.

* [signal_c](https://github.com/Villasdaniel/simple_shell/blob/master/built-in.c)
Function that make shell ignore input signal Ctrl + C.

* [_myenv](https://github.com/Villasdaniel/simple_shell/blob/master/built-in.c)
Function tht prints the environment variables separated

* [_getenv](https://github.com/Villasdaniel/simple_shell/blob/master/core_functions.c)
Functions that find the env variable name

* [_getline](https://github.com/Villasdaniel/simple_shell/blob/master/core_functions.c)
Function that get line command line from the prompt.

* [splitline](https://github.com/Villasdaniel/simple_shell/blob/master/core_functions.c)
Function that get line command line from the prompt.

* [execute_process](https://github.com/Villasdaniel/simple_shell/blob/master/core_functions.c)
Function that execute a process.

* [_which](https://github.com/Villasdaniel/simple_shell/blob/master/core_functions.c)
Function that search for a command in the directories.

* [_link](https://github.com/Villasdaniel/simple_shell/blob/master/list_functions.c)
Function that built linked list with directories stored in the environment.

* [_add_nodeint_end](https://github.com/Villasdaniel/simple_shell/blob/master/list_functions.c)
Function that add a new string to a node at the end.

* [free_list](https://github.com/Villasdaniel/simple_shell/blob/master/list_functions.c)
Function that frees a list_t list.

* [free_array](https://github.com/Villasdaniel/simple_shell/blob/master/list_functions.c)
Function that frees an array.

* [_strlen](https://github.com/Villasdaniel/simple_shell/blob/master/str_functions.c)
Function that find the length of a string.

* [_strcat](https://github.com/Villasdaniel/simple_shell/blob/master/str_functions.c)
Function that concatenate directories with the 1st position of the array.

* [_strtok](https://github.com/Villasdaniel/simple_shell/blob/master/str_functions.c)
Function that breaks a string into a sequence.

#### Requirements

* Allowed editors: vi, vim, emacs
* All the files will be compiled on Ubuntu 14.04 LTS
* The C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All the files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory.
* The code should use the Betty style.
* The shell should not have any memory leaks.
* No more than 5 functions per file.
* All the header files should be include guarded.
* Use system calls only when is needed.

### Examples

### No interactive

input:

$ echo "qwerty" | ./a.out

Output:

error: No such file or directory

input:

echo "ls -l" | ./a.out

output:

total 64

-rwxrwxr-x 1 daniel daniel 26184 ago 17 23:11 a.out

-rw-rw-r-- 1 daniel daniel   188 ago 12 13:56 AUTHORS

-rw-rw-r-- 1 daniel daniel  1113 ago 18 13:52 built-in.c

-rw-rw-r-- 1 daniel daniel  2881 ago 17 22:55 core_functions.c

-rw-rw-r-- 1 daniel daniel  1001 ago 17 23:13 holberton.h

-rw-rw-r-- 1 daniel daniel  1212 ago 17 23:01 list_functions.c

-rw-rw-r-- 1 daniel daniel  1951 ago 18 19:13 man_sh

-rw-rw-r-- 1 daniel daniel  3528 ago 18 18:25 README.md

-rw-rw-r-- 1 daniel daniel   726 ago 17 23:11 shell.c

-rw-rw-r-- 1 daniel daniel  1524 ago 17 23:07 str_functions.c

-rw-rw-r-- 1 daniel daniel     0 ago 17 21:38 testing_tmp_file_29291

-rw-rw-r-- 1 daniel daniel     0 ago 17 21:38 testing_tmp_file_3505

-rw-rw-r-- 1 daniel daniel     0 ago 17 21:38 testing_tmp_file_5322

$

### Interactive

input:

daniel@daniel-BOHK-WAX9X:~/Holberton/simple_shell$ ./a.out
$ qwerty

output:

error: No such file or directory
$

input:

daniel@daniel-BOHK-WAX9X:~/Holberton/simple_shell$ ./a.out
$ ls -l

output:

total 52

-rwxrwxr-x 1 daniel daniel 13792 ago 18 19:33 a.out

-rw-rw-r-- 1 daniel daniel   188 ago 12 13:56 AUTHORS

-rw-rw-r-- 1 daniel daniel  1091 ago 18 19:33 built-in.c

-rw-rw-r-- 1 daniel daniel  2881 ago 17 22:55 core_functions.c

-rw-rw-r-- 1 daniel daniel  1001 ago 17 23:13 holberton.h

-rw-rw-r-- 1 daniel daniel  1212 ago 17 23:01 list_functions.c

-rw-rw-r-- 1 daniel daniel  2634 ago 18 19:26 man_sh

-rw-rw-r-- 1 daniel daniel  3528 ago 18 18:25 README.md

-rw-rw-r-- 1 daniel daniel   726 ago 17 23:11 shell.c

-rw-rw-r-- 1 daniel daniel  1524 ago 17 23:07 str_functions.c

-rw-rw-r-- 1 daniel daniel     0 ago 17 21:38 testing_tmp_file_29291

-rw-rw-r-- 1 daniel daniel     0 ago 17 21:38 testing_tmp_file_3505

-rw-rw-r-- 1 daniel daniel     0 ago 17 21:38 testing_tmp_file_5322

$

### Authors
* Valentina Jaramillo [valen2510](https://github.com/valen2510)
* Daniel Villa [Villasdaniel](https://github.com/Villasdaniel)
