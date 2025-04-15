#include <iostream>
#include <string>
#include "src/Utils.hpp"
#include <fstream>
#include <iomanip>

using namespace std;
using namespace UtilisLibrary;

int main()
{
	//apro il file
	string file_input ("data.txt");
	
	//variabili
	size_t n;
	double S;
	double* w = nullptr;
	double* r = nullptr;
	
	//stampa su schermo
	cout << fixed << setprecision(2) << endl;

	if (lettura_valori(file_input, n, S, w, r))		//cioè se è riuscito a leggere i valori
	{
	cout << "S = " << S << ", " << "n = " << n << endl;
	}
	
	cout << "w: " << from_array_to_string(w, n) << endl;
	cout << "r: " << from_array_to_string(r, n) << endl;
	
	cout << fixed << setprecision(4);
	double rate = rate_of_return(w,r,n);
	cout << "Tasso di rendimento del portafoglio: " << rate << endl;
	
	cout << fixed << setprecision(2);
    double V = portfolio_finale(w, r, S, n);
	cout << "V: " << V << endl;
	
	//stampa su file
	ofstream risultato_output("result.txt", ofstream::trunc); 
	risultato_output << fixed << setprecision(2);
	risultato_output << "S = " << S << ", " << "n = " << n << endl;
	risultato_output << "w = " << from_array_to_string(w, n) << endl;
	risultato_output << "r = " << from_array_to_string(r, n) << endl;
	risultato_output << fixed << setprecision(4);
	risultato_output << "Tasso di rendimento del portafoglio: " << rate << endl;
	risultato_output << fixed << setprecision(2);
	risultato_output << "V: " << V << endl;
	
	delete[] w;
	delete[] r;
	risultato_output.close();
	return 0;
}


