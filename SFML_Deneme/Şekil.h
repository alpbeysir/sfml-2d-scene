#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "OyunObjesi.h"

class Şekil : public OyunObjesi {
public:
	void Start() override;
	void Update() override;
};


