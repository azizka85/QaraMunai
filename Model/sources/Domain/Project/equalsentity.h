#ifndef EQUALSENTITY_H
#define EQUALSENTITY_H

#include <qobject.h>
#include <qvector.h>
#include <qmap.h>

#include <equalsdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Stratum;

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT EQUALSEntity : public QObject
{
    Q_OBJECT

public:
    explicit EQUALSEntity(QObject *parent = nullptr);

    QVector<EQUALSData> &EQUALS();

    void AddEQUALS(EQUALSData &equalsData);

    QVector<int> GetIndexes(QString name);

    void Clear();

private:
    QVector<EQUALSData> equals;
    QMap<QString, QVector<int>> nameIndexes;
};

}}}}

#endif // EQUALSENTITY_H
