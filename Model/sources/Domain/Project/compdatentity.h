#ifndef COMPDATENTITY_H
#define COMPDATENTITY_H

#include <qobject.h>
#include <qdatetime.h>
#include <qvector.h>
#include <qmap.h>

#include <compdatdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT COMPDATEntity : public QObject
{
    Q_OBJECT

public:
    explicit COMPDATEntity(QObject *parent = nullptr);

    QVector<COMPDATData> &COMPDAT();

    Q_INVOKABLE bool exist();
    Q_INVOKABLE QVariantList getList(QDateTime date);

    QVector<int> GetIndexes(QDateTime date);

    QVector<COMPDATData> COMPDATList(QDateTime date);

    void AddCOMPDAT(COMPDATData &data);

    void Clear();

private:
    QVector<COMPDATData> compDAT;
    QMap<QDateTime, QVector<int>> dateIndexes;
};

}}}}

#endif // COMPDATENTITY_H
