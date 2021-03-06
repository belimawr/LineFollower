//#define DEBUG

#define L0 8
#define L1 9
#define R0 10
#define R1 11


#define S0T 750
#define S1T 900
#define S2T 900
#define S3T 910

#define NORMAL_SPEED 75
#define STOP_SPEED 0
#define FF_SPEED 100

int s0, s1, s2, s3;
int s0r, s1r, s2r, s3r;
int value;

void allOff(){
  analogWrite(L0, STOP_SPEED);
  analogWrite(L1, STOP_SPEED);
  analogWrite(R0, STOP_SPEED);
  analogWrite(R1, STOP_SPEED);
}

void forward(){
  allOff();
  #ifndef DEBUG
  analogWrite(L0, FF_SPEED);
  analogWrite(L1, STOP_SPEED);
  analogWrite(R0, STOP_SPEED);
  analogWrite(R1, FF_SPEED);
  #else
  Serial.println("F");
  #endif
}


void backwards(){
  allOff();
  #ifndef DEBUG
  analogWrite(L0, STOP_SPEED);
  analogWrite(L1, NORMAL_SPEED);
  analogWrite(R0, NORMAL_SPEED);
  analogWrite(R1, STOP_SPEED);
  #else
  Serial.println("B");
  #endif
}


void right(){
  allOff();
  #ifndef DEBUG
  analogWrite(L0, NORMAL_SPEED);
  analogWrite(L1, STOP_SPEED);
  analogWrite(R0, NORMAL_SPEED);
  analogWrite(R1, STOP_SPEED);
  #else
  Serial.println("R");
  #endif
}

void left(){
  allOff();
  #ifndef DEBUG
  analogWrite(L0, STOP_SPEED);
  analogWrite(L1, NORMAL_SPEED);
  analogWrite(R0, STOP_SPEED);
  analogWrite(R1, NORMAL_SPEED);
  #else
  Serial.println("L");
  #endif
}

void setup(){

  Serial.begin(9600);
  
  pinMode(L0, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(R0, OUTPUT);
  pinMode(R1, OUTPUT);

  allOff();

  #ifndef DEBUG
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  for(int i=0; i < 5; i++){
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    digitalWrite(13, HIGH);
  }
  digitalWrite(13, LOW);
  #endif

}


void loop(){

  s0 = analogRead(A0);
  s1 = analogRead(A1);
  s2 = analogRead(A2);
  s3 = analogRead(A3);

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

value = (s0r << 3) + (s1r << 2) + (s2r << 1) + s3r;

  #ifdef DEBUG
  Serial.print("(");
  Serial.print(s0r);
  Serial.print(", ");
  Serial.print(s1r);
  Serial.print(", ");
  Serial.print(s2r);
  Serial.print(", ");
  Serial.print(s3r);
  Serial.print(")    ");



  Serial.print("(");
  Serial.print(s0);
  Serial.print(", ");
  Serial.print(s1);
  Serial.print(", ");
  Serial.print(s2);
  Serial.print(", ");
  Serial.print(s3);
  Serial.print(")");


  Serial.print("    ");
  Serial.print(value, BIN);
  #endif


  switch (value){
    case B0000:
    forward();
    break;

    case B0001:
    right();
    break;

    case B0010:
    right();
    break;
    case B0011:
    right();
    break;

    case B0100:
    left();
    break;

    case B0101:
    right();
    break;

    case B0110:
    forward();
    break;

    case B0111:
    right();
    break;

    case B1000:
    left();
    break;

    case B1001:
    forward();
    break;

    case B1010:
    right();
    break;

    case B1011:
    right();
    break;

    case B1100:
    left();
    break;

    case B1101:
    left();
    break;

    case B1110:
    forward();
    break;

    case B1111:
    forward();
    break;
  }
}
