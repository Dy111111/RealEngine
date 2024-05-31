#pragma once
#include"Real/Core/Core.h"
namespace Real {

	class REAL_API Input
	{
	protected:
		Input() = default;//确保单例
	public:
		Input(const Input&) = delete;//删除了类的拷贝构造函数，不能通过拷贝对象来创建
		Input& operator=(const Input&) = delete;//删除了拷贝赋值运算符。禁止了使用拷贝赋值运算符来赋值 Input 类的实例。
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Scope<Input> s_Instance;
	};

}