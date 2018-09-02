import serial
import time

import requests

base_url = "http://srmvdpauditorium.in/aaa/arduino/"

while 1:
    try:
        ser = serial.Serial('COM3', 115200)
        break
    except:
        print("Arduino Not Found")
        time.sleep(5)
 
while 1:
 try:
     line = str(ser.readline(), "utf-8")
     print(line, end="")
     
     url = base_url + "upload.php?ppm=" + line
     r = requests.get(url)
     response = str(r.content, "utf-8")
     print(response)

     line = ""
     time.sleep(5)
     
 except ser.SerialTimeoutException:
     print('Data could not be read')
     time.sleep(5)
