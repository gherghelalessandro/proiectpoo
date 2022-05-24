#include "menu.h"

menu::menu()
{
	index = 1;
	music.openFromFile("fonts\\thump.wav");
	texture.loadFromFile("fonts\\background1.jpg");
	s.setTexture(texture);
}

menu::menu(sf::Font& f)
{
	int pozy = 100;
	for (int i = 0; i < 4; i++)
	{
		t[i].setFont(f);
		t[i].setCharacterSize(40);
		t[i].setPosition(300, pozy);
	    pozy += 100;
	}
	t[0].setString("Crazy taxy");
	t[1].setString("Play");
	t[2].setString("options");
	t[3].setString("exit");
	t[index].setFillColor(sf::Color::Red);
	music.openFromFile("fonts\\thump.wav");
	texture.loadFromFile("fonts\\background1.jpg");
	s.setTexture(texture);
}



void menu::menucontrols()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		
		index--;
		if (index < 1)
			index = 1;
		p = true;
		music.play();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		index++;
		if (index > 3)
			index = 3;
		p = true;
		music.play();
		
	}
	
	for (int i = 1; i < 4; i++)
	{
		t[i].setFillColor(sf::Color::White);
	}
	t[index].setFillColor(sf::Color::Red);
}



int menu::getindex()
{
	return index;
}

void menu::drawmenu(sf::RenderWindow& w)
{
	w.draw(s);
	for (int i = 0; i < 4; i++)
	{
		w.draw(t[i]);
	}
}


