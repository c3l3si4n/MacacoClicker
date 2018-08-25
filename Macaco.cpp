#include <iostream>
#include <Windows.h>
#include <time.h>
#include <random>
#include <conio.h>


using namespace std;
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
int main()
{
	while (true) {

		setlocale(LC_ALL, "Portuguese");
		ClearScreen();
		float cps_min;
		float cps_max;
		float cps_min_ms;
		float cps_max_ms;
		float delayy;
		int range;
		int delaycps;
		int controle;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\nWelcome to ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "MacacoClicker";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN );
		cout << " (MButton - Click , DEL - Change CPS , F4 - Quit)";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "\nMinimum CPS: ";
		cin >> cps_min;
		cout << "Maximum CPS: ";
		cin >> cps_max;
		cps_min_ms = ((1 / cps_min) * 1000);
		cps_max_ms = ((1 / cps_max) * 1000);
		range = cps_min_ms - cps_max_ms;
		cout << "\n\n\n";
		controle = 1;

		while (controle == 1)
		{
			Sleep(20);
			random_device rd{}; //(hopefully) truly random device
			mt19937 engine{ rd() }; //seed a pseudo rng with random_device
			uniform_int_distribution<int> d(1, 1000); //1 to 10, inclusive
			delayy = (d(engine) % range) + cps_max_ms;
			delaycps = (1 / (delayy / 1000));
			if (GetAsyncKeyState(VK_MBUTTON))
			{


				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);




			}
			Sleep(delayy);

			cout << ("\r                           ");
			cout << ("\rCps: ") << (delaycps);

			if (GetAsyncKeyState(0x2E))
			{
				Sleep(1);
				
				controle = 0;

			}
			Sleep(2);
		}
	}
}
