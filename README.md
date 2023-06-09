# TOTP2GO
A Google Authenticator like TOTP generator that runs on M5StickC Plus (and potentially other ESP32 platforms)
![photo1](https://user-images.githubusercontent.com/1758212/235727026-7d5deed3-63ee-4ebb-945e-60a5c6f52713.jpg)

## Background
I am a daily Google Authenticator user. I know the benefit of adopting 2AF in the authentication process. The more the 2AF tokens are stored in the app, the more nervous I become. I can't stop thinking how much trouble I will have if I lose or damage my phone. 

Google recently added a cloud backup feature for the authenticator app, and I don't feel uncomfortable at all. If thing can be done offline, why do it online?

So I grabbed my M5Stick C Plus, opened Arduino editor, and started this project.

## Demo Video
[![Watch the video](https://user-images.githubusercontent.com/1758212/235731467-25f1f88e-d946-4f31-b195-46601c6befb3.png)](https://youtu.be/OL_iH70hY_o)


## Requirements
M5StickC Plus
Arduino Editor (I am using v2, but v1 will be fine too)
There are no hardware-depending features in this project. Although I used a lot of M5Stack libraries in this project(mainly in LED, RTC and power management), it is easy to backport them using a more general product-disassociated library. 

I choose M5StickC Plus as starting hardware. The reason for using a M5StickC Plus is that it has Wifi connectivity, RTC, LED, and a built-in Battery. It is small and relatively cheap as well. But as I said, you can always build your version.

| Part | Chipset |
|--|--|
|MCU|ESP32|
|RTC|BM8563|
|Power|AXP192|
|LCD|ST7789v2 (135x240)|

More details can be found on their official website: https://docs.m5stack.com/en/core/m5stickc_plus

## How to build
1. Prepare the Arduino IDE
2. Follow https://docs.m5stack.com/en/quick_start/m5stickc_plus/arduino to add the board-supporting manifest and install its libraries.
3. Clone this repo and copy all the folders in the "libraries" folder to your own Arduino libraries folder. 

    By default, the Arduino libraries can be found in your home folder. Ex: C:\Users\<YOUR USERNAME>\Documents\Arduino\libraries in Windows or /Users/<YOUR USERNAME>/Documents/Arduino/libraries in Mac/Linux.

4. Open TOTP2GO/TOTP2GO.ino with the IDE. 
5. Modify the program. See the above sections.
6. Connect your stick by USB cable, and compile and upload the program to your M5Stick.

## Parameters
Look for 
```code
////////// SECTION 1: SETTING BEGIN //////////
```
and 
```code
////////// SECTION 2: Add your other secret data - BEGIN //////////
```
in the code. They are the essential parts that need your attention.

### Section 1
TOTP generation depends on time, so we must ensure your stick has an accurate time. Input your Wifi connection details, and we can set the correct time from the NTP server for you.

![photo2](https://user-images.githubusercontent.com/1758212/235727146-12c29839-1996-47e0-a77d-1185772e5d6e.jpg)


Besides Wifi details, we need to know your timezone as well. Please access https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv and find the correct value that suits your need. For example, everyone lives in London should fill in "GMT0BST,M3.5.0/1,M10.5.0"

Finally, we need your Google Authenticator export data.
In your Google Authenticator, in the top right-hand corner, select "Transfer accounts" -> "Export accounts"-> Select all the accounts that you want to export -> "Next". A QR code containing all the data you want will be shown. Due to security reasons, you can't do a screen cap here. You can use a QR code reader in another phone(likely your old phone) to decode the data URL from that QR code.

The URL will look like this:
otpauth-migration://offline?data=ABCD%2B%2F%2F%2F%2F%2FwE%3D

We the data parameters, in other words, all characters behind "data=", that will be "ABCD%2B%2F%2F%2F%2F%2FwE%3D" in our example.

By combing all the above, your section 1 may look like this:
```code
////////// SECTION 1: SETTING BEGIN //////////
const char* ssid     = "Home WIFI";
const char* password = "Wifi Password";
const char* ntpServer = "pool.ntp.org"; // or other NTP server you did prefer
const char* timezone_str = "GMT0BST,M3.5.0/1,M10.5.0";  // Please refer to https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv . Find the appropriate value from the second column and use it to replace "HKT-8"

// Data parameter is obtained from the export URL which is generated by GOOGLE authenticator (In base64 encoded format), eg: otpauth-migration://offline?data=Ci4KFFNlY3JlN1AhQWluJGVjcmV0S2V5EhBQbGFpbiBTZWNyZXQgS2V5IAEoATACEAEYASAAKPXz5N0H
// Please replace Ci4KFFNlY3JlN1AhQWluJGVjcmV0S2V5EhBQbGFpbiBTZWNyZXQgS2V5IAEoATACEAEYASAAKPXz5N0H with your value.
char googleAuthData[] = "ABCD%2B%2F%2F%2F%2F%2FwE%3D"; 

////////// SETTING END //////////
```
### Section 2
Fill in Section 2 if you have more keys obtained from another place. The app support secret in BASE32(Most commonly found in URL starting with otpauth://) and in plain text(You really know what you are actually doing:))

For example, if I have this two OTP links(provided by firefox): 
```code
otpauth://totp/Firefox:user%40example.com?secret=KNSWG4TFG5ICCQLJNYSGKY3SMV2EWZLZ&issuer=Firefox
otpauth://totp/Firefox:user%40example.com?secret=AABBCCDDEE&issuer=Firefox
```

We need the "secret" parameter, which will be "KNSWG4TFG5ICCQLJNYSGKY3SMV2EWZLZ" and "AABBCCDDEE".

Then your section 2 may look like this:
```code
  ////////// SECTION 2: Add your other secret data - BEGIN //////////
  // add more entries if needed, we support secret in Base32-encoded string or plain text
  // 
  // Format: 
  // parseNameAndBase32Key("NAME", "SECRET IN BASE32"); // Secret in Base32-encoded string
  // parseNameAndPlainKey("NAME", SECRET IN PLAIN");  // Secret in plain text

parseNameAndBase32Key("Son FF", "KNSWG4TFG5ICCQLJNYSGKY3SMV2EWZLZ"); 
parseNameAndBase32Key("Wife FF", "AABBCCDDEE"); 

  ////////// Add your other secret data - END //////////
```
For plain text secret, instead of using parseNameAndBase32Key(), use parseNameAndPlainKey().

## Usage
* The left-hand side button is the ON/OFF button. Long press for 6 seconds to turn off the stick. Please turn it off when you are done with the authentication process.
* The Middle button is used to switch pages.
* The right-hand side button is the NTP Sync button. Long press for 1 second and release it. It will start the time sync process. Please make sure you have the wifi connection needed when starting the process.
* Time and TOTP will refresh every 1 second.



## Limitation
* Due to the screen size limit, names longer than 10 characters can only be displayed partially. 
* We store at most 30 entries.
* Only able to process short data parameters from Google Authenticator. (Max length 512 bytes), so if you have a long import string, you must do it twice by dividing them into smaller batches.

## Acknolodgement
* Base32 library is obtained at https://github.com/NetRat/Base32/ .
* NanoPB is obtained at https://github.com/nanopb/nanopb .
* SimpleHOTP is obtained at https://github.com/jlusPrivat/SimpleHOTP .

## TODO
* Disassociate the app from the M5Stack-specified library
* Auto turns off after some inactivity time to save some battery.

## License
MIT License

