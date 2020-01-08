#include <defaultvalues.h>

#include "wconprodentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

WCONPRODEntity::WCONPRODEntity(QObject *parent) : QObject (parent) { }

QVector<WCONPRODData> &WCONPRODEntity::WCONPROD()
{
    return wconPROD;
}

bool WCONPRODEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->State() != ProjectData::CLOSED && wconPROD.length() > 0;
    }

    return false;
}

QVariantList WCONPRODEntity::getList(QDateTime date)
{
    QVariantList wconprodList;

    QVector<WCONPRODData> list = WCONPRODList(date);

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

QVector<WCONPRODData> WCONPRODEntity::WCONPRODList(QDateTime date)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->State() != ProjectData::CLOSED)
        {
            QVector<WCONPRODData> wconprodList;

            QVector<int> indexes = GetIndexes(date);

            for(int i = 0; i < indexes.length(); i++) wconprodList.append(wconPROD[indexes[i]]);

            return wconprodList;
        }
    }

    return QVector<WCONPRODData>();
}

QVector<int> WCONPRODEntity::GetIndexes(QDateTime date)
{
    return dateIndexes.contains(date) ? dateIndexes[date] : QVector<int>();
}

void WCONPRODEntity::AddWCONPROD(WCONPRODData &data)
{
    QString wellName = data.WellName();
    QDateTime date = data.Date();

    if(!dateIndexes.contains(date)) dateIndexes[date] = QVector<int>();

    QObject* projectData = parent();

    if (wellName.endsWith("*") && projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        QVector<WELSPECSData>& welSPECS = project->WELSPECS()->WELSPECS();

        QString wellSearch = wellName.left(wellName.size()-1);

        for(int i = 0; i < welSPECS.size(); i++)
        {
            if(welSPECS[i].WellName().startsWith(wellSearch))
            {
                data.SetWellName(welSPECS[i].WellName());

                dateIndexes[date].append(wconPROD.length());

                wconPROD.append(data);
            }
        }
    }
    else
    {
        dateIndexes[date].append(wconPROD.length());

        wconPROD.append(data);
    }
}

void WCONPRODEntity::Clear()
{
    dateIndexes.clear();
    wconPROD.clear();
}



}}}}
