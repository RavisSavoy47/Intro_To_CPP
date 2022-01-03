#pragma once
#include "Actor.h"

class Texture2D;

class UIText :
	public Actor
{
public:
	UIText(float x, float y, const char* name, const char* text, int width, int height, int fontSize, Font font, Color fontColor);
	UIText() {};
	~UIText() {};

	const char* m_text;
	int m_width;
	int m_height;
	int m_fontSize;
	Font m_font;
	Color m_fontColor;

	void start() override;

	void draw() override;

};

