
#include<iostream>

using namespace std;

int main(){
    cout << "Hello World !" << endl;      //prints Hello World !
    int tab[10] = {0,1,2,3,4,5,6,7,8,9};
    
    //char* a;
    //cout << a;       //Provoque un affichage indéterminé

    for (int i = 9; i >0 ; i--) {
        if (tab[i] - tab[i-1] != 1) {
            cout << "probleme !";
        }
    }

}

