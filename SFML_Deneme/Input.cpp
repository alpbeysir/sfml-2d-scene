#include "Input.h"
#include "MainLauncher.h"
using namespace sf;

std::vector<Input::Button*> Input::buttons;

void Input::Start() {
	Input::buttons.push_back(new Button("Mouse_Left"));
	Input::buttons.push_back(new Button("Mouse_Right"));
}

void Input::Update(float frameTime) {
	RenderWindow& window = *MainLauncher::windowPtr;

	//Event dinle
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Button::Left) {
				Input::FindButton("Mouse_Left")->isPressed = true;
				printf("[Input] Sol mouse basildi\n");
			}
			else if (event.mouseButton.button == Mouse::Button::Right) {
				Input::FindButton("Mouse_Right")->isPressed = true;
				printf("[Input] Sag mouse basildi\n");
			}
		}

		//Kapanma eventleri de hallet
		if (event.type == Event::Closed)
		{
			window.close();
		}
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
			window.close();
		}
	}

}

bool Input::IsButtonPressed(std::string name)
{
	return Input::FindButton(name)->isPressed;
}

Input::Button* Input::FindButton(std::string name)
{
	for (int i = 0; i < Input::buttons.size(); i++)
	{
		if (Input::buttons[i]->name == name) {
			return Input::buttons[i];
		}
	}
	printf("Boyle bir InputButton yok!");
	return nullptr;
}

void Input::ResetButtons()
{
	for (int i = 0; i < Input::buttons.size(); i++)
	{
		Input::buttons[i]->isPressed = false;
	}
}
