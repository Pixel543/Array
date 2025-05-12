#include "array.h"

Array::Array()
{
    m_size = 0;
    m_step = 2;
    m_currentIndex = 0;
    
    m_data = new int[m_size];

}

    //             90           2
Array::Array(int initSize, int growStep)
{
    if (initSize <= 0 || growStep <= 0)
    {
        //std::cout << "This data is not correct" << std::endl;
        m_size = 0;
        m_step = 0;
        m_data = 0;
        m_currentIndex = 0;
        return;
    }
    
    m_size = initSize;
    m_step = growStep;
    m_currentIndex = 0;
    m_data = new int [m_size];

    std::cout << "Array was created" << std::endl;
}   


Array::~Array()
{
    delete[]  m_data;
}

void Array::showElements()
{
    if (m_data == nullptr || m_currentIndex == 0)
        return;

    for(int i = 0; i < m_currentIndex; i++)
    {
        std::cout << m_data[i]<< " "; 
    }   
    std::cout << std::endl;
}
                        //  5
void Array::expandArray(int size)
{
    int newSize = m_size + size;
    
    if (size <= 0)
        return;

    
    if (newSize <= m_size)
        return;

    int* newArr = new int[newSize];
    
    if (!newArr)
        return;

    for (int i = 0; i < m_currentIndex; i++) {
        newArr[i] = m_data[i];
    }

 
    delete[] m_data;

    m_data = newArr;
    m_size = newSize;
}
int Array::getSize()
{
    return m_size;
}

int Array::getElemSize()
{
    return m_currentIndex;
}

void Array::setValue(int val)
{
    if (m_currentIndex >= m_size)
        expandArray(m_step);
    
    m_data[m_currentIndex++] = val;
}

void Array::setArray(int * pArr, int size) //10
{
    if (size <= 0) 
        return;
    
    int newSize = size + m_size;
    int * newArr = new int[newSize];

    for (int i = 0; i < m_currentIndex; ++i)
        newArr[i] = m_data[i];
    
    for (int i = 0; i < size; ++i)
        newArr[m_currentIndex++] = pArr[i];
    
    
   
    delete[] m_data;
    m_data = newArr;
    m_size = newSize;
   
}