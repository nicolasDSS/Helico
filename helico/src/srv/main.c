/*
 * Main.c
 *
 *  Created on: 17 juin 2018
 *      Author: root
 */

#include "../srv/com/Socket.h"

#define SERVER_PORT (12345)

int main (void)
{
	Socket * serverSocket = SocketConstructor();
	Socket * dataSocket = SocketConstructor();

	initServerSocket(serverSocket);

	bindSocket(serverSocket, SERVER_PORT);

	listenSocket(serverSocket, 1);

	acceptSocket(serverSocket, dataSocket);

	readSocket(dataSocket);

	closeSocket(dataSocket);
	closeSocket(serverSocket);

	SocketDestructor(dataSocket);
	SocketDestructor(serverSocket);

	return 0;
}
