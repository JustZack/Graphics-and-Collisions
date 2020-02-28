#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include "TimeAndFrameRate.h"
#include "InputHandler.h"
#include "RenderAction.h"

class SimpleWindow {
public:
	SimpleWindow(const SimpleWindow&);
	SimpleWindow() : SimpleWindow(std::string("Untitled").c_str()) { }
	SimpleWindow(const char* title) : SimpleWindow(title, width, height) { }
	SimpleWindow(const char* title, int width, int height) : SimpleWindow(title, width, height, framerate_limit) { }
	SimpleWindow(const char* title, int width, int height, int framerate_limit);
	~SimpleWindow() = default;

	/* Starts up the window and begins the update loop. */
	void Start();

	/* Closes the window */
	void Stop();
	
	InputProcessor InputHandler;
	RenderAction onRender;
	TimeAndFrameRate FrameCounter;
	sf::RenderWindow Window;

	void ToggleFramerate();
	void ShowFramerate();
	void HideFramerate();

private:
	/* Runs every frame */
	void Render();

	bool showFrameRate = true;
	sf::Event window_event;
	const char* title = "Untitled";
	int framerate_limit = 60, width = 640, height = 640;
};