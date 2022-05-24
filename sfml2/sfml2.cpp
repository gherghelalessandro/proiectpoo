#include <iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<time.h>
#include<sstream>
#include"inamic.h"
#include"Masina.h"
#include"menu.h"
#include"optiuni.h"


void movingbackground(float speed,sf::Sprite s1[2],float& backgroundy,float& backgroundy1);
void setfunction(menu& m,optiuni& op,inamic in[]);
bool checkscore(int score);
void increasespeed(float& speed);
void replay(float& score,int& nrinamici,Masina& masina,inamic ina[]);
bool joca = false,gameover=false;
int nrmaxim = 4;
//musica de joc
sf::Music music;


int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    
    sf::Texture spritem1[4],background;

    background.loadFromFile("fonts\\road_0.png");
    spritem1[0].loadFromFile("fonts\\car1.png");
    spritem1[1].loadFromFile("fonts\\limo.png");
    spritem1[2].loadFromFile("fonts\\car5.png");
    spritem1[3].loadFromFile("fonts\\truck.png");
    //background miscator

    sf::Sprite back[2];
    back[0].setTexture(background);
    back[0].move(-100, 0);
    back[1].setTexture(background);
    back[1].move(-100, 0);
    float backgroundy=0, background1y=-600,vitezafundal=0.01f;

    //masina 
    Masina mach(0.3f, 0.3f, spritem1[0]);
    //logica la inamic si variabilele necesare
    inamic in1[4];
    
    int nrdeinamici = 1;
    
    bool change = true;

    int posy = -100;
    float falltime = 100;

    for (int i = 0; i < 4; i++)
    {
        in1[i] = inamic(spritem1,posy , falltime, 4);
        posy += -200;
    }

    sf::Clock clock;
    
    //score-ul jucatorului
    sf::Font f;
    f.loadFromFile("fonts\\arial.ttf");
    
    //score
    sf::Text t;
    t.setFont(f);
    t.setPosition(0, 0);
    t.setCharacterSize(40);
    float score1 = 0;

    //zona menu si optiuni
    menu m(f); 
    optiuni op(f);
    op.activ = false;
    //musica
    
  
    music.openFromFile("fonts\\musci.ogg");
    music.play();
    

    while (window.isOpen())
    {
        std::string score = "";

        sf::Event event;

        std::stringstream ss;

        bool keypressonce = true;

       

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (m.activ == true)
            {
                m.menucontrols();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    setfunction(m, op,in1);
                }
            }
            if (op.activ == true)
            {
                op.menucontrols(); 
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    setfunction(m, op,in1);
                }
            }
            
            if (gameover == true)
            {
                music.setVolume(0);
            }
              
        }
               
        movingbackground(vitezafundal, back, backgroundy, background1y);

        float deltaTime = clock.restart().asSeconds();
       
        mach.localbound();

        window.clear();
        
        if (m.activ == true)
        {
            m.drawmenu(window);
        }
        if (op.activ == true)
        {
            op.drawmenu(window);
            op.drawbifa(window);
        }
        if(joca==true)
        {
           
            music.setLoop(true);
            
            if (mach.collisionwithmenemy(in1) == true)
            {
                joca =false;
                gameover = true;
            }

            window.draw(back[0]);
            window.draw(back[1]);


            if (checkscore(score1) == true)
            {
                for (int i = 0; i < nrdeinamici; i++)
                {
                    in1[i].increasefalltime();
                }
                if (change == true)
                {
                    increasespeed(vitezafundal);
                    if (nrdeinamici < nrmaxim)
                    {
                        nrdeinamici++;
                    }
                    change = false;
                }

            }
            else
            {
                change = true;
            }

            score1 += 1 * deltaTime;

            ss << int(score1);
            t.setString("Score:" + ss.str());
            mach.controlulmasini();
            mach.desenatmasina(window);

            for (int i = 0; i < nrdeinamici; i++)
            {
                in1[i].cadere_si_desen(window, spritem1, deltaTime);
            }
            window.draw(t);
            
            
        }
        if (gameover==true)
        {
            
            ss << int(score1);

            t.setString("Game over your score is:" + ss.str());
            window.draw(t);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                gameover = false;
                replay(score1, nrdeinamici,mach,in1);
                if (op.activ1[1] == 1)
                {
                    music.setVolume(0);
                }
                joca = true;
            }
        }
        window.display();
    }
   
}


void movingbackground(float speed, sf::Sprite s1[2], float& backgroundy, float& backgroundy1)
{
  
        s1[0].setPosition(-120, backgroundy);
        s1[1].setPosition(-120, backgroundy1);
        if (backgroundy1 > 0)
        {
            backgroundy = 0;
            backgroundy1 = backgroundy - 500;
        }
        backgroundy += speed;
        backgroundy1 += speed;   
    
}

bool checkscore(int score)
{
    if (score % 100 == 0 && score != 0)
    {
        return true;
    }
    else return false;
}

void setfunction(menu& m,optiuni& op,inamic in[])
{
    if (m.activ == true&&m.p==true)
    {
        switch (m.index)
        {
        case 1:
            joca = true;
            m.p = false;
            break;
        case 2:
            op.activ = true;
            m.p = false;
            op.p = false;
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
        m.activ = false;
    }
    if (op.activ == true&&op.p==true)
    {
        switch (op.index)
        {
        case 1:
            op.p = false;
            op.activ1[1] *=-1;
            if (op.activ1[1] == 1)
            {
                music.setVolume(0);
                
                //music.setPlayingOffset();
            }
            else
            {
                music.setVolume(100);
            }
            break;
        case 2:
            op.p = false;
            op.activ1[2] *=-1;
            for (int i = 0; i < nrmaxim; i++)
            {
                if (op.activ1[2] == 1)
                {
                    in[i].hardmode = true;
                }
                else
                {
                    in[i].hardmode = false;
                }
            }
            
            break;
        case 3:
            op.p = false;
            m.activ = true;
            op.index = 1;
            op.activ = false;
            break;
        default:
            break;
        }
        
        
    }
  
}

void increasespeed(float& speed)
{
    speed += 0.0001f;
}



void replay(float& score, int& nrinamici, Masina& masina, inamic ina[])
{
    for (int i = 0; i < nrinamici; i++)
    {
        ina[i].resetposition();
    }
    score = 0;
    nrinamici = 1;
    masina.resetposition();
    sf::Time t;
    
    
    music.setPlayingOffset(t.Zero);
    music.setVolume(100);
    
}




