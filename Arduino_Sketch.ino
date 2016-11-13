int relais=2;
int temp;
String val;
int open_door=4;
int close_door=5;
int open_win=7;
int close_win=8;
int fan=10;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
Serial.begin(9600);
pinMode(relais,OUTPUT);
pinMode(open_door,OUTPUT);
pinMode(close_door,OUTPUT);
pinMode(open_win,OUTPUT);
pinMode(close_win,OUTPUT);
pinMode(fan,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
temp=analogRead(A0);
temp=temp*5/1024;
temp=temp*100;
temp=273-temp;
temp-=50;
Serial.println(temp);
delay(1000);
 String(temp, DEC);
if(Serial.available()){
  val=Serial.readStringUntil('\n');
  val.replace('\n','\0');
  val.replace('\r','\0');
  val.trim();
  if (val.equals("A"))  digitalWrite(relais,HIGH);
   if (val.equals("B"))  digitalWrite(relais,LOW);  
   if (val.equals("C")) { digitalWrite(close_door,LOW);digitalWrite(open_door,HIGH);delay(800); digitalWrite(open_door,LOW);}  
   if (val.equals("D")) { digitalWrite(open_door,LOW);  digitalWrite(close_door,HIGH);delay(800); digitalWrite(close_door,LOW);}
   if (val.equals("E")) { digitalWrite(close_win,LOW); digitalWrite(open_win,HIGH);delay(800); digitalWrite(open_win,LOW);}
   if (val.equals("F")) { digitalWrite(open_win,LOW);digitalWrite(close_win,HIGH);delay(400); digitalWrite(close_win,LOW); }
  if (val.equals("G"))  digitalWrite(fan,HIGH);
  if (val.equals("H") ) digitalWrite(fan,LOW);}
  
  
  }

