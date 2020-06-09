#ifndef morseConsole_H
#define morseConsole_H
#include <string>
#include "morseMain.h"
#include <iostream>

class morseConsole : public morse

{

private:
			
	//brak nowych sk�adowych potrzebnych do wy�wietlania morsa na konsoli

public:

	morseConsole(); //konstruktor bezparametrowy 
	morseConsole(const morseConsole &m1); // konstruktor kopiuj�cy 
	morseConsole& operator = (const morseConsole &m1); // operator przyr�wnania, w razie tworzenia obiektu na podstawie ju� istniej�cego
	~morseConsole(); // destruktor


	//inne metody
	void convert(const std::string &str);
	void convert(float f);
	void convert(int i);
	void controler();
};


#endif
