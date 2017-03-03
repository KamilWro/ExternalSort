#include "RandomNumber.h"
#include "Sort.h"
#include <climits>

using namespace std;

int main()
{
    char c;
    cout<<"Do you want to create file? [Y/N/Exit]  ";
    cin.get(c);
    cin.ignore(1);
    if (c=='N'){
        string name;
        unsigned int n;
        cout<<"Name file: ";
        getline(cin,name);
        cout<<"Block Size of sorting:";
        cin>>n;
        try{
            Sort A(n,name);
            A.run();
        }
        catch(invalid_argument ex){
            cerr<<ex.what();
        }
        catch(ios::failure const & ex){
            cerr<<ex.what();
        }
    }
    else if(c=='Y'){
        try{
            RandomNumber number;
            number.generator();
            Sort A;
            A.run();
        }
        catch(invalid_argument ex){
            cerr<<ex.what();
        }
        catch(ios::failure const & ex){
            cerr<<ex.what();
        }
    }
    return 0;
}
