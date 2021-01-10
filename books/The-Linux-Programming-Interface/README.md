# The Linux Programming Interface (A linux and Unix System Programming Handbook)

## Chapter - 2 (Fundamental Concept)

## Kernel
The term kernel refer to the central software that manages and allocates computer resources(i.e. The CPU, RAM, devices) 

Tasks performed by the kernel:

- Process scheduling 
- Memory management
- Provision of a file system
- Creation and termination of processes
- Access to devices
- Networking
- Provision of a system call application programming interface(API)

## Shell
A shell is a special-purpose program designed to read commands typed by a user
and execute appropriate programs in response to those commands. Such a pro-
gram is sometimes known as a command interpreter.
A number of important shells have
appeared over time:
- Bourne shell(sh): This is the oldest and wisely used shell
- C shell(csh): This shell provides some interactive features unavailable in the bourne shell.
- Korn shell(ksh): This shell was written as the successor to the Bourne shell by
  David Korn at AT&T Bell Laboratories.
- Bourne shell again(bash): This shell is the GNU project’s reimplementation of
  the Bourne shell. It supplies interactive features similar to those available
  in the C and Korn shells. The principal authors of bash are Brian Fox and Chet
  Ramey. Bash is probably the most widely used shell on Linux.
  
## Users and Groups
- Every user of the system has a unique login name and a unique user id (UID). For each user, a line in /etc/paaswd file which contains this information as well as Group Id, Home directory, login shell. 
- An user can be a member of multiple groups. Each group is identified by a single line in
  the system group file, /etc/group , which includes Group name, group id and user list.
- Super user with the User id(UID) 0 and normally has the login name root has special priviledges in the system. The superuser can access any file in the system, regardless of the per-
  missions on that file, and can send signals to any user process in the system. The
  system administrator uses the superuser account to perform various administrative
  tasks on the system.
  