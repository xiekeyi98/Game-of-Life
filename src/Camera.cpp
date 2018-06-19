#include "Camera.h"

Camera::Camera(const sf::Vector2f& size) : size(size), view(sf::Vector2f(size.x / 2, size.y / 2), size), scale(1.f),
                                           minScale(1.f) {}

void Camera::fit(const sf::Vector2f& size, bool keepScale) {
    minScale = minimumScale(size);
    scale = keepScale ? std::max(scale, minScale) : minScale;
    view.reset(sf::FloatRect(sf::Vector2f((this->size.x - size.x / scale) / 2, (this->size.y - size.y / scale) / 2),
                             sf::Vector2f(size.x, size.y) / scale));
}

float Camera::minimumScale(const sf::Vector2f& size) {
    auto hScale = size.x / this->size.x, vScale = size.y / this->size.y;
    return std::min(hScale, vScale);
}

void Camera::move(const sf::Vector2f& offset) {
    view.move(offset / scale);
}

void Camera::zoom(float ds) {
    auto size = view.getSize() * scale;
    scale = std::max(scale + ds, minScale);
    view.setSize(size / scale);
}

void Camera::apply(sf::RenderTarget& renderTarget, const Render& render) {
    auto& original = renderTarget.getView();
    renderTarget.setView(view);
    render(renderTarget);
    renderTarget.setView(original);
}

bool Camera::handleEvent(const sf::Event& event) {
    switch (event.type) {
        case sf::Event::Resized:
            return windowResized(event.size);
        case sf::Event::KeyPressed:
            return keyPressed(event.key);
        case sf::Event::MouseWheelScrolled:
            return mouseWheelScrolled(event.mouseWheelScroll);
        default:
            return false;
    }
}

bool Camera::windowResized(sf::Event::SizeEvent event) {
    auto size = sf::Vector2f(event.width, event.height);
    fit(size, true);
    return false;
}

bool Camera::keyPressed(sf::Event::KeyEvent event) {
    switch (event.code) {
        case sf::Keyboard::W:
            zoom(0.01f);
            return true;
        case sf::Keyboard::S:
            zoom(-0.01f);
            return true;
        default:
            return false;
    }
}

bool Camera::mouseWheelScrolled(sf::Event::MouseWheelScrollEvent event) {
    if (event.wheel == sf::Mouse::Wheel::VerticalWheel) {
        zoom(event.delta * 0.01f);
        return true;
    }
    return false;
}
