#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//ho assunto che il formato del file sia GIUSTO!!!
namespace UtilisLibrary{

bool lettura_valori(const string& file_input, size_t& n, double& S, double*& w, double*& r)	
{
	ifstream file;
	file.open(file_input);
	if (file.fail())
	{
		cerr << "Vi è un errore nell'apertura del file" << endl;
		return false;
	}
	
	//S, cioè la somma totale
	string riga;
	getline(file, riga);
	size_t posizione = riga.find(";");					//cerco la posizione di ;
	string stringaS = riga.substr (posizione+1);
	S = stod(stringaS);									//questa è double S
	
	//n, cioè il numero di attività	
	getline(file, riga);
	posizione = riga.find(";");							//cerco la posizione di ;
	string stringan = riga.substr (posizione+1);
	n = stod(stringan);									//questa è double n
	
	//salto la riga w;r priva di informazioni
	getline (file, riga);
	
	//creo i vettori w e r
	w = new double[n];
	r = new double[n];
	size_t i = 0; 										//i è un contatore
	
	//w e r, cioè frazione di S e tasso di rendimento dell'attività i-esima
	while (!file.eof() and i<n)
	{
		string riga;
		getline (file, riga);
		posizione = riga.find(";");							//cerco la posizione di ;
		string stringa_w = riga.substr(0, posizione);
		string stringa_r = riga.substr (posizione +1);
		double wi = stod (stringa_w);					//questo è il valore double di w
		double ri = stod (stringa_r);					//questo è il valore double di r
		w[i] = wi;										//aggiungo wi all'array w
		r[i] = ri;										//ri a r
		i++;
	}
	file.close();
	return true;
}

string from_array_to_string (const double* const& array, const size_t& n)
{
	string str;											//stringa vuota che viene riempita con i numeri dell'array
	ostringstream toString;								//stringa che permette di aggiungere valori double
	//formatto come richiesto
	toString << "[ ";
	for (size_t i=0; i < n; i++)
	{
		toString << array[i] << " ";
	}
	toString << "]";
	
	return toString.str();								//trasforma toString che era ostringstream in una stringa "normale"
}

double rate_of_return (const double* const& w, const double* const& r, const size_t& n)
{
	//so che rate_of_return è r[i]*w[i]
	double rate = 0.0;									//rate è il tasso di interesse
	for (size_t i=0; i<n; i++)
	{
		rate = rate + w[i]*r[i];
	}
	return rate;
}

double portfolio_finale (const double* const& w, const double* const& r, const double& S, const size_t& n)
{
	//so che V= (1+r[i])*w[i]*S
	double V = 0.0;										//V è il valore finale
	for (size_t i=0; i<n; i++)
	{
		V = V + (1+r[i]) * (w[i]) * S;
	}
	return V;
}
}