#include "TitleScene.h"
#include "Scene.h"

TitleScene::TitleScene(class Game* game)
:Scene(game) {
	//コンストラクタ
}

TitleScene::~TitleScene() {
	//デストラクタ
}

void TitleScene::Start() {

}

void TitleScene::Update(float deltaTime) {

}

void TitleScene::ProcessInput(const Uint8* state) {
	if (state[SDL_SCANCODE_SPACE]) {
		mGame->
	}
}

std::string const TitleScene::GetSceneName()
{
	return "GameStart";
}


