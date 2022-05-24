#include "Masina.h"

Masina::Masina(float x1, float y1,sf::Texture& t)
{
    s.setTexture(t);
	s.setScale(x1, y1);
    x = 0;
    y = 0;
	s.setPosition(300, 300);
	
}

void Masina::desenatmasina(sf::RenderWindow& w)
{   
    w.draw(this->s);
   
}

void Masina::controlulmasini()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        s.move(0, -0.5f);
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        s.move(0, 0.5f);
       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        s.move(-0.5f, 0);
      
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        s.move(0.5f, 0);
        
    }
    limita = s.getGlobalBounds();
    
}

void Masina::localbound()
{
    limita = s.getGlobalBounds();
    if (limita.top < 0)
    {
        s.setPosition(s.getPosition().x,0);
    }
    if (limita.top + limita.height > 600)
    {
        s.setPosition(s.getPosition().x, 600-limita.height);
    }
    if (limita.left < 0)
    {
        s.setPosition(0, s.getPosition().y);
    }
    if (limita.left + limita.width > 800)
    {
        s.setPosition(800-limita.width, s.getPosition().y);
    }
}

bool Masina::collisionwithenemy(inamic& inam)
{
    if (limita.intersects(inam.size))
    {
        inam.setzerofalltime();
        return true;
    }
    return false;
    
}

bool Masina::collisionwithmenemy(inamic inam[])
{
    for (int i = 0; i < 4; i++)
    {
        if (limita.intersects(inam[i].size))
            return true;
    }
    return false;
}

void Masina::resetposition()
{
    s.setPosition(300, 300);
    limita = s.getGlobalBounds();
}


