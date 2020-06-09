#include "factory.h"

int main()
{
	factory *f;
	f=f->getInstance();

	f->setExternalInfo("400 200 400 100 200 100");
	f->setOutput(factory::beep);
	f->convert("Ala ma kota");

	f->setOutput(factory::console);
	f->setExternalInfo("BEZ INFO XD");
	f->convert("ala ma kota");
	
	f->setOutput(factory::blink);
	f->setExternalInfo("400 400 200 400 300"); 
	f->convert("ala ma kota");


	factory *f2;
	f2 = f2->getInstance();

	std::cin.get();

	return 0;
}