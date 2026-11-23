#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Credenciales WiFi y Telegram
#define WIFI_SSID     "MartinWifi"
#define WIFI_PASSWORD "87654321"
#define BOT_TOKEN     "8667908090:AAHpyvBpSDff9zamd00e4FZacTQ6FSBSp7M"
#define CHAT_ID       "1905774350"

// Pines de sensores
#define PIN_HUMEDAD 4
#define PIN_LUZ     5

// Calibración
#define RAW_SECO       2965
#define RAW_MOJADO     2300
#define RAW_LUZ_OSCURO 3800
#define RAW_LUZ_SOL    500

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

int leerAnalogicoFiltrado(int pin) {
  long suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += analogRead(pin);
    delay(10);
  }
  return suma / 10;
}

String clasificarHumedad(int pct) {
  if (pct < 25) return "SECO";
  if (pct < 55) return "OPTIMO";
  if (pct < 75) return "HUMEDO";
  return "EMPAPADO";
}

String clasificarLuz(int pct) {
  if (pct < 20) return "Oscuro";
  if (pct < 60) return "Luz media";
  return "Mucha luz";
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
  secured_client.setInsecure();
}

void loop() {
  int rawHum = leerAnalogicoFiltrado(PIN_HUMEDAD);
  int pctHum = constrain(map(rawHum, RAW_SECO, RAW_MOJADO, 0, 100), 0, 100);

  int rawLuz = leerAnalogicoFiltrado(PIN_LUZ);
  int pctLuz = constrain(map(rawLuz, RAW_LUZ_OSCURO, RAW_LUZ_SOL, 0, 100), 0, 100);

  String estadoHum = clasificarHumedad(pctHum);
  String estadoLuz = clasificarLuz(pctLuz);

  Serial.printf("Humedad: %d%% (%s) | Luz: %d%% (%s)\n", pctHum, estadoHum.c_str(), pctLuz, estadoLuz.c_str());

  // En v2 se enviaba un mensaje periódico de prueba cada 15 segundos
  String msg = "Lectura v2 -> Humedad: " + String(pctHum) + "% (" + estadoHum + ") | Luz: " + String(pctLuz) + "%";
  bot.sendMessage(CHAT_ID, msg, "");

  delay(15000);
}
