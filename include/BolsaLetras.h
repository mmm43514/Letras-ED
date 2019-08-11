/**
  * @file BolsaLetras.h
  * @brief Fichero cabecera del TDA BolsaLetras
  * 
  */

#ifndef __BolsaLetras_h__
#define __BolsaLetras_h__

#include <set>
#include <iostream>
#include <string>

#include "Letras.h"
#include "ConjuntoLetras.h"

using namespace std;

/**
	@brief T.D.A BolsaLetras

	\b Definición:
	Una instancia \e a del tipo de dato abstracto BolsaLetras se construye como un 
	objeto vacío que se rellena a través de un ConjuntoLetras

	La BolsaLetras se monta en base y a través del T.D.A Letra y el T.D.A ConjuntoLetras.

	Almacena tantas veces repetidas las letras de ConjuntoLetras como indique su campo apariciones.
*/
class BolsaLetras{
private:

	/**
		@page repConjunto Rep del TDA BolsaLetras
		
		@section invConjunto Invariante de la representación
			Sea @e T, una BolsaLetras. El invariante de representación es
			- Si T es vacío T.conjunto.size() == 0
			- Si T se lee desde un ConjuntoLetras T.conjunto.size() != 0
		
		@section faConjunto Función de abstracción
			Un objeto válido del @e rep del TDA BolsaLetras representa a
			
			(rep.bolsa)
	*/
		multiset<Letra> bolsa;

public:

	/**
		@brief Tamaño de la bolsa
	*/
	int size(){
		return bolsa.size();
	}

	/**
		@brief Sobrecarga del operador []
		@param n posición de la bolsa donde se encuentra la letra a devolver
		@return letra que se encontraba el la posición n de la bolsa de letras
	*/
	const Letra & operator[](int n){
		multiset<Letra>::iterator it = bolsa.begin();
		advance(it, n);
		return *it;
	}
	/**
		@brief Sobrecarga del operador <<
		@param os ostream donde imprimir la bolsa de letras
		@param b_l bolsa de letras a imprimir
	*/
	friend ostream& operator <<(ostream& os, const BolsaLetras& b_l){
		multiset<Letra>::iterator it;

		for (it = b_l.bolsa.begin(); it != b_l.bolsa.end(); ++it){
			os << *it << endl;
		}

		return os;
	}
	/** 
		@brief Sobrecarga del operador >>
		@param cl conjunto de letras del que rellenar la bolsa
		@param bl bolsa de letras a rellenar
	*/
	friend ConjuntoLetras& operator>>(ConjuntoLetras &cl, BolsaLetras &bl){

		for (int i=0; i < cl.size(); i++){
			Letra letra = cl[i];
			for (int j=0; j < letra.Apariciones(); j++){
				bl.bolsa.insert(letra);
			}
		}
		return cl;
	}


};

#endif


