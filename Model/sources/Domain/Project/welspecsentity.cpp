#include <defaultvalues.h>

#include "welspecsentity.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Project {

WELSPECSEntity::WELSPECSEntity(QObject *parent) : QObject (parent) { }

QVector<WELSPECSData> &WELSPECSEntity::WELSPECS()
{
    return welSPECS;
}

bool WELSPECSEntity::exist()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        return project->Loaded() && welSPECS.length() > 0;
    }

    return false;
}

QVariantList WELSPECSEntity::getList(QDateTime date)
{
    QVariantList welspecsList;

    QVector<WELSPECSData> list = WELSPECSList(date);

    for(int i = 0; i < list.length(); i++) welspecsList.append(list[i].toMap());

    return welspecsList;
}

QVariantMap WELSPECSEntity::getData()
{
    QVariantMap welSPECSData;

    QMap<QString, QVector<WELSPECSData>> data = WELSPECSGroupList();

    QList<QString> keys = data.keys();

    for(int i = 0; i < keys.length(); i++)
    {
        QString key = keys[i];

        QVariantList welSPECSList;

        QVector<WELSPECSData> list = data[key];

        for(int j = 0; j < list.length(); j++) welSPECSList.append(list[j].toMap());

        welSPECSData[key] = welSPECSList;
    }

    return welSPECSData;
}

QVector<WELSPECSData> WELSPECSEntity::WELSPECSList(QDateTime date)
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded())
        {
            QVector<WELSPECSData> welspecsList;

            QVector<int> indexes = GetDateIndexes(date);

            for(int i = 0; i < indexes.length(); i++) welspecsList.append(welSPECS[indexes[i]]);

            return welspecsList;
        }
    }

    return QVector<WELSPECSData>();
}

QMap<QString, QVector<WELSPECSData> > WELSPECSEntity::WELSPECSGroupList()
{
    QObject* projectData = parent();

    if (projectData != nullptr)
    {
        ProjectData* project = static_cast<ProjectData*>(projectData);

        if(project->Loaded())
        {
            QMap<QString, QVector<WELSPECSData>> welSPECSData;

            QList<QString> keys = groupIndexes.keys();

            for(int i = 0; i < keys.length(); i++)
            {
                QString key = keys[i];

                welSPECSData[key] = QVector<WELSPECSData>();

                QVector<int> indexes = groupIndexes[key];

                for(int j = 0; j < indexes.length(); j++) welSPECSData[key].append(welSPECS[indexes[j]]);
            }

            return welSPECSData;
        }
    }

    return QMap<QString, QVector<WELSPECSData> >();
}

QVector<int> WELSPECSEntity::GetDateIndexes(QDateTime date)
{
    return dateIndexes.contains(date) ? dateIndexes[date] : QVector<int>();
}

QVector<int> WELSPECSEntity::GetGroupIndexes(QString group)
{
    return groupIndexes.contains(group) ? groupIndexes[group] : QVector<int>();
}

void WELSPECSEntity::AddWELSPECS(WELSPECSData &data)
{
    QDateTime date = data.Date();
    QString group = data.WellGroup();

    if(!dateIndexes.contains(date)) dateIndexes[date] = QVector<int>();
    if(!groupIndexes.contains(group)) groupIndexes[group] = QVector<int>();

    dateIndexes[date].append(welSPECS.length());
    groupIndexes[group].append(welSPECS.length());

    welSPECS.append(data);
}

void WELSPECSEntity::Clear()
{
    dateIndexes.clear();
    groupIndexes.clear();
    welSPECS.clear();
}



}}}}
