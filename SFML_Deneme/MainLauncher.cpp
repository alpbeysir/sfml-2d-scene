#include "MainLauncher.h";
#include <vector>

using namespace sf;

RenderWindow *MainLauncher::windowPtr;

static void ExitGame(RenderWindow& window) {
	window.close();
}


//Genel hazırlıklar için bu class kullanılacak
void MainLauncher::main() {

	std::cout << "Deneme baslatiliyor\n";

	setlocale(LC_ALL, "Turkish");
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	RenderWindow window(VideoMode(640, 640), L"Küçük adımlar", Style::Default, settings);
	window.setFramerateLimit(60);

	windowPtr = &window;

	std::vector<OyunObjesi*> systems;

	//Burayı instantiate gibi düşün
	systems.push_back(new FPSCounter());
	//systems.push_back(new Şekil());
	systems.push_back(new CircleSpawner());
	
	//Startları çağır
	for (int i = 0; i < systems.size(); i++)
	{
		systems[i]->Start();
	}

	Clock frameClock;

	while (window.isOpen()) {
		//Temizle
		window.clear();

		//Kapanma event dinle
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
		}

		//Updateleri çağır
		for (int i = 0; i < systems.size(); i++)
		{
			systems[i]->Update(frameClock.getElapsedTime().asSeconds());
		}

		//Değişiklikleri ekrana çiz
		frameClock.restart();
		window.display();
	}


	std::cout << "Deneme bitti";
}

int main() {
	MainLauncher::main();
}