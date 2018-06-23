/*
 * Socket.c
 *
 *  Created on: 17 juin 2018
 *      Author: root
 */

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <pthread.h>
#include <assert.h>

#include "../../srv/com/Message.h"
#include "../../srv/com/Socket.h"

/**
 * Constructeur de Socket
 */
Socket * SocketConstructor()
{
	Socket * this;

	this = (Socket *) malloc(sizeof(Socket));
	this->message = MessageConstructor();

	return this;
}

/**
 * Initializes a client Socket
 */
void initServerSocket(Socket * serverSocket)
{
	/*Creation du socket : PF_INET = IP, SOCK_STREAM = TCP */
	serverSocket->id = socket (PF_INET, SOCK_STREAM, 0);
}

/**
 * Binds a socket to the communication port
 */
void bindSocket(Socket * serverSocket, int serverPort)
{
	struct sockaddr_in server;

	server.sin_family = AF_INET; /* Type d'adresse = IP */
	server.sin_port = htons (serverPort); /* Port TCP ou le service est accessible */ /* Host TO Network Short */
	server.sin_addr.s_addr = htonl (INADDR_ANY); /* On s'attache a toutes les interfaces */ /*Host TO Network Long */

	/* On attache le socket à l'adresse indiquee */
	bind (serverSocket->id, (struct sockaddr *)&server, sizeof(server));
}

/**
 * Listens to a socket making it a server socket
 */
void listenSocket(Socket * serverSocket, int maxPendingConnections)
{
	/* Mise en ecoute du socket sur une connexion */
	listen (serverSocket->id, maxPendingConnections);
}

/**
 * Accepts a socket and creates a data socket
 */
void acceptSocket(Socket * serverSocket, Socket * dataSocket)
{
	dataSocket->id = accept(serverSocket->id, NULL, 0);
}

/**
 * Reads a Message in a Socket
 */
char * readSocket(Socket * dataSocket)
{
	printf("Reading a socket\n");
	read (dataSocket->id, dataSocket->message, sizeof (*(dataSocket->message)));
/* res = ntohl (*(readerSocket->message->content));*/
	printf ("Received message : %s\n", dataSocket->message->content);
	return dataSocket->message->content;
}

/**
 * Closes a Socket
 */
int closeSocket(Socket * anySocket){
	return close(anySocket->id);
}

/**
 * Destructeur de Socket
 */
void SocketDestructor(Socket * anySocket)
{
	MessageDestructor(anySocket->message);
	free(anySocket);
}

