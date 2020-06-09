#include "factory.h"

factory* factory::instancefactory = nullptr; // domy�lnie nie mamy �adnej instacji wi�c jest to pusty wska�nik

factory::factory() : control(999), externalInfo("noinfoYet") // defaultowa warto�� kontrolna
{
	setOutput(console);        // domy�lnym wyj�ciem jest konsola

	count++;					// zwi�kszana jest liczba obiekt�w
}

factory::~factory()
{
	
}

factory * factory::getInstance()
{
	// je�li nie mamy �adnego obiektu, jest tworzona nowa instancja
	// w przeciwnym razie musi ju� takowa istnie�
	// jest ona zwracana

	if (count == 0) 
	{		
		instancefactory = new factory();
		return instancefactory;
	}
	else
	{
		return instancefactory;
	}
	
}

int factory::getStatus() const
{
	return control;
}

void factory::setOutput(int i)
{
	// warunek kt�ry sprawdza czy "pracujemy" na tej samej linii produkcyjnej
	// je�li tak to niepotrzebne jest tworzenie nowego wska�nika, kt�ry pozby�by si�
	// wszystkich zapisanych dotychczas informacji
	// umo�liwia to dzia�anie programu w przypadku gdy u�ytkownik uruchomi
	// setExternalInfo przed ustawieniem Output 


	if (control == i)
	{
		
	}
	else if (i == beep)
	{
		m = new morseBeep();
		control = 2;
		m->setInfo(externalInfo);
		m->controler();
	}
	else if (i == console)
	{
		m = new morseConsole();
		control = 0;
		m->setInfo(externalInfo);
		m->controler();
	}
	else if (i == file)
	{
		m = new morseFile();
		control = 1;
		m->setInfo(externalInfo);
		m->controler();
	}
	else if (i == blink)
	{
		m = new morseBlink();
		control = 3;
		m->setInfo(externalInfo);
		m->controler();
	}
	
}

void factory::convert(const std::string &str)
{
	m->controler();
	m->convert(str);
}

void factory::convert(float f)
{
	m->controler();
	m->convert(f);
}

void factory::convert(int i)
{
	m->controler();
	m->convert(i);
}


void factory::setExternalInfo(const std::string & str)
{
	externalInfo = str;

	m->setInfo(externalInfo); // kartka papieru z informacjami 

	m->controler();  // wywo�anie metody kt�ra zadecyduje 
					 // co ma zrobi� z informacjami dana maszyna
}
