int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

int trigPin = 8;
int echoPin = 9;

int leftSensor1 = 11;  
int leftSensor2 = 12;  
int centerSensor = 13; 
int rightSensor1 = 10; 
int rightSensor2 = 6; 


long duration;
int distance;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftSensor1, INPUT);
  pinMode(leftSensor2, INPUT);
  pinMode(centerSensor, INPUT);
  pinMode(rightSensor1, INPUT);
  pinMode(rightSensor2, INPUT);

  Serial.begin(9600);
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  int dist = duration * 0.034 / 2;

  if (dist == 0) dist = 400;

  return dist;
}

void followLine() {
  int leftState1 = digitalRead(leftSensor1);
  int leftState2 = digitalRead(leftSensor2);
  int centerState = digitalRead(centerSensor);
  int rightState1 = digitalRead(rightSensor1);
  int rightState2 = digitalRead(rightSensor2);


  if (leftState1 == HIGH && leftState2 == HIGH && centerState == HIGH && rightState1 == HIGH && rightState2 == HIGH) {
    forward();
  }
 
  else if (leftState1 == LOW && leftState2 == LOW && centerState == HIGH) {
    left();
  }

  else if (rightState1 == LOW && rightState2 == LOW && centerState == HIGH) {
    right(); 
  }

  else if (centerState == LOW) {
    if (leftState1 == HIGH || leftState2 == HIGH) {
      left(); 
    } else if (rightState1 == HIGH || rightState2 == HIGH) {
      right(); 
    } else {
      stop(); 
    }
  }

  else {
    forward(); 
  }
}

void loop() {
  distance = getDistance();

  if (distance < 20) {
    stop();
    delay(300);
    backward();
    delay(300);
    right();
    delay(700);
    forward();
    delay(1000);
    left();
    delay(550);
  } else {
    followLine(); 
  }

  delay(50);
}
