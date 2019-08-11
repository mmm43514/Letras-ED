
/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PÚBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


Diccionario::Diccionario(){
	info raiz('#',true);
	datos = ArbolGeneral<info>(raiz);
}

/*____________________________________________________________ */

int Diccionario::size() const{
	Diccionario::const_iterator it;
	int tamanio = 0;

	for (it = begin(); it != end(); ++it){
		tamanio++;
	}

	return tamanio;
}

/*____________________________________________________________ */

vector<string> Diccionario::PalabrasLongitud(unsigned int longitud){
	Diccionario::iterator it;
	vector<string> palabras;
	
	for (it = begin(); it != end(); ++it){
		if ((*it).size() == longitud){
			palabras.push_back(*it);
		}
	}

	return palabras;
}

/*____________________________________________________________ */

bool Diccionario::Esta(string palabra){
	Diccionario::iterator it;

	for (it = begin(); it != end(); ++it){
		if (*it == palabra)
			return true;
	}
	
	return false;
}

/*____________________________________________________________ */

istream& operator >>(istream& in, Diccionario& D){
	char caracter;
	bool des_directo;
	bool no_escrito;
	typename ArbolGeneral<info>::Nodo n;
	typename ArbolGeneral<info>::Nodo aux, desc;
	info insertar;

	while (in.peek() != EOF){
		n = D.datos.raiz();
		while ((caracter = in.get()) != '\n'){
			no_escrito = true;
			while (no_escrito){
				if (D.datos.hijomasizquierda(n) == 0){
					insertar.c = caracter;
					if (in.peek() == '\n')
						insertar.final = true;
					else
						insertar.final = false;
					ArbolGeneral<info> a(insertar);
					D.datos.insertar_hijomasizquierda(n,a);
					n = D.datos.hijomasizquierda(n);
					no_escrito = false;
				}
				else{
					des_directo = false;
					aux = D.datos.hijomasizquierda(n);
					while (aux != 0 && !des_directo){
						desc = aux;
						if (D.datos.etiqueta(aux).c == caracter){
							des_directo = true;
						}
						aux = D.datos.hermanoderecha(aux);
					}
					if (des_directo){
						n = desc;
						no_escrito = false;
					}
					else{
						insertar.c = caracter;
						if (in.peek() == '\n')
							insertar.final = true;
						else
							insertar.final = false;
						ArbolGeneral<info> b(insertar);
						D.datos.insertar_hermanoderecha(desc,b);
						n = D.datos.hermanoderecha(desc);
						no_escrito = false;
					}
				}
			}
		}
	}
	return in;
}

/*____________________________________________________________ */

ostream & operator<<(ostream & os, const Diccionario &D){
	Diccionario::const_iterator it;

	it = D.begin();
	
	while (it != D.end()){
		os << *it << endl;
		++it;
	}

	return os;
}

/*____________________________________________________________ */

inline Diccionario::iterator::iterator(){
	cad = "";
}

/*____________________________________________________________ */

inline string Diccionario::iterator::operator*(){
	return cad;
}

/*____________________________________________________________ */

Diccionario::iterator& Diccionario::iterator::operator++(){
	int nivel = it.getlevel();
	
	++it;
	if (it.getlevel() != 0){
		if (nivel > it.getlevel()){
			cad.resize(it.getlevel() - 1);
		}
		cad.push_back((*it).c);
		if ((*it).final){
			return *this;
		}

		do{
			++it;
			cad.push_back((*it).c);
		}while(!(*it).final);
	}
	return *this;
}

/*____________________________________________________________ */

bool Diccionario::iterator::operator ==(const Diccionario::iterator &i){
	return it == i.it;
}

/*____________________________________________________________ */

bool Diccionario::iterator::operator !=(const Diccionario::iterator &i){
	return it != i.it;
}

/*____________________________________________________________ */

typename Diccionario::iterator Diccionario::begin(){
	Diccionario::iterator iter;
	iter.it = datos.begin();
	iter.cad = "";

	return iter;
}

/*____________________________________________________________ */

typename Diccionario::iterator Diccionario::end(){
	Diccionario::iterator iter;
	iter.it = datos.end();
	iter.cad = "";

	return iter;	
}

/*____________________________________________________________ */

inline Diccionario::const_iterator::const_iterator(){
	cad = "";
}

/*____________________________________________________________ */

inline const string Diccionario::const_iterator::operator*(){
	return cad;
}

/*____________________________________________________________ */

Diccionario::const_iterator& Diccionario::const_iterator::operator++(){
	int nivel = it.getlevel();
	
	++it;
	if (it.getlevel() != 0){
		if (nivel > it.getlevel()){
			cad.resize(it.getlevel() - 1);
		}
		cad.push_back((*it).c);
		if ((*it).final){
			return *this;
		}

		do{
			++it;
			cad.push_back((*it).c);
		}while(!(*it).final);
	}
	return *this;
}

/*____________________________________________________________ */

bool Diccionario::const_iterator::operator==(const Diccionario::const_iterator &i){
	return it == i.it;
}

/*____________________________________________________________ */

bool Diccionario::const_iterator::operator!=(const Diccionario::const_iterator &i){
	return it != i.it;
}

/*____________________________________________________________ */

Diccionario::const_iterator Diccionario::begin() const{
	Diccionario::const_iterator iter;
	iter.it = datos.begin();

	return iter;
}

/*____________________________________________________________ */

Diccionario::const_iterator Diccionario::end() const{
	Diccionario::const_iterator iter;
	iter.it = datos.end();

	return iter;	
}
	

