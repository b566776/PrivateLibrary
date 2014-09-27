#ifdef ARDUINO_ARCH_SAM
/*
 * Node.h
 *
 *  Created on: 30/07/2014
 *      Author: usuario
 */

#ifndef NODE_H_
#define NODE_H_

#include "Arduino.h"
#include "JmmRf.h"
#include "StackArray.h"

class Node {

public:
	typedef struct
		{
			String id_objeto;
			int acao;
			int pino;
			int seq_ir_code[];
		} Comando;

	void Node(String id, Comando* comandos[], bool debug);

	Comando comandos[];

	String id;


	bool pede_atencao(String id);
	bool send_msg(StackArray mensagem);
	void executa(String mensagem);
	void loop();
	void escutaTransmissao();
	void ajuste_pinos();
	void setup();

	
private:
	String _atencao;
	bool _debug;
};


#endif /*NODE_H_ */

#endif /* ARDUINO_ARCH_SAM */
