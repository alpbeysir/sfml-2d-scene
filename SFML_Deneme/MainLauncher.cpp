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
	RenderWindow window(VideoMode(640, 640), L"Şekil", Style::Default);
	window.setFramerateLimit(60);

	windowPtr = &window;

	std::vector<OyunObjesi*> systems;

	//Burayı instantiate gibi düşün
	systems.push_back(new FPSCounter());
	systems.push_back(new Şekil());
	
	//Startları çağır
	for (int i = 0; i < systems.size(); i++)
	{
		systems[i]->Start();
	}

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
			systems[i]->Update();
		}

		//Değişiklikleri ekrana çiz
		window.display();
	}


	std::cout << "Deneme bitti";
}

int main() {
	MainLauncher::main();
}