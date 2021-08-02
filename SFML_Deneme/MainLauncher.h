#pragma once
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Şekil.h"
#include "OyunObjesi.h"
#include "FPSCounter.h"
#include "CircleSpawner.h"

class MainLauncher {
public:
	static void main();

	static sf::RenderWindow *windowPtr;
};