#ifndef morseBeep_H
#define morseBeep_H
#include <string>
#include <windows.h>
#include "morseMain.h"
#include <iostream>

class morseBeep : public morse

{

private:

	int frequency, timeDot, timeDash, pauza, spacePause, charPause;

public:
	morseBeep(); //konstruktor bezparametrowy ustawia domy�lnie wszystko sk�adowe na 0
	morseBeep(const morseBeep &m1); // konstruktor kopiuj�cy 
	morseBeep& operator = (const morseBeep &m1); // operator przyr�wnania, w razie tworzenia obiektu na podstawie ju� istniej�cego
	~morseBeep(); // destruktor

	// setery
	void setFrequency(int freq); // ustawia cz�stotliwo�� d�wi�ku
	void setDotTime(int t); // ustawia czas kropki
	void setDashTime(int t); // ustawia czas kreski
	void setPause(int); // ustawia czas pauzy 
	void setSpacePause(int sP); // ustawia czas mi�dzy s�owami
	void setCharPause(int cP); // ustawia czas mi�dzy znakami

	//getery 
	int getspacePause() const; // metoda pobieraj�ca czas pauzy mi�dzy s�owami 
	int gettimeDot() const ; // metoda pobieraj�ca czas kropki
	int gettimeDash() const; // metoda pobieraj�ca czas kreski
	int getpauza() const; // metoda pobieraj�ca czas pauzy
	int getcharPause() const; // metoda pobieraj�ca czas pauzy mi�dzy literami
	int getFrequency() const; // metoda pobieraj�ca cz�stotliwo��

	//inne metody
	void convert(const std::string &str);
	void convert(float f);
	void convert(int i);
	void controler();
};


#endif
