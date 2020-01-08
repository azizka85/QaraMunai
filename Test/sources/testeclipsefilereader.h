#ifndef TESTECLIPSEFILEREADER_H
#define TESTECLIPSEFILEREADER_H

#include <qdebug.h>
#include <qobject.h>
#include <qmetaobject.h>
#include <qstring.h>

#include <eclipsefilereader.h>
#include <projectdata.h>
#include <defaultvalues.h>

#include <test.h>

using namespace QaraMunai::Model::DAO;
using namespace QaraMunai::Model::Domain::Project;

class TestEclipseFileReader : public QObject
{
     Q_OBJECT
public:
    explicit TestEclipseFileReader(QObject *parent = nullptr);

signals:

private slots:
    void TestValidateLoad();

private:
    void ValidateLoad(ProjectData &data);
    void ValidateInitialization(ProjectData &data);
};

#endif // TESTECLIPSEFILEREADER_H
