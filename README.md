# Pipex

Pipex reproduces the behavior of the shell pipe command in C.

## Usage

It launches as:

```sh
./pipex infile cmd1 cmd2 outfile
```
and behaves as this line does in the shell:
```
< infile cmd1 | cmd2 > outfile
```
# Focus
Pipex focuses on three main concepts: pipelines, child processes, and execution of commands.

# Arguments
It must take 4 arguments:
```
file1 and file2 are file names.
cmd1 and cmd2 are shell commands with their parameters.
```
# Whitelisted Functions
```
dup(2)
fork(2)
pipe()
exec(3)
```
# Execution Flow
```
1. Child Process Execution (cmd1):
2. Reads input from file1.
3. Pipes the output to the parent process.
4. Executes cmd1 with input from file1 and pipes output.
5. Parent Process Execution (cmd2):
6. Reads input from the pipe (output of cmd1).
7. Writes output to file2.
8. Executes cmd2 with input from the pipe and writes output to file2.
```

# Compile
```
make 
./pipex infile "cmd1" "cmd2" outfile
