#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int righe, colonne;
	cout << "Quante righe e quante colonne?" << endl;
	cin >> righe >> colonne;
	double X[righe];
	double Y[righe];
	double EX[righe];
	double EY[righe];
	ifstream fs("filenamee.txt");
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
	cout << "Vuoi cambiare in logaritmo la X (0) o la Y (1)?" << endl;
	cin >> XoY;
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
	ofstream ffs("filename.txt");
	for(int i=0; i<righe; ++i)
	{
		switch(colonne)
		{
			default:
			case 2:
			{
				ffs << setprecision(10) << X[i] << '\t' << Y[i] << '\t' << endl;
				break;
			}
			case 3:
			{
				ffs << setprecision(10) << X[i] << '\t' << Y[i] << '\t' << EY[i] << endl;
				break;
			}
			case 4:
			{
				ffs << setprecision(10) << X[i] << '\t' << Y[i] << '\t' << EX[i] << '\t' << EY[i] << endl;
				break;
			}
		}
	}
	ffs.close();
}
