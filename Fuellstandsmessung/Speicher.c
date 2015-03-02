/*
 * Speicher.c
 *
 * Created: 01.03.2015 20:31:59
 *  Author: Tobias Rösch
 */ 

#include "Speicher.h"


void writeRadius(uint16_t Radius)
{
	EEPROM_write_16(adr_Radius, Radius);
}


uint16_t readRadius(void)
{
	return EEPROM_read_16(adr_Radius);	
}


void writeLaenge(uint16_t Laenge)
{
	EEPROM_write_16(adr_Laenge, Laenge);
}


uint16_t readLaenge(void)
{
	return EEPROM_read_16(adr_Laenge);
}


void writeHoehe(uint16_t Hoehe)
{
	EEPROM_write_16(adr_Hoehe, Hoehe);
}


uint16_t readHoehe(void)
{
	return EEPROM_read_16(adr_Hoehe);
}


void writeLage(uint8_t Lage)
{
	EEPROM_write(adr_Lage, Lage);
}


uint8_t readLage(void)
{
	return EEPROM_read(adr_Lage);
}