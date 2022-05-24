#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"inamic.h"
#include<iostream>
class Masina
{

	sf::Sprite s;
	sf::FloatRect limita,glont;

public:
	float x, y;

	Masina(float x1, float y1,sf::Texture& t);
	void desenatmasina(sf::RenderWindow& w);
	void controlulmasini();
	void localbound();
	bool collisionwithenemy(inamic& inam);
	bool collisionwithmenemy(inamic inam[]);
	void resetposition();
	void bullet();

};

