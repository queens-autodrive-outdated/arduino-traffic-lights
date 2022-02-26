#include <WiFi.h>
#include <Arduino_JSON.h>
#include <HTTPClient.h>

const char *ssid = "";
const char *password = "";

void setup()
{
    Serial.begin(115200);
    delay(1000);

    WiFi.mode(WIFI_STA); // Optional
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(100);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        String server = "https://reqres.in/api/users/1";
        String response = get_request(server);
        Serial.println(response);
    }
}

String get_request(String server)
{
    HTTPClient http;
    http.begin(server);
    int httpResponseCode = http.GET();

    String payload = "{}";

    if (httpResponseCode > 0)
    {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    }
    else
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    http.end();

    return payload;
}
