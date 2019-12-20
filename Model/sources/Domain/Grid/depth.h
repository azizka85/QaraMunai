#ifndef DEPTH_H
#define DEPTH_H

#include <qvariant.h>

#include <model_global.h>

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

class MODELSHARED_EXPORT Depth
{
public:
    Depth();
    Depth(double h1, double h2, double h3, double h4, double h5, double h6, double h7, double h8);

    double AvgDepth();

    double H1();
    double H2();
    double H3();
    double H4();
    double H5();
    double H6();
    double H7();
    double H8();

    void SetH1(double& h1);
    void SetH2(double& h2);
    void SetH3(double& h3);
    void SetH4(double& h4);
    void SetH5(double& h5);
    void SetH6(double& h6);
    void SetH7(double& h7);
    void SetH8(double& h8);

    void InitVariables();

private:
    double h1, h2, h3, h4, h5, h6, h7, h8;
};

}}}}

#endif // DEPTH_H
