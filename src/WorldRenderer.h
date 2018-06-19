#ifndef GAME_OF_LIFE_WORLD_RENDERER_H
#define GAME_OF_LIFE_WORLD_RENDERER_H

#include <SFML/Graphics.hpp>
#include "World.h"

class WorldRenderer {
public:
    explicit WorldRenderer();

    sf::Vector2u size(World& world);

    void render(sf::RenderTarget& renderTarget, World& world);

private:
    RectangleShape worldShape;
    CircleShape cellShape;
};


#endif //GAME_OF_LIFE_WORLD_RENDERER_H
