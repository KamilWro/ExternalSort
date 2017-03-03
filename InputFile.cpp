#include "InputFile.h"

    void InputFile::throws(){
        if( file.bad() || file.fail() || file.eof() ){
            file.exceptions(ios::failbit|ios::badbit|ios::eofbit);
        }
    }

    bool InputFile::eof(){
        return file.eof();
    }

    string InputFile::input(){
        throws();
        string line;
        getline(file,line);
        return line;
    }

   InputFile::InputFile(string name_file){
        file.open( name_file);
        if( file.bad() || file.fail() || file.eof() ){
            file.close();
            file.exceptions(ios::failbit|ios::badbit|ios::eofbit);
        }
    }

    InputFile::~InputFile(){
        file.close();
   }
