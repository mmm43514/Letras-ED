
/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PRIVADAS
/*____________________________________________________________ */
/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::destruir(Nodo n){
	if (n != 0){
		destruir(n->izqda);
		nodo* aux = n->izqda;

		while (aux != 0){
			aux = (*aux).drcha;
			destruir(aux);
		}

		delete n;
	}
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::copiar(Nodo& dest, Nodo orig){
	if (orig == 0){
		dest = 0;
	}
	else{
		dest = new nodo;
		dest->etiqueta = orig->etiqueta;
		copiar(dest->izqda, orig->izqda);
		nodo* aux1 = dest->izqda;
		nodo* aux2 = orig->izqda;

		while (aux2 != 0){
			aux1 = (*aux1).drcha;
			aux2 = (*aux2).drcha;
			copiar(aux1, aux2);
		}
	}
}

/*____________________________________________________________ */

template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo* n) const{
	if (n == 0){
		return 0;
	}

	if (n->izqda == 0){
		return 1;
	}

	nodo* aux = n->izqda;
	int num_hermanos = 0;

	while (aux != 0){
		aux = (*aux).drcha;
		num_hermanos = num_hermanos + contar(aux);
	}

	return num_hermanos + 1 + contar(n->izqda);
}

/*____________________________________________________________ */

template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const typename ArbolGeneral<Tbase>::nodo * n1, const typename ArbolGeneral<Tbase>::nodo * n2) const{
	if (n1 == 0 && n2 == 0){
		return true;
	}
	if (n1 == 0 || n2 == 0){
		return false;
	}
	if (n1->etiqueta != n2->etiqueta){
		return false;
	}
	if (n1->izqda != 0 || n2->izqda != 0){
		if (!soniguales(n1->izqda, n2->izqda)){
			return false;
		}
		typename ArbolGeneral<Tbase>::nodo* aux1 = n1->izqda->drcha;
		typename ArbolGeneral<Tbase>::nodo* aux2 = n2->izqda->drcha;
		while ((aux1 != 0 || aux2 != 0) && soniguales(aux1, aux2)){
			aux1 = (*aux1).drcha;
			aux2 = (*aux2).drcha;
		}
		if (aux1 != 0 || aux2 != 0){
			return false;
		}
	}
		return true;
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(ostream& out, Nodo nod) const{
	if (nod == 0){
		out << "x ";
	}
	else{
		out << "n " << nod->etiqueta << " ";
		escribe_arbol(out, nod->izqda);
		typename ArbolGeneral<Tbase>::nodo* aux = nod->izqda;
		while (aux != 0){ if (aux->etiqueta == 'r' && aux->drcha == 0){}
			aux = (*aux).drcha;
			escribe_arbol(out, aux);
		}
	}
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(istream& in, Nodo& nod){
	char c;
	in >> c;
	if (c == 'n'){
		nod = new nodo;
		in >> nod->etiqueta;
		lee_arbol(in, nod->izqda);
		typename ArbolGeneral<Tbase>::nodo* aux = nod->izqda;
		while (/*in.peek() != 'n' &&*/ aux != 0){
			aux = (*aux).drcha; 
			lee_arbol(in, aux);
		}
	}
	else{
		nod = 0;
	}
}

/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PÚBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(){
	laraiz = 0;
}

/*____________________________________________________________ */

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
	laraiz = new nodo;
	laraiz->padre = laraiz->izqda = laraiz->drcha = 0;
	laraiz->etiqueta = e;
}

/*____________________________________________________________ */

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const ArbolGeneral<Tbase>& v){
	copiar(laraiz, v.laraiz);
	if (laraiz != 0){
		laraiz->padre != 0;
	}
}

/*____________________________________________________________ */

template <class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
	destruir(laraiz);
}

/*____________________________________________________________ */

template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator=(const ArbolGeneral<Tbase>& v){
	if (this != &v){
		destruir(laraiz);
		copiar(laraiz, v.laraiz);
		if (laraiz != 0){
			laraiz->padre = 0;
		}
	}
	return *this;
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
	destruir(laraiz);
	laraiz = new nodo;
	laraiz->padre = laraiz->izqda = laraiz->drcha = 0;
	laraiz->etiqueta = e;
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const{
	return laraiz;
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo p) const{
	assert(p != 0);
	return (p->izqda);
}

/*____________________________________________________________ */

template <class Tbase>
inline typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo p) const{
	assert(p != 0);
	return (p->drcha);
}

/*____________________________________________________________ */


template <class Tbase>
inline typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const Nodo p) const{
	assert(p != 0);
	return (p->padre);
}

/*____________________________________________________________ */

template <class Tbase>
inline Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo p){
	assert(p != 0);
	return (p->etiqueta);
}

/*____________________________________________________________ */

template <class Tbase>
inline const Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo p) const{
	assert(p != 0);
	return (p->etiqueta);
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod){
	destruir(laraiz);
	copiar(laraiz, nod);
	if (laraiz != 0){
		laraiz->padre = 0;
	}
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
	assert(n != 0);
	destruir(dest.laraiz);
	dest.laraiz = n->izqda;
	if (dest.laraiz != 0){
		dest.laraiz->padre = 0;
		n->izqda = 0;
	}
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){
	assert(n != 0);
	destruir(dest.laraiz);
	dest.laraiz = n->drcha;
	if (dest.laraiz != 0){
		dest.laraiz->padre = 0;
		n->drcha = 0;
	}
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
	assert(n != 0);
	destruir(n->izqda);
	Nodo aux = n->izqda;
	n->izqda = rama.laraiz;
	n->izqda->drcha = aux;

	if (n->izqda != 0){
		n->izqda->padre = n;
		rama.laraiz = 0;
	}
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
	assert(n != 0);
	destruir(n->drcha);
	Nodo aux = n->drcha;
	n->drcha = rama.laraiz;
	n->drcha->drcha = aux;

	if (n->drcha != 0){
		n->drcha->padre = n->padre;
		rama.laraiz = 0;
	}
}

