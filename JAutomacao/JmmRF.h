#ifdef ARDUINO_ARCH_SAM

#ifndef COMANDO_H
#define COMANDO_H

#include <string>

/**
  * class Comando
  * Estrutura da mensagem
  * 
  *  R-LL-nn-n
  *     |  |  | |
  *     |  |  | ---- Ação 1 = liga    / +
  *     |  |  |           0 = desliga / -
  *     |  |  |
  *     |  |  ------ Segquencial do objeto a ser comandado
  *     |  |
  *     |  --------- Local S0 = Suite
  *     |                  Q1 .... Q3 = Quartos 1, 2 e 3
  *     |                  Sl = sala
  *     |                  Cz = Cozinha
  *     |                  Ir = Irrigação ponto 1
  *     |
  *     ------------ Região C = Casa
  *                     Q = Quintal (fim do terreno)
  * 	M = Meio do Terreno
  * 	I = Inicio do Terreno
  * 	A = Mensagem do sistema de alarme
  * 
  */

class Comando
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Comando ( );

  /**
   * Empty Destructor
   */
  virtual ~Comando ( );

  // Static Public attributes
  //  

  // Public attributes
  //  

  // Segquencial do objeto a ser comandado 
  unsigned short seq_objeto;
  // Ação 1 = liga    / +
  //     |  |  |           0 = desliga / -
  unsigned short acao;
  // numero do pino saida digital do objeto a ser comandado pelo arduino 
  bool pin;
  string seq_ir_code;

  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


  /**
   * Set the value of seq_objeto
   * Segquencial do objeto a ser comandado
   * @param new_var the new value of seq_objeto
   */
  void setSeq_objeto ( unsigned short new_var )   {
      seq_objeto = new_var;
  }

  /**
   * Get the value of seq_objeto
   * Segquencial do objeto a ser comandado
   * @return the value of seq_objeto
   */
  unsigned short getSeq_objeto ( )   {
    return seq_objeto;
  }

  /**
   * Set the value of acao
   * Ação 1 = liga    / +
   *     |  |  |           0 = desliga / -
   * @param new_var the new value of acao
   */
  void setAcao ( unsigned short new_var )   {
      acao = new_var;
  }

  /**
   * Get the value of acao
   * Ação 1 = liga    / +
   *     |  |  |           0 = desliga / -
   * @return the value of acao
   */
  unsigned short getAcao ( )   {
    return acao;
  }

  /**
   * Set the value of pin
   * numero do pino saida digital do objeto a ser comandado pelo arduino
   * @param new_var the new value of pin
   */
  void setPin ( bool new_var )   {
      pin = new_var;
  }

  /**
   * Get the value of pin
   * numero do pino saida digital do objeto a ser comandado pelo arduino
   * @return the value of pin
   */
  bool getPin ( )   {
    return pin;
  }

  /**
   * Set the value of seq_ir_code
   * @param new_var the new value of seq_ir_code
   */
  void setSeq_ir_code ( string new_var )   {
      seq_ir_code = new_var;
  }

  /**
   * Get the value of seq_ir_code
   * @return the value of seq_ir_code
   */
  string getSeq_ir_code ( )   {
    return seq_ir_code;
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  

private:


  void initAttributes ( ) ;

};

#endif // COMANDO_H


#ifndef JMMRF_H
#define JMMRF_H

#include <string>

/**
  * class JmmRF
  * 
  */

