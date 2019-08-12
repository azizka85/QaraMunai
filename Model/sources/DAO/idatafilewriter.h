#ifndef IDATAFILEWRITER_H
#define IDATAFILEWRITER_H

#include <qobject.h>
#include <qstring.h>

#include <projectdata.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Project;

namespace QaraMunai {
namespace Model {
namespace DAO {
class MODELSHARED_EXPORT IDataFileWriter : public QObject {

    Q_OBJECT

public:
    explicit IDataFileWriter(QObject *parent = nullptr) : QObject(parent) { }
    virtual ~IDataFileWriter() { }
    virtual void save(ProjectData* projectData, const QString& filePath) = 0;
};
}}}

#endif // IDATAFILEWRITER_H
