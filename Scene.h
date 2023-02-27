#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include<cstdio>
#include<cstdlib>
#include<memory>
#include<vector>
#include<iostream>
#include "SDL.h"
#include "Game.h"
#include<string>


class Scene { //�V�[���Ǘ��ׂ̈̊��N���X
public:
    Scene(class Game* game);
    virtual ~Scene();
    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void ProcessInput(const Uint8* state);
    virtual std::string const GetSceneName();

protected:
    class Game* mGame;

};

#endif // !_SCENE_H_