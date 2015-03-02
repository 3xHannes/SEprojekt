/*
 * EEPROM.h
 *
 * Created: 23.02.2015 21:17:39
 *  Author: Tobias Rösch
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include <avr/io.h>
#include <avr/interrupt.h>


/*================================================================
== Definitionen der Adressen									==
== Wichtig bei 16-Bit Werten:									==
== Bei Adressvergabe 2 Byte zu nächter Adresse freilassen		==
================================================================*/

#define adr_Radius 0x0000
#define adr_Laenge 0x0002
#define adr_Hoehe 0x0004
#define adr_Lage 0x0006




//==========	Funktionen:		==================================


/*================================================================
== EEPROM_write:												==
== schreibt ein Byte Daten an die übergebene Adresse im EEPROM	==
================================================================*/
void EEPROM_write (uint16_t address, uint8_t data);
 

/*================================================================
== EEPROM_read:													==
== liest ein Byte Daten von der übergebenen Adresse im EEPROM	==
================================================================*/
uint8_t EEPROM_read (uint16_t address);


/*================================================================
== EEPROM_write_16:												==
== schreibt zwei Byte Daten an die übergebene Adresse im EEPROM	==
================================================================*/
void EEPROM_write_16 (uint16_t adress, uint16_t data);


/*================================================================
== EEPROM_read_16:												==
== liest zwei Byte Daten von der übergebenen Adresse im EEPROM	==
================================================================*/
uint16_t EEPROM_read_16 (uint16_t adress);



#endif /* EEPROM_H_ */