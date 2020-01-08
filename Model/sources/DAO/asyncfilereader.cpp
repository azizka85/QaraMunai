#include "asyncfilereader.h"

namespace QaraMunai {
namespace Model {
namespace DAO {

AsyncFileReader::AsyncFileReader(QObject *parent) : QThread(parent) { }

void AsyncFileReader::load(IDataFileReader *reader, ProjectData *data, const QString &filePath)
{
    this->reader = reader;
    this->data = data;
    this->filePath = filePath;

    start();
}

void AsyncFileReader::run()
{
    reader->load(data, filePath);

    loadComplete();

    data->ProcessData();

    dataProcessed();
}

}}}
