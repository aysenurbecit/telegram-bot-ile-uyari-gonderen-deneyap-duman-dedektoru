#include <deneyap.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <Deneyap_DumanDedektoru.h>                          


const char* ssid = "WiFi Adi";
const char* password = "WiFi Sifresi";

SmokeDetector DumanSensor;                                   // SmokeDetector için class tanımlaması

#define BOTtoken "000000000000000000000000000000000" // Telegram uygulaması üzerinden Botfather ile öğreneceğiz
#define CHAT_ID "000000000"                          // idbot ile telegram ID'sini öğrenerek buraya yazacağız

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

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
  bot.sendMessage(CHAT_ID, "Cihaz Aktif.", "");

}

void loop() {
    bool dumanDurum = DumanSensor.ReadSmokeDigital();        // Duman durumu okunması
    if(dumanDurum == 1) {
      Serial.println("Duman Algılandı");   
       bot.sendMessage(CHAT_ID, "duman algilandi");          // Duman algılanınca çıkış ledi yanacaktır
    }

    uint16_t dumanDeger = DumanSensor.ReadSmokeAnalog();     // Duman degeri okunması
    Serial.print("Duman Degeri:");
    Serial.println(dumanDeger);                              // Duman verisi seri port ekranına yazdırılması
    bot.sendMessage(CHAT_ID, "duman degeri:");  
    String deger;
    deger=dumanDeger;
    bot.sendMessage(CHAT_ID, deger);                         
    delay(10);
}
