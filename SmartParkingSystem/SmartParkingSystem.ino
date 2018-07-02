
#include <Servo.h>          //Servo library
 
Servo servo_test,test2;    		//initialize a servo object for the connected servo  
                
int angle = 0; 
int count=0;
int caristhere;
int exiting;
int led = 13;
int obstaclePin = 7;// This is our input pin
int inpinpark=4;
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() 
{
   pinMode(led, OUTPUT); 
   pinMode(obstaclePin, INPUT);
   pinMode(5, INPUT);
   test2.attach(6);
   Serial.begin(9600); 
   servo_test.attach(9); 
}
void loop() 
{
  
   hasObstacle = digitalRead(obstaclePin);
   caristhere = digitalRead(inpinpark);
   exiting=digitalRead(6);
  //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
 

 
 
  if (hasObstacle == LOW) //LOW means something is ahead, so illuminates the 13th Port connected LED
  { 
    if(caristhere)
    {
      Serial.println("Parking Full");
      digitalWrite(led, HIGH);
    }
    else
    {
      
      digitalWrite(led, LOW); 
      Serial.println("Plz come inside");
      for(angle = 0; angle < 90; angle += 1) 	 // command to move from 0 degrees to 180 degrees 
       {                
    
        servo_test.write(angle);              	 //command to rotate the servo to the specified angle
        delay(15);                       
       } 
 
       delay(3000);
  
       for(angle = 90; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
      {                                
        servo_test.write(angle);              //command to rotate the servo to the specified angle
        delay(15);                       
      } 

      delay(1000);
    
    }
  }
  
  else
  {
    Serial.println("Path is clear");
  
  }
    delay(200);
    digitalWrite(led, LOW); 
}







