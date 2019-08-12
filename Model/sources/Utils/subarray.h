#ifndef SUBARRAY_H
#define SUBARRAY_H

#include <qvariant.h>
#include <qlist.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Utils {

class MODELSHARED_EXPORT SubArray
{
public:
    SubArray(int index);
    SubArray(int index, int length, QVariant value);

public:
    bool IsInterval();
    int Index();
    int Length();
    QVariant Value();
    QList<QVariant>& List();

    void SetIndex(int index);
    void SetLength(int length);
    void SetValue(QVariant value);

private:
    bool isInterval;
    int index;    
    int length;
    QVariant value;
    QList<QVariant> list;
};

}}}

#endif // SUBARRAY_H
