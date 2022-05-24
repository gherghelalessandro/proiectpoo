#include "optiuni.h"

optiuni::optiuni(sf::Font& font)
{
	int pozy = 100;
	for (int i = 0; i < 4; i++)
	{
		t[i].setFont(font);
		t[i].setCharacterSize(40);
		t[i].setPosition(300, pozy);
		pozy += 100;
	}
	t[0].setString("optiuni");
	t[1].setString("mute");
	t[2].setString("hardmode");
	t[3].setString("exit");
	t[index].setFillColor(sf::Color::Red);

	activ1[0] = -1;
	activ1[1] = -1;
	activ1[2] = -1;

	pozy = 200;
	for (int i = 1; i < 3; i++)
	{
		bifa[i].setPosition(500, pozy);
		bifa[i].setSize(sf::Vector2f(40,40));
		bifa[i].setFillColor(sf::Color::Red);
		pozy += 100;
	}
	
}

void optiuni::drawbifa(sf::RenderWindow& w)
{
	for (int i = 1; i < 3; i++)
	{
		if (activ1[i] == 1)
		{
			w.draw(bifa[i]);
		}
	}
}
