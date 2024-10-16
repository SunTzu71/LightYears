#pragma once
#include <SFML/Graphics.hpp>

namespace ly {
    sf::Vector2f RotationToVector(float rotation);
    float DegressToRadians(float degrees);
    float RadiansToDegress(float radians);
}
