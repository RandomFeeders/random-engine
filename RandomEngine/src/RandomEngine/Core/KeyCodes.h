#pragma once

namespace RandomEngine {

	typedef enum class MouseCode : unsigned short {		
		Button1			= 0x00,
		Button2			= 0x01,
		Button3			= 0x02,
		Button4			= 0x03,
		Button5			= 0x04,
		Button6			= 0x05,
		Button7			= 0x06,
		Button8			= 0x07,

		LeftButton		= Button1,
		RightButton		= Button2,
		MiddleButton	= Button3
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int>(mouseCode);
		return os;
	}

	typedef enum class KeyCode : unsigned short {
		// Extracted from GLFW/glfw3.h		

		Key0			= 0x30,
		Key1			= 0x31,
		Key2			= 0x32,
		Key3			= 0x33,
		Key4			= 0x34,
		Key5			= 0x35,
		Key6			= 0x36,
		Key7			= 0x37,
		Key8			= 0x38,
		Key9			= 0x39,

		Apostrophe		= 0x27,
		Comma			= 0x2C,
		Minus			= 0x2D,
		Period			= 0x2E,
		Slash			= 0x2F,
		Semicolon		= 0x3B,
		Equal			= 0x3D,
		LeftBracket		= 0x5B,
		Backslash		= 0x5C,
		RightBracket	= 0x5D,
		GraveAccent		= 0x5E,

		A				= 0x41,
		B				= 0x42,
		C				= 0x43,
		D				= 0x44,
		E				= 0x45,
		F				= 0x46,
		G				= 0x47,
		H				= 0x48,
		I				= 0x49,
		J				= 0x4A,
		K				= 0x4B,
		L				= 0x4C,
		M				= 0x4D,
		N				= 0x4E,
		O				= 0x4F,
		P				= 0x50,
		Q				= 0x51,
		R				= 0x52,
		S				= 0x53,
		T				= 0x54,
		U				= 0x55,
		V				= 0x56,
		W				= 0x57,
		X				= 0x58,
		Y				= 0x59,
		Z				= 0x5A,

		Num0			= 0x140,
		Num1			= 0x141,
		Num2			= 0x142,
		Num3			= 0x143,
		Num4			= 0x144,
		Num5			= 0x145,
		Num6			= 0x146,
		Num7			= 0x147,
		Num8			= 0x148,
		Num9			= 0x149,
		NumDecimal		= 0x14A,
		NumDivide		= 0x14B,
		NumMultiply		= 0x14C,
		NumSubtract		= 0x14D,
		NumAdd			= 0x14E,
		NumEnter		= 0x14F,
		NumEqual		= 0x150,

		LeftShift		= 0x154,
		LeftControl		= 0x155,
		LeftAlt			= 0x156,
		LeftSuper		= 0x157,
		RightShift		= 0x158,
		RightControl	= 0x159,
		RightAlt		= 0x15A,
		RightSuper		= 0x15B,
		Menu			= 0x15C,

		Escape			= 0x100,
		Enter			= 0x101,
		Tab				= 0x102,
		Backspace		= 0x103,
		Insert			= 0x104,
		Delete			= 0x105,
		Right			= 0x106,
		Left			= 0x107,
		Down			= 0x108,
		Up				= 0x109,
		PageUp			= 0x10A,
		PageDown		= 0x10B,
		Home			= 0x10C,
		End				= 0x10D,
		CapsLock		= 0x118,
		ScrollLock		= 0x119,
		NumLock			= 0x11A,
		PrintScreen		= 0x11B,
		Pause			= 0x11C,

		F1				= 0x122,
		F2				= 0x123,
		F3				= 0x124,
		F4				= 0x125,
		F5				= 0x126,
		F6				= 0x127,
		F7				= 0x128,
		F8				= 0x129,
		F9				= 0x12A,
		F10				= 0x12B,
		F11				= 0x12C,
		F12				= 0x12D,
		F13				= 0x12E,
		F14				= 0x12F,
		F15				= 0x130,
		F16				= 0x131,
		F17				= 0x132,
		F18				= 0x133,
		F19				= 0x134,
		F20				= 0x135,
		F21				= 0x136,
		F22				= 0x137,
		F23				= 0x138,
		F24				= 0x139,
		F25				= 0x13A
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int>(keyCode);
		return os;
	}

