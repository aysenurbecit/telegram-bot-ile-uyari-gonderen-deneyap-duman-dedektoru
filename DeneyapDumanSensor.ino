#include <DeneyapTelegram.h>
#include <deneyap.h>
#include <WiFiClientSecure.h>
#include <WiFi.h>
#include <Deneyap_DumanDedektoru.h>                          

const char* ssid = "wifi adi";
const char* password = "wifi sifresi";

DeneyapTelegram telegram;
SmokeDetector DumanSensor;                                   // SmokeDetector için class tanımlaması

#define BOTtoken "Bot Token" // Telegram uygulaması üzerinden Botfather ile öğreneceğiz
#define CHAT_ID "Chat ID"                          // idbot ile telegram ID'sini öğrenerek buraya yazacağız

WiFiClientSecure client;

void setup() {
    Serial.begin(115200);                                    // Seri haberlesme baslatılması
    if (!DumanSensor.begin(0x20)) {                          
        delay(3000);
        Serial.println("I2C bağlantısı başarısız ");         // I2C bağlantısı başarısız olursa seri port ekranına yazdırılması
        while (1);
    }

 Serial.begin(115200);
  
  client.setInsecure();
  Serial.print("İnternete bağlanıyor: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi bağlandı");
  Serial.print("IP adresi: ");
  Serial.println(WiFi.localIP());
  telegram.begin(BOTtoken);
  telegram.send(CHAT_ID,"baglandı");

}

void loop() {
    bool dumanDurum = DumanSensor.ReadSmokeDigital();        // Duman durumu okunması
    if(dumanDurum == 1) {
      Serial.println("Duman Algılandı");   
    telegram.send(CHAT_ID,"duman algılandı");  // Duman algılanınca çıkış ledi yanacaktır
    }

    uint16_t dumanDeger = DumanSensor.ReadSmokeAnalog();     // Duman degeri okunması
    Serial.print("Duman Degeri:");
    Serial.println(dumanDeger);                              // Duman verisi seri port ekranına yazdırılması
    
  if(dumanDeger>350){
        telegram.send(CHAT_ID,"duman degeri: "+ String(dumanDeger)); 
  }                     
    delay(100);
}
