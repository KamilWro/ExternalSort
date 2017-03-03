#ifndef INPUTFILE_H_INCLUDED
#define INPUTFILE_H_INCLUDED
#include <iostream>
#include <fstream>

/**
 * Obsługa czytania z pliku, niskopoziomowa.
 * 
 * @Kamil
 */
using namespace std;
class InputFile
{
    void throws();

   ifstream file;
 public:
    bool eof();
    string input();

   InputFile(string name_file);
    ~InputFile();
};


#endif // INPUTFILE_H_INCLUDED
