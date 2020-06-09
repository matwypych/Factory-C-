#include "morseConsole.h"

morseConsole::morseConsole() : morse()
{

}


morseConsole::morseConsole(const morseConsole &m1) : morse(m1)
{

}
morseConsole::~morseConsole()
{

}

morseConsole& morseConsole::operator = (const morseConsole &m1)
{
	if (this == &m1)
	{
		return *this;
	}

	else
	{
		morse::operator=(m1);
		return *this;
	}


}


void morseConsole::convert(const std::string & str)
{
	std::string s = str;

	const char spacjaWyraz = ' ';

	for (int i = 0; i < s.length(); i++)
	{
		mors = translate(s[i]); // zamiana na kod morsa przy u¿yciu metody translate

		for (int z = 0; z < mors.length(); z++) 
		{
			std::cout << mors[z];
		}

		if (s[i] == spacjaWyraz) // warunek na spacjê miêdzy s³owami
		{
			std::cout << " ";
		}

	}

}

void morseConsole::convert(float f)
{
	std::string str = std::to_string(f); // zamiana float'a na stringa

	for (int i = 0; i < str.length(); i++)
	{
		mors = translate(str[i]);
		std::cout << mors;
	}

}

void morseConsole::convert(int i)
{
	std::string str = std::to_string(i); // zamiana int'a na stringa

	for (int i = 0; i < str.length(); i++)
	{
		mors = translate(str[i]);
		std::cout << mors;
	}
}



void morseConsole::controler()
{
	// pusty, w konsoli nie ma ¿adnych opcji do modyfikacji 
}
