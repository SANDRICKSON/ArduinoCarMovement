int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;


int echoPin = 6;
int trigPin = 7;

int leftSensor1 = 9;
int leftSensor2 = 10;
int centerSensor = 11;
int rightSensor1 = 12;
int rightSensor2 = 13;


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
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
}

void backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
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
  Serial.print(leftState1);
  Serial.print("    ");
  Serial.print(leftState2);
  Serial.print("    ");
  Serial.print(centerState);
  Serial.print("    ");
  Serial.print(rightState1);
  Serial.print("    ");
  Serial.print(rightState2);
  Serial.println("    ");



  if (leftState1 == LOW && leftState2 == LOW && centerState == HIGH && rightState1 == LOW && rightState2 == LOW) {
    forward();
    delay(500);
  }

  if (leftState1 == LOW && leftState2 == LOW && centerState == HIGH) {
    left();
    delay(500);
  }

  if (rightState1 == LOW && rightState2 == LOW && centerState == HIGH) {
    right();
    delay(500);
  }

  if (centerState == LOW) {
    if (leftState1 == HIGH || leftState2 == HIGH) {
      left();
      delay(500);
    } else if (rightState1 == HIGH || rightState2 == HIGH) {
      right();
      delay(500);
    } else {
      stop();
      delay(500);
    }
  }

  if (leftState1 == LOW && leftState2 == LOW && centerState == LOW && rightState1 == LOW && rightState2 == LOW) {
    forward();
    delay(500);
  }

  if (leftState1 == HIGH && leftState2 == HIGH && centerState == HIGH && rightState1 == HIGH && rightState2 == HIGH) {
    stop();
    delay(500);
  }
}

void loop() {
  followLine();
  forward();

  delay(500);
}
