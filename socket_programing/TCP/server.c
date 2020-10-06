#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "errno.h"

#define SERVERPORT 3040
#define LISTENLIMIT 5
#define RECVBUFFLEN 100

int main() {
	struct sockaddr_in serveradd, clientadd[LISTENLIMIT];
	int bindsocket, acceptsocket, recvbytes;
	socklen_t clientaddsize;
	char *message = "Hello client. Message from server\n";
	char receivebuffer[RECVBUFFLEN];

	memset(receivebuffer, 0, RECVBUFFLEN);
	clientaddsize = sizeof(struct sockaddr_in);

	bindsocket = socket(PF_INET, SOCK_STREAM, 0);
	if (bindsocket == -1) {
		perror("socket");
		exit(1);
	}
	serveradd.sin_family = AF_INET;
	serveradd.sin_port = htons(SERVERPORT);
	serveradd.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(bindsocket, (struct sockaddr *)&serveradd, sizeof(serveradd)) == -1) {
		perror("bind");
		exit(1);
	}
	if (listen(bindsocket, LISTENLIMIT) == -1) {
		perror("listen");
		exit(1);
	}
	acceptsocket = accept(bindsocket, (struct sockaddr *)&clientadd, &clientaddsize);
	printf("\nConnection started with client on socketid: %d. Waiting for acknowledgement from client\n", acceptsocket);
	if(send(acceptsocket, message, strlen(message), 0) == -1) {
		perror("send");
		exit(1);
	}
	if((recvbytes = recv(acceptsocket, receivebuffer, RECVBUFFLEN, 0)) <= 0) {
		if (recvbytes == 0) {
			printf("Connection closed by socket %d.\n", acceptsocket);
		}
		else {
			perror("recv");
		}
		exit(1);
	}
	printf("\nAcknowledgement from client: %s\n", receivebuffer);
	if (close(acceptsocket) == -1) {
		perror("close");
	}
	if (close(bindsocket) == -1) {
		perror("close");
	}
	else {
		printf("\nServer operation successful. Closing server..\n");
	}
	return 0;
}
