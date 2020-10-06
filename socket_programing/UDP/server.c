#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "errno.h"

#define SERVERPORT 3040
//#define LISTENLIMIT 5
#define RECVBUFFLEN 100

int main() {
	struct sockaddr_in serveradd;
	struct sockaddr clientadd;
	int bindsocket, recvbytes;
	socklen_t clientaddsize;
	char receivebuffer[RECVBUFFLEN];

	memset(receivebuffer, 0, RECVBUFFLEN);
	clientaddsize = sizeof(struct sockaddr_in);

	bindsocket = socket(PF_INET, SOCK_DGRAM, 0);
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
	if((recvbytes = recvfrom(bindsocket, receivebuffer, RECVBUFFLEN, 0, &clientadd, &clientaddsize)) <= 0) {
		if (recvbytes == -1) {
			perror("recvfrom");
		}
		exit(1);
	}
	if(sendto(bindsocket, receivebuffer, strlen(receivebuffer), 0, &clientadd, clientaddsize) == -1) {
		perror("sendto");
		exit(1);
	}
	if (close(bindsocket) == -1) {
		perror("close");
	}
	else {
		printf("\nServer operation successful. Closing server..\n");
	}
	return 0;
}
