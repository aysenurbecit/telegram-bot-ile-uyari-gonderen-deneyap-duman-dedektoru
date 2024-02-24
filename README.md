# telegram-bot-ile-uyari-gonderen-deneyap-duman-dedektoru
Deneyap kart ve Arduino ile geliştirilen bir duman dedektörü kullanarak Telegram botu ile duman durumunu izlemeyi sağlayan proje.

# Duman Dedektörü Telegram Botu

Bu proje, Deneyap platformu ve Arduino ile geliştirilen bir duman dedektörü kullanarak Telegram botu ile duman değerini izlemeyi amaçlamaktadır.

## Gereksinimler
- Deneyap Kart
- Deneyap Duman Dedektörü
- Arduino IDE
- WiFi bağlantısı

## Kurulum

1. Arduino IDE'yi açın.
2. Bu projenin dosyalarını indirin ve Arduino IDE'ye ekleyin.
3. WiFi ağınızın adını (SSID) ve şifresini `ssid` ve `password` değişkenlerine girin.
4. Telegram botunuzun token'ını ve chat ID'sini `BOTtoken` ve `CHAT_ID` değişkenlerine girin.

## Kullanım

1. Arduino'yu bilgisayara bağlayın.
2. Kodu Arduino'ya yükleyin.
3. Telegram botunuzu açın.
4. Duman dedektörü bir duman algılarsa, Telegram botunuza bildirim gönderilecektir.
