#ifndef EXAMPLEMILION_H_INCLUDED
#define EXAMPLEMILION_H_INCLUDED
#include <string>
#include "OutputFile.h"
#include <unistd.h>


using namespace std;

/**
 * Tworzenie pliku z losowymi liczbami (nieposortowane).
 * 
 * @Kamil
 */

class RandomNumber{

    string file_name;
    int how;

    public:
    RandomNumber(string s="sort.txt", int h=100);
    void generator();
};



#endif // EXAMPLEMILION_H_INCLUDED
