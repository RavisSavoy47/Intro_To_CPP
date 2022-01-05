#include "UIText.h"

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

void UIText::draw()
{
	/*Rectangle rec = Rectangle();
	DrawTextRec(m_font, m_text, rec, m_fontSize, 1, true, m_fontColor);*/

	DrawText(m_text, 10, 10, m_fontSize, m_fontColor);
}
