#include <stdio.h>
#include <htc.h>

/* A simple demonstration of serial communications which
 * uses the bit-banging implementation of a serial communications.
 * Useful for PIC16Cxxx series of devices, or if USART is already
 * in use. */
void
main (void)
{
  unsigned char input = 'F';
  int i = 0;
  __PROG_CONFIG (1, OSC_INTIO2);
  __PROG_CONFIG (2, WDT_OFF);

  INTCON = 0;			// purpose of disabling the interrupts.
  TRISB = 0;
  TRISB3 = 0;
  TRISB2 = 1;
  TRISA = 0;
  TRISA2 = 0;
  TRISA3 = 0;
  RB0 = 1;
  PORTB = 0XFF;
  ADCON1 = 0xff;
  RB0 = 0;
  RB1 = 0;
  RB4 = 0;
  RB5 = 0;
  RB6 = 0;
  RB7 = 0;
  IRCF2 = 1;
  IRCF1 = 1;
  IRCF0 = 1;

  printf ("\rPress a key and I will echo it back:\n");
  while (1) {

    input = getch ();		// read a response from the user
    printf ("\rI detected [%c]", input);	// echo it back
    i++;
    //      for (int j = 0; j < 1000; j ++) {
    //      NOP();
    //      }
    RB0 = i & 1;
    RA2 = i & 1;
    RA3 = i & 1;
    RB1 = i & 1;
    RB4 = i & 1;
    RB5 = i & 1;
    RB6 = i & 1;
    RB7 = i & 1;
  }
}
