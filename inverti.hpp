#ifndef INVERTI_HPP
#define INVERTI_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

void inverti()
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
	
	bool DueoQuattro;
	std::cout << "Vuoi invertire solo le prime due colonne (0) o anche le seconde due (1)?" << std::endl;
	std::cin >> DueoQuattro;
	if(!DueoQuattro)
	{
		for(int i=0; i<righe; ++i)
		{
			double casella = Y[i];
			Y[i] = X[i];
			X[i] = casella;
		}
	}
	else
	{
		for(int i=0; i<righe; ++i)
		{
			double casellazza = Y[i];
			Y[i] = X[i];
			X[i] = casellazza;
			casellazza = EY[i];
			EY[i] = EX[i];
			EX[i] = casellazza;
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
