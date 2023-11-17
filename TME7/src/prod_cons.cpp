#include "Stack.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>


using namespace std;
using namespace pr;

void producteur (Stack<char> * stack) {
	char c ;
	while (cin.get(c)) {
		stack->push(c);
	}
}

void consomateur (Stack<char> * stack) {
	while (true) {
		char c = stack->pop();
		cout << c << flush ;
	}
}

int main () {

	/* TODO
	*À mettre dans un segment de mémoire partagé (anonyme)
	qui prend l'adresse 
	* Construire la stak dans la mémoire partagée
	* syntaxe  : 
		new (adresse choisie plutôt qu'un malloc) Constructeur (args)
	*/

	Stack<char> * s = new  (addr) Stack<char>();

	pid_t pp = fork();
	if (pp==0) {
		producteur(s);
		return 0;
	}

	pid_t pc = fork();
	if (pc==0) {
		consomateur(s);
		return 0;
	}

	wait(0);
	wait(0);

	delete s;
	return 0;
}

