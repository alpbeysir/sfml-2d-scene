﻿#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "OyunObjesi.h"
#include "MainLauncher.h"

class Şekil : public OyunObjesi {
public:
	void Start() override;
	void Update(float frameTime) override;
};


