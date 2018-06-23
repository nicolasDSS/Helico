/*
 * Message.c
 *
 *  Created on: 17 juin 2018
 *      Author: root
 */


#include "../../clt/com/Message.h"
#include <stdlib.h>

Message * MessageConstructor()
{
	Message * this;

	this = (Message *) malloc(sizeof(Message));

	return this;
}

void MessageDestructor(Message * message)
{
	free(message);
}
