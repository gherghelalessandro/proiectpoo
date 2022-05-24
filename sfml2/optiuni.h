#pragma once
#include"menu.h"
class optiuni:public menu
{
	sf::RectangleShape bifa[3];
public:
	int activ1[3];
	optiuni(sf::Font& font);
	void drawbifa(sf::RenderWindow& w);
};