	typedef enum class ModCode : unsigned short {
		Shift		= BIT(0),
		Control		= BIT(1),
		Alt			= BIT(2),
		Super		= BIT(3),
		CapsLock	= BIT(4),
		NumLock		= BIT(5)
	} Mod;

	typedef enum class HatCode : unsigned short {
		Centered	= 0x00,
		Up			= BIT(0),
		Right		= BIT(1),
		Down		= BIT(2),
		Left		= BIT(3),
		RightUp		= (Right | Up),
		RightDown	= (Right | Down),
		LeftUp		= (Left | Up),
		LeftDown	= (Left | Down)
	} Hat;

	typedef enum class JoystickCode : unsigned short {
		Joystick1	= 0x00,
		Joystick2	= 0x01,
		Joystick3	= 0x02,
		Joystick4	= 0x03,
		Joystick5	= 0x04,
		Joystick6	= 0x05,
		Joystick7	= 0x06,
		Joystick8	= 0x07,
		Joystick9	= 0x08,
		Joystick10	= 0x09,
		Joystick11	= 0x0A,
		Joystick12	= 0x0B,
		Joystick13	= 0x0C,
		Joystick14	= 0x0D,
		Joystick15	= 0x0E,
		Joystick16	= 0x0F
	} Joystick;

	typedef enum class GamepadCode : unsigned short {
		Button1			= 0x00,
		Button2			= 0x01,
		Button3			= 0x02,
		Button4			= 0x03,
		Button5			= 0x04,
		Button6			= 0x05,
		Button7			= 0x06,
		Button8			= 0x07,
		Button9			= 0x09,
		Button10		= 0x0A,
		Button13		= 0x08,
		
		DPadUp			= 0x0B,
		DPadRight		= 0x0C,
		DPadDown		= 0x0D,
		DPadLeft		= 0x0E,
		
		Guide			= Button13,
		Start			= Button8,
		
		A				= Button1,
		B				= Button2,
		X				= Button3,
		Y				= Button4,
		LeftBumper		= Button5,
		RightBumper		= Button6,
		Back			= Button7,
		LeftThumb		= Button9,
		RightThumb		= Button10,
		
		Cross			= Button1,
		Circle			= Button2,
		Square			= Button3,
		Triangle		= Button4,
		L1				= Button5,
		R1				= Button6,
		Select			= Button7,
		L3				= Button9,
		R3				= Button10
	} Gamepad;

	typedef enum class GamepadAxisCode {
		LeftX			= 0x00,
		LeftY			= 0x01,
		RightX			= 0x02,
		RightY			= 0x03,
		LeftTrigger		= 0x04,
		RightTrigger	= 0x05,
		L2				= LeftTrigger,
		R2				= RightTrigger
	} GamepadAxis;
}

#define RE_MOD_SHIFT						::RandomEngine::Mod::Shift
#define RE_MOD_CONTROL						::RandomEngine::Mod::Control
#define RE_MOD_ALT							::RandomEngine::Mod::Alt
#define RE_MOD_SUPER						::RandomEngine::Mod::Super
#define RE_MOD_CAPS_LOCK					::RandomEngine::Mod::CapsLock
#define RE_MOD_NUM_LOCK						::RandomEngine::Mod::NumLock

