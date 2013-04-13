#include <URGE/URGE.h>
#include "include/Player.h"
#include <iostream>

using namespace std;

USING_URGE;

URGE_BEGIN
{
    //new window: RX, RY, RENDER QUALITY LEVEL, PARAMS, WINDOW TITTLE,
    gimme_window(800,600, RENDER_QUALITY_PERFECT, WINDOWED, "URGE Application");

    //Declaracao dos objetos utilizados no jogo
    Scenario cenario;
    Player jogador;
    Terrain terreno;
    Light luz;
    Sky ceu;
    Portal portalVermelho(255,0,0);
    Portal portalAzul(0,0,255);
    bool portal;

    //Metodos do objeto luz
    luz.point();
    luz.position(0,25,0);
    luz.intensity(5);

    //Texturas do terreno e do ceu
    terreno.load("media/terrain/heightmap.jpg", 0, 20, 100, 100, "media/tex/terrain.jpg");
    ceu.loadTexture("media/sky/cloudy");

    //Metodos do objeto cenario
    cenario.insert(jogador);
    cenario.insert(terreno);
    cenario.insert(luz);
    cenario.insert(ceu);
    cenario.insert(portalVermelho);
    cenario.insert(portalAzul);
    cenario.prepare();

    //Loop do jogo
    do
    {
        if(Keyboard::hit(Keyboard::ESC))  break;
        if(Keyboard::hit(Keyboard::SPACE)) jogador.pular();
        if(Mouse::hit(Mouse::LEFT))
        {
            if(portal)
            {
               jogador.atirar(&portalAzul);
               portal = false;
            }
            else
            {
                jogador.atirar(&portalVermelho);
                portal = true;
            }
        }

        cout << jogador.velocity().y() << endl;

        cenario.update();

        next_frame();
    } while(true);

    thanks_byebye();
}
URGE_END
