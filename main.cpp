#include "Game.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"

//�����̓���Paddle��w,s�ŏ㉺�ɓ���
//���ǈ�
//��ʐ؂�ւ����遨SDL��������̂ŁASDL��\���������܂܉�ʑJ�ڂ��s����GameClass�̒��Ŋe�V�[���̌Ăяo�����s��
//Paddle�̈ʒu�������ɂ��ău���b�N�����ɂ���
//�{�[�������������u���b�N��������
//�u���b�N���S����������"Congratulations"�ƕ\������

//�d�l
//main.cpp
//���N���XScene,�p���������N���XTitleScene(�^�C�g�����),GameScene(�Q�[�����),ResultScene(���ʉ��)
//Game�������S�ʁ��X�ɍׂ��������ł������Ȃ�class�ɕ������ĔώG�ɂȂ�Ȃ��悤�ɂ���

int main(int argc, char** argv) {
	Game game;
	// ��ʓI�ȏ���
	bool game_success = game.Initialize();
	if (game_success) {
		game.Run(); //�J�n
	}
	game.Shutdown(); //�I��
	
	return 0;
}