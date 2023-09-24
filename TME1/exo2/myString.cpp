
#include "myString.hh"

namespace pr{
    size_t length(const char* str){
        const char * c = str;
        while(*c){
            ++c;
        }
        return c - str;
    }

    char * newcopy(const char* str){
        char* res = new char[length(str)+1];
        for (char* it = res; ; ){
            *it = *str;
            ++str;
            if(*it) ++it;
            else break;
        }
        return res;
    }
    /*Constructeur par copie du contenu de ori (permet la gestion mémoire automatique avec le delete *
     *car on sait que pour tous les objets de la classe, str est alloué dynamiquement sur le tas)*/
    mString::mString(const char* ori){str = newcopy(ori);}   
    mString::mString(){str = nullptr;} 
    mString::mString(const mString & ms){
        str = newcopy(ms.str);
    }

    size_t mString::length(){
        return pr::length(str);
    }

    /*Opérateurs*/

    std::ostream & operator<< (std::ostream & os, const pr::mString & st) //Opérateur pour l'affichage
    {
        os << st.str;
        return os;
    }

    mString& mString::operator=( const mString & st2){
        if (str != st2.str){            //Auto affectation ?
            if (str!=nullptr){
                delete [] str;
            }
            
            str = newcopy(st2.str);     //Duplication du tableau
        }
        return *this;                     //Permet l'enchaînement d'affectations
    }

    bool operator == (const mString &a, const mString &b){
        return strcmp(a.str,b.str) == 0;
    }

    bool mString::operator < (const mString &b){
        return strcmp(str,b.str)<0;
    }
}