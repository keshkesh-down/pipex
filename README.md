# pipex
This project aims to make you understand a bit deeper two concepts that you already know: the redirections and the pipes.

#### Used functions in this project:
- [access](https://linux.die.net/man/2/access) checks user permissions for a file.
- [unlink](https://man7.org/linux/man-pages/man2/unlink.2.html) removes the name from the file system.
- [close](https://linux.die.net/man/2/close) close a file descriptor.
- [wait](https://man7.org/linux/man-pages/man2/wait.2.html), [waitpid](https://man7.org/linux/man-pages/man2/wait.2.html), [waitid](https://man7.org/linux/man-pages/man2/wait.2.html) - wait for process to change state.
- [pipe](https://man7.org/linux/man-pages/man2/pipe.2.html), [pipe2](https://man7.org/linux/man-pages/man2/pipe.2.html) - create pipe.
- [dup](https://man7.org/linux/man-pages/man2/dup.2.html), [dup2](https://man7.org/linux/man-pages/man2/dup.2.html) - duplicate a file descriptor.
- [execve](https://man7.org/linux/man-pages/man2/execve.2.html) - execute program.
- [fork](https://man7.org/linux/man-pages/man2/fork.2.html) - create a child process.
- [exit](https://man7.org/linux/man-pages/man3/exit.3.html) - cause normal process termination.

#### Program mandatory part (only one pipe):
```console
foo@bar:> ./pipex infile "cmd1" "cmd2" outfile
```

#### Program bonus part (multiple pipes):
```console
foo@bar:> ./pipex here_doc //LIMITER\\ "cmd1" "cmd2" ... "cmdn" file
```

#### Example:

![image](https://github.com/keshkesh-down/pipex/blob/main/pipex.gif)

#### Makefile
`make` to compile without bonus functions.

`make bonus` to compile with bonuses.

`make clean` to delete `*.o` files.

`make fclean` to delete `*.o` and `./pipex` files.

`make re` to delete `*.o` and `./pipex` files, and, to compile without bonus functions.
