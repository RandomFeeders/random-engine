#pragma once

// Extracted from GLFW/glfw3.h

#define RE_MOD_SHIFT						BIT(0)
#define RE_MOD_CONTROL						BIT(1)
#define RE_MOD_ALT							BIT(2)
#define RE_MOD_SUPER						BIT(3)
#define RE_MOD_CAPS_LOCK					BIT(4)
#define RE_MOD_NUM_LOCK						BIT(5)

#define RE_MOUSE_LBUTTON					0x00
#define RE_MOUSE_RBUTTON					0x01
#define RE_MOUSE_MBUTTON					0x02
#define RE_MOUSE_BUTTON_4					0x03
#define RE_MOUSE_BUTTON_5					0x04
#define RE_MOUSE_BUTTON_6					0x05
#define RE_MOUSE_BUTTON_7					0x06
#define RE_MOUSE_BUTTON_8					0x07

#define RE_KEY_0							0x30
#define RE_KEY_1							0x31
#define RE_KEY_2							0x32
#define RE_KEY_3							0x33
#define RE_KEY_4							0x34
#define RE_KEY_5							0x35
#define RE_KEY_6							0x36
#define RE_KEY_7							0x37
#define RE_KEY_8							0x38
#define RE_KEY_9							0x39

#define RE_KEY_APOSTROPHE					0x27 
#define RE_KEY_COMMA						0x2C
#define RE_KEY_MINUS						0x2D
#define RE_KEY_PERIOD						0x2E
#define RE_KEY_SLASH						0x2F
#define RE_KEY_SEMICOLON					0x3B
#define RE_KEY_EQUAL						0x3D
#define RE_KEY_LEFT_BRACKET					0x5B
#define RE_KEY_BACKSLASH					0x5C
#define RE_KEY_RIGHT_BRACKET				0x5D
#define RE_KEY_GRAVE_ACCENT					0x5E

#define RE_KEY_A							0x41
#define RE_KEY_B							0x42
#define RE_KEY_C							0x43
#define RE_KEY_D							0x44
#define RE_KEY_E							0x45
#define RE_KEY_F							0x46
#define RE_KEY_G							0x47
#define RE_KEY_H							0x48
#define RE_KEY_I							0x49
#define RE_KEY_J							0x4A
#define RE_KEY_K							0x4B
#define RE_KEY_L							0x4C
#define RE_KEY_M							0x4D
#define RE_KEY_N							0x4E
#define RE_KEY_O							0x4F
#define RE_KEY_P							0x50
#define RE_KEY_Q							0x51
#define RE_KEY_R							0x52
#define RE_KEY_S							0x53
#define RE_KEY_T							0x54
#define RE_KEY_U							0x55
#define RE_KEY_V							0x56
#define RE_KEY_W							0x57
#define RE_KEY_X							0x58
#define RE_KEY_Y							0x59
#define RE_KEY_Z							0x5A

#define RE_KEY_NUM0							0x140
#define RE_KEY_NUM1							0x141
#define RE_KEY_NUM2							0x142
#define RE_KEY_NUM3							0x143
#define RE_KEY_NUM4							0x144
#define RE_KEY_NUM5							0x145
#define RE_KEY_NUM6							0x146
#define RE_KEY_NUM7							0x147
#define RE_KEY_NUM8							0x148
#define RE_KEY_NUM9							0x149
#define RE_KEY_DECIMAL						0x14A
#define RE_KEY_DIVIDE						0x14B
#define RE_KEY_MULTIPLY						0x14C
#define RE_KEY_SUBTRACT						0x14D
#define RE_KEY_ADD							0x14E
#define RE_KEY_ENTER						0x14F
#define RE_KEY_EQUAL						0x150

