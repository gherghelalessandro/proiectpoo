#include "inamic.h"

inamic::inamic()
{
    timpdecadere = 0;
    nr = 0;
    origpos = 0;
    pozitiein = 0;
}

inamic::inamic(sf::Texture& t,float p,float timp)
{
    
    s.setTexture(t);
    
    s.setScale(0.4, 0.4);
    
    timpdecadere = timp;
    pozitiein = p;
    origpos = p;
    nr = 1;
    size = s.getGlobalBounds();
}

inamic::inamic(sf::Texture t[], float p, float& timp, int _nr)
{
    nr=_nr;
    int x = rand() % _nr;
    
    s.setTexture(t[x]);

    s.setScale(0.4f, 0.4f);

    timpdecadere = timp;
    pozitiein = p;
    origpos = p;
    size.width = s.getScale().x;
    size.height = s.getScale().y;

}


void inamic::cadere_si_desen(sf::RenderWindow& w,sf::Texture t[],float deltatime)
{
   
    srand(time(NULL));
    int x = rand() % 600;
    
    s.setPosition(s.getPosition().x, pozitiein);
   
    pozitiein += timpdecadere*deltatime;
    
    if (s.getPosition().y > 600)
    {
        if (nr > 1)
        {
            int y = rand() % nr;
            sf::Sprite aux(t[y]);
            s = aux;
            s.setScale(0.3f, 0.3f);
          
        }
        pozitiein =origpos;
        s.setPosition(rand() % 600, pozitiein);
        
       
    }
    size.left = s.getPosition().x;
    size.top = s.getPosition().y;
    w.draw(this->s);
}



void inamic::setzerofalltime()
{
    timpdecadere = 0;
}

void inamic::increasefalltime()
{
    if (hardmode == false)
    {
        timpdecadere += 0.1f;
    }
    else
    {
        timpdecadere += 0.5f;
    }
}

void inamic::resetposition()
{
    pozitiein = origpos;
    size = s.getGlobalBounds();
    timpdecadere = 100.f;
}


