#pragma once
#include "Actor.h"

class Texture2D;

class UIText :
	public Actor
{
public:
	UIText(const char* text, int width, int height, int fontSize, Texture2D* font, Texture2D* fontColor);

	void start() override;

	void draw() override;

};

