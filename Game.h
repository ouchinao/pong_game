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
	bool Initialize(); //初期化
	void Run(); //ゲーム本体
	void Shutdown(); //ゲーム終了
private:
	//ゲームのための関数
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* mWindow; //Window
	SDL_Renderer* mRenderer; //2Dのためのレンダリング
	Uint32 mTicksCount; 
	bool mIsRunning; //ゲームの続行のため

	int mPaddlesDir; //パドルの方向
	Vector2 mPaddlesPos; //パドルの位置
	Vector2 mBallPos; //ボールの位置
	Vector2 mBallVel; //ボールの速度
};