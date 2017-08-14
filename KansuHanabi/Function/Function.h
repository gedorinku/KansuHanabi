#pragma once
#include <memory>
#include <list>

namespace hanabi {
	class Function
	{
	public:
		Function() = default;
		Function(const Function& function) : innerFunctions(function.innerFunctions) {};
		virtual ~Function() = default;

		/// <summary>
		/// 引数xに対する関数の値を返します。
		/// </summary>
		/// <param name="x">
		/// 引数x
		/// </param>
		/// <returns>
		/// 関数の値
		/// </returns>
		virtual double Evaluate(double x);

		/// <summary>
		/// 関数を合成します。sin(f(x))ってなる。
		/// </summary>
		/// <param name="function">
		/// 関数
		/// </param>
		/// <returns>
		/// 関数
		/// </returns>
		template<class Type, class Head, class... Tail>
		static Type compose(const Head& head, const Tail&... tail);

		/// <summary>
		/// 関数を合成します。sin(f(x))ってなる。
		/// </summary>
		/// <param name="function">
		/// 関数
		/// </param>
		/// <returns>
		/// 関数
		/// </returns>
		template<class Type, class Head, class... Tail>
		static Type composeEmplace(Head&& head, Tail&&... tail);

	protected:
		std::list<std::shared_ptr<Function>> innerFunctions;

	private:
		template <class Type>
		static Type compose();

		template <class Type>
		static Type composeEmplace();
	};

	template <class Type>
	Type Function::compose()
	{
		return Type();
	}

	template<class Type, class Head, class... Tail>
	Type Function::compose(const Head& head, const Tail&... tail)
	{
		auto result = compose<Type>(std::move(tail)...);
		static_cast<Function>(result)
			.innerFunctions
			.push_front(
				std::make_shared<Head>(head)
			);
		return result;
	}

	template <class Type>
	Type Function::composeEmplace()
	{
		return Type();
	}

	template<class Type, class Head, class... Tail>
	Type Function::composeEmplace(Head&& head, Tail&&... tail)
	{
		auto result = composeEmplace<Type>(std::move(tail)...);
		static_cast<Function>(result)
			.innerFunctions
			.push_front(
				std::make_shared<Head>(head)
			);
		return result;
	}
}

