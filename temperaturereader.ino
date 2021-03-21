// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h> // library used for my DHT11 temp and hum sensor

// help from: (my research in order of sites visited and researched)
// https://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
// https://docs.particle.io/tutorials/device-cloud/webhooks/
// https://docs.particle.io/reference/device-cloud/webhooks/
// https://www.w3schools.com/js/js_json_intro.asp
// https://www.hackster.io/iot-group-4/iot-project-temperature-and-humidity-sensing-395048
// https://docs.particle.io/quickstart/isk-project/
// https://docs.particle.io/workshops/photon-maker-kit-workshop/ch2/

#define DHTPIN D2     // what digital pin we're connected to
DHT dht(DHTPIN); // now we can just call dht throught the code.

unsigned long myChannelNumber = 1333868; // my ThingsSpeak channel
const char * myWriteAPIKey = "BQG243WSVCW8JFEG"; // my ThingsSpeak channel API Key

float temp; // create a float var for temperature
//, humidity; could have added
double temp_dbl; // create a double var for temperature and for 
					// Particle.variable() to work
//, humidity_dbl; could have added

void setup() {
    Serial.begin(9600); // set buad rate to 9600
    dht.begin(); // start up the dht sensor
    //Particle.variable("humidity", humidity_dbl);
	
	// Particle variable makes this temp_dbl visible to the particle console. Click GET to get the variables value
    Particle.variable("temp", temp_dbl); // NEEDS TO BE A DOUBLE. NOT A FLOAT "float is not supported as native type Particle.variable()."
}

void loop() {
    temp = dht.getTempCelcius(); // stores the temperature in celcius as a float type
    temp_dbl = temp; // converts and stores temperature from the float type as a double type 
    Particle.publish("temp", String(temp), PRIVATE); // what to publish on the particle console 
													// from the particle console will send to ThingsSpeak
    delay(10000); // delay for 10 secs
}
