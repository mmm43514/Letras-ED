/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  * 
  */

#ifndef __Diccionario_h__
#define __Diccionario_h__

#include "ArbolGeneral.h"
#include <vector>
#include <fstream>

struct info{																																			
	char c; ///<< caracter que se almacena en un nodo
	bool final; ///< nos indica si es final o no de palabra
	/**
	  * @brief Constructor por defecto
	  */
	info(){
		c='\0';
		final=false;
	}
	/**
	  * @brief Constructor 
	  * @param car caracter a guardar
	  * @param f indica si ese caracter finaliza una palabra
	  */
	info(char car, bool f):c(car),final(f){}
};

/**
	@brief T.D.A Diccionario

	\b Definición:
	Una instancia \e a del tipo de dato abstracto Diccionario se puede construir como un 
	objeto vacío (diccionario obsoleto) cuando no contenga ningún elemento

	El Diccionario se monta en base al T.D.A ArbolGeneral, cada palabra es alamacenada 
	guardando sus caracteres sobre un ArbolGeneral.

	Para poder usar el tipo de dato Diccionario se debe incluir el fichero

	<tt>\#include Diccionario.h</tt>

	Un ejemplo de su uso:
	@include testdiccionario.cpp
	
	@author Mario Muñoz Mesa
	@date Enero 2016
*/

class Diccionario{
private:
/**
  * @page repConjunto Rep del TDA Diccionario
  *
  * @section invConjunto Invariante de la representación
  *
  * Sea @e D, un diccionario. Entonces el invariante de representación es
  * Si @e D es vacío o no, T.datos.empty() == false
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Diccionario representa a
  *
  * (rep.datos)
  *
  */
	ArbolGeneral<info> datos;
public:
	/**
	@brief Construye un diccionario vacío.
	**/
	Diccionario();
	/**
	@brief Devuelve el numero de palabras en el diccionario
	**/
	int size() const ;
	/**
	@brief Obtiene todas las palabras en el diccionario de un longitud dada
	@param longitud: la longitud de las palabras de salida
	@return un vector con las palabras de longitud especifica en el parametro de entrada
	**/
	vector<string> PalabrasLongitud(unsigned int longitud);
	/**
	@brief Indica si una palabra está en el diccionario o no
	@param palabra: la palabra que se quiere buscar
	@return true si la palabra esta en el diccionario. False en caso contrario
	**/
	bool Esta(string palabra);
	/**
	@brief Lee de un flujo de entrada un diccionario
	@param is:flujo de entrada
	@param D: el objeto donde se realiza la lectura.
	@return el flujo de entrada
	**/
	friend istream & operator>>(istream & is,Diccionario &D);
	/**
	@brief Escribe en un flujo de salida un diccionario
	@param os:flujo de salida
	@param D: el objeto diccionario que se escribe
	@return el flujo de salida
	**/
	friend ostream & operator<<(ostream & os, const Diccionario &D);

	/**
	  * @brief Iterador del TDA Diccionario
	  */

	class iterator{
	private:
		ArbolGeneral<info>::iter_preorden it;
		string cad; 
	public:
		/**
		  * @brief Constructor por defecto
		  */
		iterator ();
		/**
		  * @brief Obtiene la palabra
		  */
		string operator *();
		/**
		  * @brief Obtiene una iterador que apunta a la siguiente palabra
		  */
		iterator & operator ++();
		/**
		  * @brief Compara dos iteradores
		  * @param i: iterador con el que se compara
		  * @return true si los dos iteradores son iguales. False en el caso contrario
		  */
		bool operator ==(const iterator &i);
		/**
		  * @brief Compara dos iteradores
		  * @param i: iterador con el que se compara
		  * @return false si los dos iteradores son diferentes. True en el caso contrario
		  */
		bool operator !=(const iterator &i);
		friend class Diccionario;
	};

	iterator begin();
	iterator end();
	
	class const_iterator{
	private:
		ArbolGeneral<info>::const_iter_preorden it;
		string cad; 
	public:
		/**
		  * @brief Constructor por defecto
		  */
		const_iterator ();
		/**
		  * @brief Obtiene la palabra
		  */
		const string operator *();
		/**
		  * @brief Obtiene una iterador que apunta a la siguiente palabra
		  */
		const_iterator & operator ++();
		/**
		  * @brief Compara dos iteradores
		  * @param i: iterador con el que se compara
		  * @return true si los dos iteradores son iguales. False en el caso contrario
		  */
		bool operator ==(const const_iterator &i);
		/**
		  * @brief Compara dos iteradores
		  * @param i: iterador con el que se compara
		  * @return false si los dos iteradores son diferentes. True en el caso contrario
		  */
		bool operator !=(const const_iterator &i);
		friend class Diccionario;
	};

	const_iterator begin() const;
	const_iterator end() const;
};

#include "Diccionario.cpp"
#endif
