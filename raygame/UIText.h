#pragma once
#include "Actor.h"
#include <raylib.h>

class Player;

class UIText :
	public Actor
{
public:
	UIText(float x, float y, const char* name, const char* text, int width, int height, int fontSize, Color fontColor);
	UIText() {};
	~UIText() {};

	const char* m_text;
	int m_width;
	int m_height;
	int m_fontSize;
	Font m_font;
	Color m_fontColor;

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

private:

};

