#include "RandomNumber.h"
#include <ctime>




RandomNumber::RandomNumber(string s, int h)
    :file_name(s),how(h){}



void RandomNumber::generator() {
    srand( time( 0 ) );
    OutputFile A(file_name);
    for (int i=0;i<how;i++){
        A.output(to_string(rand()));
    }
}

