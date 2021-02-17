#ifndef LIBPOWER_H
#define LIBPOWER_H

/*
Beräkningen av P enligt följande formler
* P = U * I  (Spänning gånger strömmen)
* P = U^2 / R (Spänning i kvadrat delat i resistansen)
*/


extern float calc_power_r(float volt, float resistance);

extern float calc_power_i(float volt, float current);

#endif /*LIBPOWER_H*/
