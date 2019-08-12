#ifndef EQLDIMSENTITY_H
#define EQLDIMSENTITY_H

#include <qobject.h>
#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

class MODELSHARED_EXPORT EQLDIMSEntity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant ntEQUL READ NTEQUL WRITE SetNTEQUL NOTIFY NTEQULChanged)

public:
    explicit EQLDIMSEntity(QObject *parent = nullptr);

    QVariant NTEQUL() const;

    void SetNTEQUL(const QVariant &ntEQUL);

    Q_INVOKABLE void initVariables();

signals:
    void NTEQULChanged();
};

}}}}

#endif // EQLDIMSENTITY_H
