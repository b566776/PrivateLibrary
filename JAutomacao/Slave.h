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


#ifndef SLAVE_H
#define SLAVE_H
#include "Node.h"

#include <string>

/**
  * class Slave
  * 
  */

class Slave : public Node
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Slave ( );

  /**
   * Empty Destructor
   */
  virtual ~Slave ( );

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  


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



};

#endif // SLAVE_H
#endif /* ARDUINO_ARCH_SAM */
