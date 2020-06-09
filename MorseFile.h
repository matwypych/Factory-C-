#ifndef morseFile_H
#define morseFile_H
#include <string>
#include "morseMain.h"
#include <iostream>
#include <fstream>

class morseFile : public morse
{

private:

	std::string destination;

public:

	morseFile(); //konstruktor bezparametrowy 
	morseFile(const morseFile &m1); // konstruktor kopiuj¹cy 
	morseFile& operator = (const morseFile &m1); // operator przyrównania, w razie tworzenia obiektu na podstawie ju¿ istniej¹cego
	~morseFile(); // destruktor

	//getery
	const std::string & getDestination() const;
	
	//przedefiniowane metody wirtualne
	void convert(const std::string &str);
	void convert(float f);
	void convert(int i);
	void controler();

	

};


#endif
