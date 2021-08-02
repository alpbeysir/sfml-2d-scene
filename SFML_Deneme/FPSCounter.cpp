#include "FPSCounter.h"
using namespace sf;

Text fpsText;

void FPSCounter::Start() {
	Font font;
	font.loadFromFile("font.otf");

	fpsText.setFont(font);

}

void FPSCounter::Update() {

}