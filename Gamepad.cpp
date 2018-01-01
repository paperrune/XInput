#include <math.h>

#include "Gamepad.h"

#pragma comment(lib, "XInput9_1_0.lib")

Gamepad::Gamepad(int id){
	this->id = id;
}

void Gamepad::Update(){
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	XInputGetState(id, &state);
}
void Gamepad::Vibrate(float left, float right){
	XINPUT_VIBRATION vibration;

	ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

	int left_motor  = int(left * 65535);
	int right_motor = int(right * 65535);

	vibration.wLeftMotorSpeed  = left_motor;
	vibration.wRightMotorSpeed = right_motor;

	XInputSetState(id, &vibration);
}

bool Gamepad::isConnected(){
	ZeroMemory(&state, sizeof(XINPUT_STATE));
	return (XInputGetState(id, &state) == ERROR_SUCCESS);
}

bool Gamepad::A(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_A);
}
bool Gamepad::B(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_B);
}
bool Gamepad::X(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_X);
}
bool Gamepad::Y(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y);
}
bool Gamepad::DPAD_UP(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP);
}
bool Gamepad::DPAD_DOWN(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN);
}
bool Gamepad::DPAD_LEFT(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT);
}
bool Gamepad::DPAD_RIGHT(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT);
}
bool Gamepad::LEFT_SHOULDER(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
}
bool Gamepad::RIGHT_SHOULDER(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);
}
bool Gamepad::LEFT_THUMB(float &x, float &y){
	x = (state.Gamepad.sThumbLX + 0.5) / 32767.5;
	y = (state.Gamepad.sThumbLY + 0.5) / 32767.5;

	return (abs(state.Gamepad.sThumbLX) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE || abs(state.Gamepad.sThumbLY) > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
}
bool Gamepad::RIGHT_THUMB(float &x, float &y){
	x = (state.Gamepad.sThumbRX + 0.5) / 32767.5;
	y = (state.Gamepad.sThumbRY + 0.5) / 32767.5;

	return (abs(state.Gamepad.sThumbRX) > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE || abs(state.Gamepad.sThumbRY) > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
}
bool Gamepad::START(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_START);
}
bool Gamepad::BACK(){
	return (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK);
}

float Gamepad::LEFT_TRIGGER(){
	unsigned char axis = state.Gamepad.bLeftTrigger;

	if (axis > XINPUT_GAMEPAD_TRIGGER_THRESHOLD){
		return axis / 255.0;
	}
	return 0;
}
float Gamepad::RIGHT_TRIGGER(){
	unsigned char axis = state.Gamepad.bRightTrigger;

	if (axis > XINPUT_GAMEPAD_TRIGGER_THRESHOLD){
		return axis / 255.0;
	}
	return 0;
}