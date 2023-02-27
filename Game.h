#pragma once

#ifndef _GAME_H_
#define _GAME_H_

//Scene�N���X�Q�������ׂ�Scene�̐؂�ւ��Ɋւ���֐���public�ō쐬����
//

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
	~Game();
	bool Initialize(); //������
	void Run(); //�Q�[���{��
	void Shutdown(); //�Q�[���I��
private:
	//�Q�[���̂��߂̊֐�
	void ProcessInput();
	void StartScene();
	void UpdateScene();
	void UpdateGame();
	void GenerateOutput();

	int mScene; //���݂̉��
	int mNextScene; //���ɕ\�������������

	SDL_Window* mWindow; //Window
	SDL_Renderer* mRenderer; //2D�̂��߂̃����_�����O
	Uint32 mTicksCount; 
	bool mIsRunning; //�Q�[���̑��s�̂���

	int lPaddlesDir; //�p�h���̕���
	Vector2 lPaddlesPos; //�p�h���̈ʒu
	Vector2 mBallPos; //�{�[���̈ʒu
	Vector2 mBallVel; //�{�[���̑��x
};

#endif // !_GAME_H_