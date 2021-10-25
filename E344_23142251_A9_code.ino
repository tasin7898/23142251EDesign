// Tasin Ul Islam 
// 23142251


float SupplyVoltage=0;

float BatteryVoltage=0;

float BatteryCurrent=0;

float Ambient=0;

bool OverchargeStatus = true;
String changeStatus="";

// the setup routine runs once when you press reset:

void setup() {
// initialize serial communication at 9600 bits per second:

Serial.begin (9600);

pinMode (9, OUTPUT);
}

// the loop routine runs over and over again forever:

void loop(){

// send data only when you receive data:

// read the incoming byte:
changeStatus = Serial.readString();

if (changeStatus == "OVI") {

OverchargeStatus= true;

digitalWrite (9, HIGH);
}
if (changeStatus == "OVO") {
OverchargeStatus= false;

digitalWrite (9, LOW);
}
Serial.print (OverchargeStatus);

Serial.print(",");


// read the input on analog pin 0:

// Convert the analog reading (which goes from 01023) to a voltage (0-5V) ADC:

float BatteryVoltage = 2* (((analogRead(0)*5.0)/(1023.0*3.88)) + 2.8125);


Serial.print (BatteryVoltage);

Serial.print(",");


// Convert, the analog reading (which goes from 01023) to a voltage (0 - 5V) ADC:

float SupplyVoltage = analogRead (2)* (22.0/ 1023.0);


Serial.print (SupplyVoltage);

Serial.print(",");


// Convert the analog reading (which goes from 0-1023) to a voltage (-150 450mA) ADC:
float BatteryCurrent =(((analogRead (1)* 50)/1023.0)-1.75)/ (50*0.1);


Serial.print (BatteryCurrent);

Serial.print(",");


// Convert the analog reading (which goes from 0-1023) to a voltage (-150 - 450mA) ADC:
float Ambient = analogRead(10)*20;

Serial.println (Ambient);


}
