#include "UIText.h"
#include <raylib.h>

UIText::UIText(float x, float y, const char* name, const char* text, int width, int height, int fontSize, Font font, Color fontColor) : Actor::Actor(x, y, name)
{
	m_text = text;
	m_width = width;
	m_height = height;
	m_fontSize = fontSize;

	m_font = font;
	font = LoadFont("resources/fonts/alagard.png");
	m_fontColor = fontColor;
	fontColor = RAYWHITE;
}

void UIText::start()
{
	Actor::start();
}

void UIText::draw()
{
	Rectangle rec = Rectangle();
	DrawTextRec(m_font, m_text, rec, m_fontSize, 1, true, m_fontColor);
}
