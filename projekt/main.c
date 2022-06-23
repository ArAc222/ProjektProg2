﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "izbornik.h" 
#include "funkcije.h"
#include "podatci.h"

void ucitajDatoteku(const char* imeDatoteke, int* brojPusaka, Puska** poljePusaka);

void dodajPusku(Puska** poljePusaka, int* brojPusaka);
void ispisSvihPusaka(Puska* poljePusaka, int brojPusaka);
void uzmiPusku(Puska** poljePusaka, int* brojPusaka);
void pretraziPuske(Puska* poljePusaka, int brojPusaka);

void zapisiPuskeUDatoteku(Puska* poljePusaka, int brojPusaka);

int main(void) {
	int brojPusaka = 0;
	Puska* poljePusaka = NULL;

	ucitajDatoteku("puske.binary", &brojPusaka, &poljePusaka);

	while (1) {
		prikaziIzbornik();
		int odabir = procitajOdabir();

		switch (odabir) {
		case 1:
			dodajPusku(&poljePusaka, &brojPusaka);
			break;
		case 2:
			ispisSvihPusaka(poljePusaka, brojPusaka);
			break;
		case 3: 
			pretraziPuske(poljePusaka, brojPusaka);
			break;
		case 4:
			uzmiPusku(&poljePusaka, &brojPusaka);
			break;
		case 5:
			return 0;
			break;
		case 6:
			zapisiPuskeUDatoteku(poljePusaka, brojPusaka);
			break;
		default:
			zatraziPonovniUnos();
			break;
		}
	}

	free(poljePusaka);

	return 0;
}

void ucitajDatoteku(const char* imeDatoteke, int* brojPusaka, Puska** poljePusaka) {

	FILE* pDatoteka = fopen(imeDatoteke, "r+");

	if (pDatoteka == NULL) {
		printf("Ucitavanje pusaka neuspjesno.\n");
		return;
	}
	printf("Ucitane spremljene puske.\n");

	fread(brojPusaka, sizeof(int), 1, pDatoteka);

	*poljePusaka = (Puska*)malloc(*brojPusaka * sizeof(Puska));
	fread(*poljePusaka, sizeof(Puska), *brojPusaka, pDatoteka);

	fclose(pDatoteka);
}

void dodajPusku(Puska** poljePusaka, int* brojPusaka) {
	Puska puska = unesiPusku();

	*brojPusaka = *brojPusaka + 1;

	Puska* novoPolje = (Puska*)malloc(*brojPusaka * sizeof(Puska));
	if (novoPolje == NULL) {
		printf("Dodavanje puske neuspjesno. Kraj.\n");
		exit(-1);
	}

	memcpy(novoPolje, *poljePusaka, (*brojPusaka - 1) * sizeof(Puska));
	novoPolje[*brojPusaka - 1] = puska;
	
	free(*poljePusaka);
	*poljePusaka = novoPolje;

	zapisiPuskeUDatoteku(*poljePusaka, *brojPusaka);
}

void ispisSvihPusaka(Puska* poljePusaka, int brojPusaka) {
	for (int i = 0; i < brojPusaka; i++) {
		printf("Puska %d %s:\n", poljePusaka[i].id, poljePusaka[i].ime);
		printf("- brzinaMetka: %.2f km/h\n", poljePusaka[i].brzinaMetka);
		printf("- domet: %.2f m\n", poljePusaka[i].domet);
		printf("- oblik kalibra: %s\n", poljePusaka[i].oblikKalibra);
	}
}

void uzmiPusku(Puska** poljePusaka, int* brojPusaka)
{
	printf("Unesi ID puske koju zelis uzeti: %d, ", *brojPusaka);
	int idPuske;
	scanf("%d", &idPuske);

	Puska* novePuske = (Puska*)malloc((*brojPusaka - 1) * sizeof(Puska));
	if (novePuske == NULL) {
		printf("Zauzimanje novog polja pri uzimanju puske neuspješno. Kraj.\n");
		exit(-1);
	}

	int iNovaPuska = 0;
	for (int i = 0; i < *brojPusaka; i++)
	{
		if ((*poljePusaka)[i].id != idPuske)
		{
			novePuske[iNovaPuska] = (*poljePusaka)[i];
			iNovaPuska++;
		}
	}

	free(*poljePusaka);
	*poljePusaka = novePuske;
	*brojPusaka = *brojPusaka - 1;
}

void pretraziPuske(Puska* poljePusaka, int brojPusaka) {
	printf("Unesi ime puske za koju zelite provjeriti stanje: ");
	
	char imePuske[50];
	scanf("%s", imePuske);

	for (int i = 0; i < brojPusaka; i++) {
		if (strcmp(imePuske, poljePusaka[i].ime) == 0) {
			printf("Puska %s je dostupna.\n", imePuske);
			return;
		}
	}

	printf("Puska %s nije dostupna.\n", imePuske);
}

void zapisiPuskeUDatoteku(Puska* poljePusaka, int brojPusaka) {
	FILE* pDatoteka = fopen("puske.binary", "wb+");

	if (pDatoteka == NULL) {
		printf("Zapisivanje puski u datoteku neuspjesno. Kraj.\n");
		exit(-1);
	}

	int bp = brojPusaka;
	fwrite(&bp, sizeof(int), 1, pDatoteka);
	fwrite(poljePusaka, sizeof(Puska), brojPusaka, pDatoteka);

	fclose(pDatoteka);
}