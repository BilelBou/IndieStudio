/*
** EPITECH PROJECT, 2019
** Event
** File description:
** Receiver
*/

#ifndef _EVENT_HPP_
#define _EVENT_HPP_
#include "Core.hpp"

class MyEventReceiver : public irr::IEventReceiver
{
public:
    MyEventReceiver(Core::SAppContext &context) : Context(context) {
        for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    }
    virtual bool OnEvent(const irr::SEvent &event)
    {
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        if (event.EventType == irr::EET_GUI_EVENT)
        {
            irr::s32 id = event.GUIEvent.Caller->getID();
            irr::gui::IGUIEnvironment *env = Context.device->getGUIEnvironment();
            switch (event.GUIEvent.EventType)
            {
            case irr::gui::EGET_BUTTON_CLICKED:
                switch (id)
                {
                case Menu::GUI_ID_QUIT_BUTTON:
                    Context.device->closeDevice();
                    return true;
                case Menu::GUI_ID_SETTINGS_BUTTON:
                    env->clear();
                    Context.main_menu->settings();
                    return true;
                case Menu::GUI_ID_PLAYSETUP_BUTTON:
                    env->clear();
                    Context.main_menu->playsetup();
                    return true;
                case Menu::GUI_ID_BACK_TO_BUTTON:
                    env->clear();
                    Context.main_menu->main_menu();
                    return true;
                case Menu::GUI_ID_PLAY_GAME:
                    Context.player1->set_state(Context.main_menu->box1->getSelected());
                    Context.player2->set_state(Context.main_menu->box2->getSelected());
                    text = Context.main_menu->pseudo1->getText();
                    std::cout << text << Context.main_menu->pseudo1->getText() << '\n';
                    env->clear();
                    Context.game->draw_map();
                    Context.player1->set_skin("lol", Context.game->get_tri());
                    Context.player2->set_skin("lol", Context.game->get_tri());
                    return true;
                default:
                    return false;
                }
                break;
            }
        }
        return false;
    }
    virtual bool IsKeyDown(irr::EKEY_CODE keycode) const 
    {
        return KeyIsDown[keycode];
    }

private:
    bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
    Core::SAppContext &Context;
    std::wstring my_wstr;
    std::string my_str;
    const wchar_t *text;
};

#endif /* !EVENT */
