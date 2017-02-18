int IN1 = 7; //Speed 1 Right Wheel
int IN2 = 6; //Direction 1 RIght WHeel
int IN3 = 4; //Speed 2                         
int IN4 = 5; //Direction 2

// NEW MOTOR DERIVER


//OUTPUT HIGH for Forward
//OUTPUT LOW for Reverse

void setup() 
{ 
    pinMode(IN1, OUTPUT);   
    pinMode(IN2, OUTPUT); 
} 

void loop() 
{ 
  // Move backward 
  analogWrite(IN1,0);   
  analogWrite(IN2,100);       
  analogWrite(IN3, 0);   //PWM Speed Control
  analogWrite(IN4, 100);   //PWM Speed Control 
  
  delay(2000);

  // Move Forward
  analogWrite(IN1, 100);   
  analogWrite(IN2, 0);       
  analogWrite(IN3, 100);   //PWM Speed Control
  analogWrite(IN4, 0);   //PWM Speed Control
    

  delay(2000);
}
