/*
 * Main.c
 *
 *  Created on: 17 juin 2018
 *      Author: root
 */

#include "../clt/com/Socket.h"
#include "../clt/com/Message.h"
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

#define LOCALHOST "127.0.0.1"
#define SERVER_PORT (12345)
#define SOCKET_TIMEOUT (10)

int main (void)
{
	Socket * clientSocket = SocketConstructor();
	Message * message = MessageConstructor();

	initClientSocket(clientSocket);

	connectSocket(clientSocket, LOCALHOST, SERVER_PORT);

	strcpy(message->content, "Some data maaaaaan!");
	writeSocket(clientSocket, message);
	MessageDestructor(message);

	closeSocket(clientSocket);

	SocketDestructor(clientSocket);

	return 0;
}
