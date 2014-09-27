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


#include "Mensagem.h"

// Constructors/Destructors
//  

Mensagem::Mensagem ( ) {
initAttributes();
}

Mensagem::~Mensagem ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Mensagem::initAttributes ( ) {
}

#endif /* ARDUINO_ARCH_SAM */
