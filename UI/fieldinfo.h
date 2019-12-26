#ifndef FIELDINFO_H
#define FIELDINFO_H

#include <qvariant.h>
#include <qstring.h>

class FieldInfo
{
public:
    FieldInfo();
    FieldInfo(uint id, QString title, QString legendTitle, QString unitText);

    uint Id();
    QString Title();
    QString LegendTitle();
    QString UnitText();

    void SetId(uint id);
    void SetTitle(QString title);
    void SetLegendTitle(QString legendTitle);
    void SetUnitText(QString unitText);

    QVariantMap toMap();

private:
    uint id;
    QString title, legendTitle, unitText;
};

#endif // FIELDINFO_H
