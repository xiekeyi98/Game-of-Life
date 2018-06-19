#include "GameEngine.h"
#include "RenderManager.h"
#include "StateManager.h"
#include "InitState.h"

void GameEngine::run() {
    RenderManager renderMgr;
    StateManager stateMgr;
    auto& window = renderMgr.window();
    stateMgr.pushState(new InitState());
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (!stateMgr.handleEvent(event)) {
                handleEvent(event);
            }
        }
        stateMgr.update();
        stateMgr.render();
        window.display();
    }
}

void GameEngine::handleEvent(sf::Event event) {
    auto& renderMgr = RenderManager::get();
    auto& window = renderMgr.window();
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
    }
}
