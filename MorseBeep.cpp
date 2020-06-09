#include "morseBeep.h"


morseBeep::morseBeep() : morse(), frequency(9999), timeDot(9999), timeDash(9999),
						 pauza(9999), spacePause(9999), charPause(9999)
{

}

morseBeep::morseBeep(const morseBeep &m1) : morse(m1), frequency(m1.frequency), timeDot(m1.timeDot),
											timeDash(m1.timeDash), pauza(m1.pauza), 
											spacePause(m1.spacePause), charPause(m1.charPause)
{

}
morseBeep::~morseBeep()
{

}

morseBeep& morseBeep::operator = (const morseBeep &m1)
{
	if (this == &m1)
		{
			return *this;
		}

	else
	{
		morse::operator=(m1);

		frequency = m1.frequency;
		timeDot = m1.timeDot;
		timeDash = m1.timeDash;
		pauza = m1.pauza;
		spacePause = m1.spacePause;
		charPause = m1.charPause;

		return *this;
	}
	

}

void morseBeep::setPause(int p)
{
	pauza = p;
}

void morseBeep::setSpacePause(int sP)
{
	spacePause = sP;
}

void morseBeep::setCharPause(int cP)
{
	charPause = cP;
}

int morseBeep::getspacePause() const
{
	return spacePause;
}

int morseBeep::gettimeDot() const
{
	return timeDot;
}

int morseBeep::gettimeDash() const
{
	return timeDash;
}

int morseBeep::getpauza() const
{
	return pauza;
}

int morseBeep::getcharPause() const
{
	return charPause;
}

int morseBeep::getFrequency() const
{
	return frequency;
}

void morseBeep::convert(const std::string & str)
{
	const char kreska = '_';
	const char kropka = '.';
	const char spacjaWyraz = ' ';
	const char *literka = "";
	std::string s = str;
	

	for (int i = 0; i < s.length(); i++)
	{
		mors = translate(s[i]); // zamiana na kod morsa przy u�yciu metody translate
		for (int z = 0; z < mors.length(); z++) // p�tla w kt�rej ka�dy znak morsa ma odpowiada� d�wi�kowi
		{
			if (mors[z] == kreska) // warunek je�li mamy kresk� 
			{
				Beep(frequency, timeDash);  // puszczamy sygna� kreski
				Sleep(pauza); // pauza po znaku morsa

			}
			else if ((mors[z] == kreska) && (mors[z + 1] == *literka)) // je�li mamy kresk� oraz ko�czymy literk�
			{
				Beep(frequency, timeDash); // sygna� kreski

				Sleep(charPause); // pauza na zako�czon� literk�
			}


			if (mors[z] == kropka) // je�li mamy kropke 
			{
				Beep(frequency, timeDot); // sygna� kreski

				Sleep(pauza); // pauza po znaku morsa
			}
			else if ((mors[z] == kropka) && (mors[z + 1] == *literka)) // je�li mamy kropk� oraz ko�czymy literk� 
			{
				Beep(frequency, timeDot); // sygna� kropki

				Sleep(charPause); // pauza na zako�czon� literk�
			}


		}
		if (s[i] == spacjaWyraz) // warunek na spacj� mi�dzy s�owami
		{

			Sleep(spacePause); // przerwa mi�dzy s�owami
		}


	}
	Sleep(spacePause); // pauza po zako�czeniu ca�ego zdania
	
}

void morseBeep::convert(float f)
{
	std::string str = std::to_string(f); // zamiana float'a na stringa

	const char kreska = '_';
	const char kropka = '.';
	for (int i = 0; i < str.length(); i++)
	{
		mors = translate(str[i]);

		for (int z = 0; z < mors.length(); z++)
		{
			if (mors[z] == kreska)
			{
				Beep(frequency, timeDash);
				Sleep(pauza);

			}
			if (mors[z] == kropka)
			{
				Beep(frequency, timeDot);
				Sleep(pauza);
			}

		}

	}
}

void morseBeep::convert(int i)
{
	std::string str = std::to_string(i); // zamiana int'a na stringa

	const char kreska = '_';
	const char kropka = '.';

	for (int i = 0; i < str.length(); i++)
	{
		mors = translate(str[i]);

		for (int z = 0; z < mors.length(); z++)
		{
			if (mors[z] == kreska)
			{
				Beep(frequency, timeDash);
				Sleep(pauza);

			}
			if (mors[z] == kropka)
			{
				Beep(frequency, timeDot);
				Sleep(pauza);
			}

		}

	}
}

void morseBeep::controler()
{
	std::istringstream istr(info);

	istr >> frequency >> timeDot >> timeDash >> pauza >> spacePause >> charPause;

}

void morseBeep::setFrequency(int freq)
{
	frequency = freq;
}

void morseBeep::setDotTime(int t)
{
	timeDot = t;
}

void morseBeep::setDashTime(int t)
{
	timeDash = t;
}