#pragma once
#include "Util.h"
#include <vector>
#include <Siv3D.hpp>

namespace HanabiCraft {
namespace Function {


class AbstractFunction {
private:

	Vec2 rate, translation;

public:

	AbstractFunction() : rate(1, 1), translation(0, 0) {}

	AbstractFunction(const Vec2 &rate, const Vec2 &translation) : rate(rate), translation(translation) {}

	virtual double WeakEval(double x) = 0;

	virtual std::vector<SP<AbstractFunction>> GetChildren() = 0;

	virtual void SetChilren(const std::vector<SP<AbstractFunction>> &children) = 0;

	virtual SP<AbstractFunction> Clone(const std::vector<SP<AbstractFunction>> &newChildren) = 0;

	double Eval(double x) {
		return (WeakEval((x - translation.x)/rate.x) + translation.y)*rate.y;
	}

	Vec2 GetRate() { return rate; }

	void SetRate(const Vec2 &rate) { this->rate = rate; }

	double GetRateX() { return rate.x; }

	double GetRateY() { return rate.y; }

	void SetRateX(double x) { rate.x = x; }

	void SetRateY(double y) { rate.y = y; }

	Vec2 GetTranslation() { return translation; }

	void SetTranslation(const Vec2 &translation) { this->translation = translation; }

	double GetTranslationX() { return translation.x; }

	double GetTranslationY() { return translation.y; }

	void SetTranslationX(double x) { translation.x = x; }

	void SetTranslationY(double y) { translation.y = y; }

	void Translate(const Vec2 &delta) {
		SetTranslationX(GetTranslationX() - delta.x*GetRateX());
		SetTranslationY(GetTranslationY() + delta.y/GetRateY());
	}
};


}
}