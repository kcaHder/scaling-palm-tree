#ifndef ICTS_HPP
#define ICTS_HPP

#include <iostream>
#include <typeinfo>

//Template che restituisce il tipo dell'oggetto passato come argomento
template <class X> void TypeSorter(X x, bool b = 0)
{
	const char *types[  ] { "int", "unsigned int", "double", "float", "char", "bool", "puntatore a "};
	if(!b) std::cout << "Vorrei ricevere un input di tipo ";
	switch(typeid(x).name(  )[b])
	{
		case 'i':
		{
			std::cout << types[0]; // o qualsiasi altro uso intelligente
			break;
		}
		case 'j':
		{
			std::cout << types[1];
			break;
		}
		case 'd':
		{
			std::cout << types[2];
			break;
		}
		case 'f':
		{
			std::cout << types[3];
			break;
		}
		case 'c':
		{
			std::cout << types[4];
			break;
		}
		case 'b':
		{
			std::cout << types[5];
			break;
		}
		case 'P':
		{
			std::cout << types[6];
			TypeSorter(x, 1);
			break;
		}
		default: std::cout << "\nTorna a casa\n";
	}
	std::cout << std::endl;
}

// Template per la gestione degli errori di input
template <class X> X InputCheck()
{
	X Input;
	do
	{
		char c;
		if((c = std::cin.get()) == '\n') return 0;
		else std::cin.putback(c);
		std::cin >> Input;
		if(std::cin.fail())
		{
			std::cin.clear();
			char c;
			do; while((c = std::cin.get()) != '\n');
			std::cout << "\a";
			std::cout << "Perchè mi fai questo? Riprova con un input valido.\n";
			TypeSorter(Input);
			continue;
		}

		if((std::cin.get()!='\n'))
		{
			std::cout << "\a";
			std::cout << "Non inserire spazi o caratteri, per piacere.. Ti ho chiesto un input valido\n";
			char c;
			do;
			while((c=std::cin.get())!='\n');
			continue;
		}
		else break;
	} while(true);
	return Input;
}

#endif
