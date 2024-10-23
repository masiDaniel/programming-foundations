import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      debugShowCheckedModeBanner: false,
      home: WeatherScreen(),
    );
  }
}

class WeatherScreen extends StatefulWidget {
  const WeatherScreen({super.key});

  @override
  _WeatherScreenState createState() => _WeatherScreenState();
}

class _WeatherScreenState extends State<WeatherScreen> {
  String _cityName = 'London';
  String _temperature = '';
  String _humidity = '';
  String _windSpeed = '';
  String _weatherIcon = '';

  final TextEditingController _controller = TextEditingController();

  @override
  void initState() {
    super.initState();
    _fetchWeather();
  }

  void _fetchWeather() async {
    try {
      final response = await http.get(Uri.parse(
          'http://api.openweathermap.org/data/2.5/weather?q=$_cityName&appid=d4b51b3b0234d1c3f5bc767659e10616&units=metric'));

      if (response.statusCode == 200) {
        final data = json.decode(response.body);
        setState(() {
          _temperature = data['main']['temp'].toString();
          _humidity = data['main']['humidity'].toString();
          _windSpeed = data['wind']['speed'].toString();
          _weatherIcon = data['weather'][0]['icon'];
        });
      } else {
        throw Exception("Failed to load weather");
      }
    } catch (e) {
      setState(() {
        _temperature = 'Error fetching weather';
        _humidity = '';
        _windSpeed = '';
        _weatherIcon = '';
      });
    }
  }

  Widget _buildWeatherInfo(String label, String value) {
    return Container(
      padding: const EdgeInsets.symmetric(vertical: 8.0),
      decoration: BoxDecoration(
        color: Colors.amber,
        borderRadius: BorderRadius.circular(16),
        boxShadow: [
          BoxShadow(
            color: Colors.grey.withOpacity(0.5),
            spreadRadius: 2,
            blurRadius: 5,
            offset: const Offset(0, 3),
          ),
        ],
      ),
      child: SizedBox(
        height: 150,
        width: 150,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              label,
              style: const TextStyle(fontSize: 20),
            ),
            const SizedBox(
              height: 5,
            ),
            Text(
              value,
              style: const TextStyle(fontSize: 20),
            ),
          ],
        ),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text("Weather App")),
      body: Center(
        child: SingleChildScrollView(
          scrollDirection: Axis.vertical,
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.center,
            children: [
              SizedBox(
                width: 200,
                height: 50,
                child: TextField(
                  controller: _controller,
                  decoration: InputDecoration(
                      labelText: "Enter city name",
                      suffixIcon: IconButton(
                          onPressed: () {
                            setState(() {
                              _cityName = _controller.text;
                              _fetchWeather();
                            });
                          },
                          icon: const Icon(Icons.search))),
                ),
              ),
              const SizedBox(
                height: 20,
              ),
              Text(
                'City: $_cityName',
                style: const TextStyle(fontSize: 24),
              ),
              if (_weatherIcon.isNotEmpty)
                Image.network(
                    'http://openweathermap.org/img/w/$_weatherIcon.png'),
              Padding(
                padding: const EdgeInsets.all(20),
                child: GridView.count(
                  crossAxisCount: 2,
                  shrinkWrap: true,
                  physics: const NeverScrollableScrollPhysics(),
                  mainAxisSpacing: 15,
                  crossAxisSpacing: 15,
                  children: [
                    _buildWeatherInfo('City: ', _cityName),
                    _buildWeatherInfo('Temperature: ', '$_temperature°C'),
                    _buildWeatherInfo('Humidity: ', '$_humidity%'),
                    _buildWeatherInfo('Wind Speed: ', '$_windSpeed m/s'),
                  ],
                ),
              ),
              const SizedBox(
                height: 8,
              ),
              const SizedBox(
                height: 8,
              ),
              const SizedBox(
                height: 8,
              ),
              const SizedBox(
                height: 8,
              ),
              const SizedBox(height: 20),
              ElevatedButton(
                onPressed: _fetchWeather,
                child: const Text('Refresh'),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
