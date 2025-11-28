#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 16

static int ping_pid = 0;
static int pong_count = 0;

void ping_handler(int sig) {
    printf("Received: PING\n");
    pong_count++;
    
    sleep(1);
    
    printf("PONG sent\n");
    kill(ping_pid, SIGIO);
}

void cleanup_handler(int sig) {
    printf("Pong process terminating after %d exchanges\n", pong_count);
    exit(0);
}

int main() {
    printf("Pong process started (PID: %d)\n", getpid());
    
    bsd_signal(SIGIO, ping_handler);
    bsd_signal(SIGHUP, cleanup_handler);
    
    printf("Enter Ping process PID: ");
    scanf("%d", &ping_pid);
    
    if (ping_pid <= 0) {
        fprintf(stderr, "Invalid PID\n");
        return 1;
    }
    
    printf("Waiting for PING from process %d\n", ping_pid);
    
    while (1) {
        pause();
    }
    
    return 0;
}