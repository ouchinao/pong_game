#pragma once
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include "SDL.h"

#define WIN_W 1024
#define WIN_H 768

struct Vector2 {
	float x;
	float y;
};

struct Ball {
	Vector2 pos;
	Vector2	vel;
};

class Game {
public:
	Game();
	bool Initialize(); //������
	void Run(); //�Q�[���{��
	void Shutdown(); //�Q�[���I��
private:
	//�Q�[���̂��߂̊֐�
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* mWindow; //Window
	SDL_Renderer* mRenderer; //2D�̂��߂̃����_�����O
	Uint32 mTicksCount; 
	bool mIsRunning; //�Q�[���̑��s�̂���

	int mPaddlesDir; //�p�h���̕���
	Vector2 mPaddlesPos; //�p�h���̈ʒu
	Vector2 mBallPos; //�{�[���̈ʒu
	Vector2 mBallVel; //�{�[���̑��x
};