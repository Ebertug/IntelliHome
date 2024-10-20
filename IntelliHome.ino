#include <Servo.h>
Servo servo1;
int servoClose=0;
int	servoOpen=90;
#define servoPin 11
/*-------------*/
#define gasSensor  A1
int gasValue;
int gasPer;
/*-------------*/
#define led1 3
/*-------------*/
#define ldrSensor A0
int ldrValue;
/*-------------*/
#define tempSensor A5
int tempValue;
int tempReal;
// /*-------------*/
//#define dcMotor1 9
// #define dcMotor2 4
// /*-------------*/


void setup()
{
    /*-------------*/
    Serial.begin(9600);
    /*-------------*/
    pinMode(ldrSensor,INPUT);
    /*-------------*/
    pinMode(led1, OUTPUT);
    /*-------------*/
    servo1.attach(servoPin);
    servo1.write(servoClose);
    // /*-------------*/
    pinMode(gasSensor,INPUT);
    // pinMode(dcMotor2,OUTPUT);
    // /*-------------*/
    pinMode(tempSensor,INPUT);  
    //pinMode(dcMotor1,OUTPUT);
    /*-------------*/
}

void loop()
{
    /*-------------*/
    ldrValue= analogRead(ldrSensor);
    //Serial.print("ldrValue= ");
    //Serial.println(ldrValue);
    /*-------------*/
    if (ldrValue<=475 && ldrValue>=0){
        // Serial.print("Led Closed");
        digitalWrite(led1,HIGH);
    }
    else if(ldrValue>=500 && ldrValue<=900){
        // Serial.print("led Opened");
        digitalWrite(led1,LOW);
    }
    else{Serial.print("Buffer or Error");}
    /*-------------*/
    /*-------------*/
    gasValue = analogRead(gasSensor);
    //Serial.print("gazValue= ");
    //Serial.println(gasValue);
    /*-------------*/
    if(gasValue>=300){
      servo1.write(servoOpen);
      //digitalWrite(dcMotor1,HIGH);
    }
    else if(gasValue<250){
      servo1.write(servoClose);
      //digitalWrite(dcMotor1,LOW);
    }
    else{Serial.println("Buffer or Error");}
    /*-------------*/
    /*-------------*/
    tempValue = analogRead(tempSensor);
    tempReal = tempValue/9.31;
    Serial.print("tempValue= ");
    Serial.println(tempReal);
    // /*-------------*/
    // if (tempReal>=30 && tempReal<=125){
    //     digitalWrite(dcMotor1,HIGH);
    //     Serial.print("dcMotorStatue= ");
    //     Serial.println("HIGH");
    // }
    // else if (tempReal<25 && tempReal>=-125){
    //     digitalWrite (dcMotor1,LOW);
    //     Serial.print("dcMotorStatue= ");
    //     Serial.println("LOW");
    // }
    // else{Serial.println("Buffer or Error");}
    delay(300);
}