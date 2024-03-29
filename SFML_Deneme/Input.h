#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "OyunObjesi.h"


class Input : public OyunObjesi {
public:
	void Start() override;
	void Update(float frameTime) override;

	struct Button {
		std::string name;
		bool isPressed;

		Button(std::string _name) {
			name = _name;
			isPressed = false;
		}
	};

	static bool IsButtonPressed(std::string name);
	static Button* FindButton(std::string name);
	void ResetButtons();
private:
	static std::vector<Button*> buttons;

};
