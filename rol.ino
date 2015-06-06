/*--------------------------------------------------
// Rhythm of Love: Internet Connected Paper Weight
// Redesigned comunication for LDR couples
//--------------------------------------------------
*/

//Name of the pins controlling 3 colors on the LED
int red_led = D0;
int blue_led = D2;
int green_led = D4; 

void setup() {
    
    //Register the Spark function to control the LED
    Spark.function("rgb", rgbControl);
    
    //Initialize pins as outputs
    pinMode(red_led, OUTPUT);
    pinMode(blue_led, OUTPUT);
    pinMode(green_led, OUTPUT);
    
    /*
    Initialize LED to be off
    All three color diodes share an Anode connected to +3.3V;
    thus, each cathode is connected to the Spark pins,
    making the LED turn on when pin is LOW
    */
    digitalWrite(red_led, HIGH);
    digitalWrite(blue_led, HIGH);
    digitalWrite(green_led, HIGH);
}

void loop() {
    /*
    Code below used for debugging by
    emulating a post from the API
    */
    
    rgbControl("tay");
    rgbControl("ilu");
    rgbControl("shb,100");
}

int rgbControl(String command) {
    /*
    Command has three expected values: "tay", "ilu", and "shb"
    where shb also provides a comma-separated integer value in beats per minute
    */
    if (command.substring(0,3) != "tay" ||command.substring(0,3) != "ilu" || command.substring(0,3) != "shb") return -1;
    
    if (command.substring(0,3) == "tay") {
        /*
        tay = Thinking About You
        Blink Blue LED Three times
        */
        digitalWrite(blue_led, LOW);
        delay(1000);
        digitalWrite(blue_led, HIGH);
        delay(1000);
        digitalWrite(blue_led, LOW);
        delay(1000);
        digitalWrite(blue_led, HIGH);
        delay(1000);
        digitalWrite(blue_led, LOW);
        delay(1000);
        digitalWrite(blue_led, HIGH);
    }
    
    if (command.substring(0,3) == "ilu") {
        /*
        ilu = I Love You
        Blink Red LED three times
        */
        digitalWrite(red_led, LOW);
        delay(1000);
        digitalWrite(red_led, HIGH);
        delay(1000);
        digitalWrite(red_led, LOW);
        delay(1000);
        digitalWrite(red_led, HIGH);
        delay(1000);
        digitalWrite(red_led, LOW);
        delay(1000);
        digitalWrite(red_led, HIGH);
    }
    
    if (command.substring(0,3) == "shb") {
        /*
        shb = Share Heart Beat; bpm = beats per minute
        Function emulates a heart-beat with magenta color
        based on the bpm variable. 
        */
        int bpm = command.substring(4).toInt();
        bpm = 1000*(60/bpm); //Convert beats per minute to miliseconds per beat
        digitalWrite(red_led, LOW);
        digitalWrite(blue_led, LOW);
        delay(bpm/3);
        digitalWrite(red_led, HIGH);
        digitalWrite(blue_led, HIGH);
        delay(bpm);
        digitalWrite(red_led, LOW);
        digitalWrite(blue_led, LOW);
        delay(bpm/3);
        digitalWrite(red_led, HIGH);
        digitalWrite(blue_led, HIGH);
        delay(bpm);
        digitalWrite(red_led, LOW);
        digitalWrite(blue_led, LOW);
        delay(bpm/3);
        digitalWrite(red_led, HIGH);
        digitalWrite(blue_led, HIGH);
        delay(bpm);
        digitalWrite(red_led, LOW);
        digitalWrite(blue_led, LOW);
        delay(bpm/3);
        digitalWrite(red_led, HIGH);
        digitalWrite(blue_led, HIGH);
        delay(bpm);
        digitalWrite(red_led, LOW);
        digitalWrite(blue_led, LOW);
        delay(bpm/3);
        digitalWrite(red_led, HIGH);
        digitalWrite(blue_led, HIGH);
    }
}