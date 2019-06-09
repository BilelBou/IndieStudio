/*
** EPITECH PROJECT, 2019
** Menu.cpp
** File description:
** CPP
*/

#include "Menu.hpp"
#include "Core.hpp"

Menu::Menu(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *env)
{
    int i = 0;
    this->device = device;
    this->sceneManager = sceneManager;
    this->driver = driver;
    this->env = env;
    this->font = this->env->getFont(PATH_FONT_1);
    this->button_vector.push_back(this->button1);
    this->button_vector.push_back(this->button2);
    this->button_vector.push_back(this->button3);
    button_vector[0] = this->env->addButton(irr::core::rect<irr::s32>(780, 500, 1080, 550),
                                            0, GUI_ID_PLAYSETUP_BUTTON, L"Play the game");
    button_vector[1] = this->env->addButton(irr::core::rect<irr::s32>(780, 560, 1080, 610),
                                            0, GUI_ID_SETTINGS_BUTTON, L"Settings");
    button_vector[2] = this->env->addButton(irr::core::rect<irr::s32>(780, 620, 1080, 670),
                                            0, GUI_ID_QUIT_BUTTON, L"Quit");
    this->env->getSkin()->setFont(this->font);
    while (i < button_vector.size())
    {
        this->button_vector[i]->setImage(driver->getTexture(PATH_BUTTON_1));
        this->button_vector[i]->setPressedImage(driver->getTexture(PATH_BUTTON_2));
        i++;
    }
    this->env->addImage(this->driver->getTexture("./media/logo.png"),
                        irr::core::position2d<int>(650, 80));
}

void Menu::main_menu()
{
    int i = 0;

    button_vector[0] = this->env->addButton(irr::core::rect<irr::s32>(780, 500, 1080, 550),
                                            0, GUI_ID_PLAYSETUP_BUTTON, L"Play the game");
    button_vector[1] = this->env->addButton(irr::core::rect<irr::s32>(780, 560, 1080, 610),
                                            0, GUI_ID_SETTINGS_BUTTON, L"Settings");
    button_vector[2] = this->env->addButton(irr::core::rect<irr::s32>(780, 620, 1080, 670),
                                            0, GUI_ID_QUIT_BUTTON, L"Quit");
    this->env->getSkin()->setFont(this->font);
    while (i < button_vector.size())
    {
        this->button_vector[i]->setImage(driver->getTexture(PATH_BUTTON_1));
        this->button_vector[i]->setPressedImage(driver->getTexture(PATH_BUTTON_2));
        i++;
    }
    this->env->addImage(this->driver->getTexture("./media/logo.png"),
                        irr::core::position2d<int>(650, 80));
}

void Menu::playsetup()
{
    this->pseudo1 = this->env->addEditBox(L"Player 1", irr::core::rect<irr::s32>(40, 40, 340, 90));
    this->pseudo2 = this->env->addEditBox(L"Player 2", irr::core::rect<irr::s32>(1500, 40, 1800, 90));
    this->pseudo3 = this->env->addEditBox(L"Player 3", irr::core::rect<irr::s32>(40, 800, 340, 850));
    this->pseudo4 = this->env->addEditBox(L"Player 4", irr::core::rect<irr::s32>(1500, 800, 1800, 850));
    this->box1 = this->env->addComboBox(irr::core::rect<irr::s32>(40, 95, 340, 145));
    box1->addItem(L"AI");
    box1->addItem(L"Player1");
    box1->addItem(L"None");
    this->box2 = this->env->addComboBox(irr::core::rect<irr::s32>(1500, 95, 1800, 145));
    box2->addItem(L"AI");
    box2->addItem(L"Player1");
    box2->addItem(L"None");
    this->box3 = this->env->addComboBox(irr::core::rect<irr::s32>(40, 855, 340, 905));
    box3->addItem(L"AI");
    box3->addItem(L"Player1");
    box3->addItem(L"None");
    this->box4 = this->env->addComboBox(irr::core::rect<irr::s32>(1500, 855, 1800, 905));
    box4->addItem(L"AI");
    box4->addItem(L"Player1");
    box4->addItem(L"None");
    this->validate = this->env->addButton(irr::core::rect<irr::s32>(800, 900, 990, 950),
                                          0, GUI_ID_PLAY_GAME, L"Play");
    this->back_to_menu_game = this->env->addButton(irr::core::rect<irr::s32>(1000, 900, 1190, 950),
                                                   0, GUI_ID_BACK_TO_BUTTON, L"Back");
    this->env->addImage(this->driver->getTexture("./media/logo.png"),
                        irr::core::position2d<int>(650, 100));
}

void Menu::settings()
{
    this->env->addImage(this->driver->getTexture("./media/logo.png"),
                        irr::core::position2d<int>(650, 100));
    this->env->addStaticText(L"Volume", irr::core::rect<irr::s32>(850, 300, 1050, 400));
    this->volume = this->env->addScrollBar(true,
                                           irr::core::rect<irr::s32>(700, 350, 1100, 380), 0, -1);
    this->volume->setMax(255);
    this->volume->setPos(255);
    this->fullscreen = this->env->addCheckBox(true,
                                              irr::core::rect<irr::s32>(700, 400, 1100, 430), 0, -1, L"Fullscreen");
    this->back_to_menu = this->env->addButton(irr::core::rect<irr::s32>(780, 500, 1080, 550),
                                              0, GUI_ID_BACK_TO_BUTTON, L"Back");
}

Menu::~Menu()
{
}
