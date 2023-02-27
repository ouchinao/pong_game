#pragma once
#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_
#include "Scene.h"

class TitleScene : public Scene {
public:
    TitleScene(class Game* game);
    ~TitleScene();
    void Start() override;
    void Update(float deltaTime) override;
    void ProcessInput(const Uint8* state) override;
    std::string const GetSceneName() override;
};

#endif // !_TITLESCENE_H_