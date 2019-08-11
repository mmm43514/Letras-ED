/**
  * @file ConjuntoLetras.h
  * @brief Fichero cabecera del TDA ConjuntoLetras
  * 
  */
#ifndef __ConjuntoLetras_h__
#define __ConjuntoLetras_h__

#include <iostream>
#include <string>
#include "Letras.h"
#include <set>

using namespace std;

/**
	@brief T.D.A ConjuntoLetras
	\b Definición:
	Una instancia \e a del tipo de abstracto ConjuntoLetras se construye a través
	de un archivo con el que se rellena de una serie de letras. Requiere del T.D.A Letra
	es un conjunto de letras.

	Para poder usar el TDA ConjuntoLetras se debe incluir el fichero

	<tt>\#include ConjuntoLetras.h</tt>

	*/
class ConjuntoLetras{
private:
	/**
		@page repConjunto Rep del TDA ConjuntoLetras

		@section invConjunto Invariante de la representación

		Sea @e T, un ConjuntoLetras. El invariante de representación es
			- Si T es vacío T.conjunto.size() == 0
			- Si T se lee desde un archivo T.conjunto.size() != 0

		@section faConjunto Función de abstracción

		Un objeto válido @e rep del TDA ConjuntoLetras representa a
		(rep.conjunto)
	*/
	
	set<Letra> conjunto;
public:
	/**
		@brief Devuelve la puntuación de una palabra
		@param palabra palabra a obtener la puntuación 
		@return suma de la puntuación de cada letra de la palabra, la puntuación de la palabra
	*/
	int Puntuacion (string palabra){
		int puntuacion = 0;
		bool added;
		set<Letra>::iterator it;
		Letra le;
		for (unsigned int i = 0; i < palabra.size(); i++){
			added = false;
			for (it = conjunto.begin(); !added && it != conjunto.end(); ++it){
				le = *it;
				if (palabra[i] == tolower(*le)){
					puntuacion = puntuacion + it->getPuntuacion();
					added = true;
				}
			}
		}

		return puntuacion;
	}
	/**
		@brief Sobrecarga del operador[]
		@param pos posición letra a obtener
		@return devuelve la letra indicada por la posición pos
	*/
	const Letra& operator[](int pos){
		set<Letra>::iterator it;
		it = conjunto.begin();
		advance(it,pos);

		return *it;
	}
	/** 
		@brief Número de elementos de conjunto
	*/
	int size(){
		return conjunto.size();
	}
	/**
		@brief Sobrecarga del operador <<
		@param os ostream donde imprimir el conjunto de letras
		@param conjunto_l conjunto de letras a imprimir
	*/
	friend ostream & operator<<(ostream& os, const ConjuntoLetras & conjunto_l){
		set<Letra>::iterator it;
		for(it = conjunto_l.conjunto.begin(); it != conjunto_l.conjunto.end(); ++it){
			os << *it << endl;
		}

		return os;
	}
	/**
		@brief Sobrecarga del operador >>
		@param is istream donde leer el conjunto de letras
		@param conjunto_l conjunto de letras donde almacenar los datos leídos
	*/
	friend istream& operator >> (istream& is, ConjuntoLetras & conjunto_l){
		string elimina_lineas;
		getline(is,elimina_lineas);
		char caracter_l;
		int repe_l, puntu_l;
		while(is){
			is >> caracter_l >> repe_l >> puntu_l;
			
			Letra l(caracter_l, repe_l, puntu_l);

			conjunto_l.conjunto.insert(l);
		}

		return is;
	}

};

#endif




