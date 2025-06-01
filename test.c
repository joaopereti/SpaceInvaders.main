#include "raylib.h"
#include <conio.h>

//------------------------------------------------------------------------------------------
// Estruturas e constantes(POR ENQUANTO).
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

#define TELA_LARGURA 1000
#define TELA_ALTURA 600
#define FONTE_USADA 0
//------------------------------------------------------------------------------------
// A main príncipal.
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialização
    //--------------------------------------------------------------------------------------

    InitWindow(TELA_LARGURA,TELA_ALTURA, "Space Invaders");
    int Pontuacao = 0;
    int Melhor_Pontuacao;
    int vidas = 3;
    GameScreen currentScreen = LOGO;

    // É aqui em que todas as variáveis serão inicializadas.

    int Contador_frames = 0;          // variável auxiliar, útil para contar frames.

    SetTargetFPS(60);               // Apontar quantos frames serão usados.
    //--------------------------------------------------------------------------------------

    // Laço de repetição principal do jogo.
    while (!WindowShouldClose())    // Detectar quando a tela será fechada, apertando esc.
    {

        //----------------------------------------------------------------------------------
        switch (currentScreen)
        {
            case LOGO:
            {
                // atualizar as variáveis da tela do Logo aqui.

                Contador_frames++;    // contar a quantidade de frames.

                // Carregar a tela por 2 segundos, para assim ir À tela do título do jogo.
                if (Contador_frames > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // Atualizar as variáveis da tela do Título aqui.

                // Pressionar a letra 'n' para começar o novo jogo. Matheus, podemos começar a tela de novo jogo aqui.
                if (IsKeyPressed(KEY_N) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                // Atualizar as variáveis da tela da jogabilidade(gameplay) aqui.

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = ENDING;
                }
            } break;
            case ENDING:
            {
                // Atualizar variáveis do menu de fim de jogo aqui.

                // Pressionar a letra 'r' para retornar ao menu principal.
                if (IsKeyPressed(KEY_R) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Desenhar o jogo.
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {
                case LOGO:
                {
                    // O logo do jogo é iniciado aqui.
                    DrawText("SPACE INVADERS - o jogo.", 20, 20, 40, LIGHTGRAY);
                    DrawText("Espere um momento...", 290, 220, 20, GRAY);

                } break;
                case TITLE:
                {
                    // O título do jogo, junto com o menu principal, vai aqui.
                    DrawRectangle(0, 0, TELA_LARGURA, TELA_ALTURA, BLACK);
                    DrawText("SPACE INVADERS", 20, 20, 40, RAYWHITE);
                    DrawText("Novo Jogo(n)", 120, 230, 20, RAYWHITE);
                    DrawText("Carregar Jogo(c)", 120, 250, 20, RAYWHITE);
                    DrawText("Top 10(t)", 120, 270, 20, RAYWHITE);
                    DrawText("Sair (q)", 120, 290, 20, RAYWHITE);



                } break;
                case GAMEPLAY:
                {
                    // A tela de novo jogo começa aqui.
                    DrawRectangle(0, 0, TELA_LARGURA, TELA_ALTURA, PURPLE);
                    DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);

                } break;
                case ENDING:
                {
                    // retorna para a tela do título.
                    DrawRectangle(0, 0, TELA_LARGURA, TELA_ALTURA, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Desinicialização
    //--------------------------------------------------------------------------------------

    // Aqui irá todos os dados relacionados à texturas, aúdios e fontes de escrita.
    Font fonte[FONTE_USADA] = { 0 };
    fonte[0] = LoadFont("resources/fonts/alagard.png");

    CloseWindow();        // fechar a janela e abrir o contexto OpenGL.
    //--------------------------------------------------------------------------------------
    //funcao getch, usada para fazer a validação de dados.
    getch();
    return 0;
}
