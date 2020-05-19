/*
  pins_arduino.c - pin definitions for the Arduino board
  Part of Arduino / Wiring Lite

  Copyright (c) 2005 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: pins_arduino.c 565 2009-03-25 10:50:00Z dmellis $

  Modified 28-08-2009 for attiny84 R.Wiersma
  Modified 09-10-2009 for attiny45 A.Saporetti
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

// ATMEL ATTINY84 / ARDUINO
//
//                           +-\/-+
//      ~RESET (D 17)  PA2  1|    |20  GND
//         RXD (D  0)  PD0  2|    |19  PB8  (D 16)
//         TXD (D  1)  PD1  3|    |18  PB6  (D 15) 
//       XTAL2 (D  2)  PA1  4|    |17  PB5  (D 14) 
//       XTAL1 (D  3)  PA0  5|    |16  PB4  (D 13) 
//        INT0 (D  4)  PD2  6|    |15  PB3  (D 12)
//        INT1 (D  5)  PD3  7|    |14  PB2  (D 11) 
//             (D  6)  PD4  8|    |13  PB1  (D 10)
//             (D  7)  PD5  9|    |12  PB0  (D  9) 
//                     GND 10|    |11  PD6  (D  8) 
//                           +----+

/*
// TODO: REWRITE THIS:
#define digitalPinToPCICR(p)    ( ((p) >= 0 && (p) <= 10) ? (&GIMSK) : ((uint8_t *)0) )
#define digitalPinToPCICRbit(p) ( ((p) <= 7) ? PCIE0 : PCIE1 )
#define digitalPinToPCMSK(p)    ( ((p) <= 7) ? (&PCMSK0) : (((p) <= 10) ? (&PCMSK1) : ((uint8_t *)0)) )
#define digitalPinToPCMSKbit(p) ( ((p) <= 7) ? (p) : (10 - (p)) )
*/

#ifdef ARDUINO_MAIN

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&DDRA,
  (uint16_t)&DDRB,
  (uint16_t)&DDRD, //TODO: Check if this is true.
};

const uint16_t PROGMEM port_to_output_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&PORTA,
  (uint16_t)&PORTB,
  (uint16_t)&PORTD, //TODO: Check if this is true.
};

const uint16_t PROGMEM port_to_input_PGM[] = 
{
  NOT_A_PORT,
  (uint16_t)&PINA,
  (uint16_t)&PINB,
  (uint16_t)&PIND, //TODO: Check if this is true.
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = 
{
  PD, /* 0 */
  PD,
  PA,
  PA,
  PD,
  PD,
  PD,
  PD,
  PD, /* 8 */
  PB,
  PB,
  PB,
  PB,
  PB,
  PB,
  PB,
  PB, /* 16 */
  PA,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = 
{
  _BV(0), /* port D */
  _BV(1),
  _BV(1), /* port A */
  _BV(0),
  _BV(2), /* port D */
  _BV(3), 
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(0), /* port B */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
  _BV(2), /* port A */
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = 
{
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER, 
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  TIMER0B, /* OC0B */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  TIMER0A, /* OC0A */
  TIMER1A, /* OC1A */
  TIMER1B, /* OC1B */
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
  NOT_ON_TIMER,
};

#endif

#endif
