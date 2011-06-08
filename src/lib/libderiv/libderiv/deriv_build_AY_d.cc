#include <libint/libint.h>
#include "libderiv.h"

void deriv_build_AY_d(prim_data *Data, const int bcd_num, double *vp, const double *I0, const double *I1)
{
  const double twotzeta = Data->twozeta_a;
  const double *i0, *i1;
  int bcd;

  i0 = I0 + 1*bcd_num;
  for(bcd=0;bcd<bcd_num;bcd++)
    *(vp++) = twotzeta*(*(i0++)) ;
  i0 = I0 + 3*bcd_num;
  i1 = I1;
  for(bcd=0;bcd<bcd_num;bcd++)
    *(vp++) = twotzeta*(*(i0++)) - 1.000000*(*(i1++));
  i0 = I0 + 4*bcd_num;
  for(bcd=0;bcd<bcd_num;bcd++)
    *(vp++) = twotzeta*(*(i0++)) ;
  i0 = I0 + 6*bcd_num;
  i1 = I1 + 1*bcd_num;
  for(bcd=0;bcd<bcd_num;bcd++)
    *(vp++) = twotzeta*(*(i0++)) - 2.000000*(*(i1++));
  i0 = I0 + 7*bcd_num;
  i1 = I1 + 2*bcd_num;
  for(bcd=0;bcd<bcd_num;bcd++)
    *(vp++) = twotzeta*(*(i0++)) - 1.000000*(*(i1++));
  i0 = I0 + 8*bcd_num;
  for(bcd=0;bcd<bcd_num;bcd++)
    *(vp++) = twotzeta*(*(i0++)) ;
}