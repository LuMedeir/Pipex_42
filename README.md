# Pipex
<p align="center">
<img src="./img/pipex.png">
</p>

<p align="center">
</p>

</br>

## Description  
The purpose of this project is the discovery in detail UNIX mechanism - `PIPE`.

### Discription of mandatory part
The program `pipex` should repeat the behaviour of the next shell command
bash
$> < file1 cmd1 | cmd2 > file2

and looks like this:
bash
$> ./pipex file1 cmd1 cmd2 file2

All errors like: wrong commands,  permission to files and etc, need be handle.

## Makefile rules

| Rule         |                 Description                             |
|:------------:|:-------------------------------------------------------:|
| `make`       | Compile the program.                                    |
| `make bonus` | Compile the bonus part of the program.                  |
| `make clean` | Remove every objects of compilation                     |
| `make fclean`| Do `clean` rule and remove the executable program       |
| `make re`    | Do `fclean` rule and compile the program mandatory      |
