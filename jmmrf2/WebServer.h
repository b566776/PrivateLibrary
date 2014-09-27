#ifdef ARDUINO_ARCH_SAM
/*
 * WebServer.h
 *
 *  Created on: 30/07/2014
 *      Author: usuario
 */

#ifndef WEBSERVER_H_
#define WEBSERVER_H_

#include <Ethernet.h>

class WebServer
{
	public:
	    void WebServer(byte ip[],byte gateway[], byte subnet[]);
	    String readString;



	    String service();


	private:
	    byte ip[] ;                      // ip in lan (that's what you need to use in your browser. ("192.168.1.178")
		byte gateway[];                   // internet access via router
		byte subnet[];

		 EthernetClient client;
};


#endif /* WEBSERVER_H_ */
#endif /* ARDUINO_ARCH_SAM */
