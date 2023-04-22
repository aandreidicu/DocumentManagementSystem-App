#include "DocumentFactory.h"
#include "Sablon.h"
#include "Custom.h"

IDocument* DocumentFactory::getDocument(std::string buffer)
{
	std::string tip = buffer;
	int pos = tip.find("tip:");
	tip = tip.substr(pos + 4); //m-am poz fix pe litera
	tip = tip.substr(0, 1);
	//std::cout << "tipul este: " << tip << "\n";
	if (tip == "s" || tip == "S")
		return new Sablon(buffer);
	if (tip == "c" || tip == "C")
		return new Custom(buffer);
	return NULL;
}