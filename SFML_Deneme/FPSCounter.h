#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "OyunObjesi.h"
#include "MainLauncher.h"

class FPSCounter : public OyunObjesi {
public:
	void Start() override;
	void Update(float frameTime) override;
private:
	sf::Font font;
	sf::Text fpsText;
};
