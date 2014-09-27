#ifdef ARDUINO_ARCH_SAM
/*
 * MasterNode.h
 *
 *  Created on: 30/07/2014
 *      Author: usuario
 */

#ifndef MASTERNODE_H_
#define MASTERNODE_H_

#include "Node.h"
#include "WebServer.h"



class MasterNode : public Node
{
	public:
		void MasterNode();
	    WebServer webserver;
	    StackArray pilha;

		void setup();
		void loop();
};

#endif /* MASTERNODE_H_ */
#endif /* ARDUINO_ARCH_SAM */
