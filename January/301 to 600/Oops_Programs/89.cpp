#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


class WeatherStation;

class WeatherData {
public:
    time_t timestamp;
    double temperature;
    double humidity;
    double windSpeed;

    WeatherData(double temperature, double humidity, double windSpeed)
        : timestamp(time(nullptr)), temperature(temperature), humidity(humidity), windSpeed(windSpeed) {}
};

class Forecast {
public:
    double predictedTemperature;
    double predictedHumidity;
    double predictedWindSpeed;

    Forecast(double temp, double humidity, double windSpeed)
        : predictedTemperature(temp), predictedHumidity(humidity), predictedWindSpeed(windSpeed) {}
};

class WeatherStation {
public:
    string name;
    vector<WeatherData> weatherHistory;

    WeatherStation(const string& name) : name(name) {}

    void collectWeatherData(double temperature, double humidity, double windSpeed) {
        WeatherData data(temperature, humidity, windSpeed);
        weatherHistory.push_back(data);
    }

    Forecast generateForecast() const {
        
        if (weatherHistory.empty()) {
            return Forecast(0.0, 0.0, 0.0);
        }

        double avgTemp = 0.0, avgHumidity = 0.0, avgWindSpeed = 0.0;
        for (const auto& data : weatherHistory) {
            avgTemp += data.temperature;
            avgHumidity += data.humidity;
            avgWindSpeed += data.windSpeed;
        }

        avgTemp /= weatherHistory.size();
        avgHumidity /= weatherHistory.size();
        avgWindSpeed /= weatherHistory.size();

        return Forecast(avgTemp, avgHumidity, avgWindSpeed);
    }
};

int main() {
    WeatherStation station1("Station 1");
    WeatherStation station2("Station 2");

    
    station1.collectWeatherData(25.0, 60.0, 10.0);
    station1.collectWeatherData(28.0, 55.0, 12.0);
    station2.collectWeatherData(22.0, 70.0, 8.0);
    station2.collectWeatherData(20.0, 75.0, 9.0);

    
    Forecast forecast1 = station1.generateForecast();
    Forecast forecast2 = station2.generateForecast();

    
    cout << "Forecast for " << station1.name << ":" << endl;
    cout << "Temperature: " << forecast1.predictedTemperature << "°C, Humidity: " << forecast1.predictedHumidity << "%, Wind Speed: " << forecast1.predictedWindSpeed << " m/s" << endl;

    cout << "\nForecast for " << station2.name << ":" << endl;
    cout << "Temperature: " << forecast2.predictedTemperature << "°C, Humidity: " << forecast2.predictedHumidity << "%, Wind Speed: " << forecast2.predictedWindSpeed << " m/s" << endl;

    return 0;
}
