/*
** EPITECH PROJECT, 2019
** Menu
** File description:
** Indie
*/

#ifndef MENU_HPP_
#define MENU_HPP_
#define PATH_BUTTON_1 "./media/b_1.png"
#define PATH_BUTTON_2 "./media/b_5.png"
#define PATH_FONT_1 "./media/font.png"
#include <vector>
#include <fstream>
#include <iostream>
#include "irrlicht.h"

class Menu
{
public:
        Menu(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *env);
        ~Menu();
        void playsetup();
        void settings();
        void interprete();
        void main_menu();
        irr::gui::IGUIFont *font;
        std::vector<irr::gui::IGUIButton *> button_vector;
        enum GUI
        {
                GUI_ID_QUIT_BUTTON = 101,
                GUI_ID_PLAYSETUP_BUTTON,
                GUI_ID_SETTINGS_BUTTON,
                GUI_ID_BACK_TO_BUTTON,
                GUI_ID_PLAY_GAME,
        };
        irr::gui::IGUIComboBox *box1;
        irr::gui::IGUIComboBox *box2;
        irr::gui::IGUIComboBox *box3;
        irr::gui::IGUIComboBox *box4;
        irr::gui::IGUIEditBox *pseudo1;
        irr::gui::IGUIEditBox *pseudo2;
        irr::gui::IGUIEditBox *pseudo3;
        irr::gui::IGUIEditBox *pseudo4;

protected:
        //      Element principaux recu du core (set dans le constructor)
        irr::scene::ISceneManager *sceneManager;
        irr::video::IVideoDriver *driver;
        irr::gui::IGUIEnvironment *env;
        irr::IrrlichtDevice *device;

        //      Bouton du menu de base
        irr::gui::IGUIButton *button1;
        irr::gui::IGUIButton *button2;
        irr::gui::IGUIButton *button3;
        //      Elements du setup de la game
        irr::gui::IGUIButton *validate;
        irr::gui::IGUIButton *back_to_menu_game;
        //      Elements des settings
        irr::gui::IGUIScrollBar *volume;
        irr::gui::IGUICheckBox *fullscreen;
        irr::gui::IGUIButton *back_to_menu;

private:
};

#endif /* !MENU_HPP_ */
