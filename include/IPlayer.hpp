/*
** EPITECH PROJECT, 2019
** Indie
** File description:
** Bilel Bouricha
*/

#ifndef _IPLAYER_HPP_
#define _IPLAYER_HPP_
#include <iostream>
#include "irrlicht.h"

class IPlayer
{
public:
    ~IPlayer(){};
    virtual void set_skin(std::string, irr::scene::IMetaTriangleSelector *main_tri) = 0;
    irr::scene::ISceneNode *player;
    virtual void set_state(irr::s32 id) = 0;
    irr::s32 stat;

protected:
    irr::scene::IAnimatedMeshSceneNode *skin;
    irr::scene::ISceneNodeAnimator *anim;
    irr::core::vector3df player_pos;
    irr::scene::ICameraSceneNode *camera;
    enum state
    {
        IA,
        PLAYER,
        NONE
    };
    std::string name;
    int pos_x;
    int pos_y;
    irr::IrrlichtDevice *device;
    irr::scene::ISceneManager *sceneManager;
    irr::video::IVideoDriver *driver;
    irr::gui::IGUIEnvironment *env;
    irr::scene::ISceneNodeAnimator *colis;
};

#endif
