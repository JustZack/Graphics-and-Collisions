#include "SimpleWindow.h"

SimpleWindow::SimpleWindow(const SimpleWindow& Window) {
	this->InputHandler = Window.InputHandler;
	this->onRender = Window.onRender;
	this->FrameCounter = Window.FrameCounter;
	this->Window.create(Window.Window.getSystemHandle());
	this->showFrameRate = Window.showFrameRate;
	this->window_event = Window.window_event;
	this->title = Window.title;
	this->framerate_limit = Window.framerate_limit;
	this->width = Window.width;
	this->height = Window.height;
}

SimpleWindow::SimpleWindow(const char* title, int width, int height, int framerate_limit) : width(width), height(height), 
					       framerate_limit(framerate_limit), title(title), Window(sf::VideoMode(width, height), title) {
	this->Window.setFramerateLimit(framerate_limit);
	
	this->onRender.SetWindow(&this->Window);

	this->window_event = sf::Event();
}

void SimpleWindow::Start() {
	//Begins collection frame rate information
	FrameCounter.Start();
	//Kicks off the rendering process
	this->Render();
}
void SimpleWindow::Stop() {
	FrameCounter.Stop();
	this->Window.close();
}

void SimpleWindow::Render() {
	while (this->Window.isOpen()) {
		while (this->Window.pollEvent(this->window_event)) {
			if (this->window_event.type == sf::Event::Closed) {
				this->Stop();
			}
		}

		this->Window.clear();

		this->InputHandler.ProcessInput();

		if (this->showFrameRate) 
			this->Window.draw(FrameCounter.text());
		
		//Calls the render ACTION, which renders the world onto the window.
	    if (onRender.IsSet())
			onRender(FrameCounter.getFrameTime());
		
		this->Window.display();

		//Tells the FPS timer that a frame has passed. 
		FrameCounter.Increment();
	}
}

void SimpleWindow::ToggleFramerate() {
	if (showFrameRate) HideFramerate();
	else			   ShowFramerate();
}
void SimpleWindow::ShowFramerate() {
	showFrameRate = true;
}
void SimpleWindow::HideFramerate() {
	showFrameRate = false;
}