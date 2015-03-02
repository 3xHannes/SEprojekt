/*
 * Speicher.h
 *
 * Created: 01.03.2015 20:32:09
 *  Author: Tobias R�sch
 */ 


#ifndef SPEICHER_H_
#define SPEICHER_H_

#include <avr/io.h>
#include "EEPROM.h"


/*================================================================
== Definitionen der Werte zum Speichern der Lage				==
== Stehender / Liegender Zylinder								==
================================================================*/

#define Stehend 0x11
#define Liegend 0x22


//==========	Funktionen:		==================================


/*================================================================
== writeRadius/readRadius										==
== schreibt/lie�t den Radius in den/aus dem EEPROM				==
================================================================*/
void writeRadius(uint16_t Radius);
uint16_t readRadius(void);


/*================================================================
== writeLaenge/readLaenge										==
== schreibt/lie�t die L�nge in den/aus dem EEPROM				==
================================================================*/
void writeLaenge(uint16_t Laenge);
uint16_t readLaenge(void);


/*================================================================
== writeHoehe/readHoehe											==
== schreibt/lie�t die H�he in den/aus dem EEPROM				==
================================================================*/
void writeHoehe(uint16_t Hoehe);
uint16_t readHoehe(void);


/*====================================================================
== writeLage/readLage												==
== schreibt/lie�t die Lage in den/aus dem EEPROM					==
== Dazu die Vordefinierten Makros "Stehend" und "Liegend" verwenden	==
====================================================================*/
void writeLage(uint8_t Lage);
uint8_t readLage(void);


#endif /* SPEICHER_H_ */