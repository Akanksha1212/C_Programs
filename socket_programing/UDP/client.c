#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "errno.h"

#define CLIENTPORT 12001
#define SERVERPORT 12000
#define SERVERIP "127.0.0.1"
#define RECVBUFFLEN 100

int main() {
	int socketid;
	char recvbuffer[RECVBUFFLEN], *message = (char *)malloc(sizeof(char)*100);
	size_t messagelen = 100;
	struct sockaddr_in serveradd;
	memset(recvbuffer, 0, RECVBUFFLEN);
	memset(message, 0, 100*sizeof(char));
	socketid = socket(PF_INET, SOCK_DGRAM, 0);
	if (socketid == -1) {
		perror("socket");
		exit(1);
	}
	printf("-->socket() success\n");
	serveradd.sin_family = AF_INET;
	serveradd.sin_port = htons(SERVERPORT);
	if(inet_pton(AF_INET, SERVERIP, &(serveradd.sin_addr)) == -1) {
		perror("inet_pton");
		exit(1);
	}
	printf("client: Enter message: ");
	getline(&message, &messagelen, stdin);
	if(sendto(socketid, message, strlen(message), 0, (struct sockaddr *)&serveradd, sizeof(serveradd)) == -1) {
		perror("send");
		exit(1);
	}
	if(recv(socketid, recvbuffer, RECVBUFFLEN, 0) == -1) {
		perror("recv");
		exit(1);
	}
	printf("client: received message: %s\n", recvbuffer);
	if (close(socketid) == -1) {
		perror("close");
	}
	return 0;
}

