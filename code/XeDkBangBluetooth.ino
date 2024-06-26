
#include <SoftwareSerial.h>
 
#define TX_PIN      4
#define RX_PIN      3
char value; 
SoftwareSerial bluetooth(RX_PIN, TX_PIN);
int baudRate[] = {300, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
   
int enbA=5;
int in1 = 6;       
int in2 = 7;        
int in3 = 8;        
int in4 = 9;  
int enbB=10;      
  
void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  
  Serial.println("Configuring, please wait...");
  
  for (int i = 0 ; i < 9 ; i++) {
     bluetooth.begin(baudRate[i]);
     String cmd = "AT+BAUD4";
     bluetooth.print(cmd);
     bluetooth.flush();
     delay(100);
  }
  
  bluetooth.begin(9600);
  Serial.println("Config done");
  while (!bluetooth) {}
  
  Serial.println("Enter AT commands:");

  pinMode(11,  INPUT);
  pinMode(13, OUTPUT);  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enbA, OUTPUT);
  pinMode(enbB, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enbA, LOW);
  digitalWrite(enbB, LOW);  
  digitalWrite(13, 0);
  
 


}

void loop()
{
  value="";
  if (bluetooth.available()) {
    
    value=bluetooth.read();
    Serial.write(value);
    switch(value)
    {
      case 'F':
        dithang();
        break;
      case 'B': 
        dilui();
        break;
      case 'L':
        disangtrai();
        break;
      case 'R':
        disangphai();
        break;
      case 'W':
        coi();
        break;
      case 'U':
        dunglai();
        break;
     case 'V':
        xoaytrai();
        break; 
      case 'v':
      xoayphai(); 
      break;
    }
  }
  // int ct= digitalRead(11);//doc cong tac hanh trinh
  // Serial.println(ct);
  // if(ct ==0){
  //   digitalWrite(13, HIGH); //coi
  //   delay(100);
  //   digitalWrite(13, LOW);

  // }

}
void coi(){
   digitalWrite(13, HIGH); //coi
    delay(500);
    digitalWrite(13, LOW);
}
void dithang()
{
  analogWrite(enbA, 200);
  analogWrite(enbB, 200);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);


}
void dunglai(){
  analogWrite(enbA, 0);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  }

void disangphai()
{
  analogWrite(enbA, 200);
  analogWrite(enbB, 0);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);


}
void disangtrai()
{
  analogWrite(enbA, 0);
  analogWrite(enbB, 200);
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}

void dilui()
{
  analogWrite(enbA, 200);
  analogWrite(enbB, 200);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

}

void xoay()
{
  analogWrite(enbA, 200);
  analogWrite(enbB, 200);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void xoaytrai()
{
  analogWrite(enbA, 200);
  analogWrite(enbB, 200);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}
void xoayphai()
{
  analogWrite(enbA, 200);
  analogWrite(enbB, 200);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);


}
