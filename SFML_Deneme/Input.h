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

	bool IsButtonPressed(std::string name);
	Button* FindButton(std::string name);
	void ResetButtons();
private:
	std::vector<Button*> buttons;

};
