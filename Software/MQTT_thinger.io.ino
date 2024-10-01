/* Tasmota-thinger.io-bridge by Laszlo Lebrun https://github.com/rin67630/Tasmota-thinger.io-bridge
   An open source solution for ESP8266 devices to bridge Tasmota devices to Thinger.io, providing dashboards and other nice benefits.
   License: GNU GPLV3.0  CC-SA-BY
*/
//----------------
// Placeholder credentials to be used with Python Patcher https://github.com/rin67630/ESP_Binary_patcher
// you may compile as is and patch later or change the credentials to upload from the compiler.


#if __has_include("Credentials.h")
#include "Credentials.h"
#else  // Placeholders credentials to be used with https://github.com/rin67630/ESP_Binary_patcher
#define DEVICE_NAME "DEVCNAME        "
#define WIFI_SSID "WIFISSID        "
#define WIFI_PASS "WIFIPASS                "
#define CLOUD_USERNAME "CLOUDNAM        "
#define DEVICE_CREDENTIALS "DEVCCRED        "
#define TZ_OFF "TZ_OFF  "   // Offset to GMT in secs (exactly 8  chars incl spaces)
#define DST_OFF "DST_OFF "  // Summer Offset in secs (exactly 8  chars incl spaces)
#define LONGTD "LONGTD  "   // Longitude             (exactly 8  chars incl spaces)
#define LATITD "LATITD  "   // Latitude              (exactly 8  chars incl spaces)
#define OPEN_WEATHER_MAP_APP_ID "GetYourId at OpenWeatherMaps.org"
#endif


// ***Weather server***


//Bucket Names (change for pay accounts only)
#define BUCKET_EVENT "EVENT"
#define BUCKET_MIN "MINUTE"
#define BUCKET_HOUR "HOUR"
#define BUCKET_DAY "DAY"

// Data provisonning
#define DEV1_IS_MQTT          //_IS_UDP, IS_MQTT  (UDP == Data from another RIN67630 device from the RIN67630's ecosystem)
#define DEV2_IS_MQTT          //_IS_UDP, IS_MQTT  (MQTT == Data from Tasmota devices or MQTT clients with Tasmota-like message formats)
#define DEV3_IS_MQTT          //_IS_UDP, IS_MQTT
#define DEV4_IS_MQTT          //_IS_UDP, IS_MQTT
#define DEV5_IS_SUM_1234      //_IS_SUM_123_MINUS4, _IS_SUM_1234 (How to compute Metadevice5)
#define DEFAULT_FREQUENCY 50  //for AC devices without frequency measurment

//includes
#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>
#include <PicoMQTT.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoOTA.h>
#include "time.h"  // built-in
#include "TZ.h"


// Macro to run things periodically
#define runEvery(t) for (static uint16_t _lasttime; \
                         (uint16_t)((uint16_t)millis() - _lasttime) >= (t); \
                         _lasttime += (t))

// Instanciations
ThingerESP8266 thing(CLOUD_USERNAME, DEVICE_NAME, DEVICE_CREDENTIALS);
PicoMQTT::Server mqtt;
HTTPClient http;
WiFiClient wifiClient;

static IPAddress ip;
static char charbuff[120];
String JSONpayload;

struct Device1 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Factor;
  float Frequency = DEFAULT_FREQUENCY;
  float Voltage;
  float Current;
  float Temperature;
  float Pressure;
  boolean RelayIn;
  boolean RelayOut;
} Device1;

struct Device2 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Factor;
  float Frequency = DEFAULT_FREQUENCY;
  float Voltage;
  float Current;
  float Temperature;
  float Humidity;
  float Pressure;
  boolean RelayIn;
  boolean RelayOut;
  byte Dummy;  // Dummy byte to change structure sizeof()
} Device2;

struct Device3 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Factor;
  float Frequency = DEFAULT_FREQUENCY;
  float Voltage;
  float Current;
  float Temperature;
  float Humidity;
  float Pressure;
  boolean RelayIn;
  boolean RelayOut;
  int Dummy;  // Dummy integer to change structure sizeof()
} Device3;

