#include "UIText.h"
#include <iostream>
#include "string.h"
#include "Player.h"
#include <math.h>

UIText::UIText(float x, float y, const char* name, const char* text, int width, int height, int fontSize, Color fontColor) : Actor::Actor(x, y, name)
{
	m_text = text;
	m_width = width;
	m_height = height;
	m_fontSize = fontSize;

	m_font = GetFontDefault();
	m_fontColor = fontColor;
	fontColor = RAYWHITE;
}

void UIText::start()
{
	Actor::start();
}

void UIText::update(float deltaTime)
{
	Actor::update(deltaTime);
}

void UIText::draw()
{
	/*Rectangle rec = Rectangle();
	DrawTextRec(m_font, m_text, rec, m_fontSize, 1, true, m_fontColor);*/

	DrawText(m_text, 30, 745, m_fontSize, m_fontColor);
}
