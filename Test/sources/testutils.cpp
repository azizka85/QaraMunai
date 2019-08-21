#include "testutils.h"

TestUtils::TestUtils(QObject *parent) : QObject(parent) { }

void TestUtils::TestLinearMatrix2D()
{
    Box3D box(0, 2, 0, 2, 0, 0);

    LinearMatrix2D linearMatrix2D;

    linearMatrix2D.SetBox(box);

    int nx = linearMatrix2D.Nx();

    VERIFY(nx == 3, "Nx of LinearMatrix2D must be equal 3");

    linearMatrix2D.Add(23.45);
    linearMatrix2D.AddInterval(4, 38.97);
    linearMatrix2D.AddInterval(3, 12.45);
    linearMatrix2D.Add(1.39);

    int count = linearMatrix2D.Count();

    VERIFY(count == nx*nx, "Number of LinearMatrix2D elements must be equal to nx*nx");

    double val = linearMatrix2D(0, 0).toDouble();

    VERIFY(ISEQUAL(val, 23.45), "Element with [0,0] indexes must be equal to 23.45");

    val = linearMatrix2D(1, 1).toDouble();

    VERIFY(ISEQUAL(val, 38.97), "Element with [1,1] indexes must be equal to 38.97");

    val = linearMatrix2D(1, 2).toDouble();

    VERIFY(ISEQUAL(val, 12.45), "Element with [1,2] indexes must be equal to 12.45");

    val = linearMatrix2D(2, 2).toDouble();

    VERIFY(ISEQUAL(val, 1.39), "Element with [2,2] indexes must be equal to 1.39");

    linearMatrix2D.Box().SetI1(10);
    linearMatrix2D.Box().SetI2(12);

    linearMatrix2D.Box().SetJ1(10);
    linearMatrix2D.Box().SetJ2(12);

    val = linearMatrix2D(10, 10).toDouble();

    VERIFY(ISEQUAL(val, 23.45), "Element with [10,10] indexes must be equal to 23.45");

    val = linearMatrix2D(11, 11).toDouble();

    VERIFY(ISEQUAL(val, 38.97), "Element with [11,11] indexes must be equal to 38.97");

    val = linearMatrix2D(11, 12).toDouble();

    VERIFY(ISEQUAL(val, 12.45), "Element with [11,12] indexes must be equal to 12.45");

    val = linearMatrix2D(12, 12).toDouble();

    VERIFY(ISEQUAL(val, 1.39), "Element with [12,12] indexes must be equal to 1.39");

}

