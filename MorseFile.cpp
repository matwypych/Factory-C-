#include "MorseFile.h"

morseFile::morseFile() : destination("save-default")
{

}

morseFile::morseFile(const morseFile & m1) : destination(m1.destination)
{

}

morseFile & morseFile::operator=(const morseFile & m1)
{
	if (this == &m1)
	{
		return *this;
	}
	morse::operator=(m1);
	destination = m1.destination;

	return *this;
}



morseFile::~morseFile()
{

}

const std::string & morseFile::getDestination() const
{
	return destination;
}

void morseFile::convert(const std::string & str)
{
	std::string s = str;

	const char spacjaWyraz = ' ';

	std::ofstream dest(destination, std::ios::binary); // info w tym wypadku to œcie¿ka podana przez u¿ytkownika  
	
	for (int i = 0; i < s.length(); i++)
	{
		mors = translate(s[i]); // zamiana na kod morsa przy u¿yciu metody translate

		for (int z = 0; z < mors.length(); z++) // pêtla w której ka¿dy znak morsa ma odpowiadaæ dŸwiêkowi
		{
			dest << mors[z];
		}

		if (str[i] == spacjaWyraz) // warunek na spacjê miêdzy s³owami
		{
			dest << " ";
		}
	}
}

void morseFile::convert(float f)
{
	std::string str = std::to_string(f); // zamiana float'a na stringa

	std::ofstream dest(destination, std::ios::binary); // info w tym wypadku to œcie¿ka podana przez u¿ytkownika  

	for (int i = 0; i < str.length(); i++)
	{
		mors = translate(str[i]);

		for (int z = 0; z < mors.length(); z++)
		{
			dest << mors[z];
		}
	}
}


void morseFile::convert(int i)
{
	std::string str = std::to_string(i); // zamiana int'a na stringa

	std::ofstream dest(destination, std::ios::binary); // info w tym wypadku to œcie¿ka podana przez u¿ytkownika  

	for (int i = 0; i < str.length(); i++)
	{
		mors = translate(str[i]);

		for (int z = 0; z < mors.length(); z++)
		{
			dest << mors[z];
		}
	}
}



void morseFile::controler()
{
	destination = info; // informacje z setExternalinfo
}
