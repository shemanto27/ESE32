void setup() {
  // initialize the serial communication:
  Serial.begin(115200);
  pinMode(41, INPUT); // Setup for leads off detection LO +
  pinMode(40, INPUT); // Setup for leads off detection LO -
 
}
 
void loop() {
  
  if((digitalRead(2) == 1)||(digitalRead(4) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
      Serial.println(analogRead(A0));
  }
  //Wait for a bit to keep serial data from saturating
  delay(1);
}
