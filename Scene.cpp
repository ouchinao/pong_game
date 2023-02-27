#include "Scene.h"


Scene::Scene(class Game* game) 
:mGame(game) {
	//コンストラクタ
}

Scene::~Scene() {
	//デストラクタ
}

void Scene::Start() {

}

void Scene::Update(float deltaTime) {

}

void Scene::ProcessInput(const Uint8* state) {

}

std::string const Scene::GetSceneName() {

	return "";
}



