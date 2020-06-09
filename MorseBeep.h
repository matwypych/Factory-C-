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
	morseBeep(); //konstruktor bezparametrowy ustawia domyœlnie wszystko sk³adowe na 0
	morseBeep(const morseBeep &m1); // konstruktor kopiuj¹cy 
	morseBeep& operator = (const morseBeep &m1); // operator przyrównania, w razie tworzenia obiektu na podstawie ju¿ istniej¹cego
	~morseBeep(); // destruktor

	// setery
	void setFrequency(int freq); // ustawia czêstotliwoœæ dŸwiêku
	void setDotTime(int t); // ustawia czas kropki
	void setDashTime(int t); // ustawia czas kreski
	void setPause(int); // ustawia czas pauzy 
	void setSpacePause(int sP); // ustawia czas miêdzy s³owami
	void setCharPause(int cP); // ustawia czas miêdzy znakami

	//getery 
	int getspacePause() const; // metoda pobieraj¹ca czas pauzy miêdzy s³owami 
	int gettimeDot() const ; // metoda pobieraj¹ca czas kropki
	int gettimeDash() const; // metoda pobieraj¹ca czas kreski
	int getpauza() const; // metoda pobieraj¹ca czas pauzy
	int getcharPause() const; // metoda pobieraj¹ca czas pauzy miêdzy literami
	int getFrequency() const; // metoda pobieraj¹ca czêstotliwoœæ

	//inne metody
	void convert(const std::string &str);
	void convert(float f);
	void convert(int i);
	void controler();
};


#endif
