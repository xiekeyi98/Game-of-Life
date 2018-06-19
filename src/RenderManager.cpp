#include "RenderManager.h"

RenderManager::RenderManager() : renderWindow() {
    reset(sf::VideoMode(800, 600));
}

void RenderManager::reset(sf::VideoMode videoMode) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    renderWindow.create(videoMode, "Game of Life", sf::Style::Default, settings);
    renderWindow.setFramerateLimit(60);
}
