#include "depth.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Grid {

Depth::Depth()
{
    InitVariables();
}

Depth::Depth(double h1, double h2, double h3, double h4, double h5, double h6, double h7, double h8)
{
    this->h1 = h1;
    this->h2 = h2;
    this->h3 = h3;
    this->h4 = h4;
    this->h5 = h5;
    this->h6 = h6;
    this->h7 = h7;
    this->h8 = h8;
}

double Depth::AvgDepth()
{
    return (h1 + h2 + h3 + h4 + h5 + h6 + h7 + h8) / 8;
}

double Depth::H1()
{
    return h1;
}

double Depth::H2()
{
    return h2;
}

double Depth::H3()
{
    return h3;
}

double Depth::H4()
{
    return h4;
}

double Depth::H5()
{
    return h5;
}

double Depth::H6()
{
    return h6;
}

double Depth::H7()
{
    return h7;
}

double Depth::H8()
{
    return h8;
}

void Depth::SetH1(double &h1)
{
    this->h1 = h1;
}

void Depth::SetH2(double &h2)
{
    this->h2 = h2;
}

void Depth::SetH3(double &h3)
{
    this->h3 = h3;
}

void Depth::SetH4(double &h4)
{
    this->h4 = h4;
}

void Depth::SetH5(double &h5)
{
    this->h5 = h5;
}

void Depth::SetH6(double &h6)
{
    this->h6 = h6;
}

void Depth::SetH7(double &h7)
{
    this->h7 = h7;
}

void Depth::SetH8(double &h8)
{
    this->h8 = h8;
}

void Depth::InitVariables()
{
    h1 = h2 = h3 = h4 = h5 = h6 = h7 = h8 = 0;
}

}}}}
