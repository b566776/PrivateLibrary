#ifdef ARDUINO_ARCH_SAM
#include "Comando.h"

// Constructors/Destructors
//  

Comando::Comando ( ) {
initAttributes();
}

Comando::~Comando ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Comando::initAttributes ( ) {
}


#include "JmmRF.h"

// Constructors/Destructors
//  

JmmRF::JmmRF ( ) {
initAttributes();
}

JmmRF::~JmmRF ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void JmmRF::initAttributes ( ) {
  pinInterrupt = _pinRx-2;;
  _pinHdRX = 12;
  feedback = false;
}

#endif /* ARDUINO_ARCH_SAM */
