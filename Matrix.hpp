#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Matrice
{
	public:
	int righe;
	int colonne;
	double **m;
/////////////////////Costruttori
	Matrice (int rig, int col) 
	{
		righe = rig;
		colonne = col;
		m = new double *[righe];
		cout << "Che valori ci vuoi mettere?" << '\n';
		for (int i = 0; i < colonne; ++i)
		{
			m[i] = new double [colonne];
		}
		
		for (int i = 0; i < colonne; ++i) 
		{
			for (int j = 0; j < righe; ++j)
			{
				cin >> m[i][j] ;
			}
		}
		
	}
	Matrice (int rig, int col, double a) 
	{
		righe = rig;
		colonne = col;
		m = new double *[righe];
		for (int i = 0; i < colonne; ++i)
		{
			m[i] = new double [colonne];
		}
		for (int i = 0; i < colonne; ++i) 
		{
			for (int j = 0; j < righe; ++j)
			{
				m[i][j] = a ;
			}
		}

	}
	
	Matrice (int rig, int col, double a, bool diag) 
	{
		righe = rig;
		colonne = col;
		m = new double *[righe];
		for (int i = 0; i < colonne; ++i)
		{
			m[i] = new double [colonne];
		}
		for (int i = 0; i < a; ++i) 
		{
				m[i][i] = 1 ;
		}
		m[a][a] = 80 ;
		m[a+1][a+1] = 80 ;
		m[a][a+1] = 50 ;
		m[a+1][a] = 40 ;


	}
	
	
/////////////////////Operatori



	friend ostream & operator << (ostream &, Matrice );
	Matrice operator = (Matrice mat2)
	{	
 			
 		if (this->colonne==mat2.colonne && this->righe == mat2.righe)
 		{
 			Matrice matass(this->righe, mat2.colonne, 0.);
 			for (int i = 0; i < mat2.colonne; ++i)
 			{	
 				for (int j = 0; j < mat2.righe; ++j)
 				{
 				matass.m[i][j] = mat2.m[i][j];
 				}
 			}	
 			return matass;
 		}

 	}
	Matrice operator + (Matrice mat2)
	{	
 			
 		if (this->colonne==mat2.colonne && this->righe == mat2.righe)
 		{
 			Matrice matsum(this->righe, mat2.colonne, 0.);
 			for (int i = 0; i < mat2.colonne; ++i)
 			{	
 				for (int j = 0; j < mat2.righe; ++j)
 				{
 				matsum.m[i][j] = this->m[i][j] + mat2.m[i][j];
 				}
 			}	
 			return matsum;
 		}

 	}
	
	Matrice operator - (Matrice mat2)
	{	
 		Matrice matsub(this->righe, mat2.colonne, 0.);
 		if(this->colonne==mat2.colonne && this->righe == mat2.righe) 	
 		{	
 			for (int i = 0; i < mat2.colonne; ++i)
 			{	
 				for (int j = 0; j < mat2.righe; ++j)
 				{
 				matsub.m[i][j] = this->m[i][j] - mat2.m[i][j];
 				}
 			}	
 			return matsub;
 		}	
 		
	}

	Matrice operator * (double a)
	{	
 		Matrice matmulti(this->righe, this->colonne, 0.);
 			for (int i = 0; i < this->colonne; ++i)
 			{	
 				for (int j = 0; j < this->righe; ++j)
 				{
 				matmulti.m[i][j] = this->m[i][j] * a;
 				}
 			}	
 		return matmulti;	
	}

	Matrice operator / (double a)
	{	
 		Matrice matdiv(this->righe, this->colonne, 0.);
 			for (int i = 0; i < this->colonne; ++i)
 			{	
 				for (int j = 0; j < this->righe; ++j)
 				{
 				matdiv.m[i][j] = this->m[i][j] / a;
 				}
 			}	
 		return matdiv;	
	}

	Matrice operator * (Matrice mat2)
	{
		Matrice matmulti(this->righe, mat2.colonne, 0.);
		double *a = new double [this->righe];
		double b = 0;
 		for(int i = 0; i < this->righe; ++i)
 		{ 
        	for(int j = 0; j < mat2.colonne; ++j)
        	{
            	for(int k = 0; k < this->colonne; ++k)
            	{
                	matmulti.m[i][j] += this->m[i][k] * mat2.m[k][j];
            	}
            }
        }
       

    	return matmulti;
	}

	Matrice() {}
};

ostream & operator << (ostream &os, Matrice mat)
	{
		os << "Ecco la tua matrice: " << "\n\n";
		
		for (int i = 0; i < mat.colonne; ++i)
		{
			for (int j = 0; j < mat.righe; ++j)
			{

				os << mat.m[i][j] << '\t';

			}
			os << '\n';
		}
		os << '\n';
	}	


#endif
