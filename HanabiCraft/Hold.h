#pragma once
#include <Siv3D.hpp>

namespace HanabiCraft {


class Hold {
private:

	int thresholdDuration;
	double r;
	Vec2 clickedPos;
	bool lastIsHeld;
	bool isHeld;

public:

	Hold(int thresholdDuration, double r);

	void Update();

	Vec2 GetClickedPos();

	//�O���Update���Ƀz�[���h���삪����������
	bool IsStarted();

	//�z�[���h�������Ă��邩
	bool IsHeld();

	bool LastIsHeld();

	//�O���Update���Ƀz�[���h���삪�I��������
	bool IsFinished();
};


}