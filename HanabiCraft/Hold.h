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

	//前回のUpdate時にホールド操作が発生したか
	bool IsStarted();

	//ホールドし続けているか
	bool IsHeld();

	bool LastIsHeld();

	//前回のUpdate時にホールド操作が終了したか
	bool IsFinished();
};


}