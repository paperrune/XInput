#include <Windows.h>
#include <Xinput.h>

class Gamepad{
private:
	XINPUT_STATE state;

public:
	int id;

	Gamepad(int id);

	void Update();
	void Vibrate(float left = 0, float right = 0);

	bool isConnected();

	bool A();
	bool B();
	bool X();
	bool Y();
	bool DPAD_UP();
	bool DPAD_DOWN();
	bool DPAD_LEFT();
	bool DPAD_RIGHT();
	bool LEFT_SHOULDER();
	bool RIGHT_SHOULDER();
	bool LEFT_THUMB(float &x, float &y);
	bool RIGHT_THUMB(float &x, float &y);
	bool START();
	bool BACK();

	float LEFT_TRIGGER();
	float RIGHT_TRIGGER();
};