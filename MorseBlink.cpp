#include "MorseBlink.h"
#define _WIN32_WINNT 0x403


morseBlink::morseBlink() : morse(), timeDot(9999), timeDash(9999), pauza(9999),
						            spacePause(9999), charPause(9999)
{
	in[0].type = INPUT_KEYBOARD;               
	in[0].ki.wVk = VK_CAPITAL;                  
	in[0].ki.wScan = 0;
	in[0].ki.time = 0;
	in[0].ki.dwFlags = 0;                       
	in[0].ki.dwExtraInfo = 0;

	in[1] = in[0];                               
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;          
}

morseBlink::morseBlink(const morseBlink & m1) : morse(m1), timeDot(m1.timeDot), timeDash(m1.timeDash), 
												pauza(m1.pauza), spacePause(m1.spacePause), 
												charPause(m1.charPause)
{
	for (int i = 0; i < 1; i++)
	{
		in[i] = m1.in[i];
	}
	
}

morseBlink & morseBlink::operator=(const morseBlink & m1) 
{
	if (this == &m1)
	{
		return *this;
	}

	else
	{
		morse::operator=(m1);

		timeDot = m1.timeDot;
		timeDash = m1.timeDash;
		pauza = m1.pauza;
		spacePause = m1.spacePause;
		charPause = m1.charPause;

		return *this;
	}

}

morseBlink::~morseBlink()
{
}

void morseBlink::convert(const std::string & str)
{          
	const char kreska = '_';
	const char kropka = '.';
	const char spacjaWyraz = ' ';
	const char *literka = "";

	for (int i = 0; i < str.length(); i++)
	{
		mors = translate(str[i]); // zamiana na kod morsa przy u¿yciu metody translate
		for (int z = 0; z < mors.length(); z++) // pêtla w której ka¿dy znak morsa ma odpowiadaæ dŸwiêkowi
		{
			if (mors[z] == kreska) // warunek jeœli mamy kreskê 
			{
				::SendInput(2, in, sizeof(INPUT));   // puszczamy sygna³ kreski
				::Sleep(pauza); // pauza po znaku morsa

			}
			else if ((mors[z] == kreska) && (mors[z + 1] == *literka)) // jeœli mamy kreskê oraz koñczymy literkê
			{
				::SendInput(2, in, sizeof(INPUT)); // sygna³ kreski
				::Sleep(charPause); // pauza na zakoñczonê literkê
			}


			if (mors[z] == kropka) // jeœli mamy kropke 
			{
				::SendInput(2, in, sizeof(INPUT)); // sygna³ kreski
				::Sleep(pauza); // pauza po znaku morsa
			}
			else if ((mors[z] == kropka) && (mors[z + 1] == *literka)) // jeœli mamy kropkê oraz koñczymy literkê 
			{
				::SendInput(2, in, sizeof(INPUT));
				::Sleep(charPause); // pauza na zakoñczon¹ literkê
			}

		}

		if (str[i] == spacjaWyraz) // warunek na spacjê miêdzy s³owami
		{
			::Sleep(spacePause); // przerwa miêdzy s³owami
		}
	}

	::Sleep(spacePause); // pauza po zakoñczeniu ca³ego zdania
}


void morseBlink::convert(float f)
{
}

void morseBlink::convert(int i)
{
}

void morseBlink::controler()
{
	std::istringstream istr(info);
	istr >> timeDot >> timeDash >> pauza >> spacePause >> charPause;
}
