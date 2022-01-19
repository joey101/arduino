#--------------------Project RFID Time-Attendance Scanner-----------------------
#   sudo raspi-config (To configure pins to read data from scanner).
#   sudo pip3 install spidev (To communicate with the scanner).
#   sudo pip3 install mfrc522 (This is for the scanner).
#   mkdir ~/pi-rfid 
#   python3 ~/pi-rfid/RFID_scanner.py (Run the Script after saving)
#
#   SDA connects to GPIO8 (Physical Pin 24)  
#   SCK connects to GPIO11 (Physical Pin 23)
#   MOSI connects to GPIO10 (Physical Pin 19)
#   MISO connects to GPIO9 (Physical Pin 21)
#   GND connects to Breadboard Ground Rail.
#   RST connects to GPIO25 (Physical Pin 22)
#   3.3v connects to 3v3 (Physical Pin 1)
#

#!/usr/bin/env python
#********************************Libraries*************************************#

import requests                                  # API Library
from datetime import datetime
import RPi.GPIO as GPIO                          # All the functions needed to interact with GPIO Pins  (pip install RPi.GPIO)
from mfrc522 import SimpleMFRC522                # this is what we will use actually to talk with the RFID RC522 (https://github.com/pimylifeup/MFRC522-python)                                 
import Adafruit_CharLCD as LCD                   # An LCD to show they have been scanned (git clone https://github.com/pimylifeup/Adafruit_Python_CharLCD.git)
import os as os                                  # For File removal
import json as json                              # To store in JSon format.  

#******************************************************************************#
#*******************************API Connection*********************************#

url = "https://test.com/post"
timeout = 5
connection = requests.post("https://test.com/post", timeout=timeout)

#******************************************************************************#

reader = SimpleMFRC522()                        # Creates an object to store all our variables.
lcd = LCD.Adafruit_CharLCD(4, 24, 23, 17, 18, 22, 16, 2, 4);
# Raspberry Pi pin configuration:
#lcd_rs        = 4
#lcd_en        = 24
#lcd_d4        = 23
#lcd_d5        = 17
#lcd_d6        = 18
#lcd_d7        = 22

#*****************************Main Body Code***********************************#
try:
    while True:
        # This block of code is if we want to read data to the LCD.
        LCD.clear()                                 # Clears LCD.
        LCD.message('Place Card to\nregister')      # Prints message on LCD.
        id, text = reader.read()                    # Scans for Card.
        print(id)                                   # Prints ID scanned to terminal.
        LCD.clear()                                 # Clears LCD.                             
        LCD.message("User Scanned: " + id)          # Prints ID on LCD.
        
        if connection:                              # Checks if can connect with API
            
            if os.path.exists("card_data.json"):    # Check if file exists
                with open('card_data.json') as f:
                    data = json.load(f)
                    for person in data:             # Loop through each card data and send to API
                        response = requests.post(url, json=person)
                        response.json()

                os.remove("card_data.json")         # Removes any local files of card once sent.

            # Gets Current Date and Time
            now = datetime.now()                    
            dt_string = now.strftime("%d/%m/%Y - %H:%M:%S")

            # Sends data to API after checking files for card data
            todo = {"card_id": id, "date_t": dt_string}
            response = requests.post(url, json=todo)
            response.json()
    
        else:   # Stores card data on file if no connection with API.    
#********************Stores each card scan in the json file*********************                                            
            # THIS PREPARES THE DATA FOR STORING

            # Gets Current Date and Time
            now = datetime.now()                   
            # Changes Format of time.
            dt_string = now.strftime("%d/%m/%Y - %H:%M:%S")
            # Stores data in this JSON format
            data = [{
                'card_uid': id,
                'date_t': dt_string,
            }] 

            # THIS IF STATEMENT IS WHAT WRITES TO THE JSON FILE.

            # Check if file exists to append to the existing data in JSON format
            if os.path.exists("card_data.json"):            
                with open('card_data.json') as outfile:
                    array = json.load(outfile)

                array.append(data)
    
                with open("card_data.json", "w") as f:
                    json.dump(array, f, indent=4)

            # If first time storing data, it will create the file.
            else:                                           
                json_object = json.dumps(data, indent = 2)
                with open("card_data.json", "w") as f:
                    f.write(json_object)              
            
finally:
    GPIO.cleanup()                                          # Cleans up