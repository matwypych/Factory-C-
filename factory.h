/*

Klasa "factory"
Opis: Klasa factory jest pewnego rodzaju interfejsem, który obs³uguje klasê morseMain. 
Autor: Mateusz Wypych
Data utworzenia: 10.01.2020
Data poprawki/edycja:

*/

#ifndef factory_H
#define factory_H

#include "morseMain.h"
#include "morseBeep.h"
#include "MorseConsole.h"
#include "MorseFile.h"
#include "MorseBlink.h"

// Dodatkowe informacje:
	// Klasa zosta³a napisana tak aby konsola by³a domyœlnym wyjœciem.
	// Istnieje mo¿liwoœæ podania najpierw informacji do setExternalInfo
	// i póŸniejsze ustawienie outputu. Program bêdzie dzia³a³ poprawnie.

	// Jeœli informacje podane przez u¿ytkownika s¹ nieprawid³owe
	// program przyjmie wszystkie poprawne podane parametry, natomiast
	// te nieprawid³owe odrzuci i zast¹pi domyœlnymi.

	// Fabrykê mo¿na stworzyæ tylko raz, tworzenie kilku 
	// obiektów jest zablokowane, nie stworzy siê nowy obiekt
    // a w³aœciwie wskaŸnik, a metoda getInstance zwróci wskaŸnik
    // na istniej¹ca ju¿ instancje

static int count=0;

class factory
{
protected:

	// zmienna która kontroluje, którym obiektem "jesteœmy"
	int control; 

	// informacje o dzia³aniu obiektów
	std::string externalInfo;

	// wskaŸnik na bazowy obiekt morsa
	morse *m; 

	// zablokowane tworzenie nowych obiektów
	factory(const factory &f1) = delete; 
	factory& operator = (const factory &f1) = delete;

private:

	// konstruktor prywatny
	factory();
	~factory();

public:

	// rodzaje "wyjœæ" 
	enum Output {
		console,
		file,
		beep,
		blink
	};
	
	// wskaŸnik na instacje fabryki
	static factory *instancefactory;

	// metoda pobieraj¹ca instancje fabryki
	static factory* getInstance();

	//getery

	// pobiera aktywn¹ "liniê produkcyjn¹"
	//"0 - konsola, 1 - plik, 2 - beep, 3 - blink
	int getStatus() const; 

	//metody 

	// ustawia wyjœcie na które ma zostaæ wys³any mors 
	void setOutput(int i); 

	// zamienia tekst na morsa
	void convert(const std::string &str); 

	// zamienia liczbê zmiennoprzecinkow¹ na morsa
	void convert(float f); 

	// zamienia liczbê ca³kowit¹ na morsa
	void convert(int i);

	
						   
	// ustawia informacje 
	// konsola - brak
	// plik - scie¿ka i nazwa pliku
	// beep - czêstotliwoœæ, czas kropki, czas kreski, pauza po znaku, pauza po spacji, pauza po literce
	// blink - 
	void setExternalInfo(const std::string &str); 
};



#endif 
