//#ifdef ARDUINO_ARCH_SAM
/*
 *  StackArray.h
 *
 *  Library implementing a generic, dynamic stack (array version).
 *
 *  ---
 *
 *  Copyright (C) 2010  Efstathios Chatzikyriakidis (contact@efxa.org)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *  ---
 *
 *  Version 1.0
 *
 *    2010-09-25  Efstathios Chatzikyriakidis  <contact@efxa.org>
 *
 *      - added resize(): for growing, shrinking the array size.
 *
 *    2010-09-23  Efstathios Chatzikyriakidis  <contact@efxa.org>
 *
 *      - added exit(), blink(): error reporting and handling methods.
 *
 *    2010-09-20  Alexander Brevig  <alexanderbrevig@gmail.com>
 *
 *      - added setPrinter(): indirectly reference a Serial object.
 *
 *    2010-09-15  Efstathios Chatzikyriakidis  <contact@efxa.org>
 *
 *      - initial release of the library.
 *
 *  ---
 *
 *  For the latest version see: http://www.arduino.cc/
 */

// header defining the interface of the source.
// StackArray foi modificada para trabalhar com um typedef Mensagem
#ifndef _STACKARRAYJMM_H
#define _STACKARRAYJMM_H

// include Arduino basic header.
#include <Arduino.h>
#include <defdacasa.h>

// the definition of the stack class.
//template<typename T>
class StackArray {
  public:

	Mensagem * mensagens[];    // the array of the stack.

    // init the stack (constructor).
    StackArray ();

    // clear the stack (destructor).
    ~StackArray ();

    // push an item to the stack. INSERE ITEM
    void push (Mensagem m, int i);

    // pop an item from the stack. REMOVE UM ITEM - RETORNA UM POTEIRO utilizar &pop()
    Mensagem pop ();

    // get an item from the stack. RETORNA UM POTEIRO
    Mensagem peek () const;

    // check if the stack is empty.
    bool isEmpty () const;

    // get the number of items in the stack.
    int count () const;

    // check if the stack is full.
    bool isFull () const;

    // set the printer of the stack.
    void setPrinter (Print & p);



  private:
    // resize the size of the stack.
    void resize (const int s);

    // exit report method in case of error.
    void exit (const char * m) const;

    // led blinking method in case of error.
    void blink () const;

    // the initial size of the stack.
    static const int initialSize = 2;

    // the pin number of the on-board led.
    static const int ledPin = 13;

    Print * printer; // the printer of the stack.

    int size;        // the size of the stack.
    int top;         // the top index of the stack.

};



// init the stack (constructor).
//template<typename T>
StackArray::StackArray () {
  size = 0;       // set the size of stack to zero.
  top = 0;        // set the initial top index of the stack.
  printer = NULL; // set the printer of stack to point nowhere.

  //Mensagem * mensagens[];    // the array of the stack.

  // allocate enough memory for the array.
  mensagens = (Mensagem *) malloc (sizeof (Mensagem) * initialSize);

  // if there is a memory allocation error.
  if (mensagens == NULL)
    exit ("STACK: insufficient memory to initialize stack.");

  // set the initial size of the stack.
  size = initialSize;
}

// clear the stack (destructor).

StackArray::~StackArray () {
  free (mensagens); // deallocate the array of the stack.

  //mensagens = NULL; // set stack's array pointer to nowhere.
  printer = NULL;  // set the printer of stack to point nowhere.
  size = 0;        // set the size of stack to zero.
  top = 0;         // set the initial top index of the stack.
}

// resize the size of the stack.
void StackArray::resize (const int s) {
  // defensive issue.
  if (s <= 0)
    exit ("STACK: error due to undesirable size for stack size.");

  // reallocate enough memory for the array.
  mensagens = (Mensagem *) realloc (mensagens, sizeof (Mensagem) * s);


  // if there is a memory allocation error.
  if (mensagens == NULL)
    exit ("STACK: insufficient memory to resize stack.");

  // set the new size of the stack.
  size = s;
}

// push an item to the stack.
//template<typename T>
void StackArray::push (const Mensagem m, int i) {
  for (int j = 0; j <i+1; j++){
	  // check if the stack is full.

      if (isFull ())
         // double size of array.
         resize (size * 2);

      // store the item to the array.
      mensagens[top++] = m;
  }
}

// pop an item from the stack.
//template<typename T>
Mensagem StackArray::pop () {
  // check if the stack is empty.
  if (isEmpty ())
    exit ("STACK: can't pop item from stack: stack is empty.");

  // fetch the top item from the array.
  Mensagem item = mensagens[--top];

  // shrink size of array if necessary.
  if (!isEmpty () && (top <= size / 4))
    resize (size / 2);

  // return the top item from the array.
  return item;
}

// get an item from the stack.
//template<typename T>
Mensagem StackArray::peek () const {
  // check if the stack is empty.
  if (isEmpty ())
    exit ("STACK: can't peek item from stack: stack is empty.");

  // get the top item from the array.
  return mensagens[top - 1];
}

// check if the stack is empty.
//template<typename T>
bool StackArray::isEmpty () const {
  return top == 0;
}

// check if the stack is full.
//template<typename T>
bool StackArray::isFull () const {
  return top == size;
}

// get the number of items in the stack.
//template<typename T>
int StackArray::count () const {
  return top;
}

// set the printer of the stack.
//template<typename T>
void StackArray::setPrinter (Print & p) {
  printer = &p;
}

// exit report method in case of error.
//template<typename T>
void StackArray::exit (const char * m) const {
  // print the message if there is a printer.
  if (printer)
    printer->println (m);

  // loop blinking until hardware reset.
  blink ();
}

// led blinking method in case of error.
//template<typename T>
void StackArray::blink () const {
  // set led pin as output.
  pinMode (ledPin, OUTPUT);

  // continue looping until hardware reset.
  while (true) {
    digitalWrite (ledPin, HIGH); // sets the LED on.
    delay (250);                 // pauses 1/4 of second.
    digitalWrite (ledPin, LOW);  // sets the LED off.
    delay (250);                 // pauses 1/4 of second.
  }

  // solution selected due to lack of exit() and assert().
}

#endif // _STACKARRAY_H
//#endif /* ARDUINO_ARCH_SAM */
