int solenoid = D2; // Instead of writing D0 over and over again, we'll write led1

char buffer[9];

unsigned long duration;

void setup() {

  pinMode(solenoid, OUTPUT);
  
  pinMode(D4, INPUT);
  
  Particle.variable("buffer", buffer);
  Particle.function("setStatus", state);
}

void loop() {
    
  duration = pulseIn(D4, HIGH);
  
  sprintf(buffer, "%lu", duration);
  
  //Particle.publish("meter pulse count", buffer);
   
  delay(200);
 
}
  
int state(String command) {  // declaration of this func needed for Particle cloud
  if(command == "ON") {
    turnOn(solenoid);
    return 1;
  }
      
  if(command == "OFF") {
    turnOff(solenoid);
    return 0;
  }
}

void turnOn(int solenoid) {
     digitalWrite(solenoid, HIGH);

}

void turnOff(int solenoid) {
    digitalWrite(solenoid, LOW);
}

