/*
 * Socket.h
 *
 *  Created on: 17 juin 2018
 *      Author: root
 */

#ifndef CLT_COM_SOCKET_H_
#define CLT_COM_SOCKET_H_

#include "../../clt/com/Message.h"

/**
 * Définition de la classe Socket
 */
typedef struct
{
	int id;
	Message * message;
}Socket;

/**
 * Constructeur de Socket
 */
Socket * SocketConstructor();

/**
 * Initializes a server Socket
 */
void initClientSocket(Socket * clientSocket);

/**
 * Connects a socket to the server
 */
void connectSocket(Socket * clientSocket, char * serverIP, int serverPort);

/**
 * Writes a Message in a Socket
 */
void writeSocket(Socket * clientSocket, Message * message);

/**
 * Closes a Socket
 */
int closeSocket(Socket * anySocket);

/**
 * Destructeur de Socket
 */
void SocketDestructor(Socket * anySocket);


#endif /* C_CLT_COM_SOCKET_H_ */
