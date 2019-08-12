#ifndef PVCDODATA_H
#define PVCDODATA_H

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

class MODELSHARED_EXPORT PVCDOData
{
public:
    PVCDOData();

    double PORef();
    double BORef();
    double CO();
    double MORef();
    double CVO();

    void SetPORef(const double& poRef);
    void SetBORef(const double& boRef);
    void SetCO(const double& co);
    void SetMORef(const double& moRef);
    void SetCVO(const double& cvo);

    void InitVariables();

private:
    double poRef, boRef, co, moRef, cvo;
};

}}}}

#endif // PVCDODATA_H
