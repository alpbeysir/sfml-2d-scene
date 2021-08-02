#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "OyunObjesi.h"
#include "MainLauncher.h"

class CircleSpawner : public OyunObjesi {
public:
	void Start() override;
	void Update(float frameTime) override;
private:
	std::vector<sf::Vector2f> points;
};
