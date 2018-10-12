#include <math.h>                              
#include <Servo.h>                                //Include Servo library
Servo irservo;                                    // create servo object to control a servo 

#define Svo_Pin 9

int posnow;

int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;     //M1 Direction Control
int M2 = 7;     //M1 Direction Control
int MotorSpeed = 30;

void stop(void)                    //Stop
{
  digitalWrite(E1,0); 
  digitalWrite(M1,LOW);    
  digitalWrite(E2,0);   
  digitalWrite(M2,LOW);    
}   
void advance(char a,char b)          //Move forward
{
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}  
void back_off (char a,char b)          //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_L (char a,char b)             //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)             //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}


void setup()
{
  int i;
  for(i=4;i<=7;i++)
   pinMode(i, OUTPUT); 
//  pinMode(2,OUTPUT);
//  Serial.println("Run keyboard control");
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);
  irservo.attach(Svo_Pin);                         //attaches the servo on pin 9 to the servo object 
  Serial.begin(19200);                            //Set Baud Rate
  advance(MotorSpeed,MotorSpeed);
}

int pos=0;                                        // variable to store the servo position 
float distance;

void loop()
{
//  digitalWrite(2,HIGH); 
  for (int i=0;i<180;i++)          
  {
    irservo.write(i);
    int x=analogRead(0);                   // connect the GP2Y0A21 distance sensor to Analog 0
    Serial.println(x);                    // print distance 
    if(x>350)
    {
//      digitalWrite(2,LOW);delay(100); digitalWrite(2,HIGH); delay(100); 
      if(i<135)                           
      {
        back_off(MotorSpeed,MotorSpeed);delay(300);
        turn_L(MotorSpeed,MotorSpeed);delay(300);
      }
      else
      {
        back_off(MotorSpeed,MotorSpeed);delay(300);
        turn_R(MotorSpeed,MotorSpeed);delay(300);
      }
      advance(MotorSpeed,MotorSpeed);
    }
    delay(4);
  } 
  for(int i=180;i>0;i--)
  {
    irservo.write(i);
    int x=analogRead(0);
    Serial.println(x);                    // print distance 
    if(x>350)
    {
//      digitalWrite(2,LOW);delay(100); digitalWrite(2,HIGH); delay(100); 
      if(i<135)
      {
        back_off(MotorSpeed,MotorSpeed);delay(300);
        turn_L(MotorSpeed,MotorSpeed);delay(300);
      }
      else
      {
        back_off(MotorSpeed,MotorSpeed);delay(300);
        turn_R(MotorSpeed,MotorSpeed);delay(300);
      }
      advance(MotorSpeed,MotorSpeed);
    }
    delay(4);
  }
}
