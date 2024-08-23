# Simple Shell Project

## Introduction

This project involves creating a simple shell in C that can execute commands, manage processes, and manipulate environment variables. This shell was developed in a Linux environment (Ubuntu 20.04 LTS) and was designed to adhere to coding and documentation standards as imposed by the Betty style.

## Project Requirements

-   **Allowed Editors**: `vi`, `vim`, `emacs`
-   **Compilation**: All files are compiled on Ubuntu 20.04 LTS using `gcc` with the following options:
    -   `-Wall -Werror -Wextra -pedantic -std=gnu89`
-   **File Structure**:
    -   All files must end with a new line.
    -   A `README.md` file is mandatory at the root of the project.
    -   The code must follow the Betty style, checked using `betty-style.pl` and `betty-doc.pl`.
    -   The shell must not have any memory leaks.
    -   No more than 5 functions per file.
    -   All header files must be protected by include guards (`#ifndef`, `#define`, `#endif`).
    -   Use system calls only when necessary.

## List of Allowed Functions and System Calls

-   `access` (man 2 access)
-   `chdir` (man 2 chdir)
-   `close` (man 2 close)
-   `closedir` (man 3 closedir)
-   `execve` (man 2 execve)
-   `exit` (man 3 exit)
-   `_exit` (man 2 _exit)
-   `fflush` (man 3 fflush)
-   `fork` (man 2 fork)
-   `free` (man 3 free)
-   `getcwd` (man 3 getcwd)
-   `getline` (man 3 getline)
-   `getpid` (man 2 getpid)
-   `isatty` (man 3 isatty)
-   `kill` (man 2 kill)
-   `malloc` (man 3 malloc)
-   `open` (man 2 open)
-   `opendir` (man 3 opendir)
-   `perror` (man 3 perror)
-   `read` (man 2 read)
-   `readdir` (man 3 readdir)
-   `signal` (man 2 signal)
-   `stat` (__xstat) (man 2 stat)
-   `lstat` (__lxstat) (man 2 lstat)
-   `fstat` (__fxstat) (man 2 fstat)
-   `strtok` (man 3 strtok)
-   `wait` (man 2 wait)
-   `waitpid` (man 2 waitpid)
-   `wait3` (man 2 wait3)
-   `wait4` (man 2 wait4)
-   `write` (man 2 write)

## Project Overview

### Project Objectives

The goal of this project was to recreate some basic functionalities of a Unix shell. We implemented functions to handle command execution, child processes (fork), and environment variable expansion. 

### Code Compilation

To compile the project, use the following command:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

This command compiles all `.c` files in the project and generates an executable named `hsh`.

### Implemented Features

1.  **Command Execution**: The shell supports command execution via `execve` after forking a child process.
2.  **Variable Expansion**: Environment variables are automatically expanded in the entered commands.
3.  **Process Management**: The shell handles the creation and waiting of child processes.
4.  **Built-in Commands**: Commands  `exit` are implemented as built-in command within the shell.

## Flowchart

Here is the flowchart of the main function flow:

![[https://github.com/bluelightwatcher/holbertonschool-simple_shell/blob/main/Flowchart/Simple_shell_flow_chart.png]] 

## How to Use

### Compilation

To compile the project, use the following command:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh` 

This command compiles all `.c` files in the project and generates an executable named `hsh`.

### Launching the Shell

After compiling, you can start the shell with the following command :

`./hsh` 

### Shell Prompt

When you start the shell, you will see a prompt displayed as follows:

`$` 

This prompt indicates that the shell is ready to accept commands.

### Usage Examples

Here are some examples of commands you can execute in the shell:

#### 1. Display the current working directory (`pwd`)
    $ pwd 
    /home/user/project_directory`

#### 2. List files in the current directory (`ls`)

    $ ls
    file1  file2  directory1


#### 3. List files with details (`ls -l`)

    $ ls -l 
    total 4
    -rwxr-xr-x 1 user user  0 Jan  1 00:00 file1
    -rwxr-xr-x 1 user user  0 Jan  1 00:00 file2
    drwxr-xr-x 2 user user 4096 Jan  1 00:00
    directory1`


#### 4. Non-Interactive Mode

The shell can also be executed in non-interactive mode by piping a command into it. For example, to execute the `ls` command via the shell, you can use:


	echo "/bin/ls" | ./hsh


The result might look like this:

	file1  file2  directory1`

This mode is useful for running commands from other scripts or programs without entering an interactive shell session.

#### 5. Exiting the Shell (`exit`)

To exit the shell in interactive mode, you can use the command:

   `$ exit`

You can also exit the shell by pressing "Ctrl+D".

This will terminate the shell session.


### Conclusion

These examples show how to interact with your shell, including non-interactive mode where you can pipe commands for automation. The `$` prompt appears whenever the shell is ready to accept a new command, and you can execute various standard Unix commands like `pwd`, `ls`, or more complex commands with arguments.

## Integrated Modules

The project is divided into several modules that handle different functionalities of the shell:

-   **main.c**: Main entry point of the program.
-   **execute_command.c**: Handles command execution.
-   **expand_variable.c**: Handles environment variable expansion.
-   **handle_builtin.c**: Manages built-in commands.
-   **path.c**: Manages command path resolution.
-   **token_args.c**: Tokenizes command arguments.
-   **non_interactive.c**: Handles non-interactive mode of the shell.
-   **prompt.c**: Displays the user prompt.

## Authors

-   **Fabio Dejieux** [[https://github.com/Pizzapanda92]]
-   **Etienne Seguin**[[https://github.com/bluelightwatcher]]
