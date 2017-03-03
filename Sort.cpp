#include "Sort.h"


    void Sort::fmerge(){
        OutputFile B(tmpB);
        InputFile A(tmpA);
        auto i = memory.begin();
        string tmp;
        if (!A.eof()) tmp=A.input();
        bool ptr=false;
        while ((!A.eof())&& (i<memory.end())){
            if (compare(tmp,*i)){
                B.output(tmp);
                tmp=A.input();
                if (A.eof()) ptr=true;
            }
            else{
                B.output(*i);
                i++;
            }
        }
        if(!ptr) B.output(tmp);
        while (!A.eof()){
            tmp=A.input();
            if(!A.eof()) B.output(tmp);
        }
        while(i<memory.end()){
            B.output(*i);
            i++;
        }
    }

    Sort::Sort (unsigned int b,string n) throw (invalid_argument){
        if ((access(tmpA.c_str(),F_OK)==0)||(access(tmpB.c_str(),F_OK)==0))
            throw invalid_argument("File temporary exist");
        if (b<=0) throw invalid_argument("!! incorrect data !!");
        file_name=n;
        box=b;
        tmpA=".tmpA.txt";
        tmpB=".tmpB.txt";
    }

    bool Sort::compare (string one, string two) {
        if ((one[0]=='-')&&(two[0]!='-')) return true;
        if ((one[0]!='-')&&(two[0]=='-')) return false;
        int i=0;
        bool is_minus=false;

        if ((one[0]=='-')&&(two[0]=='-')){
            is_minus=true;
            i=1;
        }

        int size_one=one.size();
        int size_two=two.size();
        if (size_one == size_two){
            for(int i=0;i<size_one;i++){
                if (one[i]!=two[i]){
                    if(is_minus)
                        return one[i]>two[i];
                    return one[i]<two[i];
                }
            }
        }
        else{
            if(is_minus)
                return size_one>size_two;
            return size_one<size_two;
        }
        return false;
    }

    void Sort::download(InputFile &file){
        memory.clear();
        for (int i=0;((i<box)&&(!file.eof()));i++){
            string tmp=file.input();
            if (!file.eof()) memory.push_back(tmp);
        }
    }

    void Sort::update(){
        remove(file_name.c_str());
        rename(tmpA.c_str(),file_name.c_str());
    }

    void Sort::merge(){
        if (access(tmpA.c_str(),F_OK)==0){
            fmerge();
            remove(tmpA.c_str());
            rename(tmpB.c_str(), tmpA.c_str() );
        }
        else{
            OutputFile A(tmpA);
            for(auto i = memory.begin(); i <memory.end(); i++ ){
                A.output(*i);
            }
        }
    }

    void Sort::fsort() {
        InputFile file(file_name);
        while(!file.eof()){
            download(file);
            sort(memory.begin(),memory.end(),compare);
            merge();
        }
    }

    void Sort::run(){
        fsort();
        update();
    }
