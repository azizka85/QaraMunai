#ifndef IDATAFILEREADER_H
#define IDATAFILEREADER_H

#include <qobject.h>
#include <qstring.h>

#include <projectdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Project;

namespace QaraMunai {
namespace Model {
namespace DAO {

class MODELSHARED_EXPORT IDataFileReader : public QObject {

    Q_OBJECT

public:
    explicit IDataFileReader(QObject *parent = nullptr) : QObject(parent) { }
    virtual ~IDataFileReader() { }
    virtual void load(ProjectData* projectData, const QString& filePath) = 0;
};
}}}

#endif // IDATAFILEREADER_H
