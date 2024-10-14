#pragma once
#include <SFML/Graphics.hpp>

namespace ly {
    class Application {
    public:
        Application();
        void Run();
    private:
        void TickInternal(float deltaTime);
        void RenderInternal();

        virtual void Render(); // override with child class
        virtual void Tick(float deltaTime); // override with child class

        sf::RenderWindow mWindow;
        float mTargetFrameRate;
        sf::Clock mTickClock;
    };
}
