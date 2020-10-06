#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "errno.h"

#define CLIENTPORT 12001
#define SERVERPORT 3040
#define SERVERIP "127.0.0.1"
#define RECVBUFFLEN 100

int main() {
	int socketid;
	char recvbuffer[RECVBUFFLEN], *message = "Hi, this is client\n";
	struct sockaddr_in serveradd;
	memset(recvbuffer, 0, RECVBUFFLEN);
	socketid = socket(PF_INET, SOCK_STREAM, 0);
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
	//if (connect(socketid, (struct sockaddr *)&serveradd, sizeof(struct sockaddr)) == -1) {
	if (connect(socketid, (struct sockaddr *)&serveradd, INET_ADDRSTRLEN) == -1) {
		perror("connect");
		exit(1);
	}
	printf("-->connect() success\n");
	printf("-->connect() success\tip: %s\tport: %d\n", SERVERIP, SERVERPORT);
	//	if(recv(socketid, recvbuffer, RECVBUFFLEN, 0) == -1) {
	//		perror("recv");
	//		exit(1);
	//	}
	//	printf("received message: %s\n", recvbuffer);
	if(send(socketid, message, strlen(message), 0) == -1) {
		perror("send");
		exit(1);
	}
	if (close(socketid) == -1) {
		perror("close");
	}
	return 0;
}

