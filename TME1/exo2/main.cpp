
#include<iostream>
#include "myString.hh"


using namespace std;

int main(){

    /*=====Test de nos primitives sur les chaînes de caractère (char*)=====*/
    cout << "====Tests des primitives sur les char*===="<< endl;
    const char * str1 = "lorem ipsum dolor";
    const char* str0 = "";
    cout << "Test de length OK : " << ((pr::length(str1) ==17) && (pr::length(str0) ==0)) <<endl;
    char* str2 = pr::newcopy(str1);
    cout << "Copie de la première chaîne : " << str2 << endl;
    delete[] str2;

    /*=====Tests avec la classe mString=====*/
    cout << "\n====Tests avec la classe mString===="<< endl;
    /*constructeur avec une chaîne de caractères (char*)*/
    pr::mString mstr3 = "sit amet";
    cout << "mString : " << mstr3 << endl;   //Surcharge de <<
    
    /*Constructeur par copie d'un mString*/
    pr::mString  mstr4 = mstr3;    
    cout << "mString avec un constructeur par copie : " <<  mstr4 << endl;

    /*Test de l'affectation (surcharge de =)*/
    pr::mString  mstr5 = "consectetur adipiscing elit";
     mstr4 =  mstr5;
    cout << "mString à qui on a affecté une autre mString : " <<  mstr4 <<endl;

    /*Test des comparaisons (surcharge de == et <)*/
    bool tests = ( mstr5== mstr4) && !(mstr3== mstr5) && !(mstr3 <  mstr4) && ( mstr5 < mstr3);
    cout << "Tests comparaison OK : " << tests << endl;
}