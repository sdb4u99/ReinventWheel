#include <iostream>
#include <initializer_list>

template <typename T>
class myVector{

    private:
    T* data;
    unsigned int size;
    unsigned int capacity;

    public:
    unsigned int get_size() {return size;} 
    myVector():data (nullptr) , size(0), capacity(0) {};
    
    myVector(int msize):data (new T[msize]) , size(0), capacity(msize) {};

    T operator[](int index){
        return data[index];
    }

    void reserve (unsigned int newCapacity){

        if( newCapacity > capacity){
            T* tmp = new T[newCapacity];
            for (int i =0 ; i<= size ; i++){
                tmp[i] = std::move(data[i]);    //why move
            }
            delete[]data;
            data = tmp;
        }
        else{
            std::cout << "underflow\n" ;
        }
    }

    void push_back(T elem){

        if ( capacity <= size){
            reserve( size == 0 ? 1 : size*2 );
        }

        data[size++] = elem;
    }

    myVector(std::initializer_list<T> list) : myVector(list.size()) {

        for (auto const & it : list ){
            push_back(it);
        }
    }

    ~myVector(){
        delete []data;
    }


};

int main()
{
    std::cout << "hello\n" ;
    myVector<int> v1;// default const
    myVector<int> v2(6); //parametrized const
    v2.push_back(5);
    myVector<int> v3 = {1,2,3};  //init list braced

    auto printvInt = []( myVector<int>& v )  {
        for (int i =0 ; i < v.get_size(); i++){
            std::cout << v[i] << " ";
        }
    };

    printvInt(v3);
    std::cout << "\n====\n";
    printvInt(v2);
}