struct Device4 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Factor;
  float Frequency = DEFAULT_FREQUENCY;
  float Voltage;
  float Current;
  float Temperature;
  float Humidity;
  float Pressure;
  boolean RelayIn;
  boolean RelayOut;
  double Dummy;  // Dummy double to change structure sizeof()
} Device4;

// Device 5 is a meta device summarizing currents and powers, hence no other variables are included.
struct Device5 {
  float Total;
  float Yesterday;
  float Today;
  float Power;
  float Apparent;
  float Reactive;
  float Current;
} Device5;

// Room climate***
float roomTemperature;
float roomHumidity;
float roomPressure;


// ***Weather***
float temperature;
float humidity;
float pressure;
float wind_speed;
int wind_direction;
int cloudiness;
String weather_summary;
String openWeatherMapsURL = String("http://api.openweathermap.org/data/2.5/weather?units=metric&appid=") + OPEN_WEATHER_MAP_APP_ID + String("&lat=") + LATITD + String("&lon=") + LONGTD;

void getWIFI() {
  WiFi.hostname(DEVICE_NAME);
  Serial.printf("\n\n\n\nTry WiFi %s as %s", WIFI_SSID, DEVICE_NAME);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(1000); }
  Serial.print("\nWiFi connected to: ");
  ip = WiFi.localIP();
  Serial.println(ip);
}  // end getWIFI

void getWeather() {
  http.begin(wifiClient, openWeatherMapsURL);
  int httpCode2 = http.GET();
  if (httpCode2 == HTTP_CODE_OK) {
    JSONpayload = http.getString();
    JsonDocument doc;
    auto error = deserializeJson(doc, JSONpayload.c_str());
    if (not error) {
      temperature = doc["main"]["temp"];
      pressure = doc["main"]["pressure"];
      humidity = doc["main"]["humidity"];
      wind_speed = doc["wind"]["speed"];
      wind_direction = doc["wind"]["deg"];
      cloudiness = doc["clouds"]["all"];  // % Clouds
      const char* w = doc["weather"][0]["description"];
      weather_summary = w;
    }
  }
  http.end();
}  // end getWeather

void computeDevice5() {
#ifdef DEV5_IS_SUM_1234
  Device5.Total = Device1.Total + Device2.Total + Device3.Total + Device4.Total;
  Device5.Yesterday = Device1.Yesterday + Device2.Yesterday + Device3.Yesterday + Device4.Yesterday;
  Device5.Today = Device1.Today + Device2.Today + Device3.Today + Device4.Today;
  Device5.Power = Device1.Power + Device2.Power + Device3.Power + Device4.Power;
  Device1.Apparent = Device1.Power + Device2.Power + Device3.Power + Device4.Power;
  Device1.Reactive = Device1.Reactive + Device2.Reactive + Device3.Reactive + Device4.Reactive;
#endif
#ifdef DEV5_IS_SUM_123_MINUS4
  Device5.Total = Device1.Total + Device2.Total + Device3.Total - Device4.Total;
  Device5.Yesterday = Device1.Yesterday + Device2.Yesterday + Device3.Yesterday - Device4.Yesterday;
  Device5.Today = Device1.Today + Device2.Today + Device3.Today - Device4.Today;
  Device5.Power = Device1.Power + Device2.Power + Device3.Power - Device4.Power;
  Device1.Apparent = Device1.Power + Device2.Power + Device3.Power - Device4.Power;
  Device1.Reactive = Device1.Reactive + Device21.Reactive + Device3.Reactive - Device4.Reactive;
#endif
}

