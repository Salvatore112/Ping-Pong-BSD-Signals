all: ping pong

ping: ping.c
	gcc -g -o ping ping.c

pong: pong.c
	gcc -g -o pong pong.c

clean:
	rm -f ping pong