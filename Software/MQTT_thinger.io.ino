// Placeholder credentials to be used with Python Patcher.

#define DEVICE_NAME             "DEVCNAME        " 
#define WIFI_SSID               "WIFISSID        "
#define WIFI_PASS               "WIFIPASS                "
#define CLOUD_USERNAME          "CLOUDNAM        "
#define DEVICE_CREDENTIALS      "DEVCCRED        "
#define TZ_OFF                  "TZ_OFF  "        // Offset to GMT in secs (exactly 8  chars incl spaces)
#define DST_OFF                 "DST_OFF "        // Summer Offset in secs (exactly 8  chars incl spaces)
#define LONGTD                  "LONGTD  "        // Longitude             (exactly 8  chars incl spaces)
#define LATITD                  "LATITD  "        // Latitude              (exactly 8  chars incl spaces)

//Bucket Names (for pay accounts only)
#define BUCKET_EVENT "EVENT"
#define BUCKET_MIN "MIN"
#define BUCKET_HOUR "HOUR"
#define BUCKET_DAY "DAY"

#define DEFAULT_FREQUENCY 50

#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>
#include <PicoMQTT.h>
#include <ArduinoJson.h>


ThingerESP8266 thing(CLOUD_USERNAME, DEVICE_NAME, DEVICE_CREDENTIALS);
PicoMQTT::Server mqtt;

static IPAddress ip;
static char charbuff[120];

struct Device1 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Factor;
  float Voltage;
  float Current;
  float Temperature;
  float Humidity;
  float Pressure;
  float Windspeed;
  float Winddirection;
} Device1;

struct Device2 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Factor;
  float Voltage;
  float Current;
  float Temperature;
  float Humidity;
  float Pressure;
  float Windspeed;
  float Winddirection;
} Device2;

struct Device3 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Factor;
  float Voltage;
  float Current;
  float Temperature;
  float Humidity;
  float Pressure;
  float Windspeed;
  float Winddirection;
} Device3;

struct Device4 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Factor;
  float Voltage;
  float Current;
  float Temperature;
  float Humidity;
  float Pressure;
  float Windspeed;
  float Winddirection;
} Device4;

void getWIFI() {
  WiFi.hostname(DEVICE_NAME);
  Serial.printf("\n\n\n\nTry WiFi %s as %s", WIFI_SSID, DEVICE_NAME);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(1000); }
  Serial.print("\nWiFi connected to: ");
  ip = WiFi.localIP();
  Serial.println(ip);
}

