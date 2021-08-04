#include "MainLauncher.h";

using namespace sf;

RenderWindow *MainLauncher::windowPtr;

//static void ExitGame(RenderWindow& window) {
//	window.close();
//}

//Genel hazırlıklar için bu class kullanılacak
void MainLauncher::main() {

	std::cout << "Deneme baslatiliyor\n";

	setlocale(LC_ALL, "Turkish");
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	RenderWindow window(VideoMode(1280, 720), L"Küçük adımlar", Style::Close, settings);
	window.setFramerateLimit(60);

	windowPtr = &window;

	std::vector<OyunObjesi*> systems;

	//Burayı instantiate gibi düşün

	//Inputu hazırla
	systems.push_back(new Input());

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

		//Updateleri çağır
		for (int i = 0; i < systems.size(); i++)
		{
			systems[i]->Update(frameClock.getElapsedTime().asSeconds());
		}

		//Değişiklikleri ekrana çiz
		frameClock.restart();
		window.display();

		//Inputu sıfırla
		((Input*)systems[0])->ResetButtons();
	}


	std::cout << "Deneme bitti";
}

int main() {
	MainLauncher::main();
}