#include "factory.h"

factory* factory::instancefactory = nullptr; // domyœlnie nie mamy ¿adnej instacji wiêc jest to pusty wskaŸnik

factory::factory() : control(999), externalInfo("noinfoYet") // defaultowa wartoœæ kontrolna
{
	setOutput(console);        // domyœlnym wyjœciem jest konsola

	count++;					// zwiêkszana jest liczba obiektów
}

factory::~factory()
{
	
}

factory * factory::getInstance()
{
	// jeœli nie mamy ¿adnego obiektu, jest tworzona nowa instancja
	// w przeciwnym razie musi ju¿ takowa istnieæ
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
	// warunek który sprawdza czy "pracujemy" na tej samej linii produkcyjnej
	// jeœli tak to niepotrzebne jest tworzenie nowego wskaŸnika, który pozby³by siê
	// wszystkich zapisanych dotychczas informacji
	// umo¿liwia to dzia³anie programu w przypadku gdy u¿ytkownik uruchomi
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

	m->controler();  // wywo³anie metody która zadecyduje 
					 // co ma zrobiæ z informacjami dana maszyna
}
