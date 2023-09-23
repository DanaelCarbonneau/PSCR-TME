
#include<iostream>
#include "myString.hh"

using namespace std;

int main(){
    const char * str1 = "lorem ipsum dolor";

    cout << "Longueur de -lorem ipsum dolor- : " << pr::length(str1)<<endl;

    char* str2 = pr::newcopy(str1);

    cout << "Copie de la première chaîne : " << str2 << endl;

    delete[] str2;


    pr::mString str3 = "sit amet";

    cout << "Voilà la chaîne de la classe string : " << str3 << endl;

    pr::mString str4 ;      //On ne peut pas faire l'affectation directement (?), sinon l'opérateur re défini n'est pas utilisé...
    str4= str3;            

    cout << "Voilà la chaîne de la classe string ayant été crée en faisant une affectation : " << str4 << endl;

    pr::mString str5 = "consectetur adipiscing elit";

    cout << "Tests de la comparaison entre nos différentes string\n" << 
    "\tstr3 == str4 (attendu : vrai) " << (str3==str4) <<endl
    <<"\tstr3 == str5 (attendu : faux) " <<(str3==str5) << endl
    <<"\tstr3 < str4 (attendu : faux) " << (str3 < str4) <<endl
    <<"\tstr5 < str3 (attendu : vrai) " << (str5 < str3) << endl;;
     

}