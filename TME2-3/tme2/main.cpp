#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include "Hashtable.hpp"
using namespace std;


/*Partie 1*/

/*Fonction qui ajoute un mot s au tableau de fréquences tab*/
void ajouteMotVect(std::vector<std::pair<string,int>> &tab, const string& s){
	for(size_t i = 0; i < tab.size() ; i++){
		if( tab[i].first==s ){
			++tab[i].second;
			return;
		}
	}
	tab.push_back(make_pair(s,1));	//On ne l'a pas trouvé dans le tableau
}

/*Fonction qui retourne le nombre d'occurences de s dans le texte dont les fréquences sont contenues dans tab*/
int nbOccurenceMot(const std::vector<std::pair<string,int>> &tab, const string& s){
	for (size_t i = 0; i < tab.size(); i++){
		if (tab[i].first == s){
			return tab[i].second;
		}
	}
	return 0;
}




int main () {

	using namespace std::chrono;

	ifstream input = ifstream("WarAndPeace.txt");

	auto start = steady_clock::now();

	/*Partie 1*/
	std::vector<std::pair<string,int>> tab;

	/*Partie 2*/
	pr::Hashtable<string,int> htab (30000);

	cout << "Parsing War and Peace" << endl;

	size_t nombre_lu = 0;
	// prochain mot lu
	string word;
	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re( R"([^a-zA-Z])");
	while (input >> word) {
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace ( word, re, "");
		// passe en lowercase
		transform(word.begin(),word.end(),word.begin(),::tolower);


		/*Partie 1*/
		//ajouteMotVect(tab,word);

		/*Partie 2*/

		int* word_count = htab.get(word);
		if (word_count != nullptr){
			++(*word_count);
		}
		else {
			htab.put(word,1);		//Ajoute l'entrée à la table de hachage (il y a une occurence actuellement)
		}

		// word est maintenant "tout propre"
		if (nombre_lu % 100 == 0)
			// on affiche un mot "propre" sur 100
			cout << nombre_lu << ": "<< word << endl;
		nombre_lu++;
	}
	input.close();


/* Partie 1 */
/*
	cout << "Amount of different words " << tab.size()<<endl;
	cout << "Occurences of \"war\" : " << nbOccurenceMot(tab,"war") << endl;
	cout << "Occurences of \"peace\" : " << nbOccurenceMot(tab,"peace") << endl;
	cout << "Occurences of \"toto\" : " << nbOccurenceMot(tab,"toto") << endl;
 */
/* Partie 2 */
	cout << "Amount of different words " << htab.size()<<endl;
	cout << "Occurences of \"war\" : " <<  (htab.get("war") ? *htab.get("war") : 0) << endl;
	cout << "Occurences of \"peace\" : " << (htab.get("peace") ? *htab.get("peace") : 0) << endl;
	cout << "Occurences of \"toto\" : " << (htab.get("toto") ? *htab.get("toto") : 0) << endl;

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

	cout << "Found a total of " << nombre_lu << " words." << endl;	

    return 0;
}


