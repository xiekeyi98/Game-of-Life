#ifndef GAME_OF_LIFE_WORLD_STATE_H
#define GAME_OF_LIFE_WORLD_STATE_H

#include "State.h"
#include "World.h"
#include "WorldRenderer.h"
#include "Camera.h"

class WorldState : public State {
public:
    explicit WorldState(World& world);

    void update() override;

    void render() override;

    bool handleEvent(sf::Event& event) override;

protected:
    World& world;
    Camera camera;
    WorldRenderer worldRenderer;
};


#endif //GAME_OF_LIFE_WORLD_STATE_H
