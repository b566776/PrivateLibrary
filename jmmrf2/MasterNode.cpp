#ifdef ARDUINO_ARCH_SAM
/*
 * MasterNode.cpp
 *
 *  Created on: 30/07/2014
 *      Author: usuario
 */

#include "MasterNode.h"
#include "StackArray.h"


void MasterNode::MasterNode(){
	this->_atencao = this->id;   //por enquanto transmissao só se inicia pelo master node


}

void MasterNode::loop()
{
	String comando = webserver.service(); //verifica se recebe comando de pagina web
    // comando é parecido com "C-S0-01-1"

	if (comando.length() > 0) {
	   while(1){
	      if (this->_atencao != id)  //por enquanto transmissao só se inicia pelo master node
	    	this->pede_atencao(id);
	      else {

	    	pilha.push({id,comando.substring(0,3),comando},3); // Node remetente, Node destinatario e String comando
   			rf.send2(pilha.pop());

   		    break;
          }
	   }
    }else
       if(!pilha.isEmpty()) this->rf.send()(pilha.pop()); // se tem mensagem transmite a mensagem

}
#endif /* ARDUINO_ARCH_SAM */
