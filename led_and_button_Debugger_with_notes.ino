  // Demo for Grove - Starter V2.0
  // Author: Loovee  2013-3-10
  // Pulses the Grove - LED with a "breathing" effect.
  // Connect the Grove - LED to the socket marked D3
  
  // Defines the pin to which the LED is connected.
  // Any pin that supports PWM can also be used:
  // 3, 5, 6, 9, 10, 11
  const int pinLed    = 5;
  const int pinButton = 3;                        // pin of button define here
  
  
  // Define the delay for the "breathing" effect; change this
  // to a smaller value for a faster effect, larger for slower.
  //const int BREATH_DELAY = 5; // milliseconds
  
  void setup()
  {
      // Configure the LED's pin for output signals.
      pinMode(pinLed, OUTPUT);
      pinMode(pinButton, INPUT);                  // set button INPUT

      Serial.begin(9600); //serial begin is arduino to talk to the computer and have it send and recieve values
  }
  
  void loop()
  {
      //Serial.print("First line of loop:"); // this will show us what state of where the button begins
      //Serial.println(digitalRead(pinButton)); //this will print out what the button is doing 
      // this is a test to see if that things are beginning where they need to be, it eliminates a possibility of an error
      
      if(digitalRead(pinButton)) {    // when button is pressed
        Serial.println("Entered if statement!");
        
        for(int i=0; i<256; i++){
          Serial.print("Value of i for the first loop:");
          Serial.println(i);
            analogWrite(pinLed, i);
            delay(5); //shorter delay so it doesn't jam up the board
        }
        delay(100); // meaningful delay more noticeable 
        
        for(int i=254; i>=0; i--){
        
            analogWrite(pinLed, i); // check reference on arduino for the function
            delay(5);
        }
        delay(500);
  }
  }
  
