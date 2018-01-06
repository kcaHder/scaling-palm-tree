#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <cmath>
using namespace std;

template <class X> void Somma_in_quadratura(vector<X> x)
{
    X quadrato;
    for(auto i:x) quadrato+=(i*i);
    cout << setprecision(10) << sqrt(quadrato) << endl;
}
template <class X> void InputCheck(vector<X> &vettore)
{
    int conta;
    cout << "Dammi gli elementi. Quando vuoi smettere, premi Ctrl+D" << endl;
    while(true)
    {
        X input;
        cout << "Elemento numero " << conta+1 << ':' << endl;
        cin >> input;
        if(cin.eof()) break;
        vettore.push_back(input);
        ++conta;
    }
    cin.clear();
}
int main()
{
    vector<double> vettore;
    InputCheck(vettore);
    for(auto i:vettore) cout << i << endl;
    Somma_in_quadratura(vettore);
}
