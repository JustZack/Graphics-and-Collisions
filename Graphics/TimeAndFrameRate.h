#pragma once
#include <SFML\Graphics.hpp>

class TimeAndFrameRate
{
private:
	//Used to know how many seconds have passed
	sf::Clock clock;
	//Font of the framerate text
	sf::Font font;
	//text used to draw the fps
	sf::Text frameRateText;
	//The totalruntime of the application
	double totalTime;
	//The interval at which the framerate is updated/calculated
	float timeInterval = .5f;
	//Temp time used to calculate avg framerate later
	float tempTime;
	//The total number of frames that have elapsed in the app
	double totalFrameCount;
	//The number of frames that have elapsed over the course of the timeInterval
	int tempFrameCount;

	//The currently calculated framerate
	float currentFrameRate;
	//How long the current frame took to render
	double MillisecondsSinceLastFrame;
public:
	//constructor
	TimeAndFrameRate();

	void setInterval(float TimeInterval);

	//Add to the accumulators of the object
	//Called every frame
	void Increment();

	//Return the current framerate
	float getCurrentFrameRate();
	//Return the time that the current frame took
	double getMillisecondsSinceLastFrame();
	//Get the frame time in fractional seconds
	float getFrameTime();
	//Return how long the app (specificaly this object) has been runing (instansiated)
	double getRunningtime();

	sf::Text& text();

	void Reset();
	void Start();
	void Stop();
};