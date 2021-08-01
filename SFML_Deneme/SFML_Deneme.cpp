// SFML_Deneme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

void CenterCircle(CircleShape& shape, Vector2u windowSize) {
    shape.setOrigin(Vector2f(shape.getRadius(), shape.getRadius()));
    shape.setPosition(Vector2f(windowSize.x / 2, windowSize.y / 2));
}

void ExitGame(RenderWindow& window) {
    window.close();
    std::cout << "Oyun bitti";
}


int main()
{
    setlocale(LC_ALL, "Turkish");

    RenderWindow window(VideoMode(640, 640), L"Şekil", Style::Default);
    window.setFramerateLimit(60);

    CircleShape triangle;
    triangle.setRadius(150.f);
    triangle.setPointCount(3);
    triangle.setOutlineThickness(5.f);
    triangle.setOutlineColor(Color::Cyan);
    CenterCircle(triangle, window.getSize());
    
    Font font;
    font.loadFromFile("font.otf");

    Text info;
    info.setFont(font);
    info.setString(L"Sol tık ile kenar sayısı artar, sağ ile azalır");

    Text lineCount;
    lineCount.setFont(font);
    lineCount.setString(L"Kenar sayısı: 3");
    lineCount.setPosition(Vector2f(0.f, 30.f));



    while (window.isOpen())
    {
        //Main game loop
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                ExitGame(window);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                ExitGame(window);
            }
            //if (event.type == Event::MouseButtonPressed) {
            //    if (event.mouseButton.button == 0) {
            //        //Sol tık
            //        triangle.setPointCount(triangle.getPointCount() + 1);
            //        std::cout << "Kenar sayisi artirildi\n";
            //    }
            //    else
            //    {
            //        //Sağ tık  
            //        triangle.setPointCount(triangle.getPointCount() - 1);
            //        std::cout << "Kenar sayisi azaltildi\n";
            //    }
            //}
        }

        if (Mouse::isButtonPressed(Mouse::Button::Left)) {
            triangle.setPointCount(triangle.getPointCount() + 1);
            std::cout << "Kenar sayisi artirildi\n";
            lineCount.setString((L"Kenar sayısı: ") + std::to_string(triangle.getPointCount()));
        }

        if (Mouse::isButtonPressed(Mouse::Button::Right) && triangle.getPointCount() > 3) {
            triangle.setPointCount(triangle.getPointCount() - 1);
            std::cout << "Kenar sayisi azaltildi\n";
            lineCount.setString((L"Kenar sayısı: ") + std::to_string(triangle.getPointCount()));
        }


        //Clear
        window.clear();

        //Draw
        window.draw(triangle);
        window.draw(info);
        window.draw(lineCount);

        //Show
        window.display();
    }

    return 0;
}


