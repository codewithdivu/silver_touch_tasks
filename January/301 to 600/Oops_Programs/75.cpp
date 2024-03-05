#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Sensor {
public:
    string sensorType;

    Sensor(const string& type) : sensorType(type) {}

    double readData() const {
        
        return 25.5; 
    }
};

class WeatherData {
private:
    vector<Sensor> sensors;

public:
    void addSensor(const Sensor& sensor) {
        sensors.push_back(sensor);
    }

    double analyzeWeatherData() const {
        double averageTemperature = 0.0;

        for (const auto& sensor : sensors) {
            averageTemperature += sensor.readData();
        }

        averageTemperature /= sensors.size();
        return averageTemperature;
    }
};

class WeatherStation {
private:
    WeatherData weatherData;

public:
    void addSensor(const Sensor& sensor) {
        weatherData.addSensor(sensor);
    }

    double getAverageTemperature() const {
        return weatherData.analyzeWeatherData();
    }
};

int main() {
    Sensor temperatureSensor("Temperature");
    Sensor humiditySensor("Humidity");

    WeatherStation weatherStation;
    weatherStation.addSensor(temperatureSensor);
    weatherStation.addSensor(humiditySensor);

    double averageTemperature = weatherStation.getAverageTemperature();
    cout << "Average Temperature: " << averageTemperature << " degrees Celsius." << endl;

    return 0;
}
