/*

 C++ przez OpenGL - szablon do �wicze� laboratoryjnych
 (C) Micha� Turek.

*/

#ifdef _DEFINICJE
#include "Terrain.h"


Terrain *ter = new Terrain(8, 9, 2);

	/******************* SZABLON **************************/

	// DEFINICJE ZMIENNYCH	

	// w tablicy sa pozycje drzew i krzewow: {x,y,z,rotacjaY}
	float drzewa1 [12][4] = {{-110,-8,130,16},{-90,-8,145,96},{-150,-8,-60,158},{-140,-8,-90,138},{30,-6,-80,70},{-43,-16,-120,-70},{20,-8,80,180},{30,-8,30,80},{35,-8,160,50},{40,-8,130,0},{133,-8,29,210},{128,-16,-70,110}};
	float drzewa2 [12][4] = {{-120,-17,100,16},{-95,-8,70,76},{-135,-8,-10,158},{-148,-15,10,128},{-10,-10,-40,70},{-20,-8,40,20},{30,-8,130,80},{80,-8,160,180},{110,-8,140,0},{140,-8,150,100},{81,-8,-90,140},{119,-8,-140,210}};
	float drzewa3 [12][4] = {{-99,-8,110,16},{-151,-8,72,76},{-145,-8,-30,178},{-128,-8,40,128},{-140,1,-140,170},{-23,-8,75,20},{15,-8,120,80},{100,-8,138,180},{115,-8,120,0},{98,-8,50,100},{83,-8,-110,110},{111,-8,-134,210}};
	float krzaki  [12][4] = {{-181,43,-64,100},{-104,-6,40,90},{-138,-7,-60,40},{-113,-5,-70,76},{-8,-8,-80,320},{20,-5,53,170},{-39,11,-53,120},{30,-8,140,10},{80,7,100,40},{120,-8,45,206},{140,1,-23,6},{101,-8,110,146}};

	int animacjaLisci = 0;
	float posx= 0;
	float posy= 0;

	float mgla = 0;

	int zmienna = 0;


	float lawkaPozycja = 0;
	float lawkaPredkosc = 0;

		int iterator = 0;
	/******************************************************/
	bool rysujLawke = true;

#undef _DEFINICJE
#endif
