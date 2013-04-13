#ifndef PLAYER_H
#define PLAYER_H
#include <URGE/URGE.h>
#include "Portal.h"

USING_URGE;
class Player : public FirstPersonCamera
{
    public:
        Player();
        virtual ~Player();
        void pular();
        void atirar(Portal* portal);
    protected:
    private:
};

#endif // PLAYER_H
