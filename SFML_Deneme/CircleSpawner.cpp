#include "CircleSpawner.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "MainLauncher.h"
using namespace sf;

void CircleSpawner::Start() {
    CircleSpawner::font.loadFromFile("font.otf");
    CircleSpawner::info.setFont(CircleSpawner::font);
    CircleSpawner::info.setString(L"Sol tık ile ekle, sağ tık ile son ekleneni sil");
    CircleSpawner::info.setCharacterSize(20);
}

void CircleSpawner::Update(float frameTime) {
    //Yeni nokta ekle
    if (Input::IsButtonPressed("Mouse_Left")) {
        CircleShape* newCircle = new CircleShape(3.F);
        newCircle->setPosition((Vector2f)Mouse::getPosition(*MainLauncher::windowPtr));
        CircleSpawner::circles.push_back(*newCircle);
    }
    
    //Yuvarlakları çiz
    for (int i = 0; i < circles.size(); i++)
    {
        MainLauncher::windowPtr->draw(circles[i]);
    }
    
    //Çizgileri çiz
    if (CircleSpawner::circles.size() > 1)
    for (int i = 0; i < CircleSpawner::circles.size() - 1; i++)
    {
        Vector2f point1 = CircleSpawner::circles[i].getPosition();
        Vector2f point2 = CircleSpawner::circles[i + 1].getPosition();

        sf::Vertex arr[] = {sf::Vertex(point1), sf::Vertex(point2)};
        MainLauncher::windowPtr->draw(arr, 2, sf::Lines);
    }

    //Sağ mouse ile son ekleneni sil
    if (Input::IsButtonPressed("Mouse_Right")) {
        CircleSpawner::circles.pop_back();
    }

    //Yazıyı çiz
    MainLauncher::windowPtr->draw(CircleSpawner::info);
}