#include <stdio.h>

#include "Gamepad.h"

int main(){
	Gamepad gamepad = Gamepad(0);

	if (!gamepad.isConnected()){
		printf("Gamepad is not connected\n");
		return 0;
	}

	for (bool record[16] = { 0, }; gamepad.isConnected();){
		int number_buttons = 16;

		gamepad.Update();

		for (int i = 0; i < number_buttons; i++){
			bool button;

			char name[16];

			float x, y;

			switch (i){
			case 0:
				button = gamepad.A();
				strcpy(name, "A");
				break;
			case 1:
				button = gamepad.B();
				strcpy(name, "B");
				break;
			case 2:
				button = gamepad.X();
				strcpy(name, "X");
				break;
			case 3:
				button = gamepad.Y();
				strcpy(name, "Y");
				break;
			case 4:
				button = gamepad.DPAD_UP();
				strcpy(name, "DPAD UP");
				break;
			case 5:
				button = gamepad.DPAD_DOWN();
				strcpy(name, "DPAD DOWN");
				break;
			case 6:
				button = gamepad.DPAD_LEFT();
				strcpy(name, "DPAD LEFT");
				break;
			case 7:
				button = gamepad.DPAD_RIGHT();
				strcpy(name, "DPAD RIGHT");
				break;
			case 8:
				button = gamepad.LEFT_SHOULDER();
				strcpy(name, "LEFT SHOULDER");
				break;
			case 9:
				button = gamepad.RIGHT_SHOULDER();
				strcpy(name, "RIGHT SHOULDER");
				break;
			case 10:
				button = gamepad.LEFT_THUMB(x, y);
				strcpy(name, "LEFT STICK");
				break;
			case 11:
				button = gamepad.RIGHT_THUMB(x, y);
				strcpy(name, "RIGHT STICK");
				break;
			case 12:
				button = gamepad.START();
				strcpy(name, "START");
				break;
			case 13:
				button = gamepad.BACK();
				strcpy(name, "BACK");
				break;
			case 14:
				button = (gamepad.LEFT_TRIGGER() != 0);
				strcpy(name, "LEFT TRIGGER");
				break;
			case 15:
				button = (gamepad.RIGHT_TRIGGER() != 0);
				strcpy(name, "RIGHT TRIGGER");
				break;
			}

			if (record[i] || button){
				if (i == 10) printf("LEFT STICK	 x: %f, y: %f\n", x, y);
				if (i == 11) printf("RIGHT STICK	x: %f, y: %f\n", x, y);
				if (i == 14) printf("LEFT TRIGGER	power: %f\n", gamepad.LEFT_TRIGGER());
				if (i == 15) printf("RIGHT TRIGGER	power: %f\n", gamepad.RIGHT_TRIGGER());

				if (!record[i])	printf("%s pressed\n", name);
				if (!button)	printf("%s released\n", name);
			}
			record[i] = button;
		}
	}

	printf("Gamepad is disconnected\n");
	return 0;
}