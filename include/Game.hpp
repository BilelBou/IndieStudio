/*
** EPITECH PROJECT, 2019
** Game Indie
** File description:
** Game
*/

#ifndef _GAME_HPP
#define _GAME_HPP
#include "irrlicht.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Game
{
public:
    Game(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *env);
    ~Game();
    void draw_map();
    irr::scene::IMetaTriangleSelector *get_tri();
    irr::scene::IMetaTriangleSelector *mainTriangle;
    irr::scene::ITriangleSelector *selector;

protected:
private:
    //  Element principaux recu du core (set dans le constructor)

    irr::scene::ISceneManager *sceneManager;
    irr::video::IVideoDriver *driver;
    irr::gui::IGUIEnvironment *env;
    irr::IrrlichtDevice *device;
    std::ifstream map;
    std::vector<irr::scene::IMeshSceneNode*> walls;
    irr::scene::IMeshSceneNode *cube;
    irr::scene::IMeshSceneNode *cub2;
};

#endif /* !_GAME_HPP */