void TestUtils::TestUnitConstants()
{
    // Gravity
    double val = UnitHelper::GravityTable[ProjectData::METRIC];

    VERIFY(ISEQUAL(val, 0.0000980665), QString("Gravity in Metric unit is %1").arg(0.0000980665).toLatin1());

    val = UnitHelper::GravityTable[ProjectData::FIELD];

    VERIFY(ISEQUAL(val, 0.00694444), QString("Gravity in Field unit is %1").arg(0.00694444).toLatin1());

    val = UnitHelper::GravityTable[ProjectData::LAB];

    VERIFY(ISEQUAL(val, 0.000967841), QString("Gravity in Lab unit is %1").arg(0.000967841).toLatin1());

    val = UnitHelper::DarcyTable[ProjectData::METRIC];

    // Darcy
    VERIFY(ISEQUAL(val, 0.00852702), QString("Darcy in Metric unit is %1").arg(0.00852702).toLatin1());

    val = UnitHelper::DarcyTable[ProjectData::FIELD];

    VERIFY(ISEQUAL(val, 0.00112712), QString("Darcy in Field unit is %1").arg(0.00112712).toLatin1());

    val = UnitHelper::DarcyTable[ProjectData::LAB];

    VERIFY(ISEQUAL(val, 3.6), QString("Darcy in Lab unit is %1").arg(3.6).toLatin1());

    // Atmospheric pressure
    val = UnitHelper::AtmosphericPressureTable[ProjectData::METRIC];

    VERIFY(ISEQUAL(val, 1.01325), QString("Atmospheric pressure in Metric unit is %1").arg(1.01325).toLatin1());

    val = UnitHelper::AtmosphericPressureTable[ProjectData::FIELD];

    VERIFY(ISEQUAL(val, 14.6959), QString("Atmospheric pressure in Field unit is %1").arg(14.6959).toLatin1());

    val = UnitHelper::AtmosphericPressureTable[ProjectData::LAB];

    VERIFY(ISEQUAL(val, 1.0), QString("Atmospheric pressure in Lab unit is %1").arg(1.0).toLatin1());

    // Density of air
    val = UnitHelper::DensityOfAirTable[ProjectData::METRIC];

    VERIFY(ISEQUAL(val, 1.2232), QString("Density of air in Metric unit is %1").arg(1.2232).toLatin1());

    val = UnitHelper::DensityOfAirTable[ProjectData::FIELD];

    VERIFY(ISEQUAL(val, 0.076362), QString("Density of air in Field unit is %1").arg(0.076362).toLatin1());

    val = UnitHelper::DensityOfAirTable[ProjectData::LAB];

    VERIFY(ISEQUAL(val, 0.0012232), QString("Density of air in Lab unit is %1").arg(0.0012232).toLatin1());

    // Density of water
    val = UnitHelper::DensityOfWaterTable[ProjectData::METRIC];

    VERIFY(ISEQUAL(val, 999.014), QString("Density of water in Metric unit is %1").arg(999.014).toLatin1());

    val = UnitHelper::DensityOfWaterTable[ProjectData::FIELD];

    VERIFY(ISEQUAL(val, 62.3664), QString("Density of water in Field unit is %1").arg(62.3664).toLatin1());

    val = UnitHelper::DensityOfWaterTable[ProjectData::LAB];

    VERIFY(ISEQUAL(val, 0.999014), QString("Density of water in Lab unit is %1").arg(0.999014).toLatin1());

    // Gas constant
    val = UnitHelper::GasConstantTable[ProjectData::METRIC];

    VERIFY(ISEQUAL(val, 0.083143), QString("Gas constant in Metric unit is %1").arg(0.083143).toLatin1());

    val = UnitHelper::GasConstantTable[ProjectData::FIELD];

    VERIFY(ISEQUAL(val, 10.732), QString("Gas constant in Field unit is %1").arg(10.732).toLatin1());

    val = UnitHelper::GasConstantTable[ProjectData::LAB];

    VERIFY(ISEQUAL(val, 820.55776), QString("Gas constant in Lab unit is %1").arg(820.55776).toLatin1());
}

void TestUtils::TestConvertPressure()
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    double val = UnitHelper::ConvertPressure(ProjectData::METRIC, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::BarToPsi), QString("1 barsa must be equal %1 psia").arg(UnitHelper::BarToPsi).toLatin1());

    val = UnitHelper::ConvertPressure(ProjectData::METRIC, ProjectData::LAB, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::BarToAtm), QString("1 barsa must be equal %1 atma").arg(UnitHelper::BarToAtm).toLatin1());

    val = UnitHelper::ConvertPressure(ProjectData::FIELD, ProjectData::LAB, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::PsiToAtm), QString("1 psia must be equal %1 atma").arg(UnitHelper::PsiToAtm).toLatin1());

    val = UnitHelper::ConvertPressure(ProjectData::LAB, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1 / UnitHelper::PsiToAtm), QString("1 atma must be equal %1 psia").arg(1 / UnitHelper::PsiToAtm).toLatin1());

    val = UnitHelper::ConvertPressure(ProjectData::LAB, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1 / UnitHelper::BarToAtm), QString("1 atma must be equal %1 barsa").arg(1 / UnitHelper::BarToAtm).toLatin1());

    val = UnitHelper::ConvertPressure(ProjectData::FIELD, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1 / UnitHelper::BarToPsi), QString("1 psia must be equal %1 barsa").arg(1 / UnitHelper::BarToPsi).toLatin1());
}

