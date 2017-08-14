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
		/// ����x�ɑ΂���֐��̒l��Ԃ��܂��B
		/// </summary>
		/// <param name="x">
		/// ����x
		/// </param>
		/// <returns>
		/// �֐��̒l
		/// </returns>
		virtual double Evaluate(double x);

		/// <summary>
		/// �֐����������܂��Bsin(f(x))���ĂȂ�B
		/// </summary>
		/// <param name="function">
		/// �֐�
		/// </param>
		/// <returns>
		/// �֐�
		/// </returns>
		template<class Type, class Head, class... Tail>
		static Type compose(const Head& head, const Tail&... tail);

		/// <summary>
		/// �֐����������܂��Bsin(f(x))���ĂȂ�B
		/// </summary>
		/// <param name="function">
		/// �֐�
		/// </param>
		/// <returns>
		/// �֐�
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

