#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "OyunObjesi.h"

class FPSCounter : public OyunObjesi {
public:
	void Start() override;
	void Update() override;
};
