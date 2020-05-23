#ifdef _KONFIGURACJA
	/******************* SZABLON **************************/

	// KONFIGURACJA	WYSWIETLANIA

	oknoFullScreen = false;

	// KONFIGURACJA	KAMERY

	ustalObszar (500);						// promien obszaru (kola), po jakim kamera moze sie poruszac

 // wymiary terenu: (-200,-200) - (200,200)

	// Funkcja rejestrujaca przeszkody - kolejne parametry to X1, Z1, X2, Z2 prostokata, ktory jest dodatkowo zabroniony dla kamery
	
	// blokady terenu (sciany)
	rejestrujPrzeszkode(-200,-200,-200,200);	// lewy brzeg
	rejestrujPrzeszkode(200,-200,200,200);		// prawy  brzeg
	rejestrujPrzeszkode(-200,-200,200,-200);	// przedni brzeg
	rejestrujPrzeszkode(-200,200,200,200);		// tylny brzeg
	
	//rejestrujPrzeszkode(-101,-90,-26,200);		// lewa wyspa
	//rejestrujPrzeszkode(13,-200,90,132);		// prawa wyspa



	/******************************************************/


#undef _KONFIGURACJA
#endif
