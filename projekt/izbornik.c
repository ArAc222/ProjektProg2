#include "izbornik.h"

#define _CRT_SECURE_NO_WARNINGS
#define LINIJA "====================\n"

#include <stdio.h>
#include <stdlib.h>

void prikaziIzbornik() {
	printf(LINIJA);
	printf("Odaberite jednu od ponudenih opcija:\n");
	printf(LINIJA);
	printf("\n");

	printf("(1): Dodavanje puske\n"); // gotovo
	printf("(2): Ispis svih pusaka\n"); // gotovo
	printf("(3): Pretraga pusaka\n"); // gotovo
	printf("(4): Uzimanje puske\n"); 
	printf("(5): Izlaz iz programa\n"); // gotovo
	printf("(6): Zapisi puske u datoteku\n"); // teoretski gotovo
}

int procitajOdabir() {
	int odabir = 0;

	printf("\nVas odabir: ");
	scanf("%d", &odabir);
	printf("\n\n");

	return odabir;
}

void zatraziPonovniUnos()
{
	printf("Pogresan unos. Molim Vas ponovite!\n\n");
}
