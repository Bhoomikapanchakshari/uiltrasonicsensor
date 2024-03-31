#define TRIGGER_PIN 4
#define ECHO_PIN 3
#define LED_PIN 12
unsigned long lasttime=millis();
unsigned long timedelay=100;
int varl=0;

void trigger(){
  digitalWrite(TRIGGER_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);
}

double getdistance(){
  double duration=pulseIn(ECHO_PIN,HIGH);
  double distance=duration/58.0;
  varl=distance;
  return distance;
}

void setup(){
  Serial.begin(115200);
  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop(){
  int timenow=millis();
  if(timenow-lasttime>timedelay){
    lasttime+=timedelay;
    trigger();
    Serial.println(getdistance());
    if(varl<20){
      digitalWrite(LED_PIN,HIGH);
    }
    else{
      digitalWrite(LED_PIN,LOW);
    }
  }
}  
  