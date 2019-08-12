#ifndef LINEARVECTOR_H
#define LINEARVECTOR_H

#include <typeinfo.h>

#include <qvariant.h>
#include <qlist.h>

#include <box1d.h>
#include <subarray.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;

namespace QaraMunai {
namespace Model {
namespace Utils {

class MODELSHARED_EXPORT LinearVector
{
public:
    LinearVector();

    Box1D &Box();
    int Count();

    QVariant operator() (int i);

    void SetBox(const Box1D& box);
    void Add(QVariant value);
    void AddInterval(int length, QVariant value);
    QVariant Search(int index);

    void Clear();

private:
    int index;
    Box1D box;
    QList<SubArray> data;

    int SearchDataIndex(int index);
    int BinarySearch(int l, int r, int index);
};

}}}

#endif // LINEARVECTOR_H
