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

void loop() {
  forward();
  delay(1000);


  backward();
  delay(300);  //უკან





  right();
  delay(700);  //მარჯვნივ

  forward();
  delay(500);  //წინ


  left();
  delay(550);  //მარცხნივ

  forward();
  delay(700);  //წინ



  left();

  delay(500);  //მარცხნივ


  forward();
  delay(1000);  //წინ


  right();

  delay(700);  //მარჯვნივ

  stop();
  delay(1000);  //სტოპ
}
