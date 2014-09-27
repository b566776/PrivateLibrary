#ifdef ARDUINO_ARCH_SAM
/*
 * Node.cpp
 *
 *  Created on: 30/07/2014
 *      Author: usuario
 */

#include "Node.h"

#include "Comando.h"

extern HardwareSerial Serial;


void Node::Node (String id, Comando* comandos[], bool debug){
	this->id = id;
	&this->comandos = *comandos;
	this->_debug = debug;
	this->_atencao = "C-00";

	StackArray pilha;
	JmmRf rf(2, 3, 0, true); // pinRx, pinTx, pinInterrupt e debug


};

bool Node::pede_atencao (String id) {
    // por enquanto so master transmite
	return(true);
}

void Node::ajuste_pinos(){

	if (sizeof(this->comandos) > 0 ){
		if(this->_debug) Serial.println("Ajustando pinagem: ");
		for (int i = 0; i < sizeof(this->comandos)-1; i++){
		   pinMode(this->comandos[i].pino, OUTPUT);
		  if(this->_debug) Serial.print(this->comandos[i].pino+" ");
	    };

	    if(this->_debug) Serial.println("Fim de Ajuste.");
    }
}

/*
void Node::escutaTransmissao(){
  comando = rf.receive();
}
*/
void Node::loop(){
	// executa comando recebido

    if( rf.receive()){
		executa(rf.mensagem);
    }


	// se mensagem tem o destinatario deste node executa mensagem

}


bool Node::send_msg(StackArray mensagem){

	 return true;
}

void Node::executa(String mensagem){
	//serializa
	// mensagem "C-S0-01-1"
	String comando[] = {mensagem.substring(0,3),mensagem.substring(5,6), mensagem.substring(8,8)};
	if(this->id == comando[0]){
		for(int i=0; i < sizeof(this->comandos) +1 ;i++){
			if (this->comandos[i].id_objeto == comando[1]){
				if(this->comandos[i].seq_ir_code == NULL){
					// executa ação
					digitalWrite(this->comandos[i].pino,this->comandos[i].acao);
					if(_debug) Serial.println("enviar código infra red para o pino "+this->comandos[i].pino);
				}else
					if(_debug) Serial.println("enviar código infra red para o pino "+this->comandos[i].pino);
			}
		}
    }else if(_debug) Serial.println("Node::executa - comando não é para este node /n Node: "+id+"/n Destinatario: "+comando[0] );

}


void Node::setup(){

}
#endif /* ARDUINO_ARCH_SAM */
