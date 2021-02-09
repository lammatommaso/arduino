# compiler options
CC = avr-gcc #sets the compiler
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p
		 # optimizes for size since we don't have a big memory
			 # sets clock rate to 16MHz
								# chooses the microcontroller to compile for

# compiling
#all: blink.out

# detect what port the arduino is on
# like /dev/tty.usbmodem14401
# assuming there is only one attached, if more it returns the first one listed
USBPORT:=$(shell ls /dev/ttyACM*)

# compiling rules
%.out: %.c
	$(CC) $(CFLAGS) $< -o $@
%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@
	# extracts the .eeprom segment of the program into ihex format which is the one required

# upload to board
install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P $(USBPORT) -b 115200 -U flash:w:$<
				  # board specifics
										   # serial port
														 # communication speed
																	  # write to processor flash memory

clean:
	rm -f *.hex *.out




