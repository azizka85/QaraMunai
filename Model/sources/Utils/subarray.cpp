#include "subarray.h"

namespace QaraMunai {
namespace Model {
namespace Utils {

SubArray::SubArray() : SubArray(-1)
{

}

SubArray::SubArray(int index) : SubArray(index, -1, QVariant())
{    
    isInterval = false;
}

SubArray::SubArray(int index, int length, QVariant value)
{
    isInterval = true;

    this->index = index;
    this->length = length;
    this->value = value;
}

bool SubArray::IsInterval()
{
    return isInterval;
}

int SubArray::Index()
{
    return  index;
}

int SubArray::Length()
{
    if(isInterval) return length;

    return list.length();
}

QVariant SubArray::Value()
{
    return value;
}

QVector<QVariant> &SubArray::List()
{  
    return list;
}

void SubArray::SetIndex(int index)
{
    this->index = index;
}

void SubArray::SetLength(int length)
{
    this->length = length;
}

void SubArray::SetValue(QVariant value)
{
    this->value = value;
}

}}}
