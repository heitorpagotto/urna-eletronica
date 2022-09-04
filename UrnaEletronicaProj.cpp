#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

int currentStep = 0;

int isProgramRunning = 1;

//int passwordSecret = 20021987201817;
int passwordSecret = 123;

void ConfigureAppFullScreen();
int HandleProgramRunning();
void TransformCursorCoordinates(int x, int y);
void RenderMenu(int width, int height, int startingRow,  int startingColumn);
void RenderBasicInfo();
void RenderNumberTiles();
void HandleKeyPresses(int keycode);

int main() {
	ConfigureAppFullScreen();
	//setlocale(LC_ALL, "Portuguese");
	return HandleProgramRunning();
}

void ConfigureAppFullScreen() {
	system("color 80");
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo; 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);
    
    COORD new_screen_buffer_size;

    new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - 
    screenBufferInfo.srWindow.Left + 1; // Columns
    new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - 
    screenBufferInfo.srWindow.Top + 1; // Rows

    SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);
	ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
	system("mode con:cols=170 lines=48");
}


void TransformCursorCoordinates(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int HandleProgramRunning() {
	RenderBasicInfo();
	while (isProgramRunning == 1) {
		int pressedKey = getch();
		
		switch (pressedKey) {
			case 112:
				TransformCursorCoordinates(80, 10);
				printf("Insira a senha:");
				TransformCursorCoordinates(75, 12);
				int insertedPassword;
				scanf("%d", &insertedPassword);
				if (insertedPassword == passwordSecret) {
					// RenderResults
				} else {
					system("cls");
				}
				break;
			case 27:
				system("cls");
				TransformCursorCoordinates(80, 10);
				printf("Insira a senha para sair da aplicação:");
				TransformCursorCoordinates(75, 12);
				int insertedPasswordExit;
				scanf("%d", &insertedPasswordExit);
				
				if (insertedPasswordExit == passwordSecret) {
					isProgramRunning = 0;
				} else {
					system("cls");
					RenderBasicInfo();
				}
				
				break;
			default:
				HandleKeyPresses(pressedKey);
				break;
		}	
	}
	return 0;
}

void HandleKeyPresses(int keycode) {
	switch (currentStep) {
		case 0:
			// BEM VINDO AS ELEIÇÕES 2022
			break;
		case 1:
			// SEU VOTO PARA DEPUTADO FED.
			break;
		case 2:
			// SEU VOTO PARA DEPUTADO EST.
			break;
		case 3:
			// SEU VOTO PARA SENADOR
			break;
		case 4:
			// SEU VOTO PARA GOVERNADOR
			break;
		case 5:
			// SEU VOTO PARA PRESIDENTE
			break;
		case 6:
			// FIM
			break;
	}
}

void RenderBasicInfo() {
	RenderMenu(170,47,0, 0);

	RenderMenu(69, 6, 1, 100);
	TransformCursorCoordinates(125, 4);
	printf("JUSTICA ELEITORAL");

	RenderMenu(99, 45, 1, 1);
	RenderNumberTiles();
}

void RenderNumberTiles() {
	int baseColumn = 102;

	RenderMenu(15, 6, 15, baseColumn);
	TransformCursorCoordinates(107, 18);
	printf("1");

	RenderMenu(15, 6, 15, baseColumn + 15);
	TransformCursorCoordinates(122, 18);
	printf("2");

	RenderMenu(15, 6, 15, baseColumn + 30);
	TransformCursorCoordinates(137, 18);
	printf("3");

	RenderMenu(20, 6, 15, baseColumn + 45);
	TransformCursorCoordinates(152, 18);
	printf("BRANCO");


	RenderMenu(15, 6, 22, baseColumn);
	TransformCursorCoordinates(107, 25);
	printf("4");

	RenderMenu(15, 6, 22, baseColumn + 15);
	TransformCursorCoordinates(122, 25);
	printf("5");

	RenderMenu(15, 6, 22, baseColumn + 30);
	TransformCursorCoordinates(137, 25);
	printf("6");

	RenderMenu(20, 6, 22, baseColumn + 45);
	TransformCursorCoordinates(152, 25);
	printf("CORRIGE");

	RenderMenu(15, 6, 29, baseColumn);
	TransformCursorCoordinates(107, 32);
	printf("7");

	RenderMenu(15, 6, 29, baseColumn + 15);
	TransformCursorCoordinates(122, 32);
	printf("8");

	RenderMenu(15, 6, 29, baseColumn + 30);
	TransformCursorCoordinates(137, 32);
	printf("9");

	RenderMenu(20, 12, 29, baseColumn + 45);
	TransformCursorCoordinates(152, 35);
	printf("CONFIRMA");

	RenderMenu(15, 6, 36, baseColumn + 15);
	TransformCursorCoordinates(122, 39);
	printf("0");
}

void RenderMenu(int width, int height, int startingRow, int startingColumn) {
	int index = 1;
	if (height > 47){
		height = 47;
	}
	if (width > 170){
		width = 170;
	}
	TransformCursorCoordinates(startingColumn, startingRow);
	printf("%c", 201);
	for (index = 1; index + 1 <= width; index++) {
		TransformCursorCoordinates(index + startingColumn,startingRow);
		if (index + 1 == width) {
			printf("%c", 187);	
		} else {
			printf("%c", 205);		
		}
	}
	for (index = 1; index + 1 <= height; index++) {
		TransformCursorCoordinates(startingColumn,index+startingRow);
		printf("%c", 186);		
	}
	for (index = 1; index + 1 <= height; index++) {
		TransformCursorCoordinates(width - 1 + startingColumn, index+startingRow);
		printf("%c", 186);	
	}
	TransformCursorCoordinates(startingColumn,height+startingRow);
	printf("%c", 200);
	for (index = 1; index + 1 <= width; index++) {
		TransformCursorCoordinates(index + startingColumn,height + startingRow);
		if (index + 1 == width) {
			printf("%c", 188);	
		} else {
			printf("%c", 205);		
		}
	}
}

