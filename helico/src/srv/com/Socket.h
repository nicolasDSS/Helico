/*
 * Socket.h
 *
 *  Created on: 17 juin 2018
 *      Author: root
 */

#ifndef SRV_COM_SOCKET_H_
#define SRV_COM_SOCKET_H_

#include "../../srv/com/Message.h"

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
 * Initializes a client Socket
 */
void initServerSocket(Socket * serverSocket);

/**
 * Binds a socket to the communication port
 */
void bindSocket(Socket * serverSocket, int serverPort);

/**
 * Listens to a socket making it a server socket
 */
void listenSocket(Socket * serverSocket, int maxPendingConnections);

/**
 * Accepts a socket and creates a data socket
 */
void acceptSocket(Socket * serverSocket, Socket * dataSocket);

/**
 * Reads a Message in a Socket
 */
char * readSocket(Socket * dataSocket);

/**
 * Closes a Socket
 */
int closeSocket(Socket * anySocket);

/**
 * Destructeur de Socket
 */
void SocketDestructor(Socket * anySocket);


#endif /* SRV_COM_SOCKET_H_ */