#define RE_MOUSE_BUTTON_1					::RandomEngine::Mouse::Button1
#define RE_MOUSE_BUTTON_2					::RandomEngine::Mouse::Button2
#define RE_MOUSE_BUTTON_3					::RandomEngine::Mouse::Button3
#define RE_MOUSE_BUTTON_4					::RandomEngine::Mouse::Button4
#define RE_MOUSE_BUTTON_5					::RandomEngine::Mouse::Button5
#define RE_MOUSE_BUTTON_6					::RandomEngine::Mouse::Button6
#define RE_MOUSE_BUTTON_7					::RandomEngine::Mouse::Button7
#define RE_MOUSE_BUTTON_8					::RandomEngine::Mouse::Button8
#define RE_MOUSE_LBUTTON					::RandomEngine::Mouse::LeftButton
#define RE_MOUSE_RBUTTON					::RandomEngine::Mouse::RightButton
#define RE_MOUSE_MBUTTON					::RandomEngine::Mouse::MiddleButton

#define RE_KEY_0							::RandomEngine::Key::Key0
#define RE_KEY_1							::RandomEngine::Key::Key1
#define RE_KEY_2							::RandomEngine::Key::Key2
#define RE_KEY_3							::RandomEngine::Key::Key3
#define RE_KEY_4							::RandomEngine::Key::Key4
#define RE_KEY_5							::RandomEngine::Key::Key5
#define RE_KEY_6							::RandomEngine::Key::Key6
#define RE_KEY_7							::RandomEngine::Key::Key7
#define RE_KEY_8							::RandomEngine::Key::Key8
#define RE_KEY_9							::RandomEngine::Key::Key9

#define RE_KEY_APOSTROPHE					::RandomEngine::Key::Apostrophe
#define RE_KEY_COMMA						::RandomEngine::Key::Comma
#define RE_KEY_MINUS						::RandomEngine::Key::Minus
#define RE_KEY_PERIOD						::RandomEngine::Key::Period
#define RE_KEY_SLASH						::RandomEngine::Key::Slash
#define RE_KEY_SEMICOLON					::RandomEngine::Key::Semicolon
#define RE_KEY_EQUAL						::RandomEngine::Key::Equal
#define RE_KEY_LEFT_BRACKET					::RandomEngine::Key::LeftBracket
#define RE_KEY_BACKSLASH					::RandomEngine::Key::Backslash
#define RE_KEY_RIGHT_BRACKET				::RandomEngine::Key::RightBracket
#define RE_KEY_GRAVE_ACCENT					::RandomEngine::Key::GraveAccent

#define RE_KEY_A							::RandomEngine::Key::A
#define RE_KEY_B							::RandomEngine::Key::B
#define RE_KEY_C							::RandomEngine::Key::C
#define RE_KEY_D							::RandomEngine::Key::D
#define RE_KEY_E							::RandomEngine::Key::E
#define RE_KEY_F							::RandomEngine::Key::F
#define RE_KEY_G							::RandomEngine::Key::G
#define RE_KEY_H							::RandomEngine::Key::H
#define RE_KEY_I							::RandomEngine::Key::I
#define RE_KEY_J							::RandomEngine::Key::J
#define RE_KEY_K							::RandomEngine::Key::K
#define RE_KEY_L							::RandomEngine::Key::L
#define RE_KEY_M							::RandomEngine::Key::M
#define RE_KEY_N							::RandomEngine::Key::N
#define RE_KEY_O							::RandomEngine::Key::O
#define RE_KEY_P							::RandomEngine::Key::P
#define RE_KEY_Q							::RandomEngine::Key::Q
#define RE_KEY_R							::RandomEngine::Key::R
#define RE_KEY_S							::RandomEngine::Key::S
#define RE_KEY_T							::RandomEngine::Key::T
#define RE_KEY_U							::RandomEngine::Key::U
#define RE_KEY_V							::RandomEngine::Key::V
#define RE_KEY_W							::RandomEngine::Key::W
#define RE_KEY_X							::RandomEngine::Key::X
#define RE_KEY_Y							::RandomEngine::Key::Y
#define RE_KEY_Z							::RandomEngine::Key::Z

