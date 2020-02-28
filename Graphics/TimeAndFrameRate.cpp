#include "TimeAndFrameRate.h"
#include <iostream>
#include "UtilityMethods.h"

TimeAndFrameRate::TimeAndFrameRate()
{
	totalTime = .0f;
	timeInterval = 1.0f;
	tempTime = .0f;
	currentFrameRate = .0f;
	MillisecondsSinceLastFrame = .0f;
	totalFrameCount = 0;
	tempFrameCount = 0;

	frameRateText.setPosition(0, 0);
	frameRateText.setFillColor(sf::Color::Green);
	frameRateText.setStyle(sf::Text::Regular);
	frameRateText.setCharacterSize(15);
	font.loadFromFile("arial.ttf");
	frameRateText.setFont(font);
}

void TimeAndFrameRate::setInterval(float TimeInterval)
{
	timeInterval = TimeInterval;
}

void TimeAndFrameRate::Increment()
{
	MillisecondsSinceLastFrame = clock.restart().asMilliseconds();
	totalTime += MillisecondsSinceLastFrame;
	tempTime += MillisecondsSinceLastFrame;
	totalFrameCount++; tempFrameCount++;
	
	if (tempTime >= timeInterval)
	{
		currentFrameRate = tempFrameCount / (tempTime / 1000.f);
		tempFrameCount = 0;
		tempTime = 0.f;
	}
	
	frameRateText.setString(std::to_string((int)currentFrameRate));
}

float TimeAndFrameRate::getCurrentFrameRate()
{
	return currentFrameRate;
}

double TimeAndFrameRate::getMillisecondsSinceLastFrame()
{
	return MillisecondsSinceLastFrame;
}
float TimeAndFrameRate::getFrameTime() {
	return MillisecondsSinceLastFrame / 1000.f;
}

double TimeAndFrameRate::getRunningtime()
{
	return totalTime;
}

sf::Text& TimeAndFrameRate::text()
{
	return frameRateText;
}

void TimeAndFrameRate::Reset()
{
	totalTime = 0.f;
	clock.restart();
}

void TimeAndFrameRate::Start()
{
	this->Reset();
}

void TimeAndFrameRate::Stop()
{
	this->Reset();
}