void TestUtils::TestConvertLength()
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    double val = UnitHelper::ConvertLength(ProjectData::METRIC, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::MeterToFoot), QString("1 meter must be equal %1 foot").arg(UnitHelper::MeterToFoot).toLatin1());

    val = UnitHelper::ConvertLength(ProjectData::FIELD, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::MeterToFoot), QString("1 foot must be equal %1 meter").arg(1/UnitHelper::MeterToFoot).toLatin1());

    QVariant varVal = UnitHelper::ConvertLength(ProjectData::METRIC, ProjectData::LAB, 1, unitsEnum);

    VERIFY(varVal.isNull(), QString("1 meter in Lab unit not defined yet").toLatin1());
}

void TestUtils::TestConvertVolume()
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    double val = UnitHelper::ConvertVolume(ProjectData::METRIC, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::CmToCf), QString("1 m^3 must be equal %1 f^3").arg(UnitHelper::CmToCf).toLatin1());

    val = UnitHelper::ConvertVolume(ProjectData::FIELD, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::CmToCf), QString("1 f^3 must be equal %1 m^3").arg(1/UnitHelper::CmToCf).toLatin1());

    val = UnitHelper::ConvertVolume(ProjectData::METRIC, ProjectData::LAB, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::CmToBbl), QString("1 m^3 must be equal %1 bbl").arg(UnitHelper::CmToBbl).toLatin1());

    val = UnitHelper::ConvertVolume(ProjectData::LAB, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::CmToBbl), QString("1 bbl must be equal %1 m^3").arg(1/UnitHelper::CmToBbl).toLatin1());

    val = UnitHelper::ConvertVolume(ProjectData::FIELD, ProjectData::LAB, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::CfToBbl), QString("1 cf must be equal %1 bbl").arg(UnitHelper::CfToBbl).toLatin1());

    val = UnitHelper::ConvertVolume(ProjectData::LAB, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::CfToBbl), QString("1 bbl must be equal %1 cf").arg(1/UnitHelper::CfToBbl).toLatin1());
}

void TestUtils::TestConvertMass()
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    double val = UnitHelper::ConvertMass(ProjectData::METRIC, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::KgToLb), QString("1 kg must be equal %1 lb").arg(UnitHelper::KgToLb).toLatin1());

    val = UnitHelper::ConvertMass(ProjectData::FIELD, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::KgToLb), QString("1 lb must be equal %1 kg").arg(1/UnitHelper::KgToLb).toLatin1());

    QVariant varVal = UnitHelper::ConvertMass(ProjectData::METRIC, ProjectData::LAB, 1, unitsEnum);

    VERIFY(varVal.isNull(), QString("1 kg in Lab unit not defined yet").toLatin1());
}

void TestUtils::TestConvertDensity()
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    double val = UnitHelper::ConvertDensity(ProjectData::METRIC, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::DMToDF), QString("1 kg/m3 must be equal %1 lb/ft3").arg(UnitHelper::DMToDF).toLatin1());

    val = UnitHelper::ConvertDensity(ProjectData::FIELD, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::DMToDF), QString("1 lb/ft3 must be equal %1 kg/m3").arg(1/UnitHelper::DMToDF).toLatin1());

    val = UnitHelper::ConvertDensity(ProjectData::METRIC, ProjectData::LAB, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::DMToDL), QString("1 kg/m3 must be equal %1 g/cm3").arg(UnitHelper::DMToDL).toLatin1());

    val = UnitHelper::ConvertDensity(ProjectData::LAB, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::DMToDL), QString("1 g/cm3 must be equal %1 kg/m3").arg(1/UnitHelper::DMToDL).toLatin1());

    val = UnitHelper::ConvertDensity(ProjectData::FIELD, ProjectData::LAB, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::DFToDL), QString("1 lb/ft3 must be equal %1 g/cm3").arg(UnitHelper::DFToDL).toLatin1());

    val = UnitHelper::ConvertDensity(ProjectData::LAB, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::DFToDL), QString("1 lb/ft3 must be equal %1 g/cm3").arg(1/UnitHelper::DFToDL).toLatin1());
}

