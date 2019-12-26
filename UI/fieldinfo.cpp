#include "fieldinfo.h"

FieldInfo::FieldInfo() { }

FieldInfo::FieldInfo(uint id, QString title, QString legendTitle, QString unitText)
{
    this->id = id;
    this->title = title;
    this->legendTitle = legendTitle;
    this->unitText = unitText;
}

uint FieldInfo::Id()
{
    return id;
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

void FieldInfo::SetId(uint id)
{
    this->id = id;
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
    return QVariantMap {{"id", id}, {"title", title}, {"legendTitle", legendTitle}, {"unitText", unitText}};
}