class JmmRF
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  JmmRF ( );

  /**
   * Empty Destructor
   */
  virtual ~JmmRF ( );

  // Static Public attributes
  //  

  // Public attributes
  //  

  bool tem_mensagem;
  unsigned short _pinRx;
  unsigned short _pinTx;
  unsigned short pinInterrupt;
  // pino de alimentação do modulo receptor do node
  unsigned short _pinHdRX;
  bool feedback;

  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


  /**
   * Set the value of tem_mensagem
   * @param new_var the new value of tem_mensagem
   */
  void setTem_mensagem ( bool new_var )   {
      tem_mensagem = new_var;
  }

  /**
   * Get the value of tem_mensagem
   * @return the value of tem_mensagem
   */
  bool getTem_mensagem ( )   {
    return tem_mensagem;
  }

  /**
   * Set the value of _pinRx
   * @param new_var the new value of _pinRx
   */
  void set_pinRx ( unsigned short new_var )   {
      _pinRx = new_var;
  }

  /**
   * Get the value of _pinRx
   * @return the value of _pinRx
   */
  unsigned short get_pinRx ( )   {
    return _pinRx;
  }

  /**
   * Set the value of _pinTx
   * @param new_var the new value of _pinTx
   */
  void set_pinTx ( unsigned short new_var )   {
      _pinTx = new_var;
  }

  /**
   * Get the value of _pinTx
   * @return the value of _pinTx
   */
  unsigned short get_pinTx ( )   {
    return _pinTx;
  }

  /**
   * Set the value of pinInterrupt
   * @param new_var the new value of pinInterrupt
   */
  void setPinInterrupt ( unsigned short new_var )   {
      pinInterrupt = new_var;
  }

  /**
   * Get the value of pinInterrupt
   * @return the value of pinInterrupt
   */
  unsigned short getPinInterrupt ( )   {
    return pinInterrupt;
  }

  /**
   * Set the value of _pinHdRX
   * pino de alimentação do modulo receptor do node
   * @param new_var the new value of _pinHdRX
   */
  void set_pinHdRX ( unsigned short new_var )   {
      _pinHdRX = new_var;
  }

  /**
   * Get the value of _pinHdRX
   * pino de alimentação do modulo receptor do node
   * @return the value of _pinHdRX
   */
  unsigned short get_pinHdRX ( )   {
    return _pinHdRX;
  }

  /**
   * Set the value of feedback
   * @param new_var the new value of feedback
   */
  void setFeedback ( bool new_var )   {
      feedback = new_var;
  }

  /**
   * Get the value of feedback
   * @return the value of feedback
   */
  bool getFeedback ( )   {
    return feedback;
  }


  /**
   * @return bool
   * @param  mensagem
   */
  bool send (Mensagem mensagem )
  {
    
    mensagem += "#";
    
    //desliga pino de alimentação do hardware receptor do node
    digitalWrite(_pinHdRX,LOW);
    for(int j=0;j < mensagem.length();j++){
        input = mensagem[i];
         //sincronismo
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
    
         //transmite byte
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
    }// for j
    digitalWrite(_pinHdRX,HIGH);
    //interrupt(true);
    return(true);
  }


  /**
   * chamada atravez de
   * 
   * void interrupt(){
   *   detachInterrupt(automacao.pinInterrupt);
   *   automacao.data_incoming();
   *   attachInterrupt(automacao.pinInterrupt,interrupt,RISING);
   * }
   * @return bool
   * @param  mensagem
   */
  bool receive (Mensagem mensagem )
  {
    //data_incoming()
    int i;
    byte data_in;
    
    while(1){
      if(digitalRead(1)==LOW){
    	delayMicroseconds(750);
    
    	for(i=0; i<8; i++){
    	  if(digitalRead(1)==HIGH)
    		bitWrite(data_in, i, 1);
    	  else
    		bitWrite(data_in, i, 0);
    
    	  delayMicroseconds(1000);// = 500 + 500 microsegundos na transmissão
    	}//for
    
    	if(data_in=='#'){
    		tem_msg = true;
    		//if (feedback) Serial.println("");
    		Serial.println("mensagem: "+msg);
    	}
    	else {
    		//if (feedback) Serial.print(char(data_in));
    		Serial.print(char(data_in));
    		tem_msg = false;
    		msg = msg + char(data_in);
    	}
    	break;//while
      }//low kickoff
    
    }// while
  }


  /**
   */
  void processar_fila ( )
  {
  }


  /**
   */
  void ajuste_pinos ( )
  {
    pinMode(_pinTx, OUTPUT);
      pinMode(_pinRx, INPUT);
      //pinMode(13, OUTPUT);
      pinMode(_pinHdRX, OUTPUT);
      digitalWrite(_pinHdRX,HIGH); // liga alimentacao do modulo receptor
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

  FilaMensagem fila;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of fila
   * @param new_var the new value of fila
   */
  void setFila ( FilaMensagem new_var )   {
      fila = new_var;
  }

  /**
   * Get the value of fila
   * @return the value of fila
   */
  FilaMensagem getFila ( )   {
    return fila;
  }
private:


  void initAttributes ( ) ;

};

#endif // JMMRF_H
#endif /* ARDUINO_ARCH_SAM */
