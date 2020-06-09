/*

Klasa "morseMain"
Opis: 
Autor: Mateusz Wypych
Data utworzenia: 10.01.2020
Data poprawki/edycja: 16.11.2019 19.11.2019

*/

#ifndef morseMain_H
#define morseMain_H
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class morse
{
protected:

	std::string mors; //kod morsa
	std::string info; //informacje dla linii produkcyjnych

public:

	morse(); //konstruktor bezparametrowy ustawia domy�lnie wszystko sk�adowe na 0
	morse(const morse &m1); // konstruktor kopiuj�cy 
	morse& operator = (const morse &m1); // operator przyr�wnania, w razie tworzenia obiektu na podstawie ju� istniej�cego
	virtual ~morse(); // destruktor, w programie nie by�o �adnej dynamicznej alokacji pami�ci wi�c jest pusty


	//setery
	void setInfo(const std::string &str);
	void setMorse(const std::string & str);

	//getery 
	const std::string & getMors() const; // metoda pobieraj�ca morsa 
	const std::string & getInfo() const; // metoda pobieraj�ca informacj�

	//const std::string& getTranslate(const std::string& (*translate)(char x));


	//inne metody 
	std::string translate(char x); // Metoda "t�umacz�ca" podany znak na morsa
	virtual void controler() = 0;
	virtual void convert(const std::string &str) = 0;
	virtual void convert(float f) = 0;
	virtual void convert(int i) = 0;


};


#endif
