#pragma once
#include <SFML/Graphics.hpp>
#include "OyunObjesi.h"
#include "MainLauncher.h"

class Input : public OyunObjesi {
public:
	void Start() override;
	void Update(float frameTime) override;
};
