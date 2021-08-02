#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class OyunObjesi {
public:
	virtual void Start() = 0;
	virtual void Update(float frameTime) = 0;
};
