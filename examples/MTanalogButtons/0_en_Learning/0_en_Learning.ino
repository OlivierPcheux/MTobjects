// Version V1.1.1

//###########################################################################
//###########################################################################
//####                                                                   ####
//####                          Olivier Pécheux                          ####
//####                        Olivier@Dansetrad.fr                       ####
//####                        (33) +6 69 77 82 58                        ####
//####              http://arduino.dansetrad.fr/en/MTobjects             ####
//####                                                                   ####
//###########################################################################
//###########################################################################

// This program uses learning to generate a demo program from MTanalogButtons
//
// You need to change a few constants to configure it.
//
// You must give the pin for analog reading
const uint8_t PIN = A5; // Change A5 to A0..A7 depending on the case
//
// You must choose the voltage reference to use for the conversion
// DEFAULT: for Vcc
// INTERNAL: 1.1V for Nano/Uno
// INTERNAL1V1: 1.1V for Mega
// INTERNAL2V56: 2.56V for Mega
// EXTERNAL: to use AREF
#define REFERENCE INTERNAL
//
// You must give the console transfer rate
#define BAUDS 115200 // 115200 recommended, but you can put 9600
// Don't forget to set the console to 115200 bauds



// *************************** Memorization of ADC values for all buttons
byte seen[128]; // Will contain the possible ADC values for all buttons

inline void write(word value) // Records that we have seen the value passed as an argument (0 to 1023)
{ 
  seen[value/8] = bitSet(seen[value/8], value%8);
}

byte read(word value) // true if the ADC had this value
{ 
  return bitRead(seen[value/8], value%8);
}

// *************************** Variables globales
boolean rest; // true for 1023, false for 0 when no button is pressed
word valueRead, // Conversion result then key number 
     oldValueRead, oldOldValueRead, // Memorization to allow three consecutive identical readings 
     startTime; // To wait while a key is pressed; word is enough because we will never exceed 3000
int startIndex = 0, endIndex = 0; // To explore the table and read the limit values
byte nbButtons = 0;
boolean notFirstComma = false;


