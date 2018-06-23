/*
 * Message.h
 *
 *  Created on: 17 juin 2018
 *      Author: root
 */

#ifndef CLT_COM_MESSAGE_H_
#define CLT_COM_MESSAGE_H_

/**
 * Définition de la classe Message.
 */
typedef struct
{
	char content[20];
}Message;

/**
 * Constructeur de Message
 */
Message * MessageConstructor();

/**
 * Destructeur de Message
 */
void MessageDestructor(Message * message);

#endif /* CLT_COM_MESSAGE_H_ */
