#pragma once
#include "OyunObjesi.h"


class CircleSpawner : public OyunObjesi {
public:
	void Start() override;
	void Update(float frameTime) override;
private:
	std::vector<sf::Vector2f> points;
};
