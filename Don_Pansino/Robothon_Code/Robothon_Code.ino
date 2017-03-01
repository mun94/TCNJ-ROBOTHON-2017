int IRRightPort = 0;
int IRLeftPort = 1;
int IRCenterPort = 2;
int FlamePort = 3;
int r,l,c,f,i,r_prev,l_prev,c_prev;
int LeftWheel2Port = 7;
int LeftWheel1Port = 6;
int RightWheel2Port = 5;
int RightWheel1Port = 4;
int Fan1Port = 2;
int Fan2Port = 3;
int A = 33;
int B = 26;
int C = 37;
int D = 27;
int E = 23;
int F = 31;
int G = 22;

void resetAllMotors();
void _90DegreeCW();
void _90DegreeCCW();
void _45DegreeCW();
void _45DegreeCCW();
void LEDCountdown();
void resetLED();
void measure();
void compare();
void go();
void LED(int a);

int rotateTime = 800;
int rotateSpeed = 70;
int travelSpeed = 90;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  resetLED();
  LEDCountdown();
  r = analogRead(IRRightPort);
  l = analogRead(IRLeftPort);
  c = analogRead(IRCenterPort);
  f = analogRead(FlamePort);
}

void loop() {
  measure();
  compare();
  go();
}

void resetAllMotors()
{
  analogWrite(LeftWheel1Port, 0);
  analogWrite(LeftWheel2Port, 0);
  analogWrite(RightWheel1Port, 0);
  analogWrite(RightWheel2Port, 0);
  analogWrite(Fan1Port, 0);
  analogWrite(Fan2Port, 0);
}

void _90DegreeCW()
{
  resetAllMotors();
  analogWrite(LeftWheel1Port, rotateSpeed);
  analogWrite(RightWheel2Port, rotateSpeed);
  delay(rotateTime-50);
  resetAllMotors();
}

void _90DegreeCCW()
{
  resetAllMotors();
  analogWrite(LeftWheel2Port, rotateSpeed-5);
  analogWrite(RightWheel1Port, rotateSpeed);
  delay(rotateTime);
  resetAllMotors();
}

void _45DegreeCW()
{
  analogWrite(LeftWheel1Port, 0);
  analogWrite(LeftWheel2Port, 0);
  analogWrite(RightWheel1Port, 0);
  analogWrite(RightWheel2Port, 0);
  analogWrite(LeftWheel1Port, rotateSpeed);
  analogWrite(RightWheel2Port, rotateSpeed);
  delay(int(rotateTime/2));
  analogWrite(LeftWheel1Port, 0);
  analogWrite(LeftWheel2Port, 0);
  analogWrite(RightWheel1Port, 0);
  analogWrite(RightWheel2Port, 0);
}

void _45DegreeCCW()
{
  analogWrite(LeftWheel1Port, 0);
  analogWrite(LeftWheel2Port, 0);
  analogWrite(RightWheel1Port, 0);
  analogWrite(RightWheel2Port, 0);
  analogWrite(LeftWheel2Port, rotateSpeed-5);
  analogWrite(RightWheel1Port, rotateSpeed);
  delay(int(rotateTime/2));
  analogWrite(LeftWheel1Port, 0);
  analogWrite(LeftWheel2Port, 0);
  analogWrite(RightWheel1Port, 0);
  analogWrite(RightWheel2Port, 0);
}

void LED(int a)
{
  switch(a)
  {
    case 0:
      resetLED();
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
    case 1:
      resetLED();
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
      break;
    case 2:
      resetLED();
        digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(G, HIGH);
      break;
    case 3:
      resetLED();
        digitalWrite(A, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
    case 4:
      resetLED();
        digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
      break;
    case 5:
      resetLED();
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
    case 6:
      resetLED();
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
    case 7:
      resetLED();
        digitalWrite(A, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
      break;
    case 8:
      resetLED();
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
      break;
    case 9:
      resetLED();
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
      break;
    default:
      resetLED();
      break;
  }
}

void LEDCountdown()
{
  for (i = 9; i >= 0; i = i - 1)
  {
    LED(i);
    delay(1000);
  }
  resetLED();
}

void resetLED()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void measure()
{
  r_prev = r;
  r = analogRead(IRRightPort);
  l_prev = l;
  l = analogRead(IRLeftPort);
  c_prev = c;
  c = analogRead(IRCenterPort);
  f = analogRead(FlamePort);
  if (f < 50)
  {
    resetAllMotors();
    analogWrite(Fan1Port, 100);
    _45DegreeCCW();
    _45DegreeCW();
    _45DegreeCW();
    _45DegreeCCW();
    _45DegreeCCW();
    _45DegreeCW();
    delay(20000);
    resetAllMotors();
    delay(5000000);
    //returnHome?
  }
}

void compare()
{
  if ((r < c) && (r < l))
  {
    _90DegreeCW();
  }
  else if ((c < r) && (c < l))
  {
    //No Rotation
  }
  else if ((l < r) && (l < c))
  {
    _90DegreeCCW();
  }
}

void go()
{
  i = 0;
  analogWrite(LeftWheel1Port, (travelSpeed - 10));
  analogWrite(RightWheel1Port, travelSpeed+5);
  while ((c < 350) || (i < 30))
  {
    measure();
    if (c > 350) {
      break;
    }
    if ((abs(c-c_prev) < 20) && (abs(r-r_prev) < 25) && (abs(l-l_prev) < 25) && (abs(c-c_prev) > 5)) {
      resetAllMotors();
      analogWrite(LeftWheel2Port, (travelSpeed - 10));
      analogWrite(RightWheel2Port, travelSpeed+5);
      delay(1000);
      break;
    }
    delay(500);
    i = i + 1;
    if (i > 30) {
      break;
    }
  }
  resetAllMotors();
}
