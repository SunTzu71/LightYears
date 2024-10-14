#include "framework/Application.h"
#include <iostream>

namespace ly {
    Application::Application()
        : mWindow{ sf::VideoMode(512, 720), "Light Years" },
        mTargetFrameRate(60.f),
        mTickClock()
    {

    }

    void Application::Run() {
        mTickClock.restart();
        float accumulatedTime = 0.f;
        float targetDeltaTime = 1.f / mTargetFrameRate;

        while (mWindow.isOpen()) {
            sf::Event windowEvent;
            while (mWindow.pollEvent(windowEvent)) {
                if (windowEvent.type == sf::Event::Closed) {
                    mWindow.close();
                }
            }
            accumulatedTime += mTickClock.restart().asSeconds();
            while (accumulatedTime >= targetDeltaTime) {
                accumulatedTime -= targetDeltaTime;
                TickInternal(targetDeltaTime);
                RenderInternal();
            }
        }
    }

    void Application::TickInternal(float deltaTime) {
        Tick(deltaTime);
    }

    void Application::RenderInternal() {
        mWindow.clear(sf::Color::Black);
        Render();
        mWindow.display();
    }

    void Application::Render() {
        sf::RectangleShape rect{ sf::Vector2f{100, 100} };
        rect.setFillColor(sf::Color::Cyan);
        rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
        rect.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);
        mWindow.draw(rect);
    }

    void Application::Tick(float deltaTime) {

    }
}
