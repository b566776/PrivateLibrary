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


#include "FilaMensagem.h"

// Constructors/Destructors
//  

FilaMensagem::FilaMensagem ( ) {
initAttributes();
}

FilaMensagem::~FilaMensagem ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void FilaMensagem::initAttributes ( ) {
}

#endif /* ARDUINO_ARCH_SAM */
