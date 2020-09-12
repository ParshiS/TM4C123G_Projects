// GPIO Macros for LED control.
// Author: Srinidhi Parshi

#ifndef LED_GPIO_H_
#define LED_GPIO_H_

// Define Port Address

#define PortF_Addr	0x40025000

// Define Pins Pin 0 and 4 are for switches. Pin 1-3 are the RGB LEDs

#define Pin1R	0x00000002
#define Pin2B	0x00000004
#define Pin3G	0x00000008

// Define register offsets
#define DataReg	0x00000000 // Data Register Register Offset. Note: bits 9:2 to be set when giving outputs
#define Direction	0x00000400 // Direction Register Offset
#define DigEn	0x0000051C // Digital Enable Register Offset
#define PullUpReg	0x00000510 // Pull Up Register Offset
#define AFSEL	0x00000420 // Alternate Function Select Register Offset
#define AFSEL	0x00000528 // Analog Mode Select
#define LockReg	0x00000520 // Lock, Unlock Register Offset
#define Drive2mA	0x00000500 // Drive 2mA to LED Register Offset
#define Drive4mA	0x00000504 // Drive 4mA to LED Register Offset
#define Drive8mA	0x00000508 // Drive 8mA to LED Register Offset

// Function Signatures

void PinConfig( unsigned long PortAddr, unsigned long PinAddr, int ConfigAsIO);	
void PinWrite( unsigned long PortAddr, unsigned long PinAddr, unsigned int Out);
void PinToggle( unsigned long PortAddr, unsigned long PinAddr);
void PinClear( unsigned long PortAddr, unsigned long PinAddr);

#endif