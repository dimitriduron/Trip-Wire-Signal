int NOTIF = 13;
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

float prev_distances[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(NOTIF,OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  distance = pingForDistance();
  Serial.println(distance);

  

  Serial.println();
  
  bool tripped = false;
  if(0 < distance && distance < 10){
    digitalWrite(NOTIF, HIGH);
    tripped = true;
  }
  else{
    digitalWrite(NOTIF, LOW);
    tripped = false;
  }
  delay(10);
}

float pingForDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  return (duration*0.0343)/2;
}
