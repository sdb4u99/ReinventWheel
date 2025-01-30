#include <iostream>
#include <cstring>

using namespace std;

class myString{
    private:
    char* res;
    unsigned int size;

    public:

    myString():res(nullptr),size(0){
    }

    myString(const char* s) : res(new char[strlen(s)+1]), size(strlen(s)){

        strcpy(res, s);
    }


};

int main(){
    cout << "Hi" << endl;
    myString s1;
    myString s2("Hi");
}