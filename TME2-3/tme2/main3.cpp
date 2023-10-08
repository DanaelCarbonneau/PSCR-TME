/*Question 1. Ecrivez une fonction générique size_t count (iterator begin, iterator end) qui
compte le nombre d'éléments entre begin et end.
Question 2. Ecrivez une fonction générique size_t count_if_equal (iterator begin, iterator
end, const T & val) qui compte le nombre d'éléments entre begin et end qui sont égaux à val au
sens de ==.
Question 3. Invoquez ces fonctions dans votre programme qui compte les mots, et contrôlez le
résultat : par exemple une invocation*/

#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include "Hashtable.hpp"
using namespace std;




/*TME3 Partie 1, Algorithm*/
template <typename Iterator>
size_t count (Iterator begin, Iterator end){
    size_t cpt = 0;

    for (auto it = begin; it!=end; ++it){
        ++cpt;
    }
    return cpt;
}

template <typename T, typename Iterator>
size_t count_if_equal (Iterator begin, Iterator end, const T & val){
    size_t cpt = 0;

    for (auto it = begin; it!=end; ++it){
        if (*it == val){
            ++cpt;
        }
    }
    return cpt;
}



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



	cout << "Amount of different words " << htab.size()<<endl;
	cout << "Occurences of \"war\" : " <<  (htab.get("war") ? *htab.get("war") : 0) << endl;
	cout << "Occurences of \"peace\" : " << (htab.get("peace") ? *htab.get("peace") : 0) << endl;
	cout << "Occurences of \"toto\" : " << (htab.get("toto") ? *htab.get("toto") : 0) << endl;

	cout << "Finished Parsing War and Peace" << endl;

    cout << "Nombre d'éléments dans la table de hachage : " << count(htab.begin(),htab.end()) <<endl ;
	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

	cout << "Found a total of " << nombre_lu << " words." << endl;	

    return 0;
}


