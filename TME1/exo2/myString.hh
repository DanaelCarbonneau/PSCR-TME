#pragma once

#include <cstring>  //size_t
#include <ostream>


namespace pr{


    size_t length(const char* str);
    char* newcopy(const char* str);

    class mString{
        const char* str;
    public :
        

        /*Constructeur copiant (duplication) la chaîne st*/
        mString(const char* st);
        /*Constructeur sans argument (cas d'une déclaration sans affectation)*/
        mString();
        size_t length();

        ~mString(){
            delete[]str;
        }

        
        /*Surchage d'opérateurs*/
        mString & operator=(const pr::mString & st2);
        bool operator<(const mString &b);
        friend bool operator == (const mString &a, const mString &b);
        friend  std::ostream & operator<< (std::ostream & os, const mString & vec) ;
    };

    std::ostream & operator<< (std::ostream & os, const mString & vec) ;

    bool operator == (const mString &a, const mString &b);
    
}