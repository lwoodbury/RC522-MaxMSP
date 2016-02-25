# RC522-MaxMSP
Use RC522 RFID reader to send tag IDs to Max MSP 

I came across this exceptionally cheap RFID reader/writer kit (http://www.bitsbox.co.uk/index.php?main_page=product_info&cPath=302_312&products_id=2844) which includes a card, a tag and two types of headers all for £3.49 and had to buy one! I have previously used the Innovations ID-12 and 20 which cost around £20 before you add the supporting circuitry or tags, so I wasn't expecting much. The RC522 is NFC working at high frequency (13.56MHz opposed to the ID-12s low frequency 125KHz), with a read range of 10cm (slightly less than ID-12), and the most basic tags costing around 70p (similar to LF tags). 

There is an existing Arduino library (https://github.com/miguelbalboa/rfid) for the reader which can be installed with the library manager (search for MFRC522) or manually (see the Arduino website for details on installing libraries). There are a load of great examples included for reading writing and controlling things from Arduino, but I simply wanted to get the RFID tag ID into Max MSP to use it to trigger stuff. I got together a sketch which just booted the ID out of serial which I could then read into Max. The Arduino sketch describes the circuit to use and the Max patch is heavily commented, both resources can be found here. 

Blog post about this topic here: http://www.dotlib.org/blog/2016/2/25/mf-rc522-rfid-reader
