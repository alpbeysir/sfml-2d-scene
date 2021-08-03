#include "Input.h"
using namespace sf;


void Input::Start() {

}

void Input::Update(float frameTime) {
	RenderWindow& window = *MainLauncher::windowPtr;

	//Event dinle
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			//ExitGame(window);
		}
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
			//ExitGame(window);
		}
	}
}