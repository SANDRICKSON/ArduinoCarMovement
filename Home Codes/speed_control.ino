int ENA = 5;
int ENB = 6;

int in1 = 9 ;
int in2 = 10;
int in3 = 11;
int in4 = 12;


int echoPin = A0;
int trigPin = 8;

int leftSensor1 = A1;
int leftSensor2 = A2;
int centerSensor = A3;
int rightSensor1 = A4;
int rightSensor2 = A5;


long duration;
int distance;


int speedLeft = 180;
int speedRight = 180;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

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
  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void backward() {
  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void left() {
  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  analogWrite(ENA, speedLeft);
  analogWrite(ENB, speedRight);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopCar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
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
  int L1 = digitalRead(leftSensor1);
  int L2 = digitalRead(leftSensor2);
  int C = digitalRead(centerSensor);
  int R1 = digitalRead(rightSensor1);
  int R2 = digitalRead(rightSensor2);

  Serial.print(L1);
  Serial.print(" ");
  Serial.print(L2);
  Serial.print(" ");
  Serial.print(C);
  Serial.print(" ");
  Serial.print(R1);
  Serial.print(" ");
  Serial.println(R2);


  if (C == LOW && L1 == HIGH && L2 == HIGH && R1 == HIGH && R2 == HIGH) {
    backward();
    return;
  }

  if (C == HIGH && L1 == HIGH && L2 == HIGH && R1 == HIGH && R2 == HIGH) {
    backward();
    return;
  }
  if (L1 == LOW || L2 == LOW) {
    left();
    return;
  }


  if (R1 == LOW || R2 == LOW) {
    right();
    return;
  }
}


void loop() {

  int dist = getDistance();

  Serial.print("Distance: ");
  Serial.println(dist);



  followLine();
}
