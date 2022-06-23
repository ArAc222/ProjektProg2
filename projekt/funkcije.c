#include "funkcije.h"

#define _CRT_SECURE_NO_WARNINGS
#define LINIJA "====================\n"

#include <stdio.h>
#include <stdlib.h>
#include "podatci.h"


Puska unesiPusku() {
	printf(LINIJA);
	printf("Dodavanje puske\n");
	printf(LINIJA);

	Puska puska;
	printf("Unesi id: ");
	scanf("%d", &(puska.id));
	
	printf("Unesi ime: ");
	scanf("%s", puska.ime);

	printf("Unesi brzinu metka: ");
	scanf("%f", &(puska.brzinaMetka));

	printf("Unesi domet: ");
	scanf("%f", &(puska.domet));

	printf("Unesi oblik kalibra: ");
	scanf("%s", puska.oblikKalibra);

	return puska;
}
