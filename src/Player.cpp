#include "../include/Player.h"

Player::Player()
{
    mouseSensibility(0.25);
    position(0,50,0);
    activeBody();
    move();
}

Player::~Player()
{
    //dtor
}

void Player::pular()
{
    if (-2 < velocity().y() && velocity().y() < 2)
    {
        velocity(velocity().x(),200,velocity().z());
    }
}

void Player::atirar(Portal* portal)
{
    portal->visible(true);
    portal->position() = position();
    portal->velocity() = (Mouse::ray() * 300);
}
