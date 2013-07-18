// This code is based on a program called "Sweep"
// by BARRAGAN <http://barraganstudio.com> 
// (which is an example placed in the public domain found under the example menu of the Arduino IDE)
// and we also utilize the Servo.h Library

//Creative commons license for my modifications
//
//I created additional functions created for handling continuous-rotation-servos as motors
//Forward, Backward, RotateLeft, RotateRight, Stop, and attachServo
//by gskielian  < http://www.kielian.net > 

double ForwardSpeed = 30.0;
double RotateSpeed = 30.0;
double BackwardSpeed = 30.0;

#include <Servo.h> 
 
Servo LeftWheel;  // create servo object to control a servo 
Servo RightWheel;  // create servo object to control a servo 
Servo Pan;
Servo Tilt;

// Note: a maximum of eight servo objects can be created 

int LWPin = 10; //set the pin number for your left servo-motors (just change the number if not pin 9)
int RWPin = 11; //right-wheel control pin
int PanPin = 9;
int TiltPin = 6;

//for the Remote Control
int A = 2;
int B = 3;
int C = 4;
int D = 5;
 

void setup() 
{ 
  LeftWheel.attach( LWPin );  //  Connects LeftWheel to the pin LWPin
  RightWheel.attach( RWPin );  // Connects another wheel to be controlled by the pin RWPin
  Pan.attach(PanPin);
  Tilt.attach(TiltPin);
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C,INPUT);
  pinMode(D,INPUT);

Serial.begin(9600);
} 
 
 
void loop() 
{    
  
 Serial.print("A Pin");
 Serial.println(digitalRead(A));

 Serial.print("B Pin");
 Serial.println(digitalRead(B));

 Serial.print("C Pin");
 Serial.print(digitalRead(C));

 Serial.print("D Pin");
 Serial.print(digitalRead(D));


delay(100); 
  /*
     Pan.write(180); //LookStraight
     Tilt.write(150);
     Backward(5);
     Pan.write(90); //LookRight
     Tilt.write(150);
     Pan.write(0); //LookLeft
     Tilt.write(150);
     Backward(5);
     Pan.write(70);
     Tilt.write(150);
     Stop(4);
     Tilt.write(90);
     Pan.write(180);
     delay(500);
     Tilt.write(45);
     Pan.write(60);
     delay(500);
     Tilt.write(0);
     Pan.write(90);
     delay(500);
  */
} 









void Forward(double seconds)
{
    double speed = ForwardSpeed;

     attachServos(); //in case we disconnected them

     //The CRS thinks it is always at 90 degrees
     //if you tell it to go to 180 degrees it will go really fast clock-wise
     //0 degrees really quickly counterclockwise
     // 95 really slowly clockwise
     
    double leftspeed = (-speed/100.0*90.0 + 90) ;
    double rightspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write( (int) leftspeed);             
    RightWheel.write((int) rightspeed); // Right wheel is backwards
 
   //delay wants an integer number of milliseconds, we turn seconds to milliseconds
   //then we turn the result into an int
   delay((int) (seconds*1000)); 
}



void Backward ( double seconds)
{
    double speed = BackwardSpeed; 

    attachServos(); //in case we disconnected them

    double leftspeed = (speed/100.0*90.0 + 90) ;
    double rightspeed = (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write( (int) leftspeed);             
    RightWheel.write((int) rightspeed);
    
    delay((int) (seconds*1000));
}



void RotateLeft (double seconds)
{
    double speed = RotateSpeed;

    attachServos(); //in case we disconnected them

    double leftspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    double rightspeed = (speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write((int) leftspeed);             
    RightWheel.write((int) rightspeed);
    delay((int) (seconds*1000));
}

void RotateRight (double seconds)
{
    double speed = RotateSpeed;
    
    attachServos(); //in case we disconnected them
     
    double leftspeed =  (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    double rightspeed =  (-speed/100.0*90.0 + 90) ;  // translates it to servo-speak (servo input is from 0-180)
    
    LeftWheel.write((int) leftspeed);             
    RightWheel.write((int) rightspeed); 

    delay((int) (seconds*1000));
}


void Stop( double seconds)
{
  LeftWheel.detach();  //to stop the motors, we have the Arduino stop sending signals entirely
  RightWheel.detach();

  delay((int) (seconds*1000));
}





void attachServos()
{
   LeftWheel.attach(LWPin);
   RightWheel.attach(RWPin);
}                                                                                           