void initOTA() {
  if (WiFi.status() == WL_CONNECTED) {
    // Over the Air Framework
    ArduinoOTA.onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH) {
        type = "sketch";
      } else {  // U_FS
        type = "filesystem";
      }
      // NOTE: if updating FS this would be the place to unmount FS using FS.end()
      Serial.println("Start updating " + type);
    });
    ArduinoOTA.onEnd([]() {
      Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) {
        Serial.printf("Auth Failed\n");
      } else if (error == OTA_BEGIN_ERROR) {
        Serial.printf("Begin Failed\n");
      } else if (error == OTA_CONNECT_ERROR) {
        Serial.printf("Connect Failed\n");
      } else if (error == OTA_RECEIVE_ERROR) {
        Serial.printf("Receive Failed\n");
      } else if (error == OTA_END_ERROR) {
        Serial.printf("End Failed\n");
      }
    });
    ArduinoOTA.setHostname(DEVICE_NAME);
    ArduinoOTA.begin();
  }
}  //end initOTA

void togglePower() {
  // testing blinking on the second device
  mqtt.publish("cmnd/thinger2/Power2", "TOGGLE");
}

void setup() {
  // Setup serial
  Serial.begin(9600);
  Serial.flush();
  delay(1000);

  // Connect to WiFi
  getWIFI();
  delay(2000);
  mqtt.begin();


  // Subscribe to a topic and attach a callback
  mqtt.subscribe("tele/thinger#", [](const char* topic, const char* message) {
    Serial.print(topic);
    Serial.println(message);
    if (String(topic) == "tele/thinger1/SENSOR") {
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
      }
    }
    if (String(topic) == "tele/thinger2/SENSOR") {
      JsonDocument doc;
      auto error = deserializeJson(doc, message);
      if (not error) {
        Device2.Total = doc["ENERGY"]["Total"];
        Device2.Yesterday = doc["ENERGY"]["Yesterday"];
        Device2.Today = doc["ENERGY"]["Today"];
        Device2.Power = doc["ENERGY"]["Power"];
        Device2.Apparent = doc["ENERGY"]["ApparentPower"];
        Device2.Reactive = doc["ENERGY"]["ReactivePower"];
        Device2.Factor = doc["ENERGY"]["Factor"];
        Device2.Voltage = doc["ENERGY"]["Voltage"];
        Device2.Current = doc["ENERGY"]["Current"];
        Device2.Temperature = doc["ENERGY"]["Temperature"];
      }
    }
    if (String(topic) == "tele/thinger3/SENSOR") {
      JsonDocument doc;
      auto error = deserializeJson(doc, message);
      if (not error) {
        Device3.Total = doc["ENERGY"]["Total"];
        Device3.Yesterday = doc["ENERGY"]["Yesterday"];
        Device3.Today = doc["ENERGY"]["Today"];
        Device3.Power = doc["ENERGY"]["Power"];
        Device3.Apparent = doc["ENERGY"]["ApparentPower"];
        Device3.Reactive = doc["ENERGY"]["ReactivePower"];
        Device3.Factor = doc["ENERGY"]["Factor"];
        Device3.Voltage = doc["ENERGY"]["Voltage"];
        Device3.Current = doc["ENERGY"]["Current"];
        Device3.Temperature = doc["ANALOG"]["Temperature"];
      }
    }
    if (String(topic) == "tele/thinger4/SENSOR") {
      JsonDocument doc;
      auto error = deserializeJson(doc, message);
      if (not error) {
        Device4.Total = doc["ENERGY"]["Total"];
        Device4.Yesterday = doc["ENERGY"]["Yesterday"];
        Device4.Today = doc["ENERGY"]["Today"];
        Device4.Power = doc["ENERGY"]["Power"];
        Device4.Apparent = doc["ENERGY"]["ApparentPower"];
        Device4.Reactive = doc["ENERGY"]["ReactivePower"];
        Device4.Factor = doc["ENERGY"]["Factor"];
        Device4.Voltage = doc["ENERGY"]["Voltage"];
        Device4.Current = doc["ENERGY"]["Current"];
        Device4.Temperature = doc["ANALOG"]["Temperature"];
      }
    }
  });

  thing["toggleDevice2.2"] = []() {
    mqtt.publish("cmnd/thinger2/Power2", "TOGGLE");
  };

  thing["toggleDevice1.1"] = []() {
    mqtt.publish("cmnd/thinger1/Power1", "TOGGLE");
  };


  thing["measure"] >> [](pson& out) {
    out["Voltage1"] = Device1.Voltage;
    out["Current1"] = Device1.Current;
    out["Frequency1"] = Device1.Frequency;
    out["MeasPower1"] = Device1.Power;
    out["ReaPower1"] = Device1.Reactive;
    out["AppPower1"] = Device1.Apparent;
    out["Yesterday1"] = Device1.Yesterday;
    out["Today1"] = Device1.Today;
    out["Total1"] = Device1.Total;
    out["Factor1"] = Device1.Factor;
    out["Temperature1"] = Device1.Temperature;

    out["Voltage2"] = Device2.Voltage;
    out["Current2"] = Device2.Current;
    out["Frequency2"] = Device2.Frequency;
    out["MeasPower2"] = Device2.Power;
    out["ReaPower2"] = Device2.Reactive;
    out["AppPower2"] = Device2.Apparent;
    out["Yesterday2"] = Device2.Yesterday;
    out["Today2"] = Device2.Today;
    out["Total2"] = Device2.Total;
    out["Factor2"] = Device2.Factor;
    out["Temperature2"] = Device2.Temperature;

    out["Voltage3"] = Device3.Voltage;
    out["Current3"] = Device3.Current;
    out["Frequency3"] = Device3.Frequency;
    out["MeasPower3"] = Device3.Power;
    out["ReaPower3"] = Device3.Reactive;
    out["AppPower3"] = Device3.Apparent;
    out["Yesterday3"] = Device3.Yesterday;
    out["Today3"] = Device3.Today;
    out["Total3"] = Device3.Total;
    out["Factor3"] = Device3.Factor;
    out["Temperature3"] = Device3.Temperature;

    out["Voltage4"] = Device4.Voltage;
    out["Current4"] = Device4.Current;
    out["Frequency4"] = Device4.Frequency;
    out["MeasPower4"] = Device4.Power;
    out["ReaPower4"] = Device4.Reactive;
    out["AppPower4"] = Device4.Apparent;
    out["Yesterday4"] = Device4.Yesterday;
    out["Today4"] = Device4.Today;
    out["Total4"] = Device4.Total;
    out["Factor4"] = Device4.Factor;
    out["Temperature4"] = Device4.Temperature;

    out["MeasPower5"] = Device5.Power;
    out["ReaPower5"] = Device5.Reactive;
    out["AppPower5"] = Device5.Apparent;
    out["Yesterday5"] = Device5.Yesterday;
    out["Today5"] = Device5.Today;
    out["Total5"] = Device5.Total;

    out["temperature"] = temperature;
    out["humidity"] = humidity;
    out["pressure"] = pressure;
    out["wind"] = wind_speed;
    out["direction"] = wind_direction;
    out["summary"] = weather_summary;
  };

  pson whoami;  //Setting IP and Version reminder property on thinger
  whoami["IP"] = WiFi.localIP().toString();
  whoami["MAC"] = WiFi.macAddress();
  whoami["HOST"] = WiFi.hostname();
  whoami["Soft"] = __FILE__;
  whoami["Date"] = __DATE__;
  whoami["Time"] = __TIME__;
  // whoami["WURL"] = openWeatherMapsURL;
  thing.set_property("whoami", whoami, true);

  getWeather();  // Get initial Weather data
  initOTA();
  Serial.print("Start OTA, ");
  ArduinoOTA.begin();
  delay(500);

}  //end setup

void loop() {
  mqtt.loop();
  thing.handle();
  ArduinoOTA.handle();
  runEvery(10000) {
    computeDevice5();
  }  // Compute values for meta-device 5
  runEvery(1000000) {
    getWeather();
  }  // Get Weather data every ~18 minutes
  runEvery(60000) {
    thing.write_bucket(BUCKET_MIN, "measure");
  }  // Write minutely bucket data.
  runEvery(3000) {
    // togglePower();
  }
}
