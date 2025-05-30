#include "raylib.h"
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
//estruturas Ó ser postas
 struct posicao {
	int a;
	int b;
};
typedef enum GameScreen { LOGO = 0, TITULO, GAMEPLAY, ENDING } GameScreen;


//constantes definidas
#define TELA_LARGURA 1000
#define TELA_ALTURA 600
#define FONTE_USADA 0

int main() {
    //Configurar a lÝnguagem falada que serß utilizada no jogo
    setlocale(LC_ALL,"");


    //Inicializar janela e abrir o OpenGL context(contexto Ú o local que armazena todas as teclas, informaþ§es ou buffers na mem¾ria
    InitWindow(TELA_LARGURA,TELA_ALTURA,"SPACE INVADERS: ediþÒo 2025");

    GameScreen currentScreen = LOGO;

    Font fonte[FONTE_USADA] = { 0 };

    Vector2 position;
    position.x = 500;
    position.y = 50;

    //Bibliográfia da fonte utilizada: https://www.raylib.com/examples/text/loader.html?name=text_raylib_fonts
    fonte[0] = LoadFont("resources/fonts/alagard.png");

    //apontar quantos Frames por Segundo serÒo requeridos para o projeto

    int ContadordeFrames = 0;

    SetTargetFPS(60);

    //confere se a aplicaþÒo deve ser fechada
    while (!WindowShouldClose()) {
        switch (currentScreen) {
        case LOGO:
            ContadordeFrames++;
            if(ContadordeFrames > 120)
                {
                    currentScreen = TITULO;
                }
            break;
        case TITULO: {
         if (IsKeyPressed(KEY_N))
                {
                    currentScreen = GAMEPLAY;
                }
            }break;
            case GAMEPLAY:
            {

                if (IsKeyPressed(KEY_C))
                {
                    currentScreen = ENDING;
                }
            } break;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        switch(currentScreen) {
            case LOGO:
                {
                    DrawText("SPACE INVADERS", 20, 20, 40, LIGHTGRAY);
                    DrawText("Espere um momento...", 290, 220, 20, GRAY);
                }break;
            }



        EndDrawing();
    }
    CloseWindow();
    //A funþÒo getch, oriunda da biblioteca Conio.h, Ú utilizada para retornar o caractere que Ú lido como um n·mero inteiro, ·til para realizar validaþÒo de dados
    //getch();
    return 0;
}
