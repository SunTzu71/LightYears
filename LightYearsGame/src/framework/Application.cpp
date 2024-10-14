#include "framework/Application.h"

namespace ly {
    Application::Application()
        : mWindow{ sf::VideoMode(512, 720), "Light Years" }
    {

    }

    void Application::Run() {
        while (mWindow.isOpen()) {
            sf::Event windowEvent;
            while (mWindow.pollEvent(windowEvent)) {
                if (windowEvent.type == sf::Event::Closed) {
                    mWindow.close();
                }
            }
        }
    }
}
