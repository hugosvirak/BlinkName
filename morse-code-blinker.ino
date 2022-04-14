// This isn't always required, but it's a good habit to get into 
// and it never hurts.
#include "Particle.h"
#include <string>

// Using blue D7 LED (next to D7 on the Photon 
// and Electron, and next to the USB connector on the Argon and Boron).
const pin_t MY_LED = D7;

const auto TIME_UNIT = 100ms;

// Allows code to run before the cloud is connected.
SYSTEM_THREAD(ENABLED);

// Turn MY_LED on for `duration` ms before turning off
void ledOn(std::chrono::milliseconds duration) {
    digitalWrite(MY_LED, HIGH);
    delay(duration);
    digitalWrite(MY_LED, LOW);
}

// Converts a morse string (e.g. ".-" for the letter a) into the LedOutput
void morseStringToLedOutput (std::string inString) {
    for (const char& c : inString) {
        switch (c) {
            case '.':
                ledOn(TIME_UNIT);
                break;
            case '-':
                ledOn(TIME_UNIT * 3);
                break;
        }
        delay(TIME_UNIT);
    }
}

// Converts a alphanumeric string into a morse LedOutput 
void stringToLedOutput (std::string inString) {
    for (const char& c : inString) {
        switch (c) {
            case 'a': 
                morseStringToLedOutput(".-");
                break;
            case 'b':
                morseStringToLedOutput("-...");
                break;
            case 'c':
                morseStringToLedOutput("-.-.");
                break;
            case 'd':
                morseStringToLedOutput("-..");
                break;
            case 'e':
                morseStringToLedOutput(".");
                break;
            case 'f':
                morseStringToLedOutput("..-.");
                break;
            case 'g':
                morseStringToLedOutput("--.");
                break;
            case 'h':
                morseStringToLedOutput("....");
                break;
            case 'i':
                morseStringToLedOutput("..");
                break;
            case 'j':
                morseStringToLedOutput(".---");
                break;
            case 'k':
                morseStringToLedOutput("-.-");
                break;
            case 'l':
                morseStringToLedOutput(".-..");
                break;
            case 'm':
                morseStringToLedOutput("--");
                break;
            case 'n':
                morseStringToLedOutput("-.");
                break;
            case 'o':
                morseStringToLedOutput("---");
                break;
            case 'p':
                morseStringToLedOutput(".--.");
                break;
            case 'q':
                morseStringToLedOutput("--.-");
                break;
            case 'r':
                morseStringToLedOutput(".-.");
                break;
            case 's':
                morseStringToLedOutput("...");
                break;
            case 't':
                morseStringToLedOutput("-");
                break;
            case 'u':
                morseStringToLedOutput("..-");
                break;
            case 'v':
                morseStringToLedOutput("...-");
                break;
            case 'w':
                morseStringToLedOutput(".--");
                break;
            case 'x':
                morseStringToLedOutput("-..-");
                break;
            case 'y':
                morseStringToLedOutput("-.--");
                break;
            case 'z':
                morseStringToLedOutput("--..");
                break;
            case '0':
                morseStringToLedOutput("-----");
                break;
            case '1':
                morseStringToLedOutput(".----");
                break;
            case '2':
                morseStringToLedOutput("..---");
                break;
            case '3':
                morseStringToLedOutput("...--");
                break;
            case '4':
                morseStringToLedOutput("....-");
                break;
            case '5':
                morseStringToLedOutput(".....");
                break;
            case '6':
                morseStringToLedOutput("-....");
                break;
            case '7':
                morseStringToLedOutput("--...");
                break;
            case '8':
                morseStringToLedOutput("---..");
                break;
            case '9':
                morseStringToLedOutput("----.");
                break;

        }
        delay(TIME_UNIT * 3);
    }
}

// Setup called once
void setup() {
	pinMode(MY_LED, OUTPUT);
}

// Loop called on loop
void loop() {
    stringToLedOutput("hugo"); // output first name
    delay(TIME_UNIT * 7);
}

