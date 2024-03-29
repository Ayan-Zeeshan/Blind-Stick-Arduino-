int trigPin = 9;
int echoPin = 10;
int buzzer = 11;
int ledPin = 13;
int duration = 0;
int distance = 0;
int safetyDistance = 0;


void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 5){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
   }
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
    }
Serial.print("Distance: ");
Serial.println(distance);
}
