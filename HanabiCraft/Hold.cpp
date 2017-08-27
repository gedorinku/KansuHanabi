#include "Hold.h"

namespace HanabiCraft {


Hold::Hold(int thresholdDuration, double r)
	: thresholdDuration(thresholdDuration), r(r), lastIsHeld(false), isHeld(false) {
}

void Hold::Update() {
	lastIsHeld = isHeld;
	if (Input::MouseL.clicked) {
		clickedPos = Mouse::PosF();
	}
	if (!isHeld &&
		Input::MouseL.pressedDuration >= thresholdDuration &&
		clickedPos.distanceFrom(Mouse::PosF()) <= r) {
		isHeld = true;
	}
	if (Input::MouseL.released)
		isHeld = false;
}

bool Hold::IsStarted() {
	return isHeld == true && lastIsHeld == false;
}

bool Hold::IsHeld() {
	return isHeld;
}

bool Hold::LastIsHeld() {
	return lastIsHeld;
}

bool Hold::IsFinished() {
	return isHeld == false && lastIsHeld == true;
}


}