#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <unordered_map>
using namespace std;

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

	std::unordered_map htab = unordered_map<string,int>();

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

		auto word_count = htab.find(word);
		if (word_count != htab.end()){
			++(word_count->second);
		}
		else {
			htab.emplace(word,1);		//Ajoute l'entrée à la table de hachage (il y a une occurence actuellement)
		}

		// word est maintenant "tout propre"
		if (nombre_lu % 100 == 0)
			// on affiche un mot "propre" sur 100
			cout << nombre_lu << ": "<< word << endl;
		nombre_lu++;
	}
	input.close();

/*Trier le nombre d'occurences, itérateur à utiliser donc utiliser la hmap de la lib standard*/

	std::vector<pair<string,int>> tab;

	for (auto it : htab){
		tab.push_back(pair(it.first,it.second));
	}

	std::sort(tab.begin(),tab.end(), [] (const pair<string,int> & a, const pair<string,int> & b) { return a.second > b.second ; });

	
	cout << "Amount of different words " << tab.size()<<endl;
	cout << "Occurences of \"war\" : " << nbOccurenceMot(tab,"war") << endl;
	cout << "Occurences of \"peace\" : " << nbOccurenceMot(tab,"peace") << endl;
	cout << "Occurences of \"toto\" : " << nbOccurenceMot(tab,"toto") << endl;
	
	cout << "\nFinished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
    cout << "Parsing took "
              << duration_cast<milliseconds>(end - start).count()
              << "ms.\n";

	cout << "Found a total of " << nombre_lu << " words." << endl; 


	



    return 0;
}


