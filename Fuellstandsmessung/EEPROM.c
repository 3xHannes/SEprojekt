/*
 * EEPROM.c
 *
 * Created: 23.02.2015 21:17:02
 *  Author: Tobias Rösch
 */ 


#include "EEPROM.h"


void EEPROM_write (uint16_t address, uint8_t data) 
{
	while (EECR & (1<<EEWE));											//Warten bis EEWE bit auf 0 ist um schreibvorgang zu starten
	EEAR = address;														//Übergebene Adresse in EEPROM-Adressregister kopieren
	EEDR = data;														//Übergebenes Datenbyte in EEPROM-Datenregister kopieren
	
	cli();																//Global Interrupts deaktivieren
	//Assembler Code Aufgrund Zeitkritischer Anforderung:
	//EEWE bit muss max. 4 Taktzyklen nach EEMWE gesetzt werden.
	asm volatile ("sbi 0x1C,2");	// entspricht: EECR |= (1<<EEMWE)	//EEMWE bit setzen (Schreibzugriff wird freigeschalten)								
	asm volatile ("sbi 0x1C,1");	// entspricht: EECR |= (1<<EEWE)	//EEWE bit setzen (Schreibvorgang wird gestartet)
	sei();																//Global Interrupts aktivieren
}



uint8_t EEPROM_read (uint16_t address) 
{
	while(EECR & (1<<EEWE));											//Warten bis EEWE bit auf 0 ist um lesevorgang zu starten
	EEAR = address;														//Übergebene Adresse in EEPROM-Adressregister kopieren
	EECR |= (1<<EERE);													//EERE bit setzen (Lesevorgang wird gestartet)
																		//Angeforderte Daten stehen 1 Takt später im EEDR Register zur Verfügung
	return EEDR;														//Rückgabe der Daten an den Aufrufer der Funktion
}



void EEPROM_write_16 (uint16_t adress, uint16_t data)
{
	uint8_t buff;
	buff=data>>8;														//Oberes Daten-Byte in 8-bit Variable kopieren
	EEPROM_write(adress,buff);											//Variable in EEPROM schreiben
	adress++;															//Adresse um ein Byte erhöhen
	buff=data;															//Unteres Daten-Byte in 8-bit Variable kopieren
	EEPROM_write(adress,buff);											//Variable in EEPROM schreiben
}


uint16_t EEPROM_read_16 (uint16_t adress)
{
	uint16_t buff;														//Buffer Variable für gelesenen Wert
	buff=EEPROM_read(adress)<<8;										//Erstes Byte lesen und in oberes Byte der 16 bit Variable schreiben
	adress++;															//Adresse um ein Byte erhöhen
	buff|=EEPROM_read(adress);											//Zweites Byte lesen und in unteres Byte der 16 bit Variable schreiben
	return buff;														//Variable zurückgeben
}