/*

Klasa "factory"
Opis: Klasa factory jest pewnego rodzaju interfejsem, kt�ry obs�uguje klas� morseMain. 
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
	// Klasa zosta�a napisana tak aby konsola by�a domy�lnym wyj�ciem.
	// Istnieje mo�liwo�� podania najpierw informacji do setExternalInfo
	// i p�niejsze ustawienie outputu. Program b�dzie dzia�a� poprawnie.

	// Je�li informacje podane przez u�ytkownika s� nieprawid�owe
	// program przyjmie wszystkie poprawne podane parametry, natomiast
	// te nieprawid�owe odrzuci i zast�pi domy�lnymi.

	// Fabryk� mo�na stworzy� tylko raz, tworzenie kilku 
	// obiekt�w jest zablokowane, nie stworzy si� nowy obiekt
    // a w�a�ciwie wska�nik, a metoda getInstance zwr�ci wska�nik
    // na istniej�ca ju� instancje

static int count=0;

class factory
{
protected:

	// zmienna kt�ra kontroluje, kt�rym obiektem "jeste�my"
	int control; 

	// informacje o dzia�aniu obiekt�w
	std::string externalInfo;

	// wska�nik na bazowy obiekt morsa
	morse *m; 

	// zablokowane tworzenie nowych obiekt�w
	factory(const factory &f1) = delete; 
	factory& operator = (const factory &f1) = delete;

private:

	// konstruktor prywatny
	factory();
	~factory();

public:

	// rodzaje "wyj��" 
	enum Output {
		console,
		file,
		beep,
		blink
	};
	
	// wska�nik na instacje fabryki
	static factory *instancefactory;

	// metoda pobieraj�ca instancje fabryki
	static factory* getInstance();

	//getery

	// pobiera aktywn� "lini� produkcyjn�"
	//"0 - konsola, 1 - plik, 2 - beep, 3 - blink
	int getStatus() const; 

	//metody 

	// ustawia wyj�cie na kt�re ma zosta� wys�any mors 
	void setOutput(int i); 

	// zamienia tekst na morsa
	void convert(const std::string &str); 

	// zamienia liczb� zmiennoprzecinkow� na morsa
	void convert(float f); 

	// zamienia liczb� ca�kowit� na morsa
	void convert(int i);

	
						   
	// ustawia informacje 
	// konsola - brak
	// plik - scie�ka i nazwa pliku
	// beep - cz�stotliwo��, czas kropki, czas kreski, pauza po znaku, pauza po spacji, pauza po literce
	// blink - 
	void setExternalInfo(const std::string &str); 
};



#endif 
