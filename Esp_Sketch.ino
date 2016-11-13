#include <ESP8266WiFi.h>

const char* ssid = "YOURSSID";
const char* password = "YOUR_PASSWORD";
String temp;

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin(ssid,password);
/*WiFi.softAP(ssid, password);
IPAddress myIP = WiFi.softAPIP();
Serial.print("AP IP address: ");
  Serial.println(myIP); */
  server.begin();
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");}
  //Serial.println("WiFi connected");
  
  Serial.println("Server started");  
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
void loop() {
 WiFiClient client = server.available();
  if (!client) {
   return;
  }
    while(!client.available()){
    delay(1);
  }
  String request = client.readStringUntil('\n');
   client.flush();
    if (request.indexOf("/Lamp=ON") != -1) {Serial.println("A\n"); }
    if (request.indexOf("/Lamp=OFF") != -1){ Serial.println("B\n");}
     if (request.indexOf("/Door=Open") != -1) {Serial.println("C\n"); }
    if (request.indexOf("/Door=Close") != -1){ Serial.println("D\n");} 
     if (request.indexOf("/Window=Open") != -1) {Serial.println("E\n"); }
    if (request.indexOf("/Window=Close") != -1){ Serial.println("F\n");} 
     if (request.indexOf("/fan=Start") != -1) {Serial.println("G\n"); }
    if (request.indexOf("/fan=Stop") != -1){ Serial.println("H\n");} 
  if (Serial.available()){
    temp = Serial.readStringUntil('\n');
      temp.replace('\r','\0');
      temp.replace('\n','\0');
      temp.trim();}
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<center>");
  client.println("<H1>Application Domotique</H1>");
   client.println("<br><br>");
   client.print("<H2>Temperature:");
   client.print(temp);
   client.print("C</H2>");
   client.println("<br><br>");
  client.println("<button onclick='location.href=\"/Lamp=ON\";'>Switch ON</button>");
  client.println("<button onclick='location.href=\"/Lamp=OFF\";'>Switch OFF</button>"); 

  client.println("<button onclick='location.href=\"/Door=Open\";'>Open Door</button>");
  client.println("<button onclick='location.href=\"/Door=Close\";'>Close Door</button>"); 
  client.println("<button onclick='location.href=\"/Window=Open\";'>Open Window</button>");
  client.println("<button onclick='location.href=\"/Window=Close\";'>Close Window</button>"); 

  client.println("<button onclick='location.href=\"/fan=Start\";'>Start fan</button>");
  client.println("<button onclick='location.href=\"/fan=Stop\";'>Stop fan</button>"); 
  client.print("</center>");
  client.println("</html>");
}