void TestUtils::TestConvertGasLiquidRatio()
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    double val = UnitHelper::ConvertGasLiquidRatio(ProjectData::METRIC, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::GLRMToGLRF), QString("1 m3/m3 must be equal %1 mcf/bbl").arg(UnitHelper::GLRMToGLRF).toLatin1());

    val = UnitHelper::ConvertGasLiquidRatio(ProjectData::FIELD, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::GLRMToGLRF), QString("1 mcf/bbl must be equal %1 m3/m3").arg(1/UnitHelper::GLRMToGLRF).toLatin1());

    val = UnitHelper::ConvertGasLiquidRatio(ProjectData::METRIC, ProjectData::LAB, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::GLRMToGLRL), QString("1 m3/m3 must be equal %1 bbl/bbl").arg(UnitHelper::GLRMToGLRL).toLatin1());

    val = UnitHelper::ConvertGasLiquidRatio(ProjectData::LAB, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::GLRMToGLRL), QString("1 bbl/bbl must be equal %1 m^3/m^3").arg(1/UnitHelper::GLRMToGLRL).toLatin1());

    val = UnitHelper::ConvertGasLiquidRatio(ProjectData::FIELD, ProjectData::LAB, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::GLRFToGLRL), QString("1 mcf/bbl must be equal %1 bbl/bbl").arg(UnitHelper::GLRFToGLRL).toLatin1());

    val = UnitHelper::ConvertGasLiquidRatio(ProjectData::LAB, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::GLRFToGLRL), QString("1 bbl/bbl must be equal %1 mcf/bbl").arg(1/UnitHelper::GLRFToGLRL).toLatin1());
}

void TestUtils::TestConvertTemperature()
{
    QMetaObject metaObject = ProjectData::staticMetaObject;

    QMetaEnum unitsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    double val = UnitHelper::ConvertTemperature(ProjectData::METRIC, ProjectData::FIELD, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, UnitHelper::KToR), QString("1 K must be equal %1 R").arg(UnitHelper::KToR).toLatin1());

    val = UnitHelper::ConvertTemperature(ProjectData::FIELD, ProjectData::METRIC, 1, unitsEnum).toDouble();

    VERIFY(ISEQUAL(val, 1/UnitHelper::KToR), QString("1 R must be equal %1 K").arg(1/UnitHelper::KToR).toLatin1());

    QVariant varVal = UnitHelper::ConvertTemperature(ProjectData::METRIC, ProjectData::LAB, 1, unitsEnum);

    VERIFY(varVal.isNull(), QString("1 K in Lab unit not defined yet").toLatin1());
}

void TestUtils::TestDefaultValues()
{
    VERIFY(DefaultValues::WELSPECS_WellGroup == "FIELD", "WellGroup default value of WELSPECS must equal to FIELD");
}

