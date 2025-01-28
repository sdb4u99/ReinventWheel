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
    unsigned int get_capacity() {return capacity;} 
    myVector():data (nullptr) , size(0), capacity(0) {};
    
    myVector(int msize):data (new T[msize]) , size(0), capacity(msize) {};

    T operator[](int index){
        if (index< size){return data[index];

        }
    }

    void clear(){
        delete[]data;
        size =0
        capacity=0;
    }

    void reserve (unsigned int newCapacity){

        if( newCapacity > capacity){
            T* tmp = new T[newCapacity];
            for (unsigned int i =0 ; i< size ; i++){
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

    //copy const

    myVector(const myVector& other ){
        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i=0; i < size; ++i){
            data[i] = other.data[i];
        }
    }

    //move const 
    myVector(myVector &&other){
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        other.data = nullptr;
        other.size = other.capacity =0 ;
    }

    //move assignment operator
    myVector& operator= (myVector&& other){
        if(this != &other){
            size = other.size;
            capacity = other.capacity;
            delete[] data;
            data = other.data;
            other.size=0;
            other.capacity=0;
            other.data=nullptr;
        }
        return *this;
    }

    // copy assignment
    myVector& operator=(const myVector& other){
        if (this != &other){
            size = other.size;
            capacity = other.capacity;
            
            auto tmp = new T[capacity];
            for (int i=0; i<size; ++i){
                tmp[i] = other.data[i];
            }
            delete [] data;
            data = tmp;
        }
        return *this;
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

    myVector<int> v4(v3);
    auto printvInt = []( std::string vName, myVector<int>& v )  {
        std::cout << vName << std::endl;
        for (unsigned int i =0 ; i < v.get_size(); i++){
            std::cout << v[i] << " ";
        }
        std::cout << "\n===\n";
    };
    std::cout << "\n====\n";

    printvInt("v1", v1);
    std::cout << "\n====\n";
        v1 = v4;
    printvInt("v1 bef move", v1);
    std::cout << "\n====\n";
    myVector<int> v5 = std::move(v1);
    std::cout << "\n====\n";
    printvInt("v1 after move", v1);
    std::cout << "\n====\n";
    printvInt("v5", v5);

    v1 = std::move(v5);
    printvInt("v1 after move = with v5\n", v1);
    printvInt("v5 after move ", v5);


}