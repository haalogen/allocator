#include <iostream>
#include <vector>
using namespace std;

template <class T> class MyAllocator {

    int _k;
    T* _p;
public:
//?    MyAllocator() {}
//?    ~MyAllocator() {}
    void allocate(int k) {}
    void deallocate(T* p) {}
    void construct() {}
    void destroy() {}
    
    int max_size() {}
    T& adress() {}
    
    bool operator== (const MyAllocator& al) {}
    bool operator!= (const MyAllocator& al) {}
};

int main()
{
    MyAllocator<int> al;
    cout << sizeof(al) << endl;

    
//    vector<int, MyAllocator> v(5)
}
