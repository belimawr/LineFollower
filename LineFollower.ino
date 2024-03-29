#define DEBUG


//Green - LEFT
//Brown - RIGHT

#define MLEFT_PWM 6
#define MLEFT_DIR 8

#define MRIGHT_PWM 5
#define MRIGHT_DIR 7

#define FORWARD HIGH
#define BACKWARD LOW

#define S0T 795
#define S1T 810
#define S2T 895
#define S3T 750

#define NORMAL_SPEED 75
#define STOP_SPEED 0
#define FF_SPEED 100

int s0, s1, s2, s3;
int s0r, s1r, s2r, s3r;
int value;

void allOff(){
  digitalWrite(MLEFT_DIR, FORWARD);
  digitalWrite(MRIGHT_DIR, FORWARD);
  
  analogWrite(MLEFT_PWM, STOP_SPEED);
  analogWrite(MRIGHT_PWM, STOP_SPEED);
}

void forward(){
  allOff();
  #ifndef DEBUG
  digitalWrite(MLEFT_DIR, FORWARD);
  digitalWrite(MRIGHT_DIR, FORWARD);
	
  analogWrite(MLEFT_PWM, FF_SPEED);
  analogWrite(MRIGHT_PWM, FF_SPEED);
  #else
  Serial.println("F");
  #endif
}


void backwards(){
  allOff();
  #ifndef DEBUG
  digitalWrite(MLEFT_DIR, BACKWARD);
  digitalWrite(MRIGHT_DIR, BACKWARD);
	
  analogWrite(MLEFT_PWM, NORMAL_SPEED);
  analogWrite(MRIGHT_PWM, NORMAL_SPEED);
  #else
  Serial.println("B");
  #endif
}


void right(){
  allOff();
  #ifndef DEBUG
  digitalWrite(MLEFT_DIR, FORWARD);
  digitalWrite(MRIGHT_DIR, BACKWARD);
	
  analogWrite(MLEFT_PWM, NORMAL_SPEED);
  analogWrite(MRIGHT_PWM, NORMAL_SPEED);
  #else
  Serial.println("R");
  #endif
}

void left(){
  allOff();
  #ifndef DEBUG
  digitalWrite(MLEFT_DIR, BACKWARD);
  digitalWrite(MRIGHT_DIR, FORWARD);
	
  analogWrite(MLEFT_PWM, NORMAL_SPEED);
  analogWrite(MRIGHT_PWM, NORMAL_SPEED);
  #else
  Serial.println("L");
  #endif
}

void setup(){

  Serial.begin(9600);
  
  pinMode(MRIGHT_PWM, OUTPUT);
  pinMode(MRIGHT_DIR, OUTPUT);
  pinMode(MLEFT_PWM, OUTPUT);
  pinMode(MLEFT_DIR, OUTPUT);

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
