String inputString = "";
boolean stringComplete = false;

const int redPin = 3;
const int greenPin = 4;
const int bluePin = 5;



void setup() {
  Serial.begin(9600);
  Serial.flush();

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setColor(false, false, false);
}

void loop() {
  // put your main code here, to run repeatedly:
  serialEvent();

  /*
  Input commands
  */

  if(stringComplete && (inputString.equalsIgnoreCase("red\n")))
  {
    setColor(true, false, false);
    resetSerial();
    Serial.println("Red");
  } else if(stringComplete && (inputString.equalsIgnoreCase("green\n")))
  {
    setColor(false, true, false);
    resetSerial();
    Serial.println("Green");
  } else if(stringComplete && (inputString.equalsIgnoreCase("blue\n")))
  {
    setColor(false, false, true);
    resetSerial();
    Serial.println("Blue");
  }else if(stringComplete && (inputString.equalsIgnoreCase("off\n")))
  {
    setColor(false, false, false);
    resetSerial();
    Serial.println("Off");
  }else if (stringComplete)
  {
    Serial.println("Error: Incorrect string received");
    resetSerial();
  }
  else

  {

  }
}

void serialEvent(void)
{
  
  while (Serial.available())
  {   
    char inChar = (char)Serial.read();
    inputString += inChar;

    if (inChar=='\n')
    {
      stringComplete = true;
    }   
  }

}

void setColor(bool red, bool green, bool blue){
  digitalWrite(redPin, red ? LOW : HIGH);
  digitalWrite(greenPin, green ? LOW : HIGH);
  digitalWrite(bluePin, blue ? LOW : HIGH);
}

void resetSerial(){
  inputString = "";
  stringComplete = false;
}
