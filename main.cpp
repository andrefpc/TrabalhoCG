#include <URGE/URGE.h>
#define PLAYER 1
#define CUBO 2

USING_URGE;

class Cubo:public Generic
{
    int collide(Object& other){
        return true;//!(other.label()==PLAYER);

    }
  void act(void){
    //Text::write(10,10,"x:%d;y:%d;z:%d\n", position().x(), position().y(), position().z());
  }
};

URGE_BEGIN
{
    //new window: RX, RY, RENDER QUALITY LEVEL, PARAMS, WINDOW TITTLE,
    gimme_window(800,600, RENDER_QUALITY_PERFECT, WINDOWED, "URGE Application");
    Scenario cenario;
    FirstPersonCamera camera;
    Terrain terreno;
    Light luz;
    Sky ceu;
    Cubo cubo;
    Cubo cubo2;

    cubo.box();
    cubo2.box();
    cubo.label(CUBO);
    camera.label(PLAYER);

    luz.point();
    luz.position(0,25,0);
    luz.intensity(5);
    camera.position(0,50,0);
    camera.activeBody();

    cubo.position(-10,1,0);
    cubo2.position(-20,1,0);
    cubo.scale(0.5,2,3);
    cubo2.scale(0.5,2,3);
    cubo.staticBody();
    cubo.loadTexture("C:/urge_devpack_0_4_1/media/tex/bricks.bmp");
    cubo2.staticBody();
    cubo2.loadTexture("C:/urge_devpack_0_4_1/media/tex/bricks.bmp");

    terreno.load("C:/urge_devpack_0_4_1/media/terrain/heightmap.jpg", 0, 0, 100, 100, "C:/urge_devpack_0_4_1/media/tex/terrain.jpg");
    ceu.loadTexture("C:/urge_devpack_0_4_1/media/sky/cloudy");

    cenario.insert(camera);
    cenario.insert(terreno);
    cenario.insert(luz);
    cenario.insert(ceu);
    cenario.insert(cubo);
    cenario.insert(cubo2);

    cenario.prepare();
    if(cubo.collide){
        camera.position(-20,1,0);
    }
    do
    {
        if(Keyboard::hit(Keyboard::ESC))  break;
        cenario.update();

        next_frame();
    } while(true);

    thanks_byebye();
}
URGE_END
