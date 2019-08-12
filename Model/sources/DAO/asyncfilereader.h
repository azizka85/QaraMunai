#ifndef ECLIPSEASYNCFILEREADER_H
#define ECLIPSEASYNCFILEREADER_H

#include <qthread.h>

#include <idatafilereader.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace DAO {

class MODELSHARED_EXPORT AsyncFileReader : public QThread
{
    Q_OBJECT

public:
    explicit AsyncFileReader(QObject *parent = nullptr);

signals:
    void loadComplete();

public:
    Q_INVOKABLE void load(IDataFileReader *reader, ProjectData *data, const QString &filePath);

    // QThread interface
protected:
    void run();

private:
    IDataFileReader *reader;
    ProjectData *data;
    QString filePath;
};

}}}

#endif // ECLIPSEASYNCFILEREADER_H
