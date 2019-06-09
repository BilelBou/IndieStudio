/*
** EPITECH PROJECT, 2019
** PLAYER1
** File description:
** Bilel Bouricha
*/

#ifndef _PLAYER_2_
#define _PLAYER_2_
#include "IPlayer.hpp"
#include "Game.hpp"

class Player2 : public IPlayer {
	public:
		Player2(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *env, Game *game);
        ~Player2();
        void set_skin(std::string, irr::scene::IMetaTriangleSelector *main_tri) override;
		void set_state(irr::s32 id) override;
	private:
};

#endif /* !_PLAYER_1_ */
