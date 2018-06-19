#include "WorldState.h"
#include "RenderManager.h"

WorldState::WorldState(World& world) : world(world), worldRenderer() {
    auto& renderMgr = RenderManager::get();
    auto& window = renderMgr.window();
    camera = Camera(sf::Vector2f(worldRenderer.size(world)));
    camera.fit(sf::Vector2f(window.getSize()), false);
}

bool WorldState::handleEvent(sf::Event& event) {
    if (camera.handleEvent(event)) return true;
    return State::handleEvent(event);
}

void WorldState::update() {
    world.update();
}

void WorldState::render() {
    auto& renderMgr = RenderManager::get();
    auto& renderTarget = renderMgr.renderTarget();
    renderTarget.clear();
    camera.apply(renderTarget, [&](sf::RenderTarget& rt) {
        worldRenderer.render(rt, world);
    });
}
