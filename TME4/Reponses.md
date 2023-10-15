# TME 4 : Mutex et section critique


## Transaction
### Question 1 : Le comportement est-il correct (pas de datarace ) avec les protections actuelles sur le Compte ?

Avec les protections actuelles, on est assuré qu'un compte ne peut être débité ou crédité par plusieurs threads en même temps. Il n'y a donc pas de problèmes de data race. 

Un problème comportemental est qu'il ne crédite pas en même temps qu'il débite : il y a un temps de latence où on crédite et où on débite le compte, pendant lequel le compte crédité pourrait être débité ailleurs, ce qui signifierait qu'il n'aurait dans le compte pas encore assez d'argent, alors que théoriquement, il vient d'être crédité.



### Question 5 Le programme se bloque immédiatement, même avec un seul thread qui fait des transferts. Pourquoi ?

Avec la stratégie de lock les mutex des deux comptes au niveau du transfert, et de les unlock juste après ce dernier, on constate un blocage du code, et ce, même avec un seul thread. Cela s'explique car juste après les avoir lock, nous appelons leurs méthodes `debiter` et `crediter`, ces dernières tentent également de prendre le lock, bloquent le thread, qui ne peut donc jamais s'unlock.

C'est comme si on faisait `m.lock() ; m.lock()`, ce qui bloque le thread à tous les coups.


### Question 6. Après correction du problème précédent à l'aide de recursive_mutex, on introduit plusieurs thread faisant des transferts, mais de nouveau on observe parfois un interblocage, le programme entier se fige. Expliquez pourquoi et corriger le problème.

Le problème est effectivement corrigé pour un seul thread, mais lorsqu'on en remet 10, parfois, on se bloque.

Dans le cas où un thread a pour débiteur c1 et créditeur c2, mais où un autre a pour débiteur c2 et créditeur c1, les locks se faisant dans l'ordre débiteur puis créditeur, on se retrouve avec cette situation, qui est un deadlock :

            T1                  T2
        c1.mutex.lock();    c2.mutex.lock();
        c2.mutex.lock();    c1.mutex.lock();

Pour résoudre ce problème, on veut forcer la prise de lock dans un ordre fixe entre tous les mutex. Pour cela, on va choisir **arbitrairement** de lock les comptes par ordre croissant d'indice dans la table des comptes. On fait attention au cas où le créditeur est débiteur (pour éviter les double lock, on fait une sortie anticipée, puisque l'opération a une somme nulle).


## Comptabilité

### Question 7. Un thread comptable qui tourne en concurrence avec les threads de transfert sera-t-il satisfait avec les synchronisations actuelles ? Expliquez pourquoi.
Il ne le serait pas toujours avec les synchronisations actuelles. Posons une situation où le comptable en est à l'indice k, avec i < k < j. Le solde de i est déjà inclus dans la somme que le comptable construit. Un transfert entre i et j rendra alors la somme jusqu'à l'indice k obsolète car elle correspondrait à d'anciennes données, ce qui rendra inévitablement faux le résultat de la somme.

### Question 9. Ajoutez un mutex dans la banque, et les synchronisations utiles pour que le thread comptable obtienne toujours les bons résultats.


En ajoutant un mutex dans sur la banque, on s'assure que personne n'accède à la banque tant que le comptable fait ses comptes : cela ralentit le programme fortement (chaque comptable bloque tout le monde en faisant sa boucle, on perd beaucoup en parallélisme).

### Question 10 : 
Une solution serait de prendre les locks de toutes les cases que le comptabilisateur visite (et de toutes les libérer après la fin du parcourt). De cette manière, on s'assure qu'aucune transaction ne peut rendre caduque la somme partielle réalisée sur le tableau de comptes. Il faut absolument s'assurer de l'ordre (ordre sur les indices) pour éviter les deadlock.