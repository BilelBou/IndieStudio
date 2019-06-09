/*
** EPITECH PROJECT, 2019
** Game
** File description:
** Game cpp
*/

#include "Game.hpp"

Game::Game(irr::IrrlichtDevice *device, irr::scene::ISceneManager *sceneManager, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *env)
{
    this->device = device;
    this->driver = driver;
    this->sceneManager = sceneManager;
    this->env = env;
    this->mainTriangle = sceneManager->createMetaTriangleSelector();
}

void Game::draw_map()
{
    int i = 0;
    int y = 0;
    irr::core::vector3df vector_walls;
    std::string map_string;

    vector_walls.X = 0;
    vector_walls.Y = 0;
    vector_walls.Z = 0;
    std::string line;
    sceneManager->setAmbientLight(irr::video::SColor(0, 255, 255, 255));

    // Load Map
    map.open("./media/map.txt");
    if (!map)
    {
        std::cerr << "Unable to open map please regenerate" << std::endl;
        exit(84);
    }
    // ----------------

    // Adding Floor ---
    const irr::scene::IGeometryCreator *geomentryCreator = sceneManager->getGeometryCreator();
    irr::scene::IMesh *plane = geomentryCreator->createPlaneMesh(irr::core::dimension2d<irr::f32>(64, 60), irr::core::dimension2d<irr::u32>(10, 10));
    irr::scene::ISceneNode *ground = sceneManager->addMeshSceneNode(plane);
    ground->setPosition(irr::core::vector3df(310, -10, 295));
    ground->setMaterialTexture(0, driver->getTexture("./media/green.png"));
    // -----------------

    // Set Map ---------
    while (std::getline(this->map, line))
    {
        while (i < line.size())
        {
            if (line[i] == '3')
            {
                irr::scene::IMeshSceneNode *cube;
                walls.push_back(cube);
                walls[i] = sceneManager->addCubeSceneNode(15.0f, 0, -1,
                                                          irr::core::vector3df(vector_walls));
                walls[i]->setMaterialTexture(0, driver->getTexture("./media/bedrock.png"));
                walls[i]->setMaterialFlag(irr::video::EMF_LIGHTING, true);
                sceneManager->addLightSceneNode(0, irr::core::vector3df(200, 200, 200),
                                                irr::video::SColorf(1.0f, 1.0f, 1.0f));
                selector = sceneManager->createTriangleSelector(walls[i]->getMesh(), walls[i]);
                walls[i]->setTriangleSelector(this->selector);
                mainTriangle->addTriangleSelector(this->selector);
                vector_walls.Z += 15;
            }
            else if (line[i] == '4')
            {
                irr::scene::IMeshSceneNode *cube;
                walls.push_back(cube);
                walls[i] = sceneManager->addCubeSceneNode(15.0f, 0, -1,
                                                          irr::core::vector3df(vector_walls));
                walls[i]->setMaterialTexture(0, driver->getTexture("./media/stone.png"));
                walls[i]->setMaterialFlag(irr::video::EMF_LIGHTING, true);
                sceneManager->addLightSceneNode(0, irr::core::vector3df(200, 200, 200),
                                                irr::video::SColorf(1.0f, 1.0f, 1.0f));
                selector = sceneManager->createTriangleSelector(walls[i]->getMesh(), walls[i]);
                walls[i]->setTriangleSelector(this->selector);
                mainTriangle->addTriangleSelector(this->selector);
                vector_walls.Z += 15;
            }
            else if (line[i] == '5')
            {
                irr::scene::IMeshSceneNode *cube;
                walls.push_back(cube);
                walls[i] = sceneManager->addCubeSceneNode(15.0f, 0, -1,
                                                          irr::core::vector3df(vector_walls));
                walls[i]->setMaterialTexture(0, driver->getTexture("./media/block.png"));
                walls[i]->setMaterialFlag(irr::video::EMF_LIGHTING, true);
                sceneManager->addLightSceneNode(0, irr::core::vector3df(200, 200, 200),
                                                irr::video::SColorf(1.0f, 1.0f, 1.0f));
                selector = sceneManager->createTriangleSelector(walls[i]->getMesh(), walls[i]);
                walls[i]->setTriangleSelector(this->selector);
                mainTriangle->addTriangleSelector(this->selector);
                vector_walls.Z += 15;
            }
            else
                vector_walls.Z += 15;
            i++;
        }
        i = 0;
        vector_walls.X += 15;
        vector_walls.Z = 0;
    }
}
// ---------------

irr::scene::IMetaTriangleSelector *Game::get_tri()
{
    return (this->mainTriangle);
}

Game::~Game()
{
}
