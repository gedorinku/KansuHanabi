#pragma once
#include <Siv3D.hpp>
#include "..\Basis2D.h"

namespace HanabiCraft {
namespace BombViewer {


class BombViewer {
private:
	Area2D viewport;
public:
	BombViewer(const Area2D &viewport);
};


}
}