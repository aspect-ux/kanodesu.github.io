#ifndef VECTOR_H
#define VECTOR_H

typedef int Rank;
#define DEFUALT_CAPACITY 3

template <typename T> class Vector{
protected:
    Rank _size;
    int capacity;
    T* _elem;
    void copyFrom(T const* A,Rank lo,Rank hi);
    void expand();//expand capacity
public:
    //===========Constructor================
    Vector(int c = DEFUALT_CAPACITY,int s = 0,T v = 0)
    {
        //s: dynamic capacity,c : fixed capacity,_size:rank,_elem:T pointer
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size ++] = v;)
    }
    //--Interval copy
    Vector(T const* A,Rank lo,Rank hi){copyFrom(A,lo,hi);}
    Vector(T const* A,Rank n) {copyFrom(A,0,n); }
    Vector(Vector<T> const& v,Rank lo,Rank hi) {copyFrom(v._elem,lo,hi);}
    Vector(Vector<T> const& v) {copyFrom(v._elem,0,v._size;)}
    //==========DeConstructor=================
    ~Vector() { delete [] _elem;} //free

    //==========ReadOnly interface==============
    Rank size() const {return _size;}
    

    //==============visitable=========================
    Rank insert(Rank r,T const& e);
    Rank insert(T const& e) { return insert(_size,e); }//defualt insert to end
    T& operator[](Rank r)const;//reload operator
    Vector<T> & operator = (Vector<T> const&);
    T remove(Rank r);
    vid permute(Vector<T>& v) {
        for (int i = v.size())
    }

    
};

#endif