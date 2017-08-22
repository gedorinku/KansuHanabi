#pragma once
#include <memory>
template<class T> using SP = std::shared_ptr<T>;
template<class T> using UP = std::unique_ptr<T>;
template<class T> using WP = std::weak_ptr<T>;

namespace HanabiCraft {


class Util {
public:
	
	//SourceがTargetにキャスト可能
	template<class Source, class Target>
	std::vector<Target> CastVector(const std::vector<Source> &source) {
		std::vector<Target> ret; ret.reserve(source.size());
		for each (auto var in source) {
			ret.push_back((Target)var);
		}
		return ret;
	}
};


}