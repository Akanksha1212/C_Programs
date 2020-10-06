#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "errno.h"

#define SERVERPORT 6969
#define LISTENLIMIT 5
#define RECVBUFFLEN 100
#define MAXCLIENTS 10

int main() {
	struct sockaddr_in serveradd, clientadd[LISTENLIMIT];
	int bindsocket, acceptsocket, recvbytes, fdmax, clients[MAXCLIENTS], top = 0;
	socklen_t clientaddsize;
	fd_set readfds;
	fd_set tempfds;
	char receivebuffer[RECVBUFFLEN];

	memset(receivebuffer, 0, RECVBUFFLEN);
	for (int i = 0; i < MAXCLIENTS; i += 1) {
		clients[i] = 0;
	}
	FD_ZERO(&readfds);
	FD_ZERO(&tempfds);
	clientaddsize = sizeof(struct sockaddr_in);

	bindsocket = socket(PF_INET, SOCK_STREAM, 0);
	if (bindsocket == -1) {
		perror("socket");
		exit(1);
	}
	printf("-->socket() success\n");
	serveradd.sin_family = AF_INET;
	serveradd.sin_port = htons(SERVERPORT);
	serveradd.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(bindsocket, (struct sockaddr *)&serveradd, sizeof(serveradd)) == -1) {
		perror("bind");
		exit(1);
	}
	FD_SET(bindsocket, &readfds);
	FD_SET(bindsocket, &tempfds);
	printf("-->bind() success\n");
	if (listen(bindsocket, LISTENLIMIT) == -1) {
		perror("listen");
		exit(1);
	}
	printf("-->listen() success\n");
	fdmax = bindsocket;

	while(1) {
		tempfds = readfds;
		if (select(fdmax+1, &tempfds, NULL, NULL, NULL) == -1) {
			perror("select");
			exit(1);
		}
		if (FD_ISSET(bindsocket, &tempfds)) {
			printf("new connection request received\n");
			acceptsocket = accept(bindsocket, (struct sockaddr *)&clientadd, &clientaddsize);
			FD_SET(acceptsocket, &readfds);
			clients[top] = acceptsocket;
			top += 1;
			printf("\nConnection started with client on socket: %d\n", acceptsocket);
			if (acceptsocket > fdmax) {
				fdmax = acceptsocket;
			}
			printf("connection established on socket: %d\n", acceptsocket);
		} else {
			for (int i = 0; i < MAXCLIENTS; i += 1) {
				if (FD_ISSET(clients[i], &tempfds)) {
					if((recvbytes = recv(clients[i], receivebuffer, RECVBUFFLEN, 0)) <= 0) {
						if (recvbytes == 0) {
							clients[i] = 0;
							printf("Connection closed by socket %d.\n", acceptsocket);
							close(clients[i]);
							FD_CLR(clients[i], &readfds);
							FD_CLR(clients[i], &tempfds);
							continue;
						}
						perror("recv");
						exit(1);
					} else {
						printf("Message received by client %d: %s\n", i, receivebuffer);
						if(send(clients[i], receivebuffer, strlen(receivebuffer), 0) == -1) {
							perror("send");
							exit(1);
						}
						memset(receivebuffer, 0, RECVBUFFLEN);
					}
				}
			}
		}
	}
	return 0;
}
