#ifdef ARDUINO_ARCH_SAM
/*
 * JmmRf.h
 *
 *  Created on: 18/08/2014
 *      Author: usuario
 */

#ifndef JMMRF_H_
#define JMMRF_H_




class JmmRf {
public:
	void send2(String item[]);
	bool receive();
	void dataIncoming();


	void JmmRf(int pinRx, int pinTx, int pinInterrupt, bool debug);

	int pinInterrupt;
	String mensagem;
	bool temMensagem;

private:
	//void ajuste_pinos();
	void _rfSend(char ch);


    int _pinRx;
    int _pinTx;
    bool _debug;
};

#endif /* JMMRF_H_ */
#endif /* ARDUINO_ARCH_SAM */
