#ifndef morseConsole_H
#define morseConsole_H
#include <string>
#include "morseMain.h"
#include <iostream>

class morseConsole : public morse

{

private:
			
	//brak nowych składowych potrzebnych do wyświetlania morsa na konsoli

public:

	morseConsole(); //konstruktor bezparametrowy 
	morseConsole(const morseConsole &m1); // konstruktor kopiujący 
	morseConsole& operator = (const morseConsole &m1); // operator przyrównania, w razie tworzenia obiektu na podstawie już istniejącego
	~morseConsole(); // destruktor


	//inne metody
	void convert(const std::string &str);
	void convert(float f);
	void convert(int i);
	void controler();
};


#endif
