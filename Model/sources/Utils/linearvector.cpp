#include "linearvector.h"

namespace QaraMunai {
namespace Model {
namespace Utils {

LinearVector::LinearVector()
{
    index = 0;
}

Box3D& LinearVector::Box()
{
    return box;
}

int LinearVector::Count()
{
    return index;
}

QVariant LinearVector::operator()(int i)
{
    return Search(i);
}

void LinearVector::SetBox(const Box3D &box)
{
    this->box = box;
}

void LinearVector::Add(QVariant value)
{
    SubArray *subArray = nullptr;

    if(data.length() > 0)
    {
        SubArray *item = &data[data.length() - 1];

        if(!item->IsInterval()) subArray = item;
    }

    if(subArray == nullptr)
    {
        data.append(SubArray(index));

        subArray = &data[data.length() - 1];
    }

    subArray->List().append(value);

    index++;
}

void LinearVector::AddInterval(int length, QVariant value)
{
    data.append(SubArray(index, length, value));

    index += length;
}

QVariant LinearVector::Search(int index)
{
    int dataIndex = SearchDataIndex(index);

    QVariant val;

    if(dataIndex >= 0)
    {
        SubArray *subArray = &data[dataIndex];

        if(index >= subArray->Index() && index < subArray->Index() + subArray->Length())
        {
            if (subArray->IsInterval())
            {
                val = subArray->Value();
            }
            else
            {
                int subIndex = subArray->Index();

                QVector<QVariant> &list = subArray->List();

                subIndex = index - subIndex;

                val = list[subIndex];
            }
        }
    }

    return val;
}

void LinearVector::Clear()
{
    index = 0;

    box.InitVariables();

    data.clear();
}

int LinearVector::SearchDataIndex(int index)
{
    int n = data.length();

    if (n == 0 || index >= Count()) return -1;
    else if (n == 1) return 0;

    int l = 0;
    int r = n - 1;

    return BinarySearch(l, r, index);
}

int LinearVector::BinarySearch(int l, int r, int index)
{
    while (r - l > 1)
    {
        int m = (r + l) / 2;

        int lower = data[m].Index();
        int upper = lower + data[m].Length() - 1;

        if (index < lower)
        {
            r = m;
        }
        else if (index > upper)
        {
            l = m;
        }
        else return m;
    }

    int lowerBound = data[l].Index();
    int upperBound = lowerBound + data[l].Length() - 1;

    if (index >= lowerBound && index <= upperBound) return l;

    return r;
}

}}}
