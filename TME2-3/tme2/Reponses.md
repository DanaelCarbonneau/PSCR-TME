# 1.1 std::vector std::pair

## Comptage du nombre de mots 

Parsing took 364ms.
Found a total of 566193 words.

## Comptage du nombre de mots différents

(compilation faite avec -O2)

Parsing took 3175ms.
Amount of different words 20333.

## Comptage d'occurences précises

Parsing took 3439ms.
Occurences of "war" : 298
Occurences of "peace" : 114
Occurences of "toto" : 0

À peu près la même complexité que le comptage de mots différents.
## Complexité

Notre complexité est en O(n^2) : il faut parcourir tout le texte de n mots, et pour chaque mot, on parcourt un tableau dont la taille est en O(n) pour le trouver, on peut donc majorer par O(n^2).

## 1.2 Table de Hash
Amount of different words 20333
Occurences of "war" : 298
Occurences of "peace" : 114
Occurences of "toto" : 0
Finished Parsing War and Peace
Parsing took 443ms.
Found a total of 566193 words.

## 1.3 Mots les plus fréquents (main2.cpp)

Afin de pouvoir itérer sur la table de hachage, pour la suite de l'exercice, nous utiliserons la table de hachage standard (`unordered_map`) de sorte à pouvoir utiliser les itérateurs dessus sans avoir à les coder à nouveau.

Ses performances sont à peu près égales aux notres : 

Parsing took 631ms.
Found a total of 566193 words.
Amount of different words 20333
Occurences of "war" : 298
Occurences of "peace" : 114
Occurences of "toto" : 0


Après avoir itéré sur cette table pour récupérer les fréquences dans un tableau et l'avoir trié, on obtient l'affichage suivant :

Amount of different words 20333
Occurences of "war" : 298
Occurences of "peace" : 114
Occurences of "toto" : 0

Finished Parsing War and Peace
Parsing took 488ms.
Found a total of 566193 words.
