#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFER_SIZE 16

static int pong_pid = 0;
static int ping_count = 0;

void pong_handler(int sig) {
    printf("Received: PONG\n");
    ping_count++;
    
    sleep(1);
    
    if (ping_count < 10) {
        printf("PING sent\n");
        kill(pong_pid, SIGIO);
    } else {
        printf("Ping finished after %d exchanges\n", ping_count);
        kill(pong_pid, SIGTERM);
        exit(0);
    }
}

void cleanup_handler(int sig) {
    printf("Ping process terminating\n");
    if (pong_pid > 0) {
        kill(pong_pid, SIGTERM);
    }
    exit(0);
}

int main() {
    printf("Ping process started (PID: %d)\n", getpid());
    
    bsd_signal(SIGIO, pong_handler);
    bsd_signal(SIGHUP, cleanup_handler);
    
    printf("Enter Pong process PID: ");
    scanf("%d", &pong_pid);
    
    if (pong_pid <= 0) {
        fprintf(stderr, "Invalid PID\n");
        return 1;
    }
    
    printf("Starting PING-PONG exchange with process %d\n", pong_pid);
    
    sleep(1);
    printf("PING sent\n");
    kill(pong_pid, SIGIO);
    
    while (1) {
        pause();
    }
    
    return 0;
}