#pragma once

#include <cstring> // size_t,memset

namespace pr {

#define STACKSIZE 100

template<typename T>
class Stack {

	/* TODO
	* mutex pour les sections critiques
	* sémaphore pour compter les cases vides
	* dans le constructeur, sem init pour les positionner
	* 
	*/
	T tab [STACKSIZE];
	
	size_t sz;
public :
	Stack () : sz(0) { memset(tab,0,sizeof tab) ;}

	T pop () {
		// bloquer si vide
		T toret = tab[--sz];
		return toret;
	}

	void push(T elt) {
		//bloquer si plein
		tab[sz++] = elt;
	}
};

}
