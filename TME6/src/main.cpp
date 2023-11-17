/*void attaque (pid_t adversaire) :
 La phase d'attaque commence par installer un gestionnaire pour le signal SIGINT, qui
décrémente les  points de vie  du processus et ache le nombre de points restants. Si
0 est atteint il ache que le processus se termine, et celui-ci se termine en retournant 1.
 Ensuite le processus envoie un signal SIGINT à l'adversaire ; si cette invocation échoue,
on suppose que l'adversaire a déjà perdu, et le processus sort avec la valeur 0 ;
 Ensuite le processus s'endort pour une durée aléatoire.
• void defense()
 La phase de défense consiste à désarmer le signal SIGINT en positionnant son action à
SIG_IGN ;
 Ensuite le processus s'endort pour une durée aléatoire.
• void combat(pid_t adversaire) : boucle indéniment sur une défense suivie d'une attaque et
invoquez-la dans le corps des deux ls.*/
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#include "rsleep.h"

int pdv = 3;

/*Handler du signal*/
void perdrePdv(int){        //Respecter la signature des handler
    pdv --;
    std::cout << getpid() << " perd un pdv" << std::endl;

    if (pdv==0){//mort du processus
        std::cout << "Je meurs !" << std::endl;
    }
}

void attaque (pid_t adversaire){
    struct sigaction sa = {0};
    sa.sa_handler= &perdrePdv;
    sigaction(SIGINT, &sa, NULL);       //Redef du handler pour le signal SIGINT
    if (kill(adversaire,SIGINT)==-1){
        exit(0);
    }
    randsleep();
}

void defense(){
    /*Désarmer le signal en posant son sigation à SIGIN*/
    struct sigaction sa = {0};
    sa.sa_handler = SIG_IGN ;       //routine qui fait ignorer le signal
    sigaction(SIGINT, &sa, NULL);
}

void combat(pid_t adversaire){
    while(1){
        defense();
        attaque(adversaire);
    }
}

/*Voir comment faire les appels avec une situation père fils*/
int main(){
    pid_t Eteocle = fork();
    if (Eteocle != 0){      //Code du père
        pid_t Polynice = fork();
    }
}