#define RE_KEY_NUM0							::RandomEngine::Key::Num0		
#define RE_KEY_NUM1							::RandomEngine::Key::Num1		
#define RE_KEY_NUM2							::RandomEngine::Key::Num2		
#define RE_KEY_NUM3							::RandomEngine::Key::Num3		
#define RE_KEY_NUM4							::RandomEngine::Key::Num4		
#define RE_KEY_NUM5							::RandomEngine::Key::Num5		
#define RE_KEY_NUM6							::RandomEngine::Key::Num6		
#define RE_KEY_NUM7							::RandomEngine::Key::Num7		
#define RE_KEY_NUM8							::RandomEngine::Key::Num8		
#define RE_KEY_NUM9							::RandomEngine::Key::Num9		
#define RE_KEY_NUMDECIMAL					::RandomEngine::Key::NumDecimal	
#define RE_KEY_NUMDIVIDE					::RandomEngine::Key::NumDivide	
#define RE_KEY_NUMMULTIPLY					::RandomEngine::Key::NumMultiply	
#define RE_KEY_NUMSUBTRACT					::RandomEngine::Key::NumSubtract	
#define RE_KEY_NUMADD						::RandomEngine::Key::NumAdd		
#define RE_KEY_NUMENTER						::RandomEngine::Key::NumEnter	
#define RE_KEY_NUMEQUAL						::RandomEngine::Key::NumEqual	

#define RE_KEY_LEFT_SHIFT					::RandomEngine::Key::LeftShift	
#define RE_KEY_LEFT_CONTROL					::RandomEngine::Key::LeftControl	
#define RE_KEY_LEFT_ALT						::RandomEngine::Key::LeftAlt		
#define RE_KEY_LEFT_SUPER					::RandomEngine::Key::LeftSuper	
#define RE_KEY_RIGHT_SHIFT					::RandomEngine::Key::RightShift	
#define RE_KEY_RIGHT_CONTROL				::RandomEngine::Key::RightControl
#define RE_KEY_RIGHT_ALT					::RandomEngine::Key::RightAlt	
#define RE_KEY_RIGHT_SUPER					::RandomEngine::Key::RightSuper	
#define RE_KEY_MENU							::RandomEngine::Key::Menu		

#define RE_KEY_ESCAPE						::RandomEngine::Key::Escape		
#define RE_KEY_ENTER						::RandomEngine::Key::Enter		
#define RE_KEY_TAB							::RandomEngine::Key::Tab			
#define RE_KEY_BACKSPACE					::RandomEngine::Key::Backspace	
#define RE_KEY_INSERT						::RandomEngine::Key::Insert		
#define RE_KEY_DELETE						::RandomEngine::Key::Delete		
#define RE_KEY_RIGHT						::RandomEngine::Key::Right		
#define RE_KEY_LEFT							::RandomEngine::Key::Left		
#define RE_KEY_DOWN							::RandomEngine::Key::Down		
#define RE_KEY_UP							::RandomEngine::Key::Up			
#define RE_KEY_PAGE_UP						::RandomEngine::Key::PageUp		
#define RE_KEY_PAGE_DOWN					::RandomEngine::Key::PageDown	
#define RE_KEY_HOME							::RandomEngine::Key::Home		
#define RE_KEY_END							::RandomEngine::Key::End			
#define RE_KEY_CAPS_LOCK					::RandomEngine::Key::CapsLock	
#define RE_KEY_SCROLL_LOCK					::RandomEngine::Key::ScrollLock	
#define RE_KEY_NUM_LOCK						::RandomEngine::Key::NumLock		
#define RE_KEY_PRINT_SCREEN					::RandomEngine::Key::PrintScreen	
#define RE_KEY_PAUSE						::RandomEngine::Key::Pause		

