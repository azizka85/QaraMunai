#include <qapplication.h>
#include <qqmlapplicationengine.h>
#include <qquickstyle.h>

#include <projectdata.h>
#include <asyncfilereader.h>
#include <idatafilereader.h>
#include <eclipsefilereader.h>
#include <endscaleentity.h>
#include <eqldimsentity.h>
#include <rockoptsentity.h>
#include <tabdimsentity.h>
#include <swofentity.h>

using namespace QaraMunai::Model::DAO;
using namespace QaraMunai::Model::Domain::Project;

int main(int argc, char *argv[])
{
    bool isDesktop = false;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    if(isDesktop) QQuickStyle::setStyle("Fusion");
    else QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;

    qmlRegisterUncreatableType<IDataFileReader>("QaraMunai.Model.DAO", 1, 0, "IDataFileReader", "Not creatable in Qml.");

    qmlRegisterType<ProjectData>("QaraMunai.Model.Domain.Project", 1, 0, "ProjectData");    
    qmlRegisterType<AsyncFileReader>("QaraMunai.Model.DAO", 1, 0, "AsyncFileReader");
    qmlRegisterType<EclipseFileReader>("QaraMunai.Model.DAO", 1, 0, "EclipseFileReader");
    qmlRegisterType<ENDSCALEEntity>("QaraMunai.Model.Domain.Project", 1, 0, "ENDSCALEData");
    qmlRegisterType<EQLDIMSEntity>("QaraMunai.Model.Domain.Project", 1, 0, "EQLDIMSData");
    qmlRegisterType<ROCKOPTSEntity>("QaraMunai.Model.Domain.Project", 1, 0, "ROCKOPTSData");
    qmlRegisterType<TABDIMSEntity>("QaraMunai.Model.Domain.Project", 1, 0, "TABDIMSData");
    qmlRegisterType<SWOFEntity>("QaraMunai.Model.Domain.Project", 1, 0, "SWOFEntity");

    if(isDesktop) engine.load(QUrl(QStringLiteral("qrc:/desktop/views/main.qml")));
    else engine.load(QUrl(QStringLiteral("qrc:/mobile/views/main.qml")));

    if (engine.rootObjects().isEmpty()) return -1;

    return app.exec();
}
