## Build

```bash
make
```

## Run

First, run `./pong` in one terminal, you'll see

```bash
Pong process started (PID: 65619)
Enter Ping process PID: 
```

Second, run `./ping` in another terminal that should give you

```bash
Ping process started (PID: 66117)
Enter Pong process PID: 
```

Finally, enter Ping's PID to Pong. After that enter Pong's PID to Ping.

Here's what you should expect to see:

Pong's terminal

```bash
./pong
Pong process started (PID: 66107)
Enter Ping process PID: 66117
Waiting for PING from process 66117
Received: PING
PONG sent
Received: PING
PONG sent
Received: PING
PONG sent
Received: PING
PONG sent
Received: PING
PONG sent
Received: PING
PONG sent
Received: PING
PONG sent
Received: PING
PONG sent
Received: PING
PONG sent
Received: PING
PONG sent
Terminated
```

Ping's terminal

```bash
./ping 
Ping process started (PID: 66117)
Enter Pong process PID: 66107
Starting PING-PONG exchange with process 66107
PING sent
Received: PONG
PING sent
Received: PONG
PING sent
Received: PONG
PING sent
Received: PONG
PING sent
Received: PONG
PING sent
Received: PONG
PING sent
Received: PONG
PING sent
Received: PONG
PING sent
Received: PONG
PING sent
Received: PONG
Ping finished after 10 exchanges
```

Note: Your PID's most likely will be different from the ones used in this example.