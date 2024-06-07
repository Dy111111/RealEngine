#pragma once

namespace Real
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

#define RE_KEY_SPACE           ::Real::Key::Space
#define RE_KEY_APOSTROPHE      ::Real::Key::Apostrophe    /* ' */
#define RE_KEY_COMMA           ::Real::Key::Comma         /* , */
#define RE_KEY_MINUS           ::Real::Key::Minus         /* - */
#define RE_KEY_PERIOD          ::Real::Key::Period        /* . */
#define RE_KEY_SLASH           ::Real::Key::Slash         /* / */
#define RE_KEY_0               ::Real::Key::D0
#define RE_KEY_1               ::Real::Key::D1
#define RE_KEY_2               ::Real::Key::D2
#define RE_KEY_3               ::Real::Key::D3
#define RE_KEY_4               ::Real::Key::D4
#define RE_KEY_5               ::Real::Key::D5
#define RE_KEY_6               ::Real::Key::D6
#define RE_KEY_7               ::Real::Key::D7
#define RE_KEY_8               ::Real::Key::D8
#define RE_KEY_9               ::Real::Key::D9
#define RE_KEY_SEMICOLON       ::Real::Key::Semicolon     /* ; */
#define RE_KEY_EQUAL           ::Real::Key::Equal         /* = */
#define RE_KEY_A               ::Real::Key::A
#define RE_KEY_B               ::Real::Key::B
#define RE_KEY_C               ::Real::Key::C
#define RE_KEY_D               ::Real::Key::D
#define RE_KEY_E               ::Real::Key::E
#define RE_KEY_F               ::Real::Key::F
#define RE_KEY_G               ::Real::Key::G
#define RE_KEY_H               ::Real::Key::H
#define RE_KEY_I               ::Real::Key::I
#define RE_KEY_J               ::Real::Key::J
#define RE_KEY_K               ::Real::Key::K
#define RE_KEY_L               ::Real::Key::L
#define RE_KEY_M               ::Real::Key::M
#define RE_KEY_N               ::Real::Key::N
#define RE_KEY_O               ::Real::Key::O
#define RE_KEY_P               ::Real::Key::P
#define RE_KEY_Q               ::Real::Key::Q
#define RE_KEY_R               ::Real::Key::R
#define RE_KEY_S               ::Real::Key::S
#define RE_KEY_T               ::Real::Key::T
#define RE_KEY_U               ::Real::Key::U
#define RE_KEY_V               ::Real::Key::V
#define RE_KEY_W               ::Real::Key::W
#define RE_KEY_X               ::Real::Key::X
#define RE_KEY_Y               ::Real::Key::Y
#define RE_KEY_Z               ::Real::Key::Z
#define RE_KEY_LEFT_BRACKET    ::Real::Key::LeftBracket   /* [ */
#define RE_KEY_BACKSLASH       ::Real::Key::Backslash     /* \ */
#define RE_KEY_RIGHT_BRACKET   ::Real::Key::RightBracket  /* ] */
#define RE_KEY_GRAVE_ACCENT    ::Real::Key::GraveAccent   /* ` */
#define RE_KEY_WORLD_1         ::Real::Key::World1        /* non-US #1 */
#define RE_KEY_WORLD_2         ::Real::Key::World2        /* non-US #2 */