void setup()
{

  // ***************************** Initializations 
  Serial.begin(BAUDS); // Also set the console to BAUDS bauds! 
  analogReference(REFERENCE); // Allows you to choose the voltage reference 
  Serial.println(F("/*\nPress all keys, one by one\n")); 
  rest = (analogRead(PIN) > 512); // At rest we have 0 or 1023

  // *************************** We wait for a key to be pressed 
  do 
  { 
    oldValueRead = valueRead; // Saving the previous ADC measurement 
    valueRead = analogRead(PIN); // New reading 
  } while ((valueRead!=oldValueRead) || // Two identical values must be read (double reading for safety) 
      (rest && (valueRead > 1020)) || (!rest && (valueRead < 3))); // And we move away from rest
  
  // *************************** Search for possible ADC values 
  do // As long as keys are pressed 
  { 
    do // As long as we do not read a good ADC value 
    { 
      oldOldValueRead = oldValueRead; // Saving the previous ADC measurement
      oldValueRead = valueRead;
      valueRead = analogRead(PIN); // New reading 
    } while ((valueRead!=oldValueRead) || (valueRead!=oldOldValueRead)); // We start again until we have three identical readings 
    write(valueRead); // We find a value, we save it 

    // Timer management, we exit the loop if we no longer press a key for 3s 
    if (rest) // Depending on whether we have 0 or 1023 without press a key 
    { 
      if (analogRead(PIN) < 1020) startTime = millis(); // Reset the timer as long as you press 
    } 
    else if (analogRead(PIN) > 5) startTime = millis(); 
  } while ((word)millis() - startTime < 3000);
  
  // *************************** Display of the values read for control 
  // 1 indicates a value seen, 0 a value that the ADC does not give 
  for (word line=0; line<16; line++) // 1023 possible values displayed with 16 lines of 64 values 
  { 
    if (line == 0) Serial.print("  0"); // Number of the line displayed on the left 
    else if (line == 1) Serial.print(" 64"); 
    else Serial.print(line*64); 
    Serial.print(" "); // To align the table 
    for (word column=0; column<64; column++) Serial.print(read(line*64+column)); // The values 
    Serial.println(); // End of line 
  } 
  Serial.println();

  // *************************** We count the number of buttons. 
  // This is the number of intervals in the table that contain 0s. 1s indicate a button 
  while (startIndex < 1024) 
  { 
    while (!read(startIndex)) startIndex++; // We go on the first value 1 
    while (read(startIndex) && (startIndex < 1024)) startIndex++; // We go on the first 0 following 
    nbButtons++; 
  }

  // *************************** Displays a number of buttons on the console 
  Serial.print(F("\nI saw ")); 
  Serial.print(--nbButtons); 
  Serial.print(F(" buttons\n*/\n\n"));

  // *************************** We now display the test program 
  // Departure comments, common beginning 
  Serial.print(F("// This program tests the reading of the set of buttons with MTanalogButtons\n\n" 
  "#include <MTobjects.h> // V1.1.1 See http://arduino.dansetrad.fr/en/MTobjects\n\n" 
  "const byte PIN = ")); 
  Serial.print(PIN); 
  Serial.print(F(";\nconst word THRESHOLDS_TABLE[] = {"));

  // You must give the table of values 
  if (rest) // The values are in descending order if at rest we have ADC=1023 
  { 
    startIndex = 1023; 
    while (!read(startIndex)) startIndex--; // We go on the last value 
    while (read(startIndex) && (startIndex >= 0)) startIndex--; // We go before the last value 
    while ((startIndex >= 0) && (endIndex >= 0)) 
    { 
      endIndex = startIndex; // We are looking for an interval without a button. It ends at startIndex 
      while (!read(endIndex) && (endIndex >= 0)) endIndex--; // The area starts at endIndex + 1 
      if (endIndex >= 0) // This is an interval without buttons 
      { 
        if (notFirstComma) Serial.print(F(", ")); // The first time we don't put commas 
        notFirstComma = true; // The other times we will put it 
        Serial.print((startIndex + endIndex + 1)/2); // And we put the middle of the interval 
      } 
      startIndex = endIndex; 
      while (read(startIndex) && (startIndex >= 0)) startIndex--; // We go before the button 
    } 
    Serial.print(F(", 0")); 
  }
  else // The values are in ascending order if at rest we have ADC=0
  { 
    startIndex = 0; 
    while (!read(startIndex)) startIndex++; // We go on the first value 
    while (read(startIndex) && (startIndex >= 1024)) startIndex--; // We go before the first value 
    while ((startIndex < 1024) && (endIndex < 1024)) 
    { 
      endIndex = startIndex; // We are looking for an interval without a button. It starts at startIndex 
      while (!read(endIndex) && (endIndex < 1024)) endIndex++; // The area starts at endIndex + 1 
      if (endIndex < 1024) // This is an interval without buttons 
      { 
        if (notFirstComma) Serial.print(F(", ")); // The first time we don't put commas 
        notFirstComma = true; // The other times we will put it 
        Serial.print((startIndex + endIndex + 1)/2); // And we put the middle of the interval 
      } 
      startIndex = endIndex; 
      while (read(startIndex) && (startIndex < 1024)) startIndex++; // We go before the button 
    } 
    Serial.print(F(", 0")); 
  }

  // Continuation of the program 
  Serial.print(F("}; // Comparison threshold values\n\n" 

    "void press(byte key)\n" 
    "{\n" 
    "  Serial.print(\"Key number \");\n" 
    "  Serial.print(key);\n" 
    "  Serial.print(\" just pressed \");\n" 
   "}\n" 

    "void release(void)\n" 
    "{\n" 
    "  Serial.println(\"and released\");\n" 
    "}\n" 

    "MTanalogButtons Keypad(PIN, THRESHOLDS_TABLE, press, release);\n\n" 


    "void setup()\n" 
    "{\n" 
    "  Serial.begin(")); 
  Serial.print(BAUDS); 
  Serial.print(F("); // Also set the console to ")); 
  Serial.print(BAUDS); 
  Serial.print(F(" baud!\n")); 
  if (REFERENCE != DEFAULT) 
  { 
    Serial.print(F("  analogReference(")); 
    Serial.print(REFERENCE); 
    Serial.print(F(");\n")); 
  } 
  Serial.print(F("  Serial.println(\"Press keys\");\n" 
    "}\n\n" 

    "void loop(){}"));
}

void loop()
{
}