import sys
import serial
from pathlib import Path

def sendreceive():
    global portName, baudRate, verify, fileName, size

    print('\a')
    print('port='+portName+' baudrate='+str(baudRate))

    ser=serial.Serial(portName, baudRate)
    if(ser.isOpen()):
        ser.close()
    ser.open()

    data = Path(fileName).read_bytes()
    print(type(data))
    #i = int.from_bytes(data[:4], byteorder='little', signed=False)
    print("Sending ..");
    ser.write(data);

    if(verify == 0):
        ser.close()
        return;

    print("Receiving ..")
    rawbyte = ser.read(size);
    Path('serialout.txt').write_bytes(rawbyte);

    ser.close()
    
    match=1
    j=0
    for i in range(size):
        if(rawbyte[i] != data[i]):
            j = j+1
            if(j<10):
                print("does not match i="+str(i)+" rawbyte[i]="+str(rawbyte[i])+" data[i]="+str(data[i]))
            match=0
    if(match == 1):
        print("match")
    print('\a')

# main
if(len(sys.argv) != 6) :
    print("Too few arguments: "+str(len(sys.argv)-1)+
        "\nSintax is:\n\tpython3 sendreceive.py <portName> <baudrate> <verify> <filename> <size>\n"+
        "Examples: \n\tpython3 sendreceive.py /dev/ttyUSB0 1000000 1 ../binary/initmem.bin 8388608\n"+
        " \tpython3 sendreceive.py /dev/ttyUSB1 1000000 0 file.txt 16\n")
    sys.exit()
    
portName = str(sys.argv[1])
baudRate = int(sys.argv[2])
verify = int(sys.argv[3])
fileName = str(sys.argv[4])
size = int(sys.argv[5])
sendreceive()
"""

    # create file
    f = open("test.txt", "wb")


    # Write the timescale directive.
    strLine = "`timescale " + str(timescaleUnit) + " / " + str(timescalePrecision) + "\n\n";
    f.write(strLine);
    f.close();
"""
