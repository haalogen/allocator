#include <iostream>
#include <vector>
using namespace std;

//struct buffer with counter
template <class T> struct Buffer {
    int cnt=0;
    T* buf;
};

template <class T> class MyAllocator {
private:
    int _k;
    Buffer<T> *_b;
public:
// если алл-р выделяет -- счетчик удалений
// если алл-р просто пользует переданный буфер -- ничего выделять/освобождать не надо
    MyAllocator(int k=10) {
        cout << "Constructor \n";
        _k = k;
        //create new buffer var & allocate new memory for buffer; buf.cnt++
        
        //I am the creator
        _b->cnt = 1;
        _b->buf = allocate(k);
    }
    MyAllocator(const MyAllocator& m) {
        cout << "Copy constructor \n";
        //simply copy buffer adress; buf.cnt++ 
        _b = m._b;
        _b->cnt++;
    }
    ~MyAllocator() {
        cout << "Destructor \n";
    }
    T* allocate(int k) { return NULL; } //google
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
    MyAllocator<int> al(5);
    cout << sizeof(al) << endl;
    MyAllocator<int> bl(al);

    
//    vector<int, MyAllocator> v(5);
}
