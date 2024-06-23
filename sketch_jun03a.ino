
#define ledpin 9
#define pot1 A0
#define pot2 A1
#define pot3 A2
#define pot4 A3

#define error_message "Please change ledpin to 3,5,6,9,10 or 11"

#define baud 9600

int brightness ;
int brightness_mapped ;
int brightness0 ;
int brightness0_mapped ;
int stoptime0 ;
int stoptime0_mapped ; 
int stoptime1 ;
int stoptime1_mapped ;

void setup() {
  Serial.begin(baud);
  if((ledpin == 3) || (ledpin == 5) || (ledpin == 6) || (ledpin == 9) || (ledpin == 10) || (ledpin == 11)){
    pinMode(ledpin, OUTPUT);
  } else {
    Serial.println(error_message);
  }
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(pot3, INPUT);
  pinMode(pot4, INPUT);

}

void loop() {
  brightness = analogRead(pot1);
  brightness0 = analogRead(pot4);
  stoptime0 = analogRead(pot2);
  stoptime1 = analogRead(pot3);

  brightness_mapped = map(brightness, 0, 1024, 0, 255);
  brightness0_mapped = map(brightness0, 0, 1024, 0, 255);
  stoptime0_mapped = map(stoptime0, 0, 1024, 250, 5000);
  stoptime1_mapped = map(stoptime1, 0, 1024, 250, 5000);
  
  Serial.print("Brightness: ");
  Serial.print(brightness);
  Serial.print(" ; ");
  Serial.println(brightness_mapped);
  Serial.print("Offtime brightness: ");
  Serial.print(brightness0);
  Serial.print(" ; ");
  Serial.println(brightness0_mapped);
  Serial.print("Delay 1: ");
  Serial.print(stoptime0);
  Serial.print(" ; ");
  Serial.println(stoptime0_mapped);
  Serial.print("Delay 2: ");
  Serial.print(stoptime1);
  Serial.print(" ; ");
  Serial.println(stoptime1_mapped);
  
  analogWrite(ledpin, brightness_mapped);
  delay(stoptime0);
  analogWrite(ledpin, brightness0_mapped);
  delay(stoptime1);

}
