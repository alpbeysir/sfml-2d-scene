#include "FPSCounter.h"
using namespace sf;


void FPSCounter::Start() {
	FPSCounter::font.loadFromFile("font.otf");
	FPSCounter::fpsText.setFont(FPSCounter::font);

	FPSCounter::fpsText.setCharacterSize(15);
	FPSCounter::fpsText.move(Vector2f(0, MainLauncher::windowPtr->getSize().y * 0.9f));
}

void FPSCounter::Update(float frameTime) {
	FPSCounter::fpsText.setString(std::to_string(1.0f / frameTime) + " FPS");
	MainLauncher::windowPtr->draw(fpsText);
}