/*____________________________________________________________ */

template <class Tbase>
void ArbolGeneral<Tbase>::clear(){
	destruir(laraiz);
	laraiz = 0;
}

/*____________________________________________________________ */

template <class Tbase>
inline int ArbolGeneral<Tbase>::size() const{
	return contar(laraiz);
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolGeneral<Tbase>::empty() const{
	return laraiz == 0;
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolGeneral<Tbase>::operator ==(const ArbolGeneral<Tbase>& v) const{
	return soniguales(laraiz,v.laraiz);
}

/*____________________________________________________________ */

template <class Tbase>
inline bool ArbolGeneral<Tbase>::operator !=(const ArbolGeneral<Tbase>& v) const{
	return !(*this == v);
}

/*____________________________________________________________ */

template <class Tbase>
inline istream& operator >>(istream& in, ArbolGeneral<Tbase>& v){
	v.lee_arbol(in, v.laraiz);
	return in;
}

/*____________________________________________________________ */

template <class Tbase>
inline ostream& operator<<(ostream& out, const ArbolGeneral<Tbase>& v){
	v.escribe_arbol(out, v.laraiz);
	return out;
}


// ITERADOR ITER_PREORDER

template <class Tbase>
ArbolGeneral<Tbase>::iter_preorden::iter_preorden(){
	level = 0;
}

/*____________________________________________________________ */

template <class Tbase>
Tbase& ArbolGeneral<Tbase>::iter_preorden::operator*(){
	return it->etiqueta;
}

/*____________________________________________________________ */

template <class Tbase>
int ArbolGeneral<Tbase>::iter_preorden::getlevel() const{
	return level;
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolGeneral<Tbase>::iter_preorden& ArbolGeneral<Tbase>::iter_preorden::operator++(){
	if (it == 0){
		return *this;
	}
	if (it->izqda != 0){
		it = it->izqda;
		level++;
	}
	else{
		if (it->drcha != 0){
			it = it->drcha;
		}
		else{
			while (it->padre != 0 && it->padre->drcha == 0){
				it = it->padre;
				level--;
			}
			if (it->padre != 0){
				it = it->padre->drcha;
				level--;
			}
			else{
				it = it->padre;
			}
		}
	}
	return *this;
}

/*____________________________________________________________ */
	
template <class Tbase>
bool ArbolGeneral<Tbase>::iter_preorden::operator==(const iter_preorden &i){
	return it == i.it;
}

/*____________________________________________________________ */

template <class Tbase>
bool ArbolGeneral<Tbase>::iter_preorden::operator!=(const iter_preorden &i){
	return it != i.it;
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolGeneral<Tbase>::iter_preorden ArbolGeneral<Tbase>::begin(){
	typename ArbolGeneral<Tbase>::iter_preorden::iter_preorden iterator;
	iterator.it = laraiz;
	iterator.raiz = laraiz;
	iterator.level = 0;
	
	return iterator;
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolGeneral<Tbase>::iter_preorden ArbolGeneral<Tbase>::end(){
	typename ArbolGeneral<Tbase>::iter_preorden::iter_preorden iterator;
	iterator.it = 0;
	iterator.raiz = laraiz;
	iterator.level = 0;
	
	return iterator;
}

// ITERADOR CONST_ITER_PREORDER

template <class Tbase>
ArbolGeneral<Tbase>::const_iter_preorden::const_iter_preorden(){
	level = 0;
}

/*____________________________________________________________ */

template <class Tbase>
const Tbase& ArbolGeneral<Tbase>::const_iter_preorden::operator*(){
	return it->etiqueta;
}

/*____________________________________________________________ */

template <class Tbase>
int ArbolGeneral<Tbase>::const_iter_preorden::getlevel() const{
	return level;
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolGeneral<Tbase>::const_iter_preorden& ArbolGeneral<Tbase>::const_iter_preorden::operator++(){
	if (it == 0){
		return *this;
	}
	if (it->izqda != 0){
		it = it->izqda;
		level++;
	}
	else{
		if (it->drcha != 0){
			it = it->drcha;
		}
		else{
			while (it->padre != 0 && it->padre->drcha == 0){
				it = it->padre;
				level--;
			}
			if (it->padre != 0){
				it = it->padre->drcha;
				level--;
			}
			else{
				it = it->padre;
			}
		}
	}
	return *this;
}

/*____________________________________________________________ */
	
template <class Tbase>
bool ArbolGeneral<Tbase>::const_iter_preorden::operator==(const const_iter_preorden &i){
	return it == i.it;
}

/*____________________________________________________________ */

template <class Tbase>
bool ArbolGeneral<Tbase>::const_iter_preorden::operator!=(const const_iter_preorden &i){
	return it != i.it;
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolGeneral<Tbase>::const_iter_preorden ArbolGeneral<Tbase>::begin() const{
	typename ArbolGeneral<Tbase>::const_iter_preorden::const_iter_preorden iterator;
	iterator.it = laraiz;
	iterator.raiz = laraiz;
	iterator.level = 0;
	
	return iterator;
}

/*____________________________________________________________ */

template <class Tbase>
typename ArbolGeneral<Tbase>::const_iter_preorden ArbolGeneral<Tbase>::end() const{
	typename ArbolGeneral<Tbase>::const_iter_preorden::const_iter_preorden iterator;
	iterator.it = 0;
	iterator.raiz = laraiz;
	iterator.level = 0;
	
	return iterator;
}
