#include "Game.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"

//左側の動くPaddleはw,sで上下に動く
//改良案
//画面切り替えする→SDLが干渉するので、SDLを表示させたまま画面遷移を行う→GameClassの中で各シーンの呼び出しを行う
//Paddleの位置を下側にしてブロック崩しにする
//ボールが当たったブロックが消える
//ブロックが全部消えたら"Congratulations"と表示する

//仕様
//main.cpp
//基底クラスScene,継承させたクラスTitleScene(タイトル画面),GameScene(ゲーム画面),ResultScene(結果画面)
//Game→処理全般→更に細かく分離できそうならclassに分離して煩雑にならないようにする

int main(int argc, char** argv) {
	Game game;
	// 一般的な処理
	bool game_success = game.Initialize();
	if (game_success) {
		game.Run(); //開始
	}
	game.Shutdown(); //終了
	
	return 0;
}