void TestUtils::TestCasesEnum()
{
    QMetaObject metaObject = EclipseFileReader::staticMetaObject;

    QMetaEnum casesEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Cases"));

    QString caseStr = "RUNSPEC";

    int value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::RUNSPEC, "Value must be equal to RUNSPEC");

    caseStr = "TITLE";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::TITLE, "Value must be equal to TITLE");

    caseStr = "START";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::START, "Value must be equal to START");

    caseStr = "METRIC";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::METRIC, "Value must be equal to METRIC");

    caseStr = "FIELD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::FIELD, "Value must be equal to FIELD");

    caseStr = "LAB";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::LAB, "Value must be equal to LAB");

    caseStr = "GAS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::GAS, "Value must be equal to GAS");

    caseStr = "TEMP";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::TEMP, "Value must be equal to TEMP");

    caseStr = "NUMRES";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::NUMRES, "Value must be equal to NUMRES");

    caseStr = "DIMENS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DIMENS, "Value must be equal to DIMENS");

    caseStr = "REGDIMS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::REGDIMS, "Value must be equal to REGDIMS");

    caseStr = "TABDIMS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::TABDIMS, "Value must be equal to TABDIMS");

    caseStr = "EQLDIMS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::EQLDIMS, "Value must be equal to EQLDIMS");

    caseStr = "WELLDIMS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::WELLDIMS, "Value must be equal to WELLDIMS");

    caseStr = "ENDSCALE";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ENDSCALE, "Value must be equal to ENDSCALE");

    caseStr = "TOPS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::TOPS, "Value must be equal to TOPS");

    caseStr = "DX";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DX, "Value must be equal to DX");

    caseStr = "DY";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DY, "Value must be equal to DY");

    caseStr = "DZ";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DZ, "Value must be equal to DZ");

    caseStr = "DXV";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DXV, "Value must be equal to DXV");

    caseStr = "DYV";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DYV, "Value must be equal to DYV");

    caseStr = "DZV";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DZV, "Value must be equal to DZV");

    caseStr = "COORD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::COORD, "Value must be equal to COORD");

    caseStr = "ZCORN";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ZCORN, "Value must be equal to ZCORN");

    caseStr = "ACTNUM";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ACTNUM, "Value must be equal to ACTNUM");

    caseStr = "MULTPV";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MULTPV, "Value must be equal to MULTPV");

    caseStr = "PERMX";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PERMX, "Value must be equal to PERMX");

    caseStr = "PERMY";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PERMY, "Value must be equal to PERMY");

    caseStr = "PERMZ";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PERMZ, "Value must be equal to PERMZ");

    caseStr = "PORO";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PORO, "Value must be equal to PORO");

    caseStr = "NTG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::NTG, "Value must be equal to NTG");

    caseStr = "DZNET";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DZNET, "Value must be equal to DZNET");

    caseStr = "MULTX";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MULTX, "Value must be equal to MULTX");

    caseStr = "MULTY";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MULTY, "Value must be equal to MULTY");

    caseStr = "MULTZ";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MULTZ, "Value must be equal to MULTZ");

    caseStr = "MULTXm";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MULTXm, "Value must be equal to MULTX-");

    caseStr = "MULTYm";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MULTYm, "Value must be equal to MULTY-");

    caseStr = "MULTZm";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MULTZm, "Value must be equal to MULTZ-");

    caseStr = "MINPV";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MINPV, "Value must be equal to MINPV");

    caseStr = "MINPVV";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MINPVV, "Value must be equal to MINPVV");

    caseStr = "RSCONST";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::RSCONST, "Value must be equal to RSCONST");

    caseStr = "RSCONSTT";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::RSCONSTT, "Value must be equal to RSCONSTT");

    caseStr = "PVTO";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PVTO, "Value must be equal to PVTO");

    caseStr = "PVCO";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PVCO, "Value must be equal to PVCO");

    caseStr = "PMAX";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PMAX, "Value must be equal to PMAX");

    caseStr = "PVCDO";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PVCDO, "Value must be equal to PVCDO");

    caseStr = "PVDO";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PVDO, "Value must be equal to PVDO");

    caseStr = "PVTW";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PVTW, "Value must be equal to PVTW");

    caseStr = "PVDG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PVDG, "Value must be equal to PVDG");

    caseStr = "PVTG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PVTG, "Value must be equal to PVTG");

    caseStr = "ROCKOPTS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ROCKOPTS, "Value must be equal to ROCKOPTS");

    caseStr = "ROCK";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ROCK, "Value must be equal to ROCK");

    caseStr = "DENSITY";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DENSITY, "Value must be equal to DENSITY");

    caseStr = "GRAVITY";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::GRAVITY, "Value must be equal to GRAVITY");

    caseStr = "SWOF";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SWOF, "Value must be equal to SWOF");

    caseStr = "SGOF";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SGOF, "Value must be equal to SGOF");

    caseStr = "SGWFN";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SGWFN, "Value must be equal to SGWFN");

    caseStr = "SLGOF";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SLGOF, "Value must be equal to SLGOF");

    caseStr = "SOF2";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SOF2, "Value must be equal to SOF2");

    caseStr = "SOF3";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SOF3, "Value must be equal to SOF3");

    caseStr = "SOF32D";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SOF32D, "Value must be equal to SOF32D");

    caseStr = "SWFN";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SWFN, "Value must be equal to SWFN");

    caseStr = "SGFN";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SGFN, "Value must be equal to SGFN");

    caseStr = "SOMGAS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SOMGAS, "Value must be equal to SOMGAS");

    caseStr = "SOMWAT";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SOMWAT, "Value must be equal to SOMWAT");

    caseStr = "SWATINIT";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SWATINIT, "Value must be equal to SWATINIT");

    caseStr = "SWCR";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SWCR, "Value must be equal to SWCR");

    caseStr = "ISWCR";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ISWCR, "Value must be equal to ISWCR");

    caseStr = "SWL";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SWL, "Value must be equal to SWL");

    caseStr = "ISWL";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ISWL, "Value must be equal to ISWL");

    caseStr = "SWLPC";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SWLPC, "Value must be equal to SWLPC");

    caseStr = "ISWLPC";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ISWLPC, "Value must be equal to ISWLPC");

    caseStr = "SWU";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SWU, "Value must be equal to SWU");

    caseStr = "ISWU";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ISWU, "Value must be equal to ISWU");

    caseStr = "SGCR";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SGCR, "Value must be equal to SGCR");

    caseStr = "ISGCR";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ISGCR, "Value must be equal to ISGCR");

    caseStr = "SGL";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SGL, "Value must be equal to SGL");

    caseStr = "ISGL";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ISGL, "Value must be equal to ISGL");

    caseStr = "SGLPC";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SGLPC, "Value must be equal to SGLPC");

    caseStr = "ISGLPC";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ISGLPC, "Value must be equal to ISGLPC");

    caseStr = "PCG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PCG, "Value must be equal to PCG");

    caseStr = "IPCG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IPCG, "Value must be equal to IPCG");

    caseStr = "PCW";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PCW, "Value must be equal to PCW");

    caseStr = "IPCW";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IPCW, "Value must be equal to IPCW");

    caseStr = "PPCWMAX";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PPCWMAX, "Value must be equal to PPCWMAX");

    caseStr = "KRO";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::KRO, "Value must be equal to KRO");

    caseStr = "IKRO";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IKRO, "Value must be equal to IKRO");

    caseStr = "KRORW";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::KRORW, "Value must be equal to KRORW");

    caseStr = "IKRORW";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IKRORW, "Value must be equal to IKRORW");

    caseStr = "KRORG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::KRORG, "Value must be equal to KRORG");

    caseStr = "IKRORG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IKRORG, "Value must be equal to IKRORG");

    caseStr = "KRW";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::KRW, "Value must be equal to KRW");

    caseStr = "IKRW";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IKRW, "Value must be equal to IKRW");

    caseStr = "KRWR";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::KRWR, "Value must be equal to KRWR");

    caseStr = "IKRWR";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IKRWR, "Value must be equal to IKRWR");

    caseStr = "KRG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::KRG, "Value must be equal to KRG");

    caseStr = "IKRG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IKRG, "Value must be equal to IKRG");

    caseStr = "KRGR";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::KRGR, "Value must be equal to KRGR");

    caseStr = "IKRGR";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::IKRGR, "Value must be equal to IKRGR");

    caseStr = "ENKRVD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ENKRVD, "Value must be equal to ENKRVD");

    caseStr = "ENPCVD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ENPCVD, "Value must be equal to ENPCVD");

    caseStr = "ENSPCVD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ENSPCVD, "Value must be equal to ENSPCVD");

    caseStr = "SCALELIM";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SCALELIM, "Value must be equal to SCALELIM");

    caseStr = "SCALECRS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SCALECRS, "Value must be equal to SCALECRS");

    caseStr = "SPECHEAT";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SPECHEAT, "Value must be equal to SPECHEAT");

    caseStr = "SPECROCK";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SPECROCK, "Value must be equal to SPECROCK");

    caseStr = "VISCREF";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::VISCREF, "Value must be equal to VISCREF");

    caseStr = "OILVISCT";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::OILVISCT, "Value must be equal to OILVISCT");

    caseStr = "WATVISCT";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::WATVISCT, "Value must be equal to WATVISCT");

    caseStr = "PVTNUM";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PVTNUM, "Value must be equal to PVTNUM");

    caseStr = "SATNUM";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SATNUM, "Value must be equal to SATNUM");

    caseStr = "EQLNUM";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::EQLNUM, "Value must be equal to EQLNUM");

    caseStr = "ENDNUM";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ENDNUM, "Value must be equal to ENDNUM");

    caseStr = "EQUIL";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::EQUIL, "Value must be equal to EQUIL");

    caseStr = "RSVD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::RSVD, "Value must be equal to RSVD");

    caseStr = "PBVD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PBVD, "Value must be equal to PBVD");

    caseStr = "PRVD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PRVD, "Value must be equal to PRVD");

    caseStr = "PRESSURE";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PRESSURE, "Value must be equal to PRESSURE");

    caseStr = "SWAT";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SWAT, "Value must be equal to SWAT");

    caseStr = "SGAS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::SGAS, "Value must be equal to SGAS");

    caseStr = "PBUB";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PBUB, "Value must be equal to PBUB");

    caseStr = "RS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::RS, "Value must be equal to RS");

    caseStr = "AQUANCON";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::AQUANCON, "Value must be equal to AQUANCON");

    caseStr = "AQUFETP";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::AQUFETP, "Value must be equal to AQUFETP");

    caseStr = "DIMPES";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DIMPES, "Value must be equal to DIMPES");

    caseStr = "RPTRST";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::RPTRST, "Value must be equal to RPTRST");

    caseStr = "RPTSCHED";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::RPTSCHED, "Value must be equal to RPTSCHED");

    caseStr = "WELSPECS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::WELSPECS, "Value must be equal to WELSPECS");

    caseStr = "COMPDAT";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::COMPDAT, "Value must be equal to COMPDAT");

    caseStr = "WCONPROD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::WCONPROD, "Value must be equal to WCONPROD");

    caseStr = "WCONINJE";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::WCONINJE, "Value must be equal to WCONINJE");

    caseStr = "DATES";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DATES, "Value must be equal to DATES");

    caseStr = "TSTEP";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::TSTEP, "Value must be equal to TSTEP");

    caseStr = "WCONHIST";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::WCONHIST, "Value must be equal to WCONHIST");

    caseStr = "WCONINJH";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::WCONINJH, "Value must be equal to WCONINJH");

    caseStr = "WELTARG";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::WELTARG, "Value must be equal to WELTARG");

    caseStr = "INCLUDE";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::INCLUDE, "Value must be equal to INCLUDE");

    caseStr = "EQUALS";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::EQUALS, "Value must be equal to EQUALS");

    caseStr = "BOX";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::BOX, "Value must be equal to BOX");

    caseStr = "ENDBOX";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ENDBOX, "Value must be equal to ENDBOX");

    caseStr = "COPY";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::COPY, "Value must be equal to COPY");

    caseStr = "ADD";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::ADD, "Value must be equal to ADD");

    caseStr = "MULTIPLY";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::MULTIPLY, "Value must be equal to MULTIPLY");

    caseStr = "DEPTH";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::DEPTH, "Value must be equal to DEPTH");

    caseStr = "PORV";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::PORV, "Value must be equal to PORV");

    caseStr = "TRANX";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::TRANX, "Value must be equal to TRANX");

    caseStr = "TRANY";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::TRANY, "Value must be equal to TRANY");

    caseStr = "TRANZ";

    value = casesEnum.keyToValue(caseStr.toLatin1());

    VERIFY(value == EclipseFileReader::TRANZ, "Value must be equal to TRANZ");
}

