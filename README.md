# Minitalk Project

This project consists of two programs, `server` and `client`, that communicate with each other using signals. The `client` program sends a message to the `server` program by converting characters to their ASCII values and sending them as signals. The `server` program receives the signals and reconstructs the message.

## Files

- `ft_printf`: This directory contains the printf function project.
- `server.c`: This file contains the function responsible for receiving signals and printing the message.
- `client.c`: This file contains the function that sends messages as signals.
- `ft_atoi.c`: This file contains the implementation of the `ft_atoi` function.
- `Makefile`: This file contains the rules for compiling the project.
- `minitalk.h`: This file contains the declarations of functions and any necessary macros.

## Signals

In Unix-like operating systems, signals are software interrupts delivered to a process. They can be used for communication between processes. In this project, we use signals to send messages from the `client` process to the `server` process.

- `SIGUSR1`: This signal is used to represent the binary digit `0`.
- `SIGUSR2`: This signal is used to represent the binary digit `1`.

## Bitwise Operators

Bitwise operators are used to perform operations on individual bits of binary numbers.

- `&` (AND): Performs a bitwise AND operation.
- `|` (OR): Performs a bitwise OR operation.
- `^` (XOR): Performs a bitwise XOR (exclusive OR) operation.
- `~` (NOT): Performs a bitwise NOT operation (flips the bits).
- `<<` (Left Shift): Shifts bits to the left by a specified number of positions.
- `>>` (Right Shift): Shifts bits to the right by a specified number of positions.

These operators are used in the `client` program to convert characters to their ASCII values and send them as individual bits.

## `pause()` Function

The `pause()` function causes the calling process to sleep until a signal is received. It is used in the `server` program to wait for incoming signals.

## Compilation

To compile the project, use the provided `Makefile`:

```bash
make
```
This will generate the server and client executables.

## Usage
Start the server program in one terminal:
```bash
./server
```
In a separate terminal, start the client program and provide the PID of the server process and the text to send as arguments:
```bash
./client [server_pid] [message]
```
Replace [server_pid] with the actual PID of the server process.
