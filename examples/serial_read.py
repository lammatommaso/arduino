import serial
ser = serial.Serial('/dev/ttyACM0')
ser.flushInput()

while True:
    try:
        ser_bytes = ser.readline()
        #decoded_bytes = str(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
        decoded_bytes = float(ser_bytes[0:len(ser_bytes)].decode("utf-8"))
        print(decoded_bytes)
    except:
        print("Keyboard Interrupt")
        break