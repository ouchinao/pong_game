#pragma once
#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "Scene.h"

class GameScene : public Scene {
public:
    GameScene(class Game* game);
    ~GameScene();
    void Start() override;
    void Update(float deltaTime) override;
    void ProcessInput(const Uint8* state) override;
    std::string const GetSceneName() override;
};

#endif // !_TITLESCENE_H_