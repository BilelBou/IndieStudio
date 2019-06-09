/*
** EPITECH PROJECT, 2019
** PLAYER1
** File description:
** Bilel Bouricha
*/

#ifndef _PLAYER_1_
#define _PLAYER_1_
#include "IPlayer.hpp"
#include "Game.hpp"

class Player1 : public IPlayer {
	public:
		Player1(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *env, Game *game);
        ~Player1();
        void set_skin(std::string, irr::scene::IMetaTriangleSelector *main_tri) override;
		void set_state(irr::s32 id) override;
	private:
};

#endif /* !_PLAYER_1_ */
