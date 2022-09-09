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

void RenderResultsMenu();

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
			case 59:
				TransformCursorCoordinates(80, 10);
				printf("Insira a senha:");
				TransformCursorCoordinates(75, 12);
				int insertedPassword;
				scanf("%d", &insertedPassword);
				if (insertedPassword == passwordSecret) {
					// RenderResults
					system("cls");
					RenderResultsMenu();
				} else {
					system("cls");
				}
				break;
			case 27:
				system("cls");
				TransformCursorCoordinates(80, 10);
				printf("Insira a senha para sair da aplica??o:");
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
			// BEM VINDO AS ELEI??ES 2022
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

void RenderResultsMenu(){
	
	RenderMenu(170,47,0, 0);
	RenderMenu(12, 2, 1, 1);
	TransformCursorCoordinates(2, 2);
	printf("RESULTADOS");
	
	RenderMenu(20, 2, 7, 5);
	TransformCursorCoordinates(7, 8);
	printf("DEPUTADO FEDERAL");
	
	RenderMenu(21, 2, 7, 40);
	TransformCursorCoordinates(42, 8);
	printf("DEPUTADO ESTADUAL");
	
	RenderMenu(19, 2, 7, 75);
	TransformCursorCoordinates(81, 8);
	printf("SENADOR");
	
	RenderMenu(20, 2, 7, 110);
	TransformCursorCoordinates(115, 8);
	printf("GOVERNADOR");
	
	RenderMenu(20, 2, 7, 145);
	TransformCursorCoordinates(150, 8);
	printf("PRESIDENTE");
}

typedef struct{
	char nome[60];
	char partido[15];
	int num;
	char nome_vice[60];
	int qtd_votos;
} candidato;

void imprimeCandidato(candidato c){
	printf("Nome: ", c.nome);
	
	if (c.nome_vice == ""){
		printf("Vice: ", c.nome_vice);
	}
	
	printf("Número: ", c.num);
	printf("Partido: ", c.partido);	
}

void candidatos (){

	candidato dep_federal[4];
	candidato dep_estadual[4];
	candidato senador[4];
	candidato governador[4];
	candidato presidente[4];
	
	strcpy(dep_federal[0].nome, "Mike Wazowski");
	strcpy(dep_federal[0].partido, "Disney");
	dep_federal[0].num = 1313;
	
	strcpy(dep_federal[1].nome, "Draco Malfoy");
	strcpy(dep_federal[1].partido, "Warner Bros");
	dep_federal[1].num = 1515;
	
	strcpy(dep_federal[2].nome, "Cortana");
	strcpy(dep_federal[2].partido, "Microsoft");
	dep_federal[2].num = 2222;
	
	strcpy(dep_federal[3].nome, "Capitão Falcon");
	strcpy(dep_federal[3].partido, "Nintendo");
	dep_federal[3].num = 1212;
	
	
	strcpy(dep_estadual[0].nome, "Pato Donald");
	strcpy(dep_estadual[0].partido, "Disney");
	dep_estadual[0].num = 13313;
	
	strcpy(dep_estadual[1].nome, "Salsicha");
	strcpy(dep_estadual[1].partido, "Warner Bros");
	dep_estadual[1].num = 15515;
	
	strcpy(dep_estadual[2].nome, "Steve (Minecraft)");
	strcpy(dep_estadual[2].partido, "Microsoft");
	dep_estadual[2].num = 22222;
	
	strcpy(dep_estadual[3].nome, "Wario");
	strcpy(dep_estadual[3].partido, "Nintendo");
	dep_estadual[3].num = 12212;
	
	strcpy(senador[0].nome, "Steven Grant / Mark Spector / Jake Lockley (Moon Knight)");
	strcpy(senador[0].partido, "Disney");
	senador[0].num = 133;
	
	strcpy(senador[1].nome, "Pernalonga");
	strcpy(senador[1].partido, "Warner Bros");
	senador[1].num = 155;
	
	strcpy(senador[2].nome, "Conker");
	strcpy(senador[2].partido, "Microsoft");
	senador[2].num = 222;
	
	strcpy(senador[3].nome, "Kirby");
	strcpy(senador[3].partido, "Nintendo");
	senador[3].num = 122;
	
	strcpy(governador[0].nome, "Timão");
	strcpy(governador[0].partido, "Disney");
	governador[0].num = 13;
	strcpy(governador[0].nome_vice, "Pumba");
	
	strcpy(governador[1].nome, "Tom");
	strcpy(governador[1].partido, "Warner Bros");
	governador[1].num = 15;
	strcpy(governador[1].nome_vice, "Jerry");
	
	strcpy(governador[2].nome, "Master Chief");
	strcpy(governador[2].partido, "Microsoft");
	governador[2].num = 22;
	strcpy(governador[2].nome_vice, "DOOM Guy");
	
	strcpy(governador[3].nome, "Link");
	strcpy(governador[3].partido, "Nintendo");
	governador[3].num = 12;
	strcpy(governador[3].nome_vice, "Zelda");
	
	strcpy(presidente[0].nome, "Lilo");
	strcpy(presidente[0].partido, "Disney");
	presidente[0].num = 13;
	strcpy(presidente[0].nome_vice, "Stitch");
	
	strcpy(presidente[1].nome, "Rick");
	strcpy(presidente[1].partido, "Warner Bros");
	presidente[1].num = 15;
	strcpy(presidente[1].nome_vice, "Morty");
	
	strcpy(presidente[2].nome, "Banjo");
	strcpy(presidente[2].partido, "Microsoft");
	presidente[2].num = 22;
	strcpy(presidente[2].nome_vice, "Kazooie");
	
	strcpy(presidente[3].nome, "Mario");
	strcpy(presidente[3].partido, "Nintendo");
	presidente[3].num = 12;
	strcpy(presidente[3].nome_vice, "Luigi");
}
