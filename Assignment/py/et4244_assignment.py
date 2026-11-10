#  =====================================================================
#   ET4244 Assignment: Displaying BME280 sensor data and performing CSV recordings
#   Display: SSD1306 OLED
#  ---------------------------------------------------------------------
#   Group Number: 8
#   Group Members
#       - Ivan Lodovica: 24409782
#       - Warda Abbasi:
#  =====================================================================

import time
import serial
com_port= 'COM7'
def main():
    ser = serial.Serial(com_port, timeout=5)
    ser.baudrate= 9600
    ser.flush()
    time.sleep(5)
    print(ser.name)
    while True:
        user_input = input("Enter command: ")
        if user_input == "exit":
            break
        command = (user_input + '\n').encode('utf-8')
        print(user_input)
        ser.write(command)



if __name__ == '__main__':
    main()