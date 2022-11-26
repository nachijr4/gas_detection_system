#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int analogPin = A1;
int val;
int back = 10;
int out=13;

const char* ssid = "hotspot"
const char* pass = "personalhotspot"

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Print a message to the LCD.
  lcd.clear();
  pinMode(back,OUTPUT);
  pinMode(out,OUTPUT);

   Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
  
}

void loop() {
  int brightness=1;
  analogWrite(back,brightness); 
  delay(1000);
  val = analogRead(analogPin);
  lcd.print(val);
  if(val>10)
  {
    digitalWrite(out,HIGH);
    Serial.println(val);
    publishData(val)
  }
  delay(500);
  lcd.clear();
}

void publishDate(int val) {
    publish_url = 'https://' + args.endpoint + ':8443/topics/gas_quality';
    publish_msg = args.message.encode('utf-8')

    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
    
      http.begin(client, publish_url);
      
      
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      String httpRequestData = "api_key=tPmAT5Ab3j7F9&sensor=GAS&value1=" + val;           
      int httpResponseCode = http.POST(httpRequestData);
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      http.end();
    }
}
