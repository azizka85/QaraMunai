#ifndef TESTUTILS
#define TESTUTILS

#include <qobject.h>
#include <qvariant.h>
#include <qstring.h>

#include <defaultvalues.h>
#include <linearmatrix2d.h>
#include <eclipsefilereader.h>
#include <unithelper.h>

#include <test.h>

using namespace QaraMunai::Model::DAO;
using namespace QaraMunai::Model::Domain::Grid;
using namespace QaraMunai::Model::Domain::Project;
using namespace QaraMunai::Model::Utils;
using namespace QaraMunai::Model::Helpers;

class TestUtils : public QObject
{
     Q_OBJECT
public:
    explicit TestUtils(QObject *parent = nullptr);

signals:

private slots:
    void TestLinearMatrix2D();
    void TestConvertPressure();
    void TestDefaultValues();
    void TestCasesEnum();
    void TestEnums();
};

#endif // TESTUTILS
