#ifndef TABDIMSENTITY_H
#define TABDIMSENTITY_H

#include <qobject.h>
#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT TABDIMSEntity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant ntSFUN READ NTSFUN WRITE SetNTSFUN NOTIFY NTSFUNChanged)
    Q_PROPERTY(QVariant ntPVT READ NTPVT WRITE SetNTPVT NOTIFY NTPVTChanged)
    Q_PROPERTY(QVariant nsSFUN READ NSSFUN WRITE SetNSSFUN NOTIFY NSSFUNChanged)

public:
    explicit TABDIMSEntity(QObject *parent = nullptr);

    QVariant NTSFUN() const;
    QVariant NTPVT() const;
    QVariant NSSFUN() const;

    void SetNTSFUN(const QVariant &ntSFUN);
    void SetNTPVT(const QVariant &ntPVT);
    void SetNSSFUN(const QVariant &nsSFUN);

    Q_INVOKABLE void initVariables();

signals:
    void NTSFUNChanged();
    void NTPVTChanged();
    void NSSFUNChanged();
};

}}}}

#endif // TABDIMSENTITY_H
