

#define L0 31
#define L1 33
#define R0 35
#define R1 37


#define S0T 720
#define S1T 800
#define S2T 930
#define S3T 940


void allOff(){
  digitalWrite(L0, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(R0, LOW);
  digitalWrite(R1, LOW);
}

void forward(){
  allOff();
  digitalWrite(L0, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(R0, LOW);
  digitalWrite(R1, HIGH);
}


void backwards(){
  allOff();
  digitalWrite(L0, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(R0, HIGH);
  digitalWrite(R1, LOW);
}


void right(){
  allOff();
  digitalWrite(L0, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(R0, HIGH);
  digitalWrite(R1, LOW);
}

void left(){
  allOff();
  digitalWrite(L0, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(R0, LOW);
  digitalWrite(R1, HIGH);
}



void setup(){

  Serial.begin(9600);
  
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(R0, OUTPUT);
  pinMode(R1, OUTPUT);
  
  digitalWrite(L0, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(R0, LOW);
  digitalWrite(R1, LOW);
  allOff();

}




int s0, s1, s2, s3;

int s0r, s1r, s2r, s3r;

void loop(){

  s0 = analogRead(A0);
  delay(5);
  s1 = analogRead(A1);
  delay(5);
  s2 = analogRead(A2);
  delay(5);
  s3 = analogRead(A3);
  delay(5);


// #define S0T 720
// #define S1T 800
// #define S2T 930
// #define S3T 940

if (s0 > S0T){
  s0r = 1;
} else {
  s0r = 0;
}

if (s1 > S1T){
  s1r = 1;
} else {
  s1r = 0;
}

if (s2 > S2T){
  s2r = 1;
} else {
  s2r = 0;
}

if (s3 > S3T){
  s3r = 1;
} else {
  s3r = 0;
}

if (s1r == 1 && s2r == 1){
  forward();
} else if (s1r == 0 && s2r == 1){
  right();
} else if (s1r == 1 && s2r == 0) {
  left();
}




  // Serial.print("(");
  // Serial.print(s0r);
  // Serial.print(", ");
  // Serial.print(s1r);
  // Serial.print(", ");
  // Serial.print(s2r);
  // Serial.print(", ");
  // Serial.print(s3r);
  // Serial.print(")    ");



  // Serial.print("(");
  // Serial.print(s0);
  // Serial.print(", ");
  // Serial.print(s1);
  // Serial.print(", ");
  // Serial.print(s2);
  // Serial.print(", ");
  // Serial.print(s3);
  // Serial.println(")");

  // delay(200);


}
