#include "fieldinfo.h"

FieldInfo::FieldInfo() { }

FieldInfo::FieldInfo(QString title, QString legendTitle, QString unitText)
{
    this->title = title;
    this->legendTitle = legendTitle;
    this->unitText = unitText;
}

QString FieldInfo::Title()
{
    return title;
}

QString FieldInfo::LegendTitle()
{
    return legendTitle;
}

QString FieldInfo::UnitText()
{
    return unitText;
}

void FieldInfo::SetTitle(QString title)
{
    this->title = title;
}

void FieldInfo::SetLegendTitle(QString legendTitle)
{
    this->legendTitle = legendTitle;
}

void FieldInfo::SetUnitText(QString unitText)
{
    this->unitText = unitText;
}

QVariantMap FieldInfo::toMap()
{
    return QVariantMap {{"title", title}, {"legendTitle", legendTitle}, {"unitText", unitText}};
}
