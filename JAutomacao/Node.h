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


#ifndef NODE_H
#define NODE_H

#include <string>

/**
  * class Node
  * 
  */

class Node
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Node ( );

  /**
   * Empty Destructor
   */
  virtual ~Node ( );

  // Static Public attributes
  //  

  // Public attributes
  //  

  string id;

  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


  /**
   * Set the value of id
   * @param new_var the new value of id
   */
  void setId ( string new_var )   {
      id = new_var;
  }

  /**
   * Get the value of id
   * @return the value of id
   */
  string getId ( )   {
    return id;
  }


  /**
   * @return bool
   */
  bool handsUp ( )
  {
  }


  /**
   * @return bool
   * @param  mensagem
   */
  bool send_msg (Mensagem mensagem )
  {
  }


  /**
   * @param  comando
   */
  void executa (Comando comando )
  {
    	//interrupt(false);  // desliga recepção
    	if (node == "C-00"){
    		if (msg.indexOf("at") == 0)
    			//atende pedido de atencao
    			set_atencao(node);
    		    if(feedback) Serial.println("Executando solicao at. Atenção para "+_atencao);
    			for(int i=0; i<3;i++) {
    				rf_send("AT"+msg.substring(2), node);
    				delay(500);
    			}
    			return("");
    		//else //ser for Master e não for pedido de atenção
    	} // fim das tarefas executadas pelo master
    	else { // inicio das tarefas a serem executadas por transceiver e slaves
    		if (msg.indexOf("AT")){ // se for comado AT
    		  _atencao = msg.substring(3);
    		  if(feedback) Serial.println("Setup de Atenção para AT"+_atencao);
    		}
    		else { // verifica se mensagem esta contida em controles para este nome especifico
    			int _pin;
    			for(int i=0; i < sizeof(controles)-1 ; i++){
    				if (controles[i][0].indexOf(node) > 0){ // msg é para este node ?
    					_pin = controles[i][1].toInt();
    					if(controles[i][2]==""){ // nao tem comando infra vermelho
    						digitalWrite(_pin,controles[i][1].substring(8).toInt());
    						if(feedback) Serial.println("Executando comando para pino "+controles[i][1]+ " para "+ controles[i][1].substring(8));
    					}
    					//else
    						//comando de Infra vermelho -> controles[i][3]
    					//}
    					//comando exectado
    					//interrupt(true);
    					//msg = "";
    					return (controles[i][1]);
    				}// if(controles[i][1] == msg)
    			}// for
    		}
    	}
    	msg = ""; // msg é para outro node
    	tem_msg = false;
    	if(feedback) Serial.println("'tem_msg' = false");
    	//interrupt(true);
    	return ("");
  }


  /**
   */
  void loop ( )
  {
  }


  /**
   */
  void escutaTransmissao ( )
  {
  }


  /**
   * ajusta pinos do node
   */
  void ajuste_pinos ( )
  {
    if (sizeof(controles) > 0 )
    	if(feedback) Serial.println("Ajustando pinagem: ");
    	for (int i = 0; i < sizeof(controles)-1; i++){
    	   pinMode(controles[i][1].toInt(),OUTPUT);
    	  if(feedback) Serial.print(controles[i][1]+" ");
    };
    if(feedback) Serial.println("Fim de Ajuste.");
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

#endif // NODE_H
#endif /* ARDUINO_ARCH_SAM */
