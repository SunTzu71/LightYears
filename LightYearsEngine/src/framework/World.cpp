#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly {
    World::World(Application* owningApp)
        : mOwningApp(owningApp),
        mBeganPlay(false),
        mActors(),
        mPendingActors()
    {

    }

    void World::BeginPlayInternal() {
        if (!mBeganPlay) {
            mBeganPlay = true;
            BeginPlay();
        }
    }

    void World::TickInternal(float deltaTime) {
        for (shared<Actor> actor : mPendingActors) {
            mActors.push_back(actor);
            actor->BeginPlayInternal();
        }
        mPendingActors.clear();

        for (auto iterator = mActors.begin(); iterator != mActors.end(); ) {
            if (iterator->get()->IsPendingDestroy()) {
                iterator = mActors.erase(iterator);
            } else {
                iterator->get()->TickInternal(deltaTime);
                ++iterator;
            }
        }

        Tick(deltaTime);
    }

    void World::Render(sf::RenderWindow &window) {
        for (auto& actor : mActors) {
            actor->Render(window);
        }
    }

    World::~World() {
    }

    void World::BeginPlay() {
        //LOG("began play");
    }

    void World::Tick(float deltaTime) {
        //LOG("Tick frame rate %f", 1.f / deltaTime);
    }
}
