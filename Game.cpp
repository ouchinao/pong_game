#include "Game.h"

const float thickness = 15;
const int paddle_H = 100.0f;

Game::Game() {
	mWindow = nullptr;
	mRenderer = nullptr;
	mTicksCount = 0;
	mIsRunning = true;
	lPaddlesDir = 0;
	lPaddlesPos.x = 0;
	lPaddlesPos.y = 0;
	mBallPos.x = 0;
	mBallPos.y = 0;
	mBallVel.x = 0;
	mBallVel.y = 0;
	mNextScene = 0;
	mScene = 0;
}

Game::~Game() {
	//デストラクタ
}

bool Game::Initialize() {
	int sdlResult = SDL_Init(SDL_INIT_VIDEO); // SDL初期化
	if (sdlResult != 0) {
		SDL_Log("SDLを初期化できません : %s", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow( // SDLウィンドウを作成
		"Pong in C++", // ウィンドウのタイトル
		100, // ウィンドウ左上隅のx座標
		100, // ウィンドウ左上隅のy座標
		WIN_W, // ウィンドウの幅(width)
		WIN_H, // ウィンドウの高さ(height)
		0 // フラグ(設定しない時は0)
	);

	if (!mWindow) {
		SDL_Log("ウィンドウの作成に失敗しました : %s", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(
		mWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer) {
		SDL_Log("ウィンドウの作成に失敗しました : %s", SDL_GetError());
		return false;
	}

	lPaddlesPos.x = 10.0f;
	lPaddlesPos.y = 768.0f / 2.0f;
	mBallPos.x = 1024.0f / 2.0f;
	mBallPos.y = 768.0f / 2.0f;
	mBallVel.x = -200.0f;
	mBallVel.y = 235.0f;

	return true;
}

void Game::Run() {
	
	while (mIsRunning) {
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown() {
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			mIsRunning = false;
			break;
		default:
			break;
		}
	}
	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}
	lPaddlesDir = 0;
	if (state[SDL_SCANCODE_W]) { //wで左側のPaddleが上に
		lPaddlesDir -= 1;
	}
	if (state[SDL_SCANCODE_S]) { //sで左側のPaddleが下に
		lPaddlesDir += 1;
	}
}

void Game::StartScene() {

}

void Game::UpdateScene() {

}

void Game::UpdateGame() {
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16)); //前のフレームから16msが経過するまで待つ
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f; //deltatimeは前のフレームとの時刻の差を秒に変換した値

	//deltatimeを最大値で制限する
	if (deltaTime > 0.05f) {
		deltaTime = 0.05f;
	}
	mTicksCount = SDL_GetTicks(); //パドル用

	if (lPaddlesDir != 0) {
		lPaddlesPos.y += lPaddlesDir * 300.0f * deltaTime;
		if (lPaddlesPos.y < (paddle_H / 2.0f + thickness)) {
			lPaddlesPos.y = paddle_H / 2.0f + thickness;
		}
		else if (lPaddlesPos.y > (768.0f - paddle_H / 2.0f - thickness)) {
			lPaddlesPos.y = 768.0f - paddle_H / 2.0f - thickness;
		}
	}

	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime; //Ballの動き方

	float diff = lPaddlesPos.y - mBallPos.y;
	diff = (diff > 0.0f) ? diff : -diff;
	if (diff <= paddle_H/2.0f && mBallPos.x <= 25.0f && mBallPos.y >= 20.0f && mBallVel.x < 0.0f) {
		mBallVel.x *= -1.0f;
	}
	else if (mBallPos.x <= 0.0f) {
		mIsRunning = false;
	}
	else if (mBallPos.x >= (1024.0f - thickness) && mBallVel.x > 0.0f) {
		mBallVel.x *= -1.0f;
	}
	if (mBallPos.y <= thickness && mBallVel.y < 0.0f) {
		mBallVel.y *= -1;
	}
	else if (mBallPos.y >= (768 - thickness) && mBallVel.y > 0.0f){
		mBallVel.y *= -1;
	}

}

void Game::GenerateOutput() {
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255); //黒色

	SDL_RenderClear(mRenderer); //背景

	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255); //白色

	SDL_Rect wall{
		0, //Top left x
		0, //Top left y
		WIN_W, //width
		thickness //height
	};

	SDL_RenderFillRect(mRenderer, &wall);
	wall.y = 768 - thickness;
	SDL_RenderFillRect(mRenderer, &wall);

	wall.x = WIN_W - thickness;
	wall.y = 0;
	wall.w = thickness;
	wall.h = WIN_H;
	SDL_RenderFillRect(mRenderer, &wall);

	SDL_Rect paddle{
		static_cast<int>(lPaddlesPos.x),
		static_cast<int>(lPaddlesPos.y - paddle_H / 2),
		thickness,
		static_cast<int>(paddle_H)
	};
	SDL_RenderFillRect(mRenderer, &paddle);

	SDL_Rect ball{
		static_cast<int>(mBallPos.x - thickness / 2),
		static_cast<int>(mBallPos.y - thickness / 2),
		thickness,
		thickness
	};
	SDL_RenderFillRect(mRenderer, &ball);

	SDL_RenderPresent(mRenderer);
}