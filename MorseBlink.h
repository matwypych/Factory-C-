#ifndef morseBlink_H
#define morseBlink_H
#include <string>
#include <windows.h>
#include "morseMain.h"


class morseBlink : public morse
{
private:

	INPUT in[2];
	int timeDot, timeDash, pauza, spacePause, charPause;
											 
public:

	morseBlink(); //konstruktor bezparametrowy 
	morseBlink(const morseBlink &m1); // konstruktor kopiuj�cy 
	morseBlink& operator = (const morseBlink &m1); // operator przyr�wnania, w razie tworzenia obiektu na podstawie ju� istniej�cego
	~morseBlink(); // destruktor


	//inne metody
	void convert(const std::string &str);
	void convert(float f);
	void convert(int i);
	void controler();
};


#endif

