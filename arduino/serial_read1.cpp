#include <iostream>
#include<fstream>


//using namespace mn::CppLinuxSerial;

int main() {
	// Create serial port object and open serial port
	// SerialPort serialPort("/dev/ttyUSB0", BaudRate::B_9600);
	// // Use SerialPort serialPort("/dev/ttyACM0", 13000); instead if you want to provide a custom baud rate
	// serialPort.SetTimeout(-1); // Block when reading until any data is received
	// serialPort.Open();

	// // Write some ASCII datae
	// //serialPort.Write("Hello");

	// // Read some data back (will block until at least 1 byte is received due to the SetTimeout(-1) call above)
	// std::string readData;
	// serialPort.Read(readData);

    // std::cout<<readData<<"\n";

	// // Close the serial port
	// serialPort.Close();
	std::istream atmega328p;
	atmega328p.open("/dev/ttyUSB0");
    
	unsigned char data;
	while(atmega328p >> data)
	{
		if(data != 0)
		    std::cout<<data<<std::endl;
	}
}