#pragma once

#ifndef _GAME_H_
#define _GAME_H_

//Sceneクラス群を扱う為のSceneの切り替えに関する関数をpublicで作成する
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
	bool Initialize(); //初期化
	void Run(); //ゲーム本体
	void Shutdown(); //ゲーム終了
private:
	//ゲームのための関数
	void ProcessInput();
	void StartScene();
	void UpdateScene();
	void UpdateGame();
	void GenerateOutput();

	int mScene; //現在の画面
	int mNextScene; //次に表示させたい画面

	SDL_Window* mWindow; //Window
	SDL_Renderer* mRenderer; //2Dのためのレンダリング
	Uint32 mTicksCount; 
	bool mIsRunning; //ゲームの続行のため

	int lPaddlesDir; //パドルの方向
	Vector2 lPaddlesPos; //パドルの位置
	Vector2 mBallPos; //ボールの位置
	Vector2 mBallVel; //ボールの速度
};

#endif // !_GAME_H_