#include "cmath.h"
namespace dvcs {

CMath::CMath()
{

}

double CMath::calCirclecArea(double dRadius)
{
    return dRadius*dRadius*CMath::PI;
}

}
