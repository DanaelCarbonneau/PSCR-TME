# Question 1

L'arbre de processus est une forme de de "peigne" où chaque étage du peigne a i fils qui sont des feuilles (sauf la racine qui n'en a pas).

Fils de forme iFn où n est le numéro en comptant de manière croissante de gauche à droite

R
| 
1F1-------
|        |
|       2F2*
|
2F1------ --------- 
|        |         |
|       3F2*      3F3*
|
3F1------ ---------       
|        |         |
4F1*    4F2*      4F3*

# Question 2
Pour faire nos Waits, on a déduit l'invariant suivant : 

Un noeud dans l'arbre des processus est soit : 

* racine (R)        -> 1 fils
* Fils tout à gauche à l'intérieur du peigne (1F1,2F1 et 3F1) -> i +1 fils
* Feuille (marquées par *)  -> 0 fils
* Bout du peigne (3F1)      -> i fils.

