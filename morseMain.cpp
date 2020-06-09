#include "morseMain.h"

morse::morse() : mors("Def"), info("no")
{

}

morse::morse(const morse &m1) : mors(m1.mors), info(m1.info)
{

}
morse::~morse()
{

}

void morse::setInfo(const std::string &str)
{
	info = str;
}

void morse::setMorse(const std::string & str)
{
	mors = str;
}

const std::string& morse::getMors() const
{
	return mors;
}

const std::string& morse::getInfo() const
{
	return info;
}



morse& morse::operator = (const morse &m1)
{
	if (this == &m1)
		{
			return *this;
		}

	else
	{
		mors = m1.mors;
		info = m1.info;
		return *this;
	}
	

}

//const std::string & morse::getTranslate(const std::string &(*translate)(char x))
//{
	//return ((*translate)(*this));
//}


std::string morse::translate(char x)
{
	switch (x)
	{
	case ' ':
		return " ";
	case 'a': case 'A':
		return "._";
	case 'b': case 'B':
		return "_...";
	case 'c': case 'C':
		return "_._.";
	case 'd': case 'D':
		return "_..";
	case 'e': case 'E':
		return ".";
	case 'f': case 'F':
		return ".._.";
	case 'g': case 'G':
		return "__.";
	case 'h': case 'H':
		return "....";
	case 'i': case 'I':
		return "..";
	case 'j': case 'J':
		return ".___";
	case 'k': case 'K':
		return "_._";
	case 'l': case 'L':
		return "._..";
	case 'm': case 'M':
		return "__";
	case 'n': case 'N':
		return "_.";
	case 'o': case 'O':
		return "___";
	case 'p': case 'P':
		return ".__.";
	case 'q': case 'Q':
		return "__._";
	case 'r': case 'R':
		return "._.";
	case 's': case 'S':
		return "...";
	case 't': case 'T':
		return "_";
	case 'u': case 'U':
		return ".._";
	case 'v': case 'V':
		return "..._";
	case 'w': case 'W':
		return ".__";
	case 'x': case 'X':
		return "_.._";
	case 'y': case 'Y':
		return "_.__";
	case 'z': case 'Z':
		return "__..";
	case '1':
		return ".____";
	case '2':
		return "..___";
	case '3':
		return "...__";
	case '4':
		return "...._";
	case '5':
		return ".....";
	case '6':
		return "_....";
	case '7':
		return "__...";
	case '8':
		return "___..";
	case '9':
		return "____.";
	case '0':
		return "_____";
	case '.':
		return "_._._";
	default:
		return "";
	}
	
}