/*
** EPITECH PROJECT, 2019
** Core
** File description:
** Core
*/

#ifndef __CORE__HPP_
#define __CORE__HPP_
#include <irrlicht.h>
#include "Menu.hpp"
#include "Game.hpp"
#include "Player1.hpp"
#include "Player2.hpp"

class Core
{
public:
        Core(int x, int y);
        ~Core();
        struct SAppContext
        {
                irr::IrrlichtDevice *device;
                Menu *main_menu;
                Game *game;
                Player1 *player1;
                Player2 *player2;
        };
        irr::IrrlichtDevice *get_device();
        irr::scene::ISceneManager *get_scene();
        irr::scene::ICameraSceneNode *get_camera();
        irr::video::IVideoDriver *get_driver();
        void check_scene();
        int get_scene_int();
        void menu_loop();
        void genMap();

protected:
private:
        irr::IrrlichtDevice *device;
        irr::video::IVideoDriver *driver;
        irr::scene::ISceneManager *sceneManager;
        irr::scene::ICameraSceneNode *camera;
        irr::core::vector3df pos_p1;
        irr::core::vector3df pos_p2;
        irr::gui::IGUIEnvironment *gui_menu;
        irr::scene::IMeshSceneNode *tnt_p1;
        Menu *main_menu;
        Game *game;
        Player1 *player1;
        Player2 *player2;
        int scene;
        int x;
        int y;
};

#endif
