#include "TitleScene.h"
#include "Scene.h"

TitleScene::TitleScene(class Game* game)
:Scene(game) {
	//�R���X�g���N�^
}

TitleScene::~TitleScene() {
	//�f�X�g���N�^
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


