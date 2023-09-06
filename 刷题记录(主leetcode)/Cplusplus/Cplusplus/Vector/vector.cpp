#include <iostream>
#include "vector.h"//if you include a .h file,then <>,or ""
using namespace std;

template <typename T>
Rank Vector<T>::insert(Rank r,T const& e)
{
    expand();
    for (int i = _size; i > r; i --) _elem[i] = _elem[i - 1];//秩为r和大于r的元素往后移
    _elem[r] = e;
    _size ++;
    return r;
}//O(_size - r + 1)

template <typename T>
void Vector<T>::copyFrom(T const* A,Rank lo,Rank hi)//[)
{
    _elem = new T[_capacity = 2 * (hi - lo)];_size = 0;
    while (lo < hi){
        _elem[_size ++] = A[lo ++];
    }
}

//reload = operator
template <typename T> Vector<T>& Vector<T>::operator=(Vector<T> const& v) {
    if (_elem) delete [] _elem;
    copyFrom(v._elem,0,v.size(););
    return *this;
}
//reload [] operator
template <typename T> T& Vector<T>::operator[](Rank r) const{
    return _elem[r];
}

//expand strategy: new a larger storage
template <typename T> void Vector<T>::expand() {
    if (_size < _capacity) return;//not necessary to expand
    if (_capacity < DEFUALT_CAPACITY) _capacity = DEFUALT_CAPACITY;//set default capacity
    T* oldElem = _elem;
    _elem = new T[_capacity <<= 1];//double the storage
    for (int i = 0; i < _size; i ++) {//copy
        _elem[i] = oldElem[i];
    }
    delete [] oldElem;//free
}

