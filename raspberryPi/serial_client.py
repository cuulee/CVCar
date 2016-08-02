"""
serial_client.py

Copyright (C) 2016 Lachlan Bell
Serial Client for CVCar Project

Function: for use when Arduino is on car, controlling the motors via an L293D H-Bridge. The script recieves TCP commands and relays them to
          a connected Arduino UNO via serial.
"""

# import libraries
from socket import *
import time
import serial

# intialise/set variables
buffer = 20 # TCP buffer
ri = "" # Received instruction
pd = "" # Previous sent data

# intialise TCP connection, connect to sever on Mac.
cs = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
cs.connect(('192.168.1.100', 8003))
cs.listen(0)

# intialise serial connection to Arduino
ser = serial.Serial('/dev/ttyACM0', 115200)

con , addr = cs.accept()
print("Connection address:", addr)
while 1:
  ri = con.recv(buffer)
  if ri != pd:
            ser.write(ri)
            pd = ri
