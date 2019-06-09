/*
** EPITECH PROJECT, 2019
** Core
** File description:
** Core
*/

#include "Core.hpp"
#include "EventReceiver.hpp"

Core::Core(int x, int y)
{
    this->x = x;
    this->y = y;
    this->device = irr::createDevice(
        irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(this->x, this->y),
        32, false, true, false, 0);
    this->driver = device->getVideoDriver();
    this->sceneManager = device->getSceneManager();
    this->scene = 0;
    this->gui_menu = sceneManager->getGUIEnvironment();
}

Core::~Core()
{
}

void Core::menu_loop()
{
    main_menu = new Menu(this->device, this->sceneManager, this->driver, this->gui_menu);
    game = new Game(this->device, this->sceneManager, this->driver, this->gui_menu);
    player1 = new Player1(this->device, this->sceneManager, this->driver, this->gui_menu, this->game);
    player2 = new Player2(this->device, this->sceneManager, this->driver, this->gui_menu, this->game);

    SAppContext context;
    context.main_menu = main_menu;
    context.game = game;
    context.device = this->device;
    context.player1 = player1;
    context.player2 = player2;
    irr::u32 then = device->getTimer()->getTime();
    const irr::f32 speed = 30.f;

    MyEventReceiver receiver(context);
    device->setEventReceiver(&receiver);
    while (this->device->run())
    {
        const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f;
        then = now;
        if (player1->stat != 2)
        {
            if (receiver.IsKeyDown(irr::KEY_KEY_Q))
            {
                this->pos_p1 = player1->player->getPosition();
                this->pos_p1.Z += speed * frameDeltaTime;
                player1->player->setPosition(this->pos_p1);
            }
            else if (receiver.IsKeyDown(irr::KEY_KEY_D))
            {
                this->pos_p1 = player1->player->getPosition();
                this->pos_p1.Z -= speed * frameDeltaTime;
                player1->player->setPosition(this->pos_p1);
            }
            else if (receiver.IsKeyDown(irr::KEY_KEY_Z))
            {
                this->pos_p1 = player1->player->getPosition();
                this->pos_p1.X += speed * frameDeltaTime;
                player1->player->setPosition(this->pos_p1);
            }
            else if (receiver.IsKeyDown(irr::KEY_KEY_S))
            {
                this->pos_p1 = player1->player->getPosition();
                this->pos_p1.X -= speed * frameDeltaTime;
                player1->player->setPosition(this->pos_p1);
            }
            else if (receiver.IsKeyDown(irr::KEY_SPACE))
            {
                this->tnt_p1 = sceneManager->addCubeSceneNode(10.0f, 0, -1,
                irr::core::vector3df(pos_p1));
                this->tnt_p1->setMaterialTexture(0, driver->getTexture("./media/tnt.png"));
                this->tnt_p1->setMaterialFlag(irr::video::EMF_LIGHTING, true);
            }
        }
        if (player2->stat != 2)
        {
            if (receiver.IsKeyDown(irr::KEY_LEFT))
            {
                this->pos_p2 = player2->player->getPosition();
                this->pos_p2.Z += speed * frameDeltaTime;
                player2->player->setPosition(this->pos_p2);
            }
            else if (receiver.IsKeyDown(irr::KEY_RIGHT))
            {
                this->pos_p2 = player2->player->getPosition();
                this->pos_p2.Z -= speed * frameDeltaTime;
                player2->player->setPosition(this->pos_p2);
            }
            else if (receiver.IsKeyDown(irr::KEY_UP))
            {
                this->pos_p2 = player2->player->getPosition();
                this->pos_p2.X += speed * frameDeltaTime;
                player2->player->setPosition(this->pos_p2);
            }
            else if (receiver.IsKeyDown(irr::KEY_DOWN))
            {
                this->pos_p2 = player2->player->getPosition();
                this->pos_p2.X -= speed * frameDeltaTime;
                player2->player->setPosition(this->pos_p2);
            }
        }
        this->driver->beginScene(true, true,
                                 irr::video::SColor(150, 150, 255, 255));
        sceneManager->drawAll();
        gui_menu->drawAll();
        this->driver->endScene();
    }
    this->device->drop();
}

irr::IrrlichtDevice *Core::get_device()
{
    return (this->device);
}

irr::scene::ISceneManager *Core::get_scene()
{
    return (this->sceneManager);
}

irr::scene::ICameraSceneNode *Core::get_camera()
{
    return (this->camera);
}

irr::video::IVideoDriver *Core::get_driver()
{
    return (this->driver);
}

int Core::get_scene_int()
{
    return (this->scene);
}