#include <defaultvalues.h>

#include "wconprodentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

WCONPRODEntity::WCONPRODEntity(QObject *parent) : QObject (parent) { }

QList<WCONPRODData> &WCONPRODEntity::WCONPROD()
{
    return wconPROD;
}

bool WCONPRODEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->Loaded() && wconPROD.length() > 0;
    }

    return false;
}

QVariantList WCONPRODEntity::getList(QDateTime date)
{
    QVariantList wconprodList;

    QList<WCONPRODData> list = WCONPRODList(date);

    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));
    QMetaEnum wellControlModeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellControlMode"));

    for(int i = 0; i < list.length(); i++)
    {
        QVariantMap map = list[i].toMap();

        map["wellStatus"] = QString(wellStatusTypeEnum.valueToKey(map["wellStatus"].toInt()));
        map["wellControl"] = QString(wellControlModeEnum.valueToKey(map["wellControl"].toInt()));

        wconprodList.append(map);
    }

    return wconprodList;
}

QList<WCONPRODData> WCONPRODEntity::WCONPRODList(QDateTime date)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded())
        {
            QList<WCONPRODData> wconprodList;

            QList<int> indexes = GetIndexes(date);

            for(int i = 0; i < indexes.length(); i++) wconprodList.append(wconPROD[indexes[i]]);

            return wconprodList;
        }
    }

    return QList<WCONPRODData>();
}

QList<int> WCONPRODEntity::GetIndexes(QDateTime date)
{
    return dateIndexes.contains(date) ? dateIndexes[date] : QList<int>();
}

void WCONPRODEntity::AddWCONPROD(WCONPRODData &data)
{
    QDateTime date = data.Date();

    if(!dateIndexes.contains(date)) dateIndexes[date] = QList<int>();

    dateIndexes[date].append(wconPROD.length());

    wconPROD.append(data);
}

void WCONPRODEntity::Clear()
{
    dateIndexes.clear();
    wconPROD.clear();
}



}}}}
