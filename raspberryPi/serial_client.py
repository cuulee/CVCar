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

# intialise TCP connection
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.connect(('192.168.1.100', 8003))
server_socket.listen(0)
buffer = 20

# intialise serial connection to Arduino
ser = serial.Serial('/dev/ttyACM0', 115200)

con , addr = s.accept()
print("Connection address:", addr)
while 1:
  data = con.recv(buffer)
