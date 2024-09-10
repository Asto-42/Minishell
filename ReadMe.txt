MINISHELL
-------------------


Minishell is a custom shell implemented in C that replicates key features of the bash shell. The goal of this project is to create a minimal, functional shell with a focus on understanding how a shell works at its core.

-------------------
Features
-------------------
Interactive Prompt: Displays a prompt while waiting for commands.
Command History: Maintains a history of commands during the session.
Command Execution: Searches for and executes commands based on the PATH variable, or using absolute/relative paths.
Signal Handling: Uses a single global variable to handle signals, restricting access to main data structures.
Quotes Handling:
Single quotes (') prevent interpretation of meta-characters.
Double quotes (") prevent interpretation of meta-characters except for $.
Redirection:
< redirects input.
> redirects output.
<< reads input until a defined delimiter is encountered.
>> redirects output in append mode.
Pipes: Implements pipes (|), allowing the output of one command to be the input of the next.
Environment Variables: Supports expanding environment variables ($), including the special variable $? for the exit status of the last executed command.
Control Characters:
Ctrl-C: Displays a new prompt.
Ctrl-D: Exits the shell.
Ctrl-\: No action (like in bash).

-------------------
Built-in Commands
-------------------

The shell also implements the following built-in commands:

echo (with -n option)
cd (with a relative or absolute path)
pwd
export
unset
env
exit
Error Handling
Unclosed Quotes: The shell does not process commands with unclosed quotes.
Special Characters: Characters like \ (backslash) and ; (semicolon) are not handled unless specified.
Signal Handling
Handles signals such as Ctrl-C, Ctrl-D, and Ctrl-\ similar to bash.
Only one global variable is used to capture signals.
Memory Management
While the readline() function can cause memory leaks (which do not need to be fixed), all user-implemented code must be free of memory leaks.
Reference
When in doubt, bash behavior should be used as a reference for implementing the shell's features.
