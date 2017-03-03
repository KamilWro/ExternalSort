#ifndef OUTPUTFILE_H_INCLUDED
#define OUTPUTFILE_H_INCLUDED
#include <iostream>
#include <fstream>

/**
 * Obsługa pisania do pliku, niskopoziomowa.
 * 
 * @Kamil
 */

using namespace std;


class OutputFile
{
    void throws();

    ofstream file;
 public:
    template<class T>
    void output(T x);
    OutputFile(string name_file);
    ~OutputFile();
};

    template<class T>
    void OutputFile::output(T x){
        file<<x<<'\n';
        throws();
    }
#endif // OUTPUTFILE_H_INCLUDED
