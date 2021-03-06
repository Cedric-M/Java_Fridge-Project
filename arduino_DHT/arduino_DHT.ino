//Libraries
#include <DHT.h>

//Constants
#define DHTPIN A0     // what pin we're connecPted to
#define DHTTYPE DHT22   // DHT 22  (AM2302)

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
int ledPin =9;
int i=0;


void setup(){
    Serial.begin(9600);
    dht.begin();
    pinMode(ledPin, OUTPUT);
}

void loop(){
  //DHT
    //Read data and store it to variables hum and temp
    float hum = dht.readHumidity();
    float temp= dht.readTemperature();
    
    //Print temp and humidity values to serial monitor with " 25.64;50.20" Format
    /*
    Serial.print("Humidité: ");
    Serial.print(hum);
    Serial.print(" %, Température: ");
    Serial.print(temp);
    Serial.println(" °C");
    delay(500); //Delay 2 sec.
    Serial.print("DATA;");*/
    Serial.print(temp);
    Serial.print(";");
    Serial.print(hum);
    Serial.print(";");
    Serial.println(point_rosee(hum,temp));

    delay(1000); //Delay 1 sec.*/
}

    double point_rosee(double humPR, double tempPR) {
      
      //Constants
      const double a = 17.27;
      const double b = 237.7;

      double temp = (a * tempPR) / (b + tempPR) + log(humPR * 0.01);
      return (b * temp) / (a - temp);
    }
