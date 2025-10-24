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


void forward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}



void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void loop() {











//სამკუთხედი

  forward();
  delay(700);  //წინ


  right();
  delay(1000); //მარჯვნივ


  forward();
  delay(700); //წინ
  


  right();
  delay(1200); //მარჯვნივ

  forward();
  delay(1000); //წინ

  stop();
  delay(1000);//სტოპ



}