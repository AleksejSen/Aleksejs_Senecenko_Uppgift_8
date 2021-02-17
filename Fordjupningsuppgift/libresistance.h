#ifndef LIBRESISTANCE_H
#define LIBRESISTANCE_H

/*
* count: Antal komponenter.
* conn: Seriellt eller parallellt kopplade komponeter [ P | S ].
* *array: En pekare på en array av komponentvärden som är lika stor som count.
*/

extern float calc_resistance(int count, char conn, float *array);

#endif /*LIBRESISTANCE_H*/
