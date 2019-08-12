#include "gravitydata.h"

namespace QaraMunai {
namespace Model {
namespace Domain {
namespace Stratum {

GRAVITYData::GRAVITYData()
{
    InitVariables();
}

QVariant GRAVITYData::GO()
{
    return go;
}

QVariant GRAVITYData::GW()
{
    return gw;
}

QVariant GRAVITYData::GG()
{
    return gg;
}

void GRAVITYData::SetGO(const QVariant &go)
{
    this->go = go;
}

void GRAVITYData::SetGW(const QVariant &gw)
{
    this->gw = gw;
}

void GRAVITYData::SetGG(const QVariant &gg)
{
    this->gg = gg;
}

void GRAVITYData::InitVariables()
{
    go.clear();
    gw.clear();
    gg.clear();
}

}}}}
