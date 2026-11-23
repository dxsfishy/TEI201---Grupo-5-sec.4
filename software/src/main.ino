#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// ==========================================
// 1. CREDENCIALES RED DE CASA Y TELEGRAM
// ==========================================
#define WIFI_SSID "MartinWifi"
#define WIFI_PASSWORD "87654321"

#define BOT_TOKEN "8667908090:AAHpyvBpSDff9zamd00e4FZacTQ6FSBSp7M"
#define CHAT_ID "1905774350"

// ==========================================
// 2. CONFIGURACIÓN DE HARDWARE Y PINES
// ==========================================
#define PIN_HUMEDAD 4
#define PIN_LUZ 5 // Sensor KY-018 (LDR)

// Calibración Sensor de Humedad
#define RAW_SECO 2965
#define RAW_MOJADO 2300

#define UMBRAL_SECO 25
#define UMBRAL_OPTIMO 55
#define UMBRAL_HUMEDO 75

// Calibración Sensor de Luz KY-018
#define RAW_LUZ_OSCURO 3800 // Valor en oscuridad
#define RAW_LUZ_SOL 500     // Valor con luz intensa

// ==========================================
// 3. OBJETOS Y VARIABLES GLOBALES
// ==========================================
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

String estadoAnteriorHumedad = "";

// ==========================================
// FUNCIONES AUXILIARES
// ==========================================

// Promedio de lecturas analógicas para filtrar ruido
int leerAnalogicoFiltrado(int pin) {
  long suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += analogRead(pin);
    delay(10);
  }
  return suma / 10;
}

// Clasifica el nivel de luz
String obtenerEstadoLuz(int pctLuz) {
  if (pctLuz < 20) return "Oscuro 🌙";
  if (pctLuz < 60) return "Luz media ⛅";
  return "Mucha luz ☀️";
}

// Clasifica la humedad
void obtenerEstadoHumedad(int pctHumedad, String &texto, String &emoji) {
  if (pctHumedad < UMBRAL_SECO) {
    texto = "SECO";
    emoji = "🥵";
  } else if (pctHumedad < UMBRAL_OPTIMO) {
    texto = "ÓPTIMO";
    emoji = "🌱";
  } else if (pctHumedad < UMBRAL_HUMEDO) {
    texto = "HÚMEDO";
    emoji = "💧";
  } else {
    texto = "EMPAPADO";
    emoji = "🌊";
  }
}

// ==========================================
// SETUP
// ==========================================
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n--- Conectando a MartinWifi ---");

  // Configuración de WiFi estándar
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Conectando a ");
  Serial.print(WIFI_SSID);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("\n¡Conectado exitosamente a WiFi!");
  Serial.print("IP asignada: ");
  Serial.println(WiFi.localIP());

  // Desactivar verificación de certificado SSL para Telegram
  secured_client.setInsecure(); 
}

// ==========================================
// LOOP
// ==========================================
void loop() {
  // 1. LECTURA Y PROCESAMIENTO HUMEDAD (GPIO4)
  int rawHumedad = leerAnalogicoFiltrado(PIN_HUMEDAD);
  int pctHumedad = map(rawHumedad, RAW_SECO, RAW_MOJADO, 0, 100);
  pctHumedad = constrain(pctHumedad, 0, 100);

  String textoHum, emojiHum;
  obtenerEstadoHumedad(pctHumedad, textoHum, emojiHum);

  // 2. LECTURA Y PROCESAMIENTO LUZ KY-018 (GPIO5)
  int rawLuz = leerAnalogicoFiltrado(PIN_LUZ);
  int pctLuz = map(rawLuz, RAW_LUZ_OSCURO, RAW_LUZ_SOL, 0, 100);
  pctLuz = constrain(pctLuz, 0, 100);
  String estadoLuzText = obtenerEstadoLuz(pctLuz);

  // 3. LOGS EN SERIAL MONITOR
  Serial.printf("Humedad: %d%% (%s) [RAW: %d] | Luz: %d%% (%s) [RAW: %d]\n", 
                pctHumedad, textoHum.c_str(), rawHumedad, 
                pctLuz, estadoLuzText.c_str(), rawLuz);

  // 4. NOTIFICACIÓN A TELEGRAM (Al detectar cambio de categoría en la tierra)
  if (textoHum != estadoAnteriorHumedad) {
    Serial.println("Cambio de estado detectado. Enviando a Telegram...");

    String mensaje = "<b>Reporte de Planta " + emojiHum + "</b>\n\n";
    mensaje += "<b>Estado Tierra:</b> " + textoHum + "\n";
    mensaje += "<b>Humedad:</b> " + String(pctHumedad) + "%\n\n";
    mensaje += "<b>Luz Ambiente:</b> " + String(pctLuz) + "% (" + estadoLuzText + ")\n";
    mensaje += "<i>Red: Casa (MartinWifi)</i>";

    if (bot.sendMessage(CHAT_ID, mensaje, "HTML")) {
      Serial.println("-> Mensaje enviado a Telegram correctamente.");
    } else {
      Serial.println("-> Error al enviar a Telegram.");
    }

    estadoAnteriorHumedad = textoHum;
  }

  // Esperar 3 segundos entre lecturas
  delay(3000);
}
