
#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

#include "Diccionario.h"
#include "ConjuntoLetras.h"
#include "BolsaLetras.h"

using namespace std;

// Funciones que servirán para ordenar al momento de imprimir según el criterio "L" o "P"

bool pairCompareL(const std::pair<string, int>& firstElem, const std::pair<string, int>& secondElem) {
  return firstElem.first.size() > secondElem.first.size();

}

bool pairCompareP(const std::pair<string, int>& firstElem, const std::pair<string, int>& secondElem) {
  return firstElem.second > secondElem.second;

}

int main(int argc, char* argv[]){

	string directorio = "../datos/";
	ifstream f_d(string(string(directorio) + argv[1]).c_str());

	if (!f_d){
		cout << "Error al abrir el diccionario" << endl;
		return(-1);
	}

	ifstream f_l(string(string(directorio) + argv[2]).c_str());

	if (!f_l){
		cout << "Error al abrir el fichero con las letras" << endl;
		return(-1);
	}

	if ((strcmp(argv[4], "L") != 0) && (strcmp(argv[4], "P") != 0)){
		cout << "Modo juego introducido --> " << argv[4];
		cout << "Modo de juego incorrecto" << endl;
		return(-1);
	}

	Diccionario dic;
	f_d >> dic;

	ConjuntoLetras c_l;
	f_l >> c_l;

	BolsaLetras bolsa_l;
	c_l >> bolsa_l;

	char continuar;
	unsigned int num_letras = atoi(argv[3]);
	int tam_bolsa = bolsa_l.size();
	srand(time(0));
	vector<Letra> letras;
	Letra le;
	int num_aleatorio;
	string pal_letras;
	bool solucion_val;
	string posible_sol;
	vector<Letra> letras_encontradas;
	vector<string> palabras_checkear;
	vector<string>::iterator it_checkear;
	string palabra_checkear;
	string palabra;
	vector<pair<string,int> > encontradas; 
	pair<string,int> p;

	unsigned int cont_usadas;
	bool salir;
	char letra_actual;
	vector<bool> letras_usadas(num_letras, false);
	vector<bool>::iterator it_l_u;
	do{

		cout << "Las letras son: ";
		
		for(unsigned int i = 0; i < num_letras; i++){
			num_aleatorio = rand() % tam_bolsa;
			le = bolsa_l[num_aleatorio];
			cout << *le << "\t";
			letras.push_back(le);
		}

		for (unsigned int i = 0; i < letras.size(); i++){
			palabra.push_back(tolower(*letras[i]));
		}

		do{
			cout << "\nDime tu solución: ";
			cin >> posible_sol;
			if (posible_sol.size() > num_letras){
				cout << "Número de letras incorrecto." << endl;
				solucion_val = false;
			}
			if (dic.Esta(posible_sol) == false){
				cout << "La palabra introducida no es solución válida" << endl;
				solucion_val = false;
			}
			else{
				cout << posible_sol << "\tPuntuación: " << c_l.Puntuacion(posible_sol) << endl;
				solucion_val = true;
			}
		}while(!solucion_val);

		cout << "\nMis soluciones son: " << endl;

		// Pruebo con las diferentes longitudes de palabra
		for (int i = num_letras; i > 0; i--){
			palabras_checkear = dic.PalabrasLongitud(i);
			// Por cada longitud pruebo las palabras individualemente
			for (it_checkear = palabras_checkear.begin(); it_checkear != palabras_checkear.end(); ++it_checkear){
			//	cout << "pasa el segundo for " << endl;
				palabra_checkear = *it_checkear;
				for (it_l_u = letras_usadas.begin(); it_l_u != letras_usadas.end(); ++it_l_u){
					*it_l_u = false;
				}
				cont_usadas = 0;
				// Recorro todas las letras de la palabra en cada caso
				for (unsigned int l_actual = 0; l_actual < palabra_checkear.size(); l_actual++){
					//cout << "pasa el tercer for" << endl;
					salir = false;
					letra_actual = palabra_checkear[l_actual];
					// Por cada letra anterior recorro las que se generaron y voy "anotando" cuales están
					for (unsigned int l_orig = 0; !salir && l_orig < palabra.size(); l_orig++){// cout << " pasa el  cuarto for " << endl;
						if (!letras_usadas[l_orig] && palabra[l_orig] == letra_actual){
							letras_usadas[l_orig] = true;
							cont_usadas++;
							salir = true;
						}
					}
				}
				// La palabra que todas sus letras estén en las que se generaron es una solución
				if (cont_usadas == palabra_checkear.size()){
					p.first = palabra_checkear;
					p.second = c_l.Puntuacion(palabra_checkear);
					encontradas.push_back(p);
				}
			}
		}
		
		if (strcmp(argv[4], "L") == 0)
			sort(encontradas.begin(), encontradas.end(), pairCompareL);
		else if (strcmp(argv[4], "P") == 0)
			sort(encontradas.begin(), encontradas.end(), pairCompareP);
		else
			cout << "Modo incorrecto" << endl;
			
		vector<pair<string, int> >::iterator it_v;
		for(it_v = encontradas.begin(); it_v != encontradas.end(); ++it_v){
			cout << it_v->first << " Puntuación--> " << it_v->second << endl;
		}
	cout << "¿Quieres seguir jugando[S/N]?";
	cin >> continuar;

	encontradas.clear();
	letras.clear();
	palabra.clear();
	palabras_checkear.clear();
	letras_encontradas.clear();
	}while(tolower(continuar) != 'n');

}
			


