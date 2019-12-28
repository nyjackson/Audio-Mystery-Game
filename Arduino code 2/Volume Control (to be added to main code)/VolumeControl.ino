/*
 Volume Control - adapted from Analog Input Example

 The circuit:
 * Potentiometer attached to analog input 0 (or any free analog pin)
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 
 Originally created by David Cuartielles, modified 30 Aug 2011 By Tom Igoe
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  
}

void loop() {
  //read sensor value
  sensorValue = analogRead(sensorPin);
  // create key_command existing variable that can be both word and double byte of left and right.
  union twobyte mp3_vol;
  // returns a double uint8_t of Left and Right packed into int16_t
  mp3_vol.word = MP3player.getVolume();
  // map slide pot value (0-1023) to volume value (2-254)
  newVolume = map(sensorValue, 0, 1023, 2, 254)
  // set volume value as new volume value
  mp3_vol.byte[1] = newVolume
  // commit new volume
  MP3player.setVolume(mp3_vol.byte[1], mp3_vol.byte[1]);
  // print volume value
  Serial.print(F("Volume changed to -"));
  Serial.print(mp3_vol.byte[1]>>1, 1);
  Serial.println(F("[dB]"));
}
