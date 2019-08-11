
#include "ArbolGeneral.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char * argv[]){
  ArbolGeneral<char> tree('h');

	cout << tree;
	if (tree == tree){
		cout << "Tree == Tree";
	}
   ifstream ifs("../prueba.txt",ifstream::in);
	ifs >> tree;cout << "\n";cout << tree << endl;
	if (tree == tree){
		cout << "Tree == Tree";
	} 
	cout << "Sacamos por pantalla con iteradores -- > " << endl;
	ArbolGeneral<char>::iter_preorden it;
	for (it = tree.begin(); it != tree.end(); ++it){
		cout << *it;
	}

}
