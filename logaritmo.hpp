#ifndef LOGARITMO_HPP
#define LOGARITMO_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

void logaritmo()
{
	int righe, colonne;
	std::cout << "Quante righe e quante colonne?" << std::endl;
	std::cin >> righe >> colonne;
	double X[righe];
	double Y[righe];
	double EX[righe];
	double EY[righe];
	std::ifstream fs("filenamee.txt");
	for(int i=0; i<righe; ++i)
	{
		switch(colonne)
		{
			default:
			case 2:
			{
				fs >> X[i] >> Y[i];
				break;
			}
			case 3:
			{
				fs >> X[i] >> Y[i] >> EY[i];
				break;
			}
			case 4:
			{
				fs >> X[i] >> Y[i] >> EX[i] >> EY[i];
				break;
			}
		}
		fs.ignore(100, '\n');
	}
	fs.close();
	
	bool XoY;
	std::cout << "Vuoi cambiare in logaritmo la X (0) o la Y (1)?" << std::endl;
	std::cin >> XoY;
	if(XoY)
	{
		for(int i=0; i<righe; ++i)
		{
			double casella = Y[i];
			double casellazza = EY[i];
			EY[i] = abs(casellazza/casella);
			Y[i] = log(casella);
		}
	}
	else
	{
		for(int i=0; i<righe; ++i)
		{
			double casella = X[i];
			double casellazza = EX[i];
			EX[i] = abs(casellazza/casella);
			X[i] = log(casella);
		}
	}
	std::ofstream ffs("filename.txt");
	for(int i=0; i<righe; ++i)
	{
		switch(colonne)
		{
			default:
			case 2:
			{
				ffs << std::setprecision(10) << X[i] << '\t' << Y[i] << '\t' << std::endl;
				break;
			}
			case 3:
			{
				ffs << std::setprecision(10) << X[i] << '\t' << Y[i] << '\t' << EY[i] << std::endl;
				break;
			}
			case 4:
			{
				ffs << std::setprecision(10) << X[i] << '\t' << Y[i] << '\t' << EX[i] << '\t' << EY[i] << std::endl;
				break;
			}
		}
	}
	ffs.close();
}
#endif
