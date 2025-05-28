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

//constantes definidas
#define TELA_LARGURA 1000
#define TELA_ALTURA 600
#define FONTE_USADA 0

int main() {
    //Configurar a lÝnguagem falada que serß utilizada no jogo
    setlocale(LC_ALL,"");


    //Inicializar janela e abrir o OpenGL context(contexto Ú o local que armazena todas as teclas, informaþ§es ou buffers na mem¾ria
    InitWindow(TELA_LARGURA,TELA_ALTURA,"SPACE INVADERS: ediþÒo 2025");

    Font fonte[FONTE_USADA] = { 0 };

    Vector2 position;
    position.x = 500;
    position.y = 50;

    //Bibliográfia da fonte utilizada: https://www.raylib.com/examples/text/loader.html?name=text_raylib_fonts
    fonte[0] = LoadFont("resources/fonts/alagard.png");

    //apontar quantos Frames por Segundo serÒo requeridos para o projeto

    SetTargetFPS(60);

    //confere se a aplicaþÒo deve ser fechada
    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);

        DrawTextEx(fonte[0],"SPACE INVADERS", position, 20, 1, RAYWHITE);
        DrawLine(220, 50, 590, 50, RAYWHITE);


        /*  char opcoes_menu;
        //escaneia as opþ§es desejadas do menu;
        scanf(" %c", &opcoes_menu);

      switch(opcoes_menu){
            case 'n':
                //IsKeyPressed: confere se uma tecla foi pressionada uma vez
            IsKeyPressed('n');
            break;

            case 'c':
            IsKeyPressed('c');
            break;

            case 't':
            IsKeyPressed('t');
            break;

            case  'q':
            IsKeyPressed('q');
            break;
        }*/
        EndDrawing();
    }
    CloseWindow();
    //A funþÒo getch, oriunda da biblioteca Conio.h, Ú utilizada para retornar o caractere que Ú lido como um n·mero inteiro, ·til para realizar validaþÒo de dados
    //getch();
    return 0;
}
