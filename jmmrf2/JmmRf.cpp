#ifdef ARDUINO_ARCH_SAM
/*
 * JmmRf.cpp
 *
 *  Created on: 18/08/2014
 *      Author: usuario
 */

#include <Arduino.h>
#include "JmmRf.h"

void JmmRf::JmmRf(int pinRx, int pinTx, int pinInterrupt, bool debug){
	this->_pinRx = pinRx;
    this->_pinTx = pinTx;
    this->pinInterrupt = pinInterrupt;
	this->_debug = debug;
	mensagem = "";
	temMensagem = false;

	// ajuste de pinos
	pinMode(this->_pinRx, INPUT);
	pinMode(this->_pinTx, OUTPUT);

	if(this->_debug) Serial.println("JmmRF::JmmRF - ok");

}

/*
 * {
		  String remetente;
	      String destinatario;
	      String comando;
	    }
 */

void JmmRf::send2(String item[]){
    String msg =  item[0] +"-"+item[1]+"-"+item[2];
	for (int i = 0; i < msg.length()+1; i++){
		_rfSend(msg.charAt(i));
    }
	_rfSend('#');

	if(this->_debug) Serial.println("JmmRF::send - ok -> "+msg);
}

bool JmmRf::receive(){

	if (temMensagem ) {
		if(this->_debug) Serial.println("JmmRF::receive() - temMensagem");
		return true;
	}
	else{
		if(this->_debug) Serial.println("JmmRF::receive() - NAOtemMensagem");
		return false;
	}

}


void JmmRf::_rfSend(char ch){
  byte input  = (byte)ch;
  int i;

  for(i=0; i<20; i++){
	digitalWrite(_pinTx, HIGH);
	delayMicroseconds(500);
	digitalWrite(_pinTx, LOW);
	delayMicroseconds(500);
  }

  digitalWrite(_pinTx, HIGH);
  delayMicroseconds(3000);
  digitalWrite(_pinTx, LOW);
  delayMicroseconds(500);


  for(i=0; i<8; i++){
	if(bitRead(input,i)==1)
		digitalWrite(_pinTx, HIGH);
	else
		digitalWrite(_pinTx, LOW);
	
	delayMicroseconds(500);
	
	if(bitRead(input,i)==1)
		digitalWrite(_pinTx, LOW);
	else
		digitalWrite(_pinTx, HIGH);
	
	delayMicroseconds(500);
}//i


  digitalWrite(_pinTx, LOW);
}


void JmmRf::dataIncoming(){
	byte data_in;
	int i, good, k;

    for(i=0; i<100; i++){
      delayMicroseconds(20);
      good=1;
      if(digitalRead(_pinRx)==LOW){
      good=0;
      i=100;
      }
    }//for

    if(good==1){
    //detachInterrupt(1);
      while(1){
		  if(digitalRead(_pinRx)==LOW){
			delayMicroseconds(750);

			for(i=0; i<8; i++){
			  if(digitalRead(_pinRx)==HIGH)
			  bitWrite(data_in, i, 1);
			  else
			  bitWrite(data_in, i, 0);
			  delayMicroseconds(1000);
			}//for
			if(data_in=='#'){
			  if (_debug) Serial.println("");
			  temMensagem = true;
			}
			else {
			  if (_debug) Serial.print(char(data_in));
			  temMensagem = false;
			}


			mensagem += data_in;

		    break;//secondtwhile
          }//low kickoff

      }//while

    }//good check

    //attachInterrupt(1,data_incoming,RISING);

}
#endif /* ARDUINO_ARCH_SAM */
