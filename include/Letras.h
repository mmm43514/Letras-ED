/**
  * @file Letras.h
  * @brief Fichero cabecera del TDA Letras
  * 
  */


#ifndef __Letra_h__
#define __Letra_h__

#include <iostream>

using namespace std;

/**
	@brief T.D.A Letras

	\b Definición:
	Una instancia \e l del tipo de dato abstracto Letras se puede construir como 
	- Un char y dos int inicializados a un serie de valores dados
	- Como una letra "vacía" en la que los elementos tomarán valores por defecto.
	Cada Letra representa un carácter junto sus apariciones y puntuación.

	Para poder usar el TDA Letra se debe incluir el fichero

	<tt>\#include Letras.h</tt>

	*/
	
class Letra{
/**
    @page repConjunto Rep del TDA Letra
	 
	 @section invConjunto Invariante de la representación
	 
	 Sea @e T, una Letra. El invariante de representación es
		- Si @e T es vacío,  entonces T.caracter = '\0', T.apariciones = 0, T.puntuacion=0
		- Si @e T no es vacío T.caracter, T.apariciones, T.puntuacion adoptarán los valores
		 introducidos

	@section faConjunto Función de abstracción

	Un objeto válido @e rep del TDA Letra representa a
	(rep.caracter, rep.apariciones, rep.puntuacion)

	*/
private:
	char caracter; // caracter de una letra
	int apariciones; // veces que aparece
	int puntuacion; // puntuacion de la letra
public:
	/**
		@brief Constructor por defecto
	*/
	Letra():caracter('\0'), apariciones(0),	puntuacion(0){}
	/**
	 	@brief Constructor de letra
		@param c caracter de la letra
		@param n apariciones de la letra
		@param p puntuacion de la letra
	*/
	Letra (char c, int n, int p):caracter(c), apariciones(n), puntuacion(p){}
	/**
		@brief Sobrecarga del operador *
		@return Devuelve el valor de la letra, el caracter
	*/
	char operator *(){
		return caracter;
	}
	/**
		@brief Sobrecarga del operador <
		@param l1 letra a comparar
		@return devuelve true si la letra es menor que la letra de l1, false en otro caso
	*/
	bool operator <(const Letra &l1)const{
		if (caracter < l1.caracter)
			return true;
		else
			return false;
	}
	/**
		@brief Devuelve el número de apariciones de la letra
	*/
	int Apariciones(){
		return apariciones;
	}
	/**
		@brief Devuelve la puntuación de la letra
	*/
	int getPuntuacion()const{
		return puntuacion;
	}
	/**
		@brief Devuelve el valor de la letra, el caracter
	*/
	int Caracter(){
		return caracter;
	}
	/** 
		@brief Sobrecarga del operador <<
		@param os ostream donde imprimir la letra
		@param letra es la letra a imprimir
	*/
	friend ostream & operator << (ostream & os, const Letra &letra){
		os << letra.caracter << " " << letra.apariciones << " " << letra.puntuacion << endl;
		return os;
	}

};

#endif


