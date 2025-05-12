#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

class Array
{
private:
    int  m_size;
    int  m_step;
    int* m_data;
    int  m_currentIndex;

public:

    Array();
    Array(int initSize, int growStep);
    ~Array();
    void showElements();
    void expandArray(int size);
    int getSize();
    int getElemSize();
    void setValue(int val);
    void setArray(int * pArr, int size);
};
#endif