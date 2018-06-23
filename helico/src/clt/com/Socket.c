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
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <assert.h>
#include "../../clt/com/Socket.h"
#include "../../clt/com/Message.h"

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
 * Initializes a server Socket
 */
void initClientSocket(Socket * clientSocket)
{
	/* On choisit un socket TCP (SOCK STREAM) sur IP (PF_INET) */
	clientSocket->id = socket (AF_INET, SOCK_STREAM, 0);
}

/**
 * Connects a socket to the server
 */
void connectSocket(Socket * clientSocket, char * serverIP, int serverPort)
{
	struct sockaddr_in server;

	/* AF_INET = famille TCP/IP */
	server.sin_family = PF_INET;
	/* Port du serveur auquel se connecter */
	server.sin_port = htons (serverPort);
	/* Adresse IP (ou nom de domaine) du serveur auquel se connecter */
	server.sin_addr = *((struct in_addr *)gethostbyname(serverIP) ->h_addr_list[0]);

	printf("demande de connection au serveur\n");
	connect (clientSocket->id, (struct sockaddr *)&server, sizeof(server));
}

/**
 * Writes a Message in a Socket
 */
void writeSocket(Socket * clientSocket, Message * message)
{
	strcpy(clientSocket->message->content, message->content);
	printf("writeSocket\n");
	/* On envoie envoie une donnee jusqu'a ce que le client */
	write (clientSocket->id, message, sizeof (*message));
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

