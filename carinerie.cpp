#include <iostream>
#include <iomanip>

    //BELLA RIGA DI CODICE CHE FUNZIONA CIRCA COME IGNORE
    //do; while (((c = std::cin.get()) != '\n') || ((c = std::cin.get()) != '\t') );


    //BARRA DI CARICAMENTO
int main()
{
    clock_t t = std::clock();
    clock_t tt;


	int n;
	std::cout << "Dammi n" << std::endl;
	std::cin >> n;
	std::cout << " ";
	for(int i=0; i<n; ++i)
	{
		double percentuale = (double)100.*(double)i/(double)n;
		int percentualeintera = (int)percentuale;
		double differenza = percentuale - percentualeintera;
		if(differenza == 0)
		{
			;
			if(percentuale<10) std::cout << std::setw(2) << percentuale << "%" << "\b\b\b";
			else std::cout << std::setw(3) << percentuale << "%" << "\b\b\b\b";
			std::cout.flush();
		}
		std::cout.flush();
	}
	std::cout << "\b\b\b\b\b100%\ \n";
    
    tt = std::clock();
    std::cout << std::endl << (tt - t)*1e-06 << std::endl;
}
