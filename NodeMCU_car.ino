//#define ENA   D5 //14          // Enable/speed motors Right        GPIO14(D5)
//#define ENB   D6 //12          // Enable/speed motors Left         GPIO12(D6)
#define IN_1  14//D8 //15          // L298N in1 motors Right           GPIO15(D8)
#define IN_2  12//D7 //13          // L298N in2 motors Right           GPIO13(D7)
#define IN_3  13//D6 //D4 //2           // L298N in3 motors Left            GPIO2(D4)
#define IN_4  15//D5 //D3 //0           // L298N in4 motors Left            GPIO0(D3)
//#define Hl 16
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

String command="";             //String to store app command state.
//int speedCar = 255;         // 400 - 1023.
//int speed_Coeff = 3;

const char* ssid = "mars_rover";
const char* password = "mars1234";

ESP8266WebServer server(80);
//
//  Waiting for link 192.168.4.1/command
//
void HTTP_handleRoot() {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "<h1>connected</h1>" );
  delay(1);
}

void setup() {
 
 //pinMode(ENA, OUTPUT);
 //pinMode(ENB, OUTPUT);  
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT); 
 //pinMode(Hl,OUTPUT); 
  Serial.begin(115200);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.println("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.on(command,fun);
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}



void loop() {
    server.handleClient();
    
     command = server.arg("State");
      Serial.println(command);
      if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "I") goAheadRight();
      else if (command == "G") goAheadLeft();
      else if (command == "J") goBackRight();
      else if (command == "H") goBackLeft();
      else if (command == "S") stopRobot();
      /*else if (command == "0") speedCar = 400;
      else if (command == "1") speedCar = 470;
      else if (command == "2") speedCar = 540;
      else if (command == "3") speedCar = 610;
      else if (command == "4") speedCar = 680;
      else if (command == "5") speedCar = 750;
      else if (command == "6") speedCar = 820;
      else if (command == "7") speedCar = 890;
      else if (command == "8") speedCar = 960;
      else if (command == "9") speedCar = 1023;
      else if (command == "S") stopRobot();
      else if (command == "A") lights_on();
      else if (command == "Z") lights_off();*/
}

void fun()
{
   //server.handleClient();
  Serial.println("");
  command = server.arg("State::::");
      Serial.println(command);
  if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "I") goAheadRight();
      else if (command == "G") goAheadLeft();
      else if (command == "J") goBackRight();
      else if (command == "H") goBackLeft();
      else if (command == "S") stopRobot();
}
/*void HTTP_handleRoot() {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "<h1>connected</h1>" );
  delay(1);
}*/

void goAhead(){ 
      Serial.println("Forward:");
      //analogWrite(ENA, speedCar);
      //analogWrite(ENB, speedCar);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
  }

void goBack(){ 
      //analogWrite(ENA, speedCar);
      //analogWrite(ENB, speedCar);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);      
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
  }

void goRight(){ 
      //analogWrite(ENA, speedCar);
      //analogWrite(ENB, speedCar);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
  }

void goLeft(){
      //analogWrite(ENA, speedCar);
      //analogWrite(ENB, speedCar);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);      
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
  }

void goAheadRight(){
      //analogWrite(ENA, speedCar);
      //analogWrite(ENB, speedCar);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
   }

void goAheadLeft(){
      // analogWrite(ENA, speedCar);
      //analogWrite(ENB, speedCar);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);   
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      
  }

void goBackRight(){ 
      //analogWrite(ENA, speedCar);
      //analogWrite(ENB, speedCar);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);    
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
  }

void goBackLeft(){ 
      //analogWrite(ENA, speedCar);
     // analogWrite(ENB, speedCar);
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);  
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      
  }

void stopRobot(){  
      //analogWrite(ENA, speedCar);
      //analogWrite(ENB, speedCar);
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      
 }