void setup() {
  WiFi.hostname(DEVICE_NAME);
  // Setup serial
  Serial.begin(9600);
  delay(1000);

  // Connect to WiFi
  getWIFI();
  delay(2000);

  // Subscribe to a topic and attach a callback
  mqtt.subscribe("#", [](const char* topic, const char* message) 
  {
    if (String(topic) == "tele/thinger1/SENSOR") {
      Serial.print(topic);
      Serial.println(message);

      JsonDocument doc;
      auto error = deserializeJson(doc, message);
      if (not error) {
        Device1.Total = doc["ENERGY"]["Total"];
        Device1.Yesterday = doc["ENERGY"]["Yesterday"];
        Device1.Today = doc["ENERGY"]["Today"];
        Device1.Power = doc["ENERGY"]["Power"];
        Device1.Apparent = doc["ENERGY"]["ApparentPower"];
        Device1.Reactive = doc["ENERGY"]["Reactive Power"];
        Device1.Factor = doc["ENERGY"]["Factor"];
        Device1.Voltage = doc["ENERGY"]["Voltage"];
        Device1.Current = doc["ENERGY"]["Current"];
        Device1.Temperature = doc["ANALOG"]["Temperature"];
        Device1.Humidity = doc["ANALOG"]["Humidity"];
        Device1.Pressure = doc["ANALOG"]["Pressure"];
        Device1.Windspeed = doc["ANALOG"]["Windspeed"];
        Device1.Winddirection = doc["ANALOG"]["Winddirection"];
      }
    }
    if (String(topic) == "tele/thinger2/SENSOR") {
      Serial.print(topic);
      Serial.println(message);

      JsonDocument doc;
      auto error = deserializeJson(doc, message);
      if (not error) {
        Device2.Total = doc["ENERGY"]["Total"];
        Device2.Yesterday = doc["ENERGY"]["Yesterday"];
        Device2.Today = doc["ENERGY"]["Today"];
        Device2.Power = doc["ENERGY"]["Power"];
        Device2.Apparent = doc["ENERGY"]["ApparentPower"];
        Device2.Reactive = doc["ENERGY"]["Reactive Power"];
        Device2.Factor = doc["ENERGY"]["Factor"];
        Device2.Voltage = doc["ENERGY"]["Voltage"];
        Device2.Current = doc["ENERGY"]["Current"];
        Device2.Temperature = doc["ENERGY"]["Temperature"];
        Device2.Humidity = doc["ANALOG"]["Humidity"];
        Device2.Pressure = doc["ANALOG"]["Pressure"];
        Device2.Windspeed = doc["ANALOG"]["Windspeed"];
        Device2.Winddirection = doc["ANALOG"]["Winddirection"];        
      }
    }
    if (String(topic) == "tele/thinger3/SENSOR") {
      Serial.print(topic);
      Serial.println(message);

      JsonDocument doc;
      auto error = deserializeJson(doc, message);
      if (not error) {
        Device3.Total = doc["ENERGY"]["Total"];
        Device3.Yesterday = doc["ENERGY"]["Yesterday"];
        Device3.Today = doc["ENERGY"]["Today"];
        Device3.Power = doc["ENERGY"]["Power"];
        Device3.Apparent = doc["ENERGY"]["ApparentPower"];
        Device3.Reactive = doc["ENERGY"]["Reactive Power"];
        Device3.Factor = doc["ENERGY"]["Factor"];
        Device3.Voltage = doc["ENERGY"]["Voltage"];
        Device3.Current = doc["ENERGY"]["Current"];
        Device3.Temperature = doc["ANALOG"]["Temperature"];
        Device3.Humidity = doc["ANALOG"]["Humidity"];
        Device3.Pressure = doc["ANALOG"]["Pressure"];
        Device3.Windspeed = doc["ANALOG"]["Windspeed"];
        Device3.Winddirection = doc["ANALOG"]["Winddirection"];        
      }
    }
    if (String(topic) == "tele/thinger4/SENSOR") {
      Serial.print(topic);
      Serial.println(message);

      JsonDocument doc;
      auto error = deserializeJson(doc, message);
      if (not error) {
        Device4.Total = doc["ENERGY"]["Total"];
        Device4.Yesterday = doc["ENERGY"]["Yesterday"];
        Device4.Today = doc["ENERGY"]["Today"];
        Device4.Power = doc["ENERGY"]["Power"];
        Device4.Apparent = doc["ENERGY"]["ApparentPower"];
        Device4.Reactive = doc["ENERGY"]["Reactive Power"];
        Device4.Factor = doc["ENERGY"]["Factor"];
        Device4.Voltage = doc["ENERGY"]["Voltage"];
        Device4.Current = doc["ENERGY"]["Current"];
        Device4.Temperature = doc["ANALOG"]["Temperature"];
        Device4.Humidity = doc["ANALOG"]["Humidity"];
        Device4.Pressure = doc["ANALOG"]["Pressure"];
        Device4.Windspeed = doc["ANALOG"]["Windspeed"];
        Device4.Winddirection = doc["ANALOG"]["Winddirection"];        
      }
    }
  });

  mqtt.begin();

  thing["measure"] >> [](pson& out) 
  {
    out["Voltage1"] = Device1.Voltage;
    out["Current1"] = Device1.Current;
    out["Frequency1"] = DEFAULT_FREQUENCY;
    out["MeasPower1"] = Device1.Power;
    out["ReaPower1"] = Device1.Reactive;
    out["AppPower1"] = Device1.Apparent;
    out["Yesterday1"] = Device1.Yesterday;
    out["Today1"] = Device1.Today;
    out["Total1"] = Device1.Total;
    out["Factor1"] = Device1.Factor;
    out["Temperature1"] = Device1.Temperature;
    out["Humidity1"] = Device1.Humidity;
    out["Pressure1"] = Device1.Pressure;
    out["Windspeed1"] = Device1.Windspeed;
    out["Winddirection1"] = Device1.Winddirection;

    out["Voltage2"] = Device1.Voltage;
    out["Current2"] = Device1.Current;
    out["Frequency2"] = DEFAULT_FREQUENCY;
    out["MeasPower2"] = Device1.Power;
    out["ReaPower2"] = Device1.Reactive;
    out["AppPower2"] = Device1.Apparent;
    out["Yesterday2"] = Device1.Yesterday;
    out["Today2"] = Device1.Today;
    out["Total2"] = Device1.Total;
    out["Factor2"] = Device1.Factor;
    out["Temperature2"] = Device2.Temperature;
    out["Humidity2"] = Device2.Humidity;
    out["Pressure2"] = Device2.Pressure;
    out["Windspeed2"] = Device2.Windspeed;
    out["Winddirection2"] = Device2.Winddirection;

    out["Voltage3"] = Device1.Voltage;
    out["Current3"] = Device1.Current;
    out["Frequency3"] = DEFAULT_FREQUENCY;
    out["MeasPower3"] = Device1.Power;
    out["ReaPower3"] = Device1.Reactive;
    out["AppPower3"] = Device1.Apparent;
    out["Yesterday3"] = Device1.Yesterday;
    out["Today3"] = Device1.Today;
    out["Total3"] = Device1.Total;
    out["Factor3"] = Device1.Factor;
    out["Temperature3"] = Device3.Temperature;
    out["Humidity3"] = Device3.Humidity;
    out["Pressure3"] = Device3.Pressure;
    out["Windspeed3"] = Device3.Windspeed;
    out["Winddirection3"] = Device3.Winddirection;    
    
    out["Voltage4"] = Device1.Voltage;
    out["Current4"] = Device1.Current;
    out["Frequency4"] = DEFAULT_FREQUENCY;
    out["MeasPower4"] = Device1.Power;
    out["ReaPower4"] = Device1.Reactive;
    out["AppPower4"] = Device1.Apparent;
    out["Yesterday4"] = Device1.Yesterday;
    out["Today4"] = Device1.Today;
    out["Total4"] = Device1.Total;
    out["Factor4"] = Device1.Factor;
    out["Temperature4"] = Device4.Temperature;
    out["Humidity4"] = Device4.Humidity;
    out["Pressure4"] = Device4.Pressure;
    out["Windspeed4"] = Device4.Windspeed;
    out["Winddirection4"] = Device4.Winddirection;    
  };
}

void loop() {
  mqtt.loop();
  thing.handle();
}