#define RE_KEY_ESCAPE          ::Real::Key::Escape
#define RE_KEY_ENTER           ::Real::Key::Enter
#define RE_KEY_TAB             ::Real::Key::Tab
#define RE_KEY_BACKSPACE       ::Real::Key::Backspace
#define RE_KEY_INSERT          ::Real::Key::Insert
#define RE_KEY_DELETE          ::Real::Key::Delete
#define RE_KEY_RIGHT           ::Real::Key::Right
#define RE_KEY_LEFT            ::Real::Key::Left
#define RE_KEY_DOWN            ::Real::Key::Down
#define RE_KEY_UP              ::Real::Key::Up
#define RE_KEY_PAGE_UP         ::Real::Key::PageUp
#define RE_KEY_PAGE_DOWN       ::Real::Key::PageDown
#define RE_KEY_HOME            ::Real::Key::Home
#define RE_KEY_END             ::Real::Key::End
#define RE_KEY_CAPS_LOCK       ::Real::Key::CapsLock
#define RE_KEY_SCROLL_LOCK     ::Real::Key::ScrollLock
#define RE_KEY_NUM_LOCK        ::Real::Key::NumLock
#define RE_KEY_PRINT_SCREEN    ::Real::Key::PrintScreen
#define RE_KEY_PAUSE           ::Real::Key::Pause
#define RE_KEY_F1              ::Real::Key::F1
#define RE_KEY_F2              ::Real::Key::F2
#define RE_KEY_F3              ::Real::Key::F3
#define RE_KEY_F4              ::Real::Key::F4
#define RE_KEY_F5              ::Real::Key::F5
#define RE_KEY_F6              ::Real::Key::F6
#define RE_KEY_F7              ::Real::Key::F7
#define RE_KEY_F8              ::Real::Key::F8
#define RE_KEY_F9              ::Real::Key::F9
#define RE_KEY_F10             ::Real::Key::F10
#define RE_KEY_F11             ::Real::Key::F11
#define RE_KEY_F12             ::Real::Key::F12
#define RE_KEY_F13             ::Real::Key::F13
#define RE_KEY_F14             ::Real::Key::F14
#define RE_KEY_F15             ::Real::Key::F15
#define RE_KEY_F16             ::Real::Key::F16
#define RE_KEY_F17             ::Real::Key::F17
#define RE_KEY_F18             ::Real::Key::F18
#define RE_KEY_F19             ::Real::Key::F19
#define RE_KEY_F20             ::Real::Key::F20
#define RE_KEY_F21             ::Real::Key::F21
#define RE_KEY_F22             ::Real::Key::F22
#define RE_KEY_F23             ::Real::Key::F23
#define RE_KEY_F24             ::Real::Key::F24
#define RE_KEY_F25             ::Real::Key::F25

/* Keypad */
#define RE_KEY_KP_0            ::Real::Key::KP0
#define RE_KEY_KP_1            ::Real::Key::KP1
#define RE_KEY_KP_2            ::Real::Key::KP2
#define RE_KEY_KP_3            ::Real::Key::KP3
#define RE_KEY_KP_4            ::Real::Key::KP4
#define RE_KEY_KP_5            ::Real::Key::KP5
#define RE_KEY_KP_6            ::Real::Key::KP6
#define RE_KEY_KP_7            ::Real::Key::KP7
#define RE_KEY_KP_8            ::Real::Key::KP8
#define RE_KEY_KP_9            ::Real::Key::KP9
#define RE_KEY_KP_DECIMAL      ::Real::Key::KPDecimal
#define RE_KEY_KP_DIVIDE       ::Real::Key::KPDivide
#define RE_KEY_KP_MULTIPLY     ::Real::Key::KPMultiply
#define RE_KEY_KP_SUBTRACT     ::Real::Key::KPSubtract
#define RE_KEY_KP_ADD          ::Real::Key::KPAdd
#define RE_KEY_KP_ENTER        ::Real::Key::KPEnter
#define RE_KEY_KP_EQUAL        ::Real::Key::KPEqual

#define RE_KEY_LEFT_SHIFT      ::Real::Key::LeftShift
#define RE_KEY_LEFT_CONTROL    ::Real::Key::LeftControl
#define RE_KEY_LEFT_ALT        ::Real::Key::LeftAlt
#define RE_KEY_LEFT_SUPER      ::Real::Key::LeftSuper
#define RE_KEY_RIGHT_SHIFT     ::Real::Key::RightShift
#define RE_KEY_RIGHT_CONTROL   ::Real::Key::RightControl
#define RE_KEY_RIGHT_ALT       ::Real::Key::RightAlt
#define RE_KEY_RIGHT_SUPER     ::Real::Key::RightSuper
#define RE_KEY_MENU            ::Real::Key::Menu