#ifdef ARDUINO_ARCH_SAM
/*
 * WebServer.cpp
 *
 *  Created on: 30/07/2014
 *      Author: usuario
 */

#include "WebServer.h"
#include <Ethernet.h>


void WebServer::WebServer(byte ip[],byte gateway[], byte subnet[]){
	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //physical mac address
	this->ip = {192,168,1,178};                      // ip in lan (that's what you need to use in your browser. ("192.168.1.178")
	this->gateway = { 192, 168, 1, 1 };                   // internet access via router
	this->subnet = { 255, 255, 255, 0 };                  //subnet mask
	EthernetServer server(80);   //server port
	server.begin();
	EthernetClient client = server.available();
}




String WebServer::service(){

	String msg2 = "";

	  if (client) {
	    while (client.connected()) {
	      if (client.available()) {
	        char c = client.read();

	        //read char by char HTTP request
	        if (readString.length() < 100) {
	          //store characters to string
	          readString += c;
	          //Serial.print(c);
	         }

	         //if HTTP request has ended
	         if (c == '\n') {
	           Serial.println(readString); //print to serial monitor for debuging

	           client.println("HTTP/1.1 200 OK"); //send new page
	           client.println("Content-Type: text/html");
	           client.println();
	           client.println("<HTML>");
	           client.println("<HEAD>");
	           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
	           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
	           client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
	           client.println("<TITLE>Random Nerd Tutorials Project</TITLE>");
	           client.println("</HEAD>");
	           client.println("<BODY>");
	           client.println("<H1>Random Nerd Tutorials Project</H1>");
	           client.println("<hr />");
	           client.println("<br />");
	           client.println("<H2>Arduino with Ethernet Shield</H2>");
	           client.println("<br />");
	           client.println("Luz da suite: ");
	           client.println("<a href=\"/?buttonLuzSuiteOn\"\">Liga</a>");
	           client.println("<a href=\"/?buttonLuzSuiteOff\"\">Desliga</a><br />");
	           client.println("<br />");
	           client.println("<br />");
	           client.println("Ar Condicionado: ");
	           client.println("<a href=\"/?buttonArOn\"\">Liga</a>");
	           client.println("<a href=\"/?buttonArOff\"\">Desliga</a><br />");
	           client.println("<p>Created by Rui Santos. Visit http://randomnerdtutorials.com for more projects!</p>");
	           client.println("<br />");
	           client.println("</BODY>");
	           client.println("</HTML>");

	           delay(1);
	           //stopping client
	           client.stop();


	           if (readString.indexOf("?buttonLuzSuiteOn") > 0){ //liga luz da suite
	        	   msg2 = "C-S0-01-1";
	           }
	           if (readString.indexOf("?buttonLuzSuiteOff") > 0){ //deslia a luz da suite
	        	   msg2 = "C-S0-01-0";
	           }
	           if (readString.indexOf("?buttonLuzArOn") > 0){ //liga ar condicionado
	        	   msg2 = "C-S0-02-1";
	           }
	           if (readString.indexOf("?buttonLuzArOff") > 0){ //deslia ar condicionado
	        	   msg2 = "C-S0-02-1";
	           }
	         }
	     }
	 }
   }
  return(msg2);
}
#endif /* ARDUINO_ARCH_SAM */
