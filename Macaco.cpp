#include <iostream>
#include <Windows.h>
#include <time.h>
#include <random>
#include <conio.h>



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
} // essa clear screen é uma função que roubei da internet
int main()
{
	while (true) {

		

		ClearScreen();
		
		
		
		
		
		
		
		
		
		
		
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
		std::cout << "\nWelcome to ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "PaoDeGay";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN );
		std::cout << " (MButton - Click , DEL - Change CPS , F4 - Quit)";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		std::cout << "\nMinimum CPS: ";
		std::cin >> cps_min;
		std::cout << "Maximum CPS: ";
		std::cin >> cps_max;
		cps_min_ms = ((1 / cps_min) * 1000);
		cps_max_ms = ((1 / cps_max) * 1000);
		range = cps_min_ms - cps_max_ms;
		std::cout << "\n\n\n";
		controle = 1;

		while (controle == 1)
		{
			Sleep(20);
			std::random_device rd{}; //(hopefully) truly random device
			std::mt19937 engine{ rd() }; //seed a pseudo rng with random_device
			std::uniform_int_distribution<int> d(1, 1000); //1 to 10, inclusive
			delayy = (d(engine) % range) + cps_max_ms;
			delaycps = (1 / (delayy / 1000));
			if (GetAsyncKeyState(VK_MBUTTON))
			{


				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);




			}
			Sleep(delayy);

			std::cout << ("\r                           ");
			std::cout << ("\rCps: ") << (delaycps);

			if (GetAsyncKeyState(0x2E))
			{
				Sleep(1);
				
				controle = 0;

			}
			if (GetAsyncKeyState(0x73))
			{
				Sleep(1);
				
				exit(0);

			}
			Sleep(2);
		}
	}
}
