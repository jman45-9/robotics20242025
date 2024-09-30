#include "helpers.hpp"
#include "helper_fuctions.hpp"

inline double helpers::math::uTauTo_uDeg(double uTau)
{
        return (uTau) * 360;
}

inline int helpers::math::sign(double x)
{
        if (x == 0)
                return 0;
        return (x<0 ? -1 : 1);
}
