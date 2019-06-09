/*
** EPITECH PROJECT, 2019
** Player
** File description:
** Bilel
*/

#include "Player2.hpp"

Player2::Player2(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *env, Game *game)
{
    this->device = device;
    this->sceneManager = sceneManager;
    this->driver = driver;
    this->env = env;
    player_pos.X = 15;
    player_pos.Y = 0;
    player_pos.Z = 560;
    this->stat = 2;
    sceneManager->addCameraSceneNode(0, irr::core::vector3df(80, 400, 280), irr::core::vector3df(400, -400, 280));
}
void Player2::set_skin(std::string, irr::scene::IMetaTriangleSelector *main_tri)
{
    if (this->stat != 2)
    {
        this->player = sceneManager->addCameraSceneNode(0, irr::core::vector3df(80, 400, 280), irr::core::vector3df(400, -400, 280));
        std::cout << this->stat << '\n';
        this->player = sceneManager->addSphereSceneNode();
        this->player->setPosition(this->player_pos);
        this->player->setMaterialTexture(0, driver->getTexture("./media/p2.jpg"));
        this->player->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        this->colis = sceneManager->createCollisionResponseAnimator(
            main_tri, this->player, irr::core::vector3df(4, 50, 4),
            irr::core::vector3df(0, 0, 0), irr::core::vector3df(1, 0, 1));
        player->addAnimator(this->colis);
        this->colis->drop();
    }
}

void Player2::set_state(irr::s32 state)
{
    this->stat = state;
}

Player2::~Player2()
{
}
