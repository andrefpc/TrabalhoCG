#include <URGE/URGE.h>

USING_URGE;

class Player : public FirstPersonCamera
{
    public:
        void pular()
        {
           position(position().x(),20,position().z());
        }

        void atirar()
        {

        }
};

class Portal : public Generic
{
    public:
        Portal()
        {
            box();
            label(Portal);
        }
};

typedef struct node {
    Portal portal;
    node* next;
}* nodePtr;

class List
{
    public:
        List()
        {

        }

        void addNode(Portal portal)
        {
            nodePtr n = new node;
            n->next = NULL;
            n->portal = portal;

            if (head != NULL)
            {
                curr = head;

                while(curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = n;
            }
            else
            {
                head = n;
            }
        }

    private:
        nodePtr head;
        nodePtr curr;
        nodePtr temp;
};

URGE_BEGIN
{
    //new window: RX, RY, RENDER QUALITY LEVEL, PARAMS, WINDOW TITTLE,
    gimme_window(800,600, RENDER_QUALITY_PERFECT, WINDOWED, "URGE Application");

    //Declaracao dos objetos utilizados no jogo
    Scenario cenario;
    Player camera;
    Terrain terreno;
    Light luz;
    Sky ceu;
    List portais;

    //Metodos do objeto luz
    luz.point();
    luz.position(0,25,0);
    luz.intensity(5);

    //Metodos do objeto camera
    camera.mouseSensibility(0.25);
    camera.position(0,50,0);
    camera.activeBody();
    camera.move();

    //Texturas do terreno e do ceu
    terreno.load("media/terrain/heightmap.jpg", 0, 25, 100, 100, "media/tex/terrain.jpg");
    ceu.loadTexture("media/sky/cloudy");

    //Metodos do objeto cenario
    cenario.insert(camera);
    cenario.insert(terreno);
    cenario.insert(luz);
    cenario.insert(ceu);
    cenario.prepare();

    //Loop do jogo
    do
    {
        if(Keyboard::hit(Keyboard::ESC))  break;
        if(Keyboard::hit(Keyboard::SPACE)) camera.pular();
        if(Mouse::hit(Mouse::LEFT)) camera.atirar();

        cenario.update();

        next_frame();
    } while(true);

    thanks_byebye();
}
URGE_END