#define RE_KEY_LEFT_SHIFT					0x154
#define RE_KEY_LEFT_CONTROL					0x155
#define RE_KEY_LEFT_ALT						0x156
#define RE_KEY_LEFT_SUPER					0x157
#define RE_KEY_RIGHT_SHIFT					0x158
#define RE_KEY_RIGHT_CONTROL				0x159
#define RE_KEY_RIGHT_ALT					0x15A
#define RE_KEY_RIGHT_SUPER					0x15B
#define RE_KEY_MENU							0x15C

#define RE_KEY_ESCAPE						0x100
#define RE_KEY_ENTER						0x101
#define RE_KEY_TAB							0x102
#define RE_KEY_BACKSPACE					0x103
#define RE_KEY_INSERT						0x104
#define RE_KEY_DELETE						0x105
#define RE_KEY_RIGHT						0x106
#define RE_KEY_LEFT							0x107
#define RE_KEY_DOWN							0x108
#define RE_KEY_UP							0x109
#define RE_KEY_PAGE_UP						0x10A
#define RE_KEY_PAGE_DOWN					0x10B
#define RE_KEY_HOME							0x10C
#define RE_KEY_END							0x10D
#define RE_KEY_CAPS_LOCK					0x118
#define RE_KEY_SCROLL_LOCK					0x119
#define RE_KEY_NUM_LOCK						0x11A
#define RE_KEY_PRINT_SCREEN					0x11B
#define RE_KEY_PAUSE						0x11C

#define RE_KEY_F1							0x122
#define RE_KEY_F2							0x123
#define RE_KEY_F3							0x124
#define RE_KEY_F4							0x125
#define RE_KEY_F5							0x126
#define RE_KEY_F6							0x127
#define RE_KEY_F7							0x128
#define RE_KEY_F8							0x129
#define RE_KEY_F9							0x12A
#define RE_KEY_F10							0x12B
#define RE_KEY_F11							0x12C
#define RE_KEY_F12							0x12D
#define RE_KEY_F13							0x12E
#define RE_KEY_F14							0x12F
#define RE_KEY_F15							0x130
#define RE_KEY_F16							0x131
#define RE_KEY_F17							0x132
#define RE_KEY_F18							0x133
#define RE_KEY_F19							0x134
#define RE_KEY_F20							0x135
#define RE_KEY_F21							0x136
#define RE_KEY_F22							0x137
#define RE_KEY_F23							0x138
#define RE_KEY_F24							0x139
#define RE_KEY_F25							0x13A

#define RE_HAT_CENTERED						0x00
#define RE_HAT_UP							BIT(0)
#define RE_HAT_RIGHT						BIT(1)
#define RE_HAT_DOWN							BIT(2)
#define RE_HAT_LEFT							BIT(3)
#define RE_HAT_RIGHT_UP						(GLFW_HAT_RIGHT | GLFW_HAT_UP)
#define RE_HAT_RIGHT_DOWN					(GLFW_HAT_RIGHT | GLFW_HAT_DOWN)
#define RE_HAT_LEFT_UP						(GLFW_HAT_LEFT  | GLFW_HAT_UP)
#define RE_HAT_LEFT_DOWN					(GLFW_HAT_LEFT  | GLFW_HAT_DOWN)

#define RE_JOYSTICK_1						0x00
#define RE_JOYSTICK_2						0x01
#define RE_JOYSTICK_3						0x02
#define RE_JOYSTICK_4						0x03
#define RE_JOYSTICK_5						0x04
#define RE_JOYSTICK_6						0x05
#define RE_JOYSTICK_7						0x06
#define RE_JOYSTICK_8						0x07
#define RE_JOYSTICK_9						0x08
#define RE_JOYSTICK_10						0x09
#define RE_JOYSTICK_11						0x0A
#define RE_JOYSTICK_12						0x0B
#define RE_JOYSTICK_13						0x0C
#define RE_JOYSTICK_14						0x0D
#define RE_JOYSTICK_15						0x0E
#define RE_JOYSTICK_16						0x0F

