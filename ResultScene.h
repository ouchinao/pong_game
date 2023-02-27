#pragma once
#ifndef _RESULTSCENE_H_
#define _RESULTSCENE_H_

#include "Scene.h"

class ResultScene : public Scene {
public:
    ResultScene(class Game* game);
    ~ResultScene();
    void Start() override;
    void Update(float deltaTime) override;
    void ProcessInput(const Uint8* state) override;
    std::string const GetSceneName() override;
};

#endif // !_TITLESCENE_H_