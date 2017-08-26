#pragma once

namespace HanabiCraft {


class HoldDrag {
private:

	int thresholdDuration;
	double r;
	bool isDragged;
	bool hasReleased;

public:

	HoldDrag(int thresholdDuration, double r);

	void Update();

	bool IsDragged();

	bool HasReleased();

};


}