void TestUtils::TestEnums()
{
    QMetaObject metaObject = EclipseFileReader::staticMetaObject;

    QMetaEnum monthsEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Months"));

    int val = monthsEnum.keyToValue("NOV");

    VERIFY(val == EclipseFileReader::NOV, "Value must be equal to NOV");


    metaObject = ENDSCALEEntity::staticMetaObject;

    QMetaEnum directionalTypes = metaObject.enumerator(metaObject.indexOfEnumerator("DirectionalType"));

    val = directionalTypes.keyToValue("DIRECT");

    VERIFY(val == ENDSCALEEntity::DIRECT, "Value must be equal to DIRECT");

    QMetaEnum irreversibleTypes = metaObject.enumerator(metaObject.indexOfEnumerator("IrreversibleType"));

    val = irreversibleTypes.keyToValue("IRREVERS");

    VERIFY(val == ENDSCALEEntity::IRREVERS, "Value must be equal to IRREVERS");


    metaObject = ROCKOPTSEntity::staticMetaObject;

    QMetaEnum maotpOptions = metaObject.enumerator(metaObject.indexOfEnumerator("MAOTPOptions"));

    val = maotpOptions.keyToValue("STRESS");

    VERIFY(val == ROCKOPTSEntity::STRESS, "Value must be equal to STRESS");

    QMetaEnum referencePressureOptions = metaObject.enumerator(metaObject.indexOfEnumerator("ReferencePressureOptions"));

    val = referencePressureOptions.keyToValue("STORE");

    VERIFY(val == ROCKOPTSEntity::STORE, "Value must be equal to STORE");

    QMetaEnum regionOptions = metaObject.enumerator(metaObject.indexOfEnumerator("RegionOptions"));

    val = regionOptions.keyToValue("SATNUM");

    VERIFY(val == ROCKOPTSEntity::SATNUM, "Value must be equal to SATNUM");

    QMetaEnum ihbOptions = metaObject.enumerator(metaObject.indexOfEnumerator("IHBOptions"));

    val = ihbOptions.keyToValue("ELASTIC");

    VERIFY(val == ROCKOPTSEntity::ELASTIC, "Value must be equal to ELASTIC");


    metaObject = ProjectData::staticMetaObject;

    QMetaEnum unitTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("UnitType"));

    val = unitTypeEnum.keyToValue("LAB");

    VERIFY(val == ProjectData::LAB, "Value must be equal to LAB");

    QMetaEnum modelTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("ModelType"));

    val = modelTypeEnum.keyToValue("ThreePhase");

    VERIFY(val == ProjectData::ThreePhase, "Value must be equal to ThreePhase");

    QMetaEnum faceTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("FaceType"));

    val = faceTypeEnum.keyToValue("Jm");

    VERIFY(val == ProjectData::Jm, "Value must be equal to Jm");

    QMetaEnum wellStatusTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellStatusType"));

    val = wellStatusTypeEnum.keyToValue("OPEN");

    VERIFY(val == ProjectData::OPEN, "Value must be equal to OPEN");

    QMetaEnum wellControlModeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("WellControlMode"));

    val = wellControlModeEnum.keyToValue("BHP");

    VERIFY(val == ProjectData::BHP, "Value must be equal to BHP");

    QMetaEnum fluidTypeEnum = metaObject.enumerator(metaObject.indexOfEnumerator("FluidType"));

    val = fluidTypeEnum.keyToValue("OIL");

    VERIFY(val == ProjectData::OIL, "Value must be equal to OIL");
}
