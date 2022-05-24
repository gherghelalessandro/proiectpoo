#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class menu
{
	sf::Sprite s;
	sf::Texture texture;
	
public:
	sf::Music music;
	sf::Text t[4];
	int index = 1;
	bool activ = true,p=true;
	menu();
	menu(sf::Font& f);

	void menucontrols();
	int getindex();
	void drawmenu(sf::RenderWindow& w);

};

