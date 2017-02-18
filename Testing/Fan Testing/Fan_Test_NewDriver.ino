int IN1 = 9;
int IN2 = 8;

int x;

void setup() 
{ 
    Serial.begin(9600); 
    pinMode(IN1, OUTPUT);   
} 

void loop() 
{ 
//Fan Off
//digitalWrite(IN1,150);   
//analogWrite(IN2, 0);
//delay(2000); 

//Flame Sensor
analogWrite(IN1,150);    
analogWrite(IN2, 0);
 
delay(1000); //Delay the output by 1s (1000ms) 
}
