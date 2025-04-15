#pragma once					

#include <string>

using namespace std;

namespace UtilisLibrary{
	bool lettura_valori(const string& file_input, size_t& n, double& S, double*& w, double*& r);
	
	string from_array_to_string (const double* const& array, const size_t& n);
	
	double rate_of_return (const double* const& w, const double* const& r, const size_t& n);
	
	double portfolio_finale (const double* const& w, const double* const& r, const double& portfolio_inizialr, const size_t& n);
}

//lettura_valori importo i valori dal file data.txt

//converto array in stringhe

//calcolo il rate of return

//calcolo il valore finale del portfolio, V
