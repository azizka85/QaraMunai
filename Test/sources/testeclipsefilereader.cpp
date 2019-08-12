#include "testeclipsefilereader.h"

TestEclipseFileReader::TestEclipseFileReader(QObject *parent) : QObject(parent)
{

}

void TestEclipseFileReader::TestLoad()
{
    EclipseFileReader eclipseReader;

    ProjectData data;

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");
}

void TestEclipseFileReader::TestValidateLoad()
{
    EclipseFileReader eclipseReader;

    ProjectData data;

    ValidateInitialization(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");    

    ValidateLoad(data);
}

void TestEclipseFileReader::TestMassiveValidateLoad()
{
    EclipseFileReader eclipseReader;

    ProjectData data;

    ValidateInitialization(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);

    eclipseReader.load(&data, "D:\\Workspace\\Qt\\QaraMunai\\Data\\OPMKBTU_TEST01 - Weltarg — No MULTPV\\OPMKBTU_TEST01.DATA");

    ValidateLoad(data);
}

void TestEclipseFileReader::ValidateInitialization(ProjectData &data)
{
    VERIFY(data.TABDIMS() != nullptr, "The TABDIMS of ProjectData can't be null");

    VERIFY(data.EQLDIMS() != nullptr, "The EQLDIMS of ProjectData can't be null");

    VERIFY(data.ENDSCALE() != nullptr, "The ENDSCALE of ProjectData can't be null");

    VERIFY(data.ROCKOPTS() != nullptr, "The ROCKOPTS of ProjectData can't be null");
}

void TestEclipseFileReader::ValidateLoad(ProjectData &data)
{
    VERIFY(data.Nx() > 0, "Nx of the stratum must be greater than 0");

    VERIFY(data.Ny() > 0, "Ny of the stratum must be greater than 0");

    VERIFY(data.Nz() > 0, "Nz of the stratum must be greater than 0");

    // PROPS
    VERIFY(data.Stratum().RSCONST().RS() >= 0, "The RS of the RSCONST must be greater than or equal to 0");

    if (data.Stratum().RSCONSTT().length()  > 0)
    {
        qDebug() << "Section RSCONSTT exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().RSCONSTT().length() == ntPVT, "The length of RSCONSTT array must be equal NTPVT of TABDIMS");

        for (int i = 0; i < data.Stratum().RSCONSTT().length(); i++)
        {
            VERIFY(data.Stratum().RSCONSTT()[i].RS() >= 0, QString("%1: The RS of the RSCONSTT must be greater than or equal to 0").arg(i).toLatin1());
        }
    }

    if (data.Stratum().PVTO().length()  > 0)
    {
        qDebug() << "Section PVTO exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().PVTO().length() == ntPVT, "The length of PVTO array must be equal NTPVT of TABDIMS");

        for (int i = 0; i < data.Stratum().PVTO().length(); i++)
        {
            for (int j = 0; j < data.Stratum().PVTO()[i].length(); j++)
            {
                PVTOData &pvto = data.Stratum().PVTO()[i][j];

                VERIFY(pvto.RS() >= 0, QString("%1-%2: The RS of the PVTO must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(pvto.BO() > 0, QString("%1-%2: The BO of the PVTO must be greater than 0").arg(i).arg(j).toLatin1());

                VERIFY(pvto.MO() > 0, QString("%1-%2: The MO of the PVTO must be greater than 0").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().PVCO().length() > 0)
    {
        qDebug() << "Section PVCO exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().PVCO().length() == ntPVT, "The length of PVCO array must be equal NTPVT of TABDIMS");
    }

    if (data.Stratum().PVCDO().length() > 0)
    {
        qDebug() << "Section PVCDO exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().PVCDO().length() == ntPVT, "The length of PVCDO array must be equal NTPVT of TABDIMS");

        for (int i = 0; i < ntPVT; i++)
        {
            PVCDOData &pvcdo = data.Stratum().PVCDO()[i];

            VERIFY(pvcdo.BORef() > 0, QString("%1: The BORef of the PVCDO must be greater than 0").arg(i).toLatin1());

            VERIFY(pvcdo.MORef() > 0, QString("%1: The MORef of the PVCDO must be greater than 0").arg(i).toLatin1());
        }
    }

    if (data.Stratum().PVDO().length() > 0)
    {
        qDebug() << "Section PVDO exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().PVDO().length() == ntPVT, "The length of PVDO array must be equal NTPVT of TABDIMS");

        for (int i = 0; i < data.Stratum().PVDO().length(); i++)
        {
            for (int j = 0; j < data.Stratum().PVDO()[i].length(); j++)
            {
                PVDOData &pvdo = data.Stratum().PVDO()[i][j];

                VERIFY(pvdo.BO() > 0, QString("%1-%2: The BO of the PVDO must be greater than 0").arg(i).arg(j).toLatin1());

                VERIFY(pvdo.MO() > 0, QString("%1-%2: The MO of the PVDO must be greater than 0").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().PVTW().length() > 0)
    {
        qDebug() << "Section PVTW exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().PVTW().length() == ntPVT, "The length of PVTW array must be equal NTPVT of TABDIMS");
    }

    if (data.Stratum().PVDG().length() > 0)
    {
        qDebug() << "Section PVDG exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().PVDG().length() == ntPVT, "The length of PVDG array must be equal NTPVT of TABDIMS");

        for (int i = 0; i < data.Stratum().PVDG().length(); i++)
        {
            for (int j = 0; j < data.Stratum().PVDG()[i].length(); j++)
            {
                PVDGData &pvdg = data.Stratum().PVDG()[i][j];

                VERIFY(pvdg.BG() > 0, QString("%1-%2: The BG of the PVDG must be greater than 0").arg(i).arg(j).toLatin1());

                VERIFY(pvdg.MG() > 0, QString("%1-%2: The MG of the PVDG must be greater than 0").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().PVTG().length() > 0)
    {
        qDebug() << "Section PVTG exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().PVTG().length() == ntPVT, "The length of PVTG array must be equal NTPVT of TABDIMS");

        for (int i = 0; i < data.Stratum().PVTG().length(); i++)
        {
            for (int j = 0; j < data.Stratum().PVTG()[i].length(); j++)
            {
                PVTGData &pvtg = data.Stratum().PVTG()[i][j];

                VERIFY(pvtg.RV() >= 0, QString("%1-%2: The RV of the PVTG must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(pvtg.BG() > 0, QString("%1-%2: The BG of the PVTG must be greater than 0").arg(i).arg(j).toLatin1());

                VERIFY(pvtg.MG() > 0, QString("%1-%2: The MG of the PVTG must be greater than 0").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().ROCK().length() > 0)
    {
        qDebug() << "Section ROCK exist";

        QMetaObject metaObject = ROCKOPTSEntity::staticMetaObject;

        QMetaEnum regionOptions = metaObject.enumerator(metaObject.indexOfEnumerator("RegionOptions"));

        int regionOption = data.ROCKOPTS() != nullptr && !data.ROCKOPTS()->RegionOption().isNull() ?
                                        data.ROCKOPTS()->RegionOption().toInt() :
                                        DefaultValues::ROCKOPTS_RegionOption;

        int nt = regionOption == ROCKOPTSEntity::PVTNUM ?
                                    data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT : data.TABDIMS()->NTPVT().toInt() :
                                    data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN : data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().ROCK().length() == nt, QString("The length of ROCK array must be equal %1 = %2 of TABDIMS").arg(regionOptions.valueToKey(regionOption)).arg(nt).toLatin1());
    }

    if (data.Stratum().DENSITY().length() > 0)
    {
        qDebug() << "Section DENSITY exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().DENSITY().length() == ntPVT, "The length of DENSITY array must be equal NTPVT of TABDIMS");
    }

    if (data.Stratum().GRAVITY().length() > 0)
    {
        qDebug() << "Section GRAVITY exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().GRAVITY().length() == ntPVT, "The length of GRAVITY array must be equal NTPVT of TABDIMS");
    }

    if (data.Stratum().SWOF().length() > 0)
    {
        qDebug() << "Section SWOF exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SWOF().length() == ntSFUN, "The length of SWOF array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SWOF().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SWOF()[i].length(); j++)
            {
                SWOFData &swof = data.Stratum().SWOF()[i][j];

                VERIFY(swof.SW() >= 0, QString("%1-%2: The SW of the SWOF must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(swof.SW() <= 1, QString("%1-%2: The SW of the SWOF must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().SGOF().length() > 0)
    {
        qDebug() << "Section SGOF exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SGOF().length() == ntSFUN, "The length of SGOF array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SGOF().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SGOF()[i].length(); j++)
            {
                SGOFData &sgof = data.Stratum().SGOF()[i][j];

                VERIFY(sgof.SG() >= 0, QString("%1-%2: The SG of the SGOF must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(sgof.SG() <= 1, QString("%1-%2: The SG of the SGOF must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().SGWFN().length() > 0)
    {
        qDebug() << "Section SGWFN exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SGWFN().length() == ntSFUN, "The length of SGWFN array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SGWFN().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SGWFN()[i].length(); j++)
            {
                SGWFNData &sgwfn = data.Stratum().SGWFN()[i][j];

                VERIFY(sgwfn.SG() >= 0, QString("%1-%2: The SG of the SGWFN must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(sgwfn.SG() <= 1, QString("%1-%2: The SG of the SGWFN must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().SLGOF().length() > 0)
    {
        qDebug() << "Section SLGOF exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SLGOF().length() == ntSFUN, "The length of SLGOF array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SLGOF().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SLGOF()[i].length(); j++)
            {
                SLGOFData &slgof = data.Stratum().SLGOF()[i][j];

                VERIFY(slgof.SL() >= 0, QString("%1-%2: The SL of the SLGOF must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(slgof.SL() <= 1, QString("%1-%2: The SL of the SLGOF must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().SOF2().length() > 0)
    {
        qDebug() << "Section SOF2 exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SOF2().length() == ntSFUN, "The length of SOF2 array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SOF2().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SOF2()[i].length(); j++)
            {
                SOF2Data &sof2 = data.Stratum().SOF2()[i][j];

                VERIFY(sof2.SO() >= 0, QString("%1-%2: The SO of the SOF2 must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(sof2.SO() <= 1, QString("%1-%2: The SO of the SOF2 must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(sof2.KrO() >= 0, QString("%1-%2: The KrO of the SOF2 must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(sof2.KrO() <= 1, QString("%1-%2: The KrO of the SOF2 must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().SOF3().length() > 0)
    {
        qDebug() << "Section SOF3 exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SOF3().length() == ntSFUN, "The length of SOF3 array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SOF3().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SOF3()[i].length(); j++)
            {
                SOF3Data &sof3 = data.Stratum().SOF3()[i][j];

                VERIFY(sof3.SO() >= 0, QString("%1-%2: The SO of the SOF3 must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(sof3.SO() <= 1, QString("%1-%2: The SO of the SOF3 must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().SOF32D().length() > 0)
    {
        qDebug() << "Section SOF32D exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SOF32D().length() == ntSFUN, "The length of SOF32D array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SOF32D().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SOF32D()[i].SW().length(); j++)
            {
                VERIFY(data.Stratum().SOF32D()[i].SW()[j] >= 0, QString("%1-%2: The SW of the SOF32D must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(data.Stratum().SOF32D()[i].SW()[j] <= 1, QString("%1-%2: The SW of the SOF32D must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }

            for (int j = 0; j < data.Stratum().SOF32D()[i].SOF32DKrO().length(); j++)
            {
                VERIFY(data.Stratum().SOF32D()[i].SOF32DKrO()[j].SG() >= 0, QString("%1-%2: The SG of the SOF32D must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(data.Stratum().SOF32D()[i].SOF32DKrO()[j].SG() <= 1, QString("%1-%2: The SG of the SOF32D must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(data.Stratum().SOF32D()[i].SOF32DKrO()[j].KrO().length() <= data.Stratum().SOF32D()[i].SW().length(), "The number of KrO elements must be less or equal to SW elements of SOF32D");

                for (int k = 0; k < data.Stratum().SOF32D()[i].SOF32DKrO()[j].KrO().length(); k++)
                {
                    VERIFY(data.Stratum().SOF32D()[i].SOF32DKrO()[j].KrO()[k] >= 0, QString("%1-%2-%3: The KrO of the SOF32D must be greater than or equal to 0").arg(i).arg(j).arg(k).toLatin1());

                    VERIFY(data.Stratum().SOF32D()[i].SOF32DKrO()[j].KrO()[k] <= 1, QString("%1-%2-%3: The KrO of the SOF32D must be less than or equal to 1").arg(i).arg(j).arg(k).toLatin1());
                }
            }
        }
    }

    if (data.Stratum().SWFN().length() > 0)
    {
        qDebug() << "Section SWFN exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SWFN().length() == ntSFUN, "The length of SWFN array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SWFN().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SWFN()[i].length(); j++)
            {
                SWFNData &swfn = data.Stratum().SWFN()[i][j];

                VERIFY(swfn.SW() >= 0, QString("%1-%2: The SW of the SWFN must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(swfn.SW() <= 1, QString("%1-%2: The SW of the SWFN must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().SGFN().length() > 0)
    {
        qDebug() << "Section SGFN exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SGFN().length() == ntSFUN, "The length of SGFN array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SGFN().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SGFN()[i].length(); j++)
            {
                SGFNData &sgfn = data.Stratum().SGFN()[i][j];

                VERIFY(sgfn.SG() >= 0, QString("%1-%2: The SG of the SGFN must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(sgfn.SG() <= 1, QString("%1-%2: The SG of the SGFN must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().SOMGAS().length() > 0)
    {
        qDebug() << "Section SOMGAS exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SOMGAS().length() == ntSFUN, "The length of SOMGAS array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SOMGAS().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SOMGAS()[i].length(); j++)
            {
                SOMGASData &somgas = data.Stratum().SOMGAS()[i][j];

                VERIFY(somgas.SG() >= 0, QString("%1-%2: The SG of the SOMGAS must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(somgas.SG() <= 1, QString("%1-%2: The SG of the SOMGAS must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(somgas.SOMin() >= 0, QString("%1-%2: The SOMin of the SOMGAS must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(somgas.SOMin() <= 1, QString("%1-%2: The SOMin of the SOMGAS must be less than or equal to 1").arg(i).arg(j).toLatin1());

            }
        }
    }

    if (data.Stratum().SOMWAT().length() > 0)
    {
        qDebug() << "Section SOMWAT exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SOMWAT().length() == ntSFUN, "The length of SOMWAT array must be equal NTSFUN of TABDIMS");

        for (int i = 0; i < data.Stratum().SOMWAT().length(); i++)
        {
            for (int j = 0; j < data.Stratum().SOMWAT()[i].length(); j++)
            {
                SOMWATData &somwat = data.Stratum().SOMWAT()[i][j];

                VERIFY(somwat.SW() >= 0, QString("%1-%2: The SW of the SOMWAT must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(somwat.SW() <= 1, QString("%1-%2: The SW of the SOMWAT must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(somwat.SOMin() >= 0, QString("%1-%2: The SOMin of the SOMWAT must be greater than or equal to 0").arg(i).arg(j).toLatin1());

                VERIFY(somwat.SOMin() <= 1, QString("%1-%2: The SOMin of the SOMWAT must be less than or equal to 1").arg(i).arg(j).toLatin1());

            }
        }
    }

    if (data.Stratum().PPCWMAX().length()  > 0)
    {
        qDebug() << "Section PPCWMAX exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().PPCWMAX().length() == ntSFUN, "The length of PPCWMAX array must be equal NTSFUN of TABDIMS");
    }

    if (data.Stratum().ENKRVD().length() > 0)
    {
        qDebug() << "Section ENKRVD exist";

        int ntENDP = data.ENDSCALE()->NTENDP().isNull() ? DefaultValues::ENDSCALE_NTENDP : data.ENDSCALE()->NTENDP().toInt();

        VERIFY(data.Stratum().ENKRVD().length() == ntENDP, "The length of ENKRVD array must be equal NTENDP of ENDSCALE");

        for (int i = 0; i < data.Stratum().ENKRVD().length(); i++)
        {
            for (int j = 0; j < data.Stratum().ENKRVD()[i].length(); j++)
            {
                ENKRVDData &enkrvd = data.Stratum().ENKRVD()[i][j];

                VERIFY(enkrvd.MaxKrW() >= 0, QString("%1-%2: The MaxKrW of the ENKRVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enkrvd.MaxKrW() <= 1, QString("%1-%2: The MaxKrW of the ENKRVD must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(enkrvd.MaxKrG() >= 0, QString("%1-%2: The MaxKrG of the ENKRVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enkrvd.MaxKrG() <= 1, QString("%1-%2: The MaxKrG of the ENKRVD must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(enkrvd.MaxKrO() >= 0, QString("%1-%2: The MaxKrO of the ENKRVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enkrvd.MaxKrO() <= 1, QString("%1-%2: The MaxKrO of the ENKRVD must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(enkrvd.KrWCO() >= 0, QString("%1-%2: The KrWCO of the ENKRVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enkrvd.KrWCO() <= 1, QString("%1-%2: The KrWCO of the ENKRVD must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(enkrvd.KrGCO() >= 0, QString("%1-%2: The KrGCO of the ENKRVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enkrvd.KrGCO() <= 1, QString("%1-%2: The KrGCO of the ENKRVD must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(enkrvd.KrOCG() >= 0, QString("%1-%2: The KrOCG of the ENKRVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enkrvd.KrOCG() <= 1, QString("%1-%2: The KrOCG of the ENKRVD must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(enkrvd.KrOCW() >= 0, QString("%1-%2: The KrOCW of the ENKRVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enkrvd.KrOCW() <= 1, QString("%1-%2: The KrOCW of the ENKRVD must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if (data.Stratum().ENPCVD().length() > 0)
    {
        qDebug() << "Section ENPCVD exist";

        int ntENDP = data.ENDSCALE()->NTENDP().isNull() ? DefaultValues::ENDSCALE_NTENDP : data.ENDSCALE()->NTENDP().toInt();

        VERIFY(data.Stratum().ENPCVD().length() == ntENDP, "The length of ENPCVD array must be equal NTENDP of ENDSCALE");
    }

    if (data.Stratum().ENSPCVD().length() > 0)
    {
        qDebug() << "Section ENSPCVD exist";

        int ntENDP = data.ENDSCALE()->NTENDP().isNull() ? DefaultValues::ENDSCALE_NTENDP : data.ENDSCALE()->NTENDP().toInt();

        VERIFY(data.Stratum().ENSPCVD().length() == ntENDP, "The length of ENSPCVD array must be equal NTENDP of ENDSCALE");

        for (int i = 0; i < data.Stratum().ENSPCVD().length(); i++)
        {
            for (int j = 0; j < data.Stratum().ENSPCVD()[i].length(); j++)
            {
                ENSPCVDData &enspcvd = data.Stratum().ENSPCVD()[i][j];

                VERIFY(enspcvd.SGL() >= 0, QString("%1-%2: The SGL of the ENSPCVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enspcvd.SGL() <= 1, QString("%1-%2: The SGL of the ENSPCVD must be less than or equal to 1").arg(i).arg(j).toLatin1());

                VERIFY(enspcvd.SWL() >= 0, QString("%1-%2: The SWL of the ENSPCVD must be greater than or equal to 0").arg(i).arg(j).toLatin1());
                VERIFY(enspcvd.SWL() <= 1, QString("%1-%2: The SWL of the ENSPCVD must be less than or equal to 1").arg(i).arg(j).toLatin1());
            }
        }
    }

    if(data.Stratum().SCALELIM().length() > 0)
    {
        qDebug() << "Section SCALELIM exist";

        int ntENDP = data.ENDSCALE()->NTENDP().isNull() ? DefaultValues::ENDSCALE_NTENDP : data.ENDSCALE()->NTENDP().toInt();

        VERIFY(data.Stratum().SCALELIM().length() == ntENDP, "The length of SCALELIM array must be equal NTENDP of ENDSCALE");

        for(int i = 0; i < data.Stratum().SCALELIM().length(); i++)
        {
            double val = data.Stratum().SCALELIM()[i].toDouble();

            VERIFY(val >= 0, QString("%1: The value of element in SCALELIM array must be greater than or equal to 0").arg(i).toLatin1());
            VERIFY(val <= 1, QString("%1: The value of element in SCALELIM array must be less than or equal to 1").arg(i).toLatin1());
        }
    }

    if (data.Stratum().SPECHEAT().length() > 0)
    {
        qDebug() << "Section SPECHEAT exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().SPECHEAT().length() == ntPVT, "The length of SPECHEAT array must be equal NTPVT of TABDIMS");
    }

    if (data.Stratum().SPECROCK().length() > 0)
    {
        qDebug() << "Section SPECROCK exist";

        int ntSFUN = data.TABDIMS()->NTSFUN().isNull() ? DefaultValues::TABDIMS_NTSFUN :  data.TABDIMS()->NTSFUN().toInt();

        VERIFY(data.Stratum().SPECROCK().length() == ntSFUN, "The length of SPECROCK array must be equal NTSFUN of TABDIMS");
    }

    if (data.Stratum().VISCREF().length() > 0)
    {
        qDebug() << "Section VISCREF exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().VISCREF().length() == ntPVT, "The length of VISCREF array must be equal NTPVT of TABDIMS");
    }

    if(data.Stratum().OILVISCT().length() > 0)
    {
        qDebug() << "Section OILVISCT exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().OILVISCT().length() == ntPVT, "The length of OILVISCT array must be equal NTPVT of TABDIMS");

        for (int i = 0; i < data.Stratum().OILVISCT().length(); i++)
        {
            for (int j = 0; j < data.Stratum().OILVISCT()[i].length(); j++)
            {
                OILVISCTData &oilvisct = data.Stratum().OILVISCT()[i][j];

                VERIFY(oilvisct.MO() > 0, QString("%1-%2: The MO of the OILVISCT must be greater than 0").arg(i).arg(j).toLatin1());
            }
        }
    }

    if(data.Stratum().WATVISCT().length() > 0)
    {
        qDebug() << "Section WATVISCT exist";

        int ntPVT = data.TABDIMS()->NTPVT().isNull() ? DefaultValues::TABDIMS_NTPVT :  data.TABDIMS()->NTPVT().toInt();

        VERIFY(data.Stratum().WATVISCT().length() == ntPVT, "The length of WATVISCT array must be equal NTPVT of TABDIMS");

        for (int i = 0; i < data.Stratum().WATVISCT().length(); i++)
        {
            for (int j = 0; j < data.Stratum().WATVISCT()[i].length(); j++)
            {
                WATVISCTData &watvisct = data.Stratum().WATVISCT()[i][j];

                VERIFY(watvisct.MW() > 0, QString("%1-%2: The MW of the WATVISCT must be greater than 0").arg(i).arg(j).toLatin1());
            }
        }

    }

    if(data.Stratum().EQUIL().length() > 0)
    {
        qDebug() << "Section EQUIL exist";

        int ntEQUL = data.EQLDIMS()->NTEQUL().isNull() ? DefaultValues::EQLDIMS_NTEQUL : data.EQLDIMS()->NTEQUL().toInt();

        VERIFY(data.Stratum().EQUIL().length() == ntEQUL, "The length of EQUIL array must be equal NTEQUL of EQLDIMS");
    }

    if(data.Stratum().RSVD().length() > 0)
    {
        qDebug() << "Section RSVD exist";

        int ntEQUL = data.EQLDIMS()->NTEQUL().isNull() ? DefaultValues::EQLDIMS_NTEQUL : data.EQLDIMS()->NTEQUL().toInt();

        VERIFY(data.Stratum().RSVD().length() == ntEQUL, "The length of RSVD array must be equal NTEQUL of EQLDIMS");
    }

    if(data.Stratum().PBVD().length() > 0)
    {
        qDebug() << "Section PBVD exist";

        int ntEQUL = data.EQLDIMS()->NTEQUL().isNull() ? DefaultValues::EQLDIMS_NTEQUL : data.EQLDIMS()->NTEQUL().toInt();

        VERIFY(data.Stratum().PBVD().length() == ntEQUL, "The length of PBVD array must be equal NTEQUL of EQLDIMS");
    }

    if (data.Stratum().PRVD().length() > 0)
    {
        qDebug() << "Section PRVD exist";

        int ntEQUL = data.EQLDIMS()->NTEQUL().isNull() ? DefaultValues::EQLDIMS_NTEQUL : data.EQLDIMS()->NTEQUL().toInt();

        VERIFY(data.Stratum().PRVD().length() == ntEQUL, "The length of PRVD array must be equal NTEQUL of EQLDIMS");
    }
}