#define RE_GAMEPAD_BUTTON_1					0x00
#define RE_GAMEPAD_BUTTON_2					0x01
#define RE_GAMEPAD_BUTTON_3					0x02
#define RE_GAMEPAD_BUTTON_4					0x03
#define RE_GAMEPAD_BUTTON_5					0x04
#define RE_GAMEPAD_BUTTON_6					0x05
#define RE_GAMEPAD_BUTTON_7					0x06
#define RE_GAMEPAD_BUTTON_8					0x07
#define RE_GAMEPAD_BUTTON_9					0x09
#define RE_GAMEPAD_BUTTON_10				0x0A
#define RE_GAMEPAD_BUTTON_13				0x08

#define RE_GAMEPAD_BUTTON_DPAD_UP			0x0B
#define RE_GAMEPAD_BUTTON_DPAD_RIGHT		0x0C
#define RE_GAMEPAD_BUTTON_DPAD_DOWN			0x0D
#define RE_GAMEPAD_BUTTON_DPAD_LEFT			0x0E

#define RE_GAMEPAD_BUTTON_GUIDE				RE_GAMEPAD_BUTTON_13

#define RE_GAMEPAD_BUTTON_A					RE_GAMEPAD_BUTTON_1
#define RE_GAMEPAD_BUTTON_B					RE_GAMEPAD_BUTTON_2
#define RE_GAMEPAD_BUTTON_X					RE_GAMEPAD_BUTTON_3
#define RE_GAMEPAD_BUTTON_Y					RE_GAMEPAD_BUTTON_4
#define RE_GAMEPAD_BUTTON_LEFT_BUMPER		RE_GAMEPAD_BUTTON_5
#define RE_GAMEPAD_BUTTON_RIGHT_BUMPER		RE_GAMEPAD_BUTTON_6
#define RE_GAMEPAD_BUTTON_BACK				RE_GAMEPAD_BUTTON_7
#define RE_GAMEPAD_BUTTON_START				RE_GAMEPAD_BUTTON_8
#define RE_GAMEPAD_BUTTON_LEFT_THUMB		RE_GAMEPAD_BUTTON_9
#define RE_GAMEPAD_BUTTON_RIGHT_THUMB		RE_GAMEPAD_BUTTON_10

#define RE_GAMEPAD_BUTTON_CROSS				RE_GAMEPAD_BUTTON_1
#define RE_GAMEPAD_BUTTON_CIRCLE			RE_GAMEPAD_BUTTON_2
#define RE_GAMEPAD_BUTTON_SQUARE			RE_GAMEPAD_BUTTON_3
#define RE_GAMEPAD_BUTTON_TRIANGLE			RE_GAMEPAD_BUTTON_4
#define RE_GAMEPAD_BUTTON_L1				RE_GAMEPAD_BUTTON_5
#define RE_GAMEPAD_BUTTON_R1				RE_GAMEPAD_BUTTON_6
#define RE_GAMEPAD_BUTTON_SELECT			RE_GAMEPAD_BUTTON_7
#define RE_GAMEPAD_BUTTON_START				RE_GAMEPAD_BUTTON_8
#define RE_GAMEPAD_BUTTON_L3				RE_GAMEPAD_BUTTON_9
#define RE_GAMEPAD_BUTTON_R3				RE_GAMEPAD_BUTTON_10

#define RE_GAMEPAD_AXIS_LEFT_X				0x00
#define RE_GAMEPAD_AXIS_LEFT_Y				0x01
#define RE_GAMEPAD_AXIS_RIGHT_X				0x02
#define RE_GAMEPAD_AXIS_RIGHT_Y				0x03
#define RE_GAMEPAD_AXIS_LEFT_TRIGGER		0x04
#define RE_GAMEPAD_AXIS_RIGHT_TRIGGER		0x05
#define RE_GAMEPAD_AXIS_L2					RE_GAMEPAD_AXIS_LEFT_TRIGGER
#define RE_GAMEPAD_AXIS_R2					RE_GAMEPAD_AXIS_RIGHT_TRIGGER