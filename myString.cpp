#include <iostream>
#include <cstring>

using namespace std;

class myString{
    private:
    char* res;
    unsigned int size;

    public:

    friend ostream&  operator<< (ostream& out, myString & str);

    myString():res(nullptr),size(0){
    }

    myString(const char* s) : res(new char[strlen(s)+1]), size(strlen(s)){

        strcpy(res, s);
    }

    myString& operator= (const myString& other){

        if(this != &other){

            delete[]res;
            size = other.size;
            res = new char[size+1];
            strcpy(res,other.res);
        }
        return *this;

    }

    ~myString(){
        delete[]res;
        res=nullptr;
        size =0;
    }


};

 ostream&  operator<< (ostream& out,  myString & str){
    out << str.res << endl;
    return out;
 }

int main(){
    myString s1;   //default const
    myString s2("Hi hello");   // copy const
    s1 = s2;

    cout << s2;     //overloaded ostream
    cout << s1;

}