#ifndef GAME_OF_LIFE_RENDER_MANAGER_H
#define GAME_OF_LIFE_RENDER_MANAGER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Singleton.h"

class RenderManager : public Singleton<RenderManager> {
public:
    explicit RenderManager();

    void reset(sf::VideoMode videoMode);

    sf::Window& window() { return this->renderWindow; }

    sf::RenderTarget& renderTarget() { return this->renderWindow; }

private:
    sf::RenderWindow renderWindow;
};

#endif //GAME_OF_LIFE_RENDER_MANAGER_H
