#include "OutputFile.h"

    void OutputFile::throws(){
        if( file.bad() || file.fail() ){
            file.exceptions(ios::failbit|ios::badbit);
        }
    }



   OutputFile::OutputFile(string name_file){
        file.open(name_file);
        if( file.bad() || file.fail() ){
            file.close();
            file.exceptions(ios::failbit|ios::badbit);
        }
   }
    OutputFile::~OutputFile(){
        file.close();
   }
