#pragma once
#include"Real/Core.h"
namespace Real {

	class REAL_API Input
	{
	protected:
		Input() = default;//ȷ������
	public:
		Input(const Input&) = delete;//ɾ������Ŀ������캯��������ͨ����������������
		Input& operator=(const Input&) = delete;//ɾ���˿�����ֵ���������ֹ��ʹ�ÿ�����ֵ���������ֵ Input ���ʵ����
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
		static Input* s_Instance;
	};

}