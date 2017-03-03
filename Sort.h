#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <string>
#include <vector>
#include "InputFile.h"
#include "OutputFile.h"
#include <algorithm>
#include <unistd.h>


/**
 * Sortowanie liczb całkowitych w pliku.
 * 
 * @Kamil
 */


using namespace std;

class Sort{
    unsigned int box; //dlugość bloków
    string file_name;
    string tmpA;
    string tmpB;
    vector <string> memory;


    void fmerge();
    void download(InputFile &file);
    void update();
    void merge();
    void fsort();
    static bool compare(string one, string two);

    public:
    Sort (unsigned int b=1000000,string n="sort.txt") throw (invalid_argument);
    void run();

};


#endif // SORT_H_INCLUDED
