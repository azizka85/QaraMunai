#ifndef FIELDINFO_H
#define FIELDINFO_H

#include <qvariant.h>
#include <qstring.h>

class FieldInfo
{
public:
    FieldInfo();
    FieldInfo(QString title, QString legendTitle, QString unitText);

    QString Title();
    QString LegendTitle();
    QString UnitText();

    void SetTitle(QString title);
    void SetLegendTitle(QString legendTitle);
    void SetUnitText(QString unitText);

    QVariantMap toMap();

private:
    QString title, legendTitle, unitText;
};

#endif // FIELDINFO_H
