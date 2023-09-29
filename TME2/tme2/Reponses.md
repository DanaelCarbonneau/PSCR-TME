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