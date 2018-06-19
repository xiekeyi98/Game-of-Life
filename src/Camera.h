#ifndef GAME_OF_LIFE_CAMERA_H
#define GAME_OF_LIFE_CAMERA_H

#include <SFML/Graphics.hpp>

class Camera {
public:
    typedef std::function<void(sf::RenderTarget&)> Render;

public:
    Camera() : Camera(sf::Vector2f(0, 0)) {}

    explicit Camera(const sf::Vector2f& size);

    void fit(const sf::Vector2f& viewportSize, bool keepScale = false);

    void move(const sf::Vector2f& offset);

    void zoom(float ds);

    bool handleEvent(const sf::Event& event);

    void apply(sf::RenderTarget& renderTarget, const Render& render);

private:
    float minimumScale(const sf::Vector2f& size);

    bool windowResized(sf::Event::SizeEvent event);

    bool keyPressed(sf::Event::KeyEvent event);

    bool mouseWheelScrolled(sf::Event::MouseWheelScrollEvent event);

private:
    sf::Vector2f size;
    sf::View view;
    float scale, minScale;
};


#endif //GAME_OF_LIFE_CAMERA_H
