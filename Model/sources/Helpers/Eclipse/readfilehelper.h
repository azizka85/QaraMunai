#ifndef READFILEHELPER_H
#define READFILEHELPER_H

#include <qmetaobject.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qtextstream.h>
#include <qdatetime.h>

#include <box3d.h>
#include <linearvector.h>
#include <linearmatrix3d.h>

#include <model_global.h>

using namespace QaraMunai::Model::Domain::Grid;
using namespace QaraMunai::Model::Utils;

namespace QaraMunai {
namespace Model {
namespace Helpers {
namespace Eclipse {

class MODELSHARED_EXPORT ReadFileHelper
{
public:
    static QString GetNextLine(QTextStream &stream);
    static QString ParseKeyword(QString &line);
    static QStringList ParseParams(QTextStream &sr, int nameIndex = -1, bool canEmpty = false);
    static QString EclipseDateToStr(QStringList &str, const QMetaEnum &monthsEnum);
    static QString DateToStr(QDateTime &dt);
    static QDateTime StrToDate(QString &strDate);
    static void IgnoreParams(QTextStream &sr);
    static QStringList GetNextLineWords(QTextStream &stream);
    static bool IsYes(QString &str);
    static void FillVector(QTextStream &sr, LinearVector &linearVector);
    static void ReadVector(QTextStream &sr, const Box3D &box, LinearVector &linearVector);
    static void Read3DArray(QTextStream &sr, const Box3D &box, LinearMatrix3D &linearMatrix3D);
};

}}}}

#endif // READFILEHELPER_H
