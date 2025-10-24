int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;



void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}


void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}




void loop() {

  
  forward();
  delay(1000);
  right();
  delay(800);
  forward();
  delay(1000);
  right();
  delay(800);
  forward();
  delay(1000);
  right();
  delay(800);
  stop();
  delay(1000);
}