#define RE_KEY_F1							::RandomEngine::Key::F1	
#define RE_KEY_F2							::RandomEngine::Key::F2	
#define RE_KEY_F3							::RandomEngine::Key::F3	
#define RE_KEY_F4							::RandomEngine::Key::F4	
#define RE_KEY_F5							::RandomEngine::Key::F5	
#define RE_KEY_F6							::RandomEngine::Key::F6	
#define RE_KEY_F7							::RandomEngine::Key::F7	
#define RE_KEY_F8							::RandomEngine::Key::F8	
#define RE_KEY_F9							::RandomEngine::Key::F9	
#define RE_KEY_F10							::RandomEngine::Key::F10
#define RE_KEY_F11							::RandomEngine::Key::F11
#define RE_KEY_F12							::RandomEngine::Key::F12
#define RE_KEY_F13							::RandomEngine::Key::F13
#define RE_KEY_F14							::RandomEngine::Key::F14
#define RE_KEY_F15							::RandomEngine::Key::F15
#define RE_KEY_F16							::RandomEngine::Key::F16
#define RE_KEY_F17							::RandomEngine::Key::F17
#define RE_KEY_F18							::RandomEngine::Key::F18
#define RE_KEY_F19							::RandomEngine::Key::F19
#define RE_KEY_F20							::RandomEngine::Key::F20
#define RE_KEY_F21							::RandomEngine::Key::F21
#define RE_KEY_F22							::RandomEngine::Key::F22
#define RE_KEY_F23							::RandomEngine::Key::F23
#define RE_KEY_F24							::RandomEngine::Key::F24
#define RE_KEY_F25							::RandomEngine::Key::F25

#define RE_HAT_CENTERED						::RandomEngine::Hat::Centered	
#define RE_HAT_UP							::RandomEngine::Hat::Up			
#define RE_HAT_RIGHT						::RandomEngine::Hat::Right		
#define RE_HAT_DOWN							::RandomEngine::Hat::Down		
#define RE_HAT_LEFT							::RandomEngine::Hat::Left		
#define RE_HAT_RIGHT_UP						::RandomEngine::Hat::RightUp		
#define RE_HAT_RIGHT_DOWN					::RandomEngine::Hat::RightDown	
#define RE_HAT_LEFT_UP						::RandomEngine::Hat::LeftUp		
#define RE_HAT_LEFT_DOWN					::RandomEngine::Hat::LeftDown	

#define RE_JOYSTICK_1						::RandomEngine::Joystick::Joystick1
#define RE_JOYSTICK_2						::RandomEngine::Joystick::Joystick2
#define RE_JOYSTICK_3						::RandomEngine::Joystick::Joystick3
#define RE_JOYSTICK_4						::RandomEngine::Joystick::Joystick4
#define RE_JOYSTICK_5						::RandomEngine::Joystick::Joystick5
#define RE_JOYSTICK_6						::RandomEngine::Joystick::Joystick6
#define RE_JOYSTICK_7						::RandomEngine::Joystick::Joystick7
#define RE_JOYSTICK_8						::RandomEngine::Joystick::Joystick8
#define RE_JOYSTICK_9						::RandomEngine::Joystick::Joystick9
#define RE_JOYSTICK_10						::RandomEngine::Joystick::Joystick10
#define RE_JOYSTICK_11						::RandomEngine::Joystick::Joystick11
#define RE_JOYSTICK_12						::RandomEngine::Joystick::Joystick12
#define RE_JOYSTICK_13						::RandomEngine::Joystick::Joystick13
#define RE_JOYSTICK_14						::RandomEngine::Joystick::Joystick14
#define RE_JOYSTICK_15						::RandomEngine::Joystick::Joystick15
#define RE_JOYSTICK_16						::RandomEngine::Joystick::Joystick16

#define RE_GAMEPAD_BUTTON_1					::RandomEngine::Gamepad::Button1	
#define RE_GAMEPAD_BUTTON_2					::RandomEngine::Gamepad::Button2	
#define RE_GAMEPAD_BUTTON_3					::RandomEngine::Gamepad::Button3	
#define RE_GAMEPAD_BUTTON_4					::RandomEngine::Gamepad::Button4	
#define RE_GAMEPAD_BUTTON_5					::RandomEngine::Gamepad::Button5	
#define RE_GAMEPAD_BUTTON_6					::RandomEngine::Gamepad::Button6	
#define RE_GAMEPAD_BUTTON_7					::RandomEngine::Gamepad::Button7	
#define RE_GAMEPAD_BUTTON_8					::RandomEngine::Gamepad::Button8	
#define RE_GAMEPAD_BUTTON_9					::RandomEngine::Gamepad::Button9	
#define RE_GAMEPAD_BUTTON_10				::RandomEngine::Gamepad::Button10
#define RE_GAMEPAD_BUTTON_13				::RandomEngine::Gamepad::Button13

#define RE_GAMEPAD_BUTTON_DPAD_UP			::RandomEngine::Gamepad::DPadUp
#define RE_GAMEPAD_BUTTON_DPAD_RIGHT		::RandomEngine::Gamepad::DPadRight
#define RE_GAMEPAD_BUTTON_DPAD_DOWN			::RandomEngine::Gamepad::DPadDown
#define RE_GAMEPAD_BUTTON_DPAD_LEFT			::RandomEngine::Gamepad::DPadLeft

#define RE_GAMEPAD_BUTTON_GUIDE				::RandomEngine::Gamepad::Guide
#define RE_GAMEPAD_BUTTON_START				::RandomEngine::Gamepad::Start

#define RE_GAMEPAD_BUTTON_A					::RandomEngine::Gamepad::A
#define RE_GAMEPAD_BUTTON_B					::RandomEngine::Gamepad::B
#define RE_GAMEPAD_BUTTON_X					::RandomEngine::Gamepad::X
#define RE_GAMEPAD_BUTTON_Y					::RandomEngine::Gamepad::Y
#define RE_GAMEPAD_BUTTON_LEFT_BUMPER		::RandomEngine::Gamepad::LeftBumper
#define RE_GAMEPAD_BUTTON_RIGHT_BUMPER		::RandomEngine::Gamepad::RightBumper
#define RE_GAMEPAD_BUTTON_BACK				::RandomEngine::Gamepad::Back
#define RE_GAMEPAD_BUTTON_LEFT_THUMB		::RandomEngine::Gamepad::LeftThumb
#define RE_GAMEPAD_BUTTON_RIGHT_THUMB		::RandomEngine::Gamepad::RightThumb

#define RE_GAMEPAD_BUTTON_CROSS				::RandomEngine::Gamepad::Cross
#define RE_GAMEPAD_BUTTON_CIRCLE			::RandomEngine::Gamepad::Circle
#define RE_GAMEPAD_BUTTON_SQUARE			::RandomEngine::Gamepad::Square
#define RE_GAMEPAD_BUTTON_TRIANGLE			::RandomEngine::Gamepad::Triangle
#define RE_GAMEPAD_BUTTON_L1				::RandomEngine::Gamepad::L1
#define RE_GAMEPAD_BUTTON_R1				::RandomEngine::Gamepad::R1
#define RE_GAMEPAD_BUTTON_SELECT			::RandomEngine::Gamepad::Select
#define RE_GAMEPAD_BUTTON_L3				::RandomEngine::Gamepad::L3
#define RE_GAMEPAD_BUTTON_R3				::RandomEngine::Gamepad::R3

#define RE_GAMEPAD_AXIS_LEFT_X				::RandomEngine::GamepadAxis::LeftX
#define RE_GAMEPAD_AXIS_LEFT_Y				::RandomEngine::GamepadAxis::LeftY
#define RE_GAMEPAD_AXIS_RIGHT_X				::RandomEngine::GamepadAxis::RightX
#define RE_GAMEPAD_AXIS_RIGHT_Y				::RandomEngine::GamepadAxis::RightY
#define RE_GAMEPAD_AXIS_LEFT_TRIGGER		::RandomEngine::GamepadAxis::LeftTrigger
#define RE_GAMEPAD_AXIS_RIGHT_TRIGGER		::RandomEngine::GamepadAxis::RightTrigger
#define RE_GAMEPAD_AXIS_L2					::RandomEngine::GamepadAxis::L2
#define RE_GAMEPAD_AXIS_R2					::RandomEngine::GamepadAxis::R2
