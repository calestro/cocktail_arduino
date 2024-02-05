////O TOTAL DO X E DE 1300

#include <AFMotor.h>

//0fd500fd560fd1300b
AF_Stepper motorZ(68 , 2);
AF_Stepper motorX(64, 1);

int totalSize = 1300;
int  homePoint = 0;
String command;
void setup() {
  Serial.begin(9600);
  motorZ.setSpeed(150);
  motorX.setSpeed(300);   
}

void loop() {

  if(Serial.available()>0){
     while(Serial.available()>0){
      char c;
      c = Serial.read();
      if(c != '\n'){
        if(c == 'b'){
          Serial.println("back");
        backwardMove(command.toInt());  
          }else if(c == 'f'){
            Serial.println("front");
            forwardMove(command.toInt());    
            
            }else if(c == 'd'){
              dispenser();
              
              }else{
                command += c;
                Serial.println(command);
                delay(200); 
                
                }
        
        
      }else{
        Serial.println("here!");
        }

    
    }

    motorX.release();
    
 
  
  }
  
  //motorX.step(450, FORWARD, SINGLE);
  //dispenser();
  //motorX.step(450, FORWARD, SINGLE);
  //dispenser();
  //motorX.step(900, BACKWARD, SINGLE);
  //delay(3000);
   


}

void forwardMove(int stepper){
motorX.step(stepper, FORWARD, SINGLE);
command = "";
homePoint +=stepper; 
motorX.release(); 
}

void backwardMove(int stepper){
motorX.step(stepper, BACKWARD, SINGLE);
homePoint -=stepper;  
command = "";
motorX.release();
}

void dispenser(){
  motorZ.step(3800, FORWARD, DOUBLE);
  delay(4000); 
  motorZ.step(3800, BACKWARD, DOUBLE);
  
    motorZ.release();
  }
