#pragma once
#include<SFML/Graphics.hpp>

class inamic
{
	//inamic care cade 
	//alcatuit din borduri,textura,
	sf::Sprite s;
	float pozitiein,origpos;
	float timpdecadere;
	int nr;
	
	
public:
	bool hardmode = false;
	sf::FloatRect size;
	inamic();
	inamic(sf::Texture& t,float p,float timp);
	inamic(sf::Texture t[], float p, float& timp, int nr);
	void cadere_si_desen(sf::RenderWindow& w,sf::Texture t[],float deltatime);

	void setzerofalltime();
	void increasefalltime();
	void resetposition();

};

