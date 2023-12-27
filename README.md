# Minitalk

Welcome to Minitalk, a project that showcases inter-process communication (IPC) using UNIX signals in C. It allows a client and a server to exchange messages using `SIGUSR1` and `SIGUSR2` signals.

## Features

- **Lightweight IPC**: Uses UNIX signals for efficient communication.
- **Supports Multiple Clients**: Server can handle simultaneous client requests.
- **Bit-by-bit Message Transfer**: Sends messages one bit at a time and reconstructs them.

## Bonus Features

- **Client Acknowledgment**: Client receives and displays confirmation from the server.
- **Robust Error Handling**: Enhanced error checking for reliability.

## Installation

Clone the repository:

```bash
git clone https://github.com/Muddrayss/minitalk.git
```

Navigate to the project directory:

```bash
cd minitalk
```

Compile the project:

```bash
make
```

For the bonus features:

```bash
make bonus
```

## Usage

Start the server:

```bash
./server
```

The server will display its PID. Use this PID for client communication.

To send a message from the client:

```bash
./client [server_PID] [message]
```

Example:

```bash
./client 12345 "Hello, Minitalk!"
```

The server will display the received message. The client will then get a confirmation when the server has fully received the message.

## How It Works

- **Client**: Transmits each character as `SIGUSR1` and `SIGUSR2` signals. Waits for server confirmation.
- **Server**: Receives signals, reconstructs characters, displays messages, and sends confirmation signal back to the client.

## Contributing

Feel free to contribute, report issues, or suggest features on the [issues page](https://github.com/Muddrayss/minitalk/issues).