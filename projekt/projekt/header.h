#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "podatci.h"

int izbornik(const char* const);
void kreiranjeDatoteke(const char* const);
void dodajOruzje(const char* const);
void* ucitajKorisnike(const char* const);
void ispisiSveKorisnike(const CLAN* const);
void* pretraziClanove(CLAN* const);
int izlazIzPrograma(CLAN*);

#endif