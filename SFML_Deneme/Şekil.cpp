#include "Şekil.h"
#include "MainLauncher.h"
using namespace sf;

CircleShape triangle;

Text info;
Text lineCount;

static void CenterCircle(CircleShape& shape, Vector2u windowSize) {
    shape.setOrigin(Vector2f(shape.getRadius(), shape.getRadius()));
    shape.setPosition(Vector2f(windowSize.x / 2, windowSize.y / 2));
}

void Şekil::Start() {
    triangle.setRadius(150.f);
    triangle.setPointCount(3);
    triangle.setOutlineThickness(5.f);
    triangle.setOutlineColor(Color::Cyan);
    CenterCircle(triangle, MainLauncher::windowPtr->getSize());

    Font font;
    font.loadFromFile("font.otf");

    info.setFont(font);
    info.setString(L"Sol tık ile kenar sayısı artar, sağ ile azalır");

    lineCount.setFont(font);
    lineCount.setString(L"Kenar sayısı: 3");
    lineCount.setPosition(Vector2f(0.f, 30.f));
}


void Şekil::Update()
{
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

    MainLauncher::windowPtr->draw(triangle);
    MainLauncher::windowPtr->draw(info);
    MainLauncher::windowPtr->draw(lineCount);
}


