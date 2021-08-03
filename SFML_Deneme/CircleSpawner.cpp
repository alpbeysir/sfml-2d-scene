#include "CircleSpawner.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "MainLauncher.h"
using namespace sf;

void CircleSpawner::Start() {
}

void CircleSpawner::Update(float frameTime) {
    if (Mouse::isButtonPressed(Mouse::Button::Left)) {
        CircleSpawner::points.push_back((Vector2f)Mouse::getPosition(*MainLauncher::windowPtr));
    }
    
    if (CircleSpawner::points.size() > 3)
    for (int i = 0; i < CircleSpawner::points.size() - 1; i++)
    {
        Vector2f point1 = CircleSpawner::points[i];
        Vector2f point2 = CircleSpawner::points[i + 1];

        sf::Vertex arr[] = {sf::Vertex(point1), sf::Vertex(point2)};
        MainLauncher::windowPtr->draw(arr, 2, sf::Lines);
    }

}