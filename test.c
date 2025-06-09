#include "raylib.h"
#include <conio.h>

//------------------------------------------------------------------------------------------
// Estruturas e constantes(POR ENQUANTO).
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

#define TELA_LARGURA 1000
#define TELA_ALTURA 600
#define LINHAS_JOGADOR 10
#define COLUNAS_JOGADOR 20
#define FONTE USADA 0
#define TEXTURA_USADA 0

typedef struct{
char Matrix[LINHAS_JOGADOR][COLUNAS_JOGADOR];
}NAVE_JOGADOR;
//------------------------------------------------------------------------------------
// A main príncipal.
//------------------------------------------------------------------------------------

void Desenhar_barra_status(int pontuacao, int vidas, const char*nome)
{
    //Fundo
    DrawRectangle(0, 0, TELA_LARGURA,40, BLACK);

    // Textos da barra de status
    DrawText(TextFormat("Nome: %s", nome), 20, 10, 20, RAYWHITE);
    DrawText(TextFormat("Pontuacao: %d", pontuacao), 200, 10, 20, RAYWHITE);
    DrawText("Dificuldade", 400, 10, 20, GREEN);  // Modo de dificuldade
    DrawText(TextFormat("Tempo: %.1f", GetTime()), 600, 10, 20, RAYWHITE);  // Cronômetro
    DrawText(TextFormat("Vidas: %i", vidas), 800, 10, 20, RAYWHITE);


}



int main(void)
{
    // Inicialização
    //--------------------------------------------------------------------------------------

    InitWindow(TELA_LARGURA,TELA_ALTURA, "Space Invaders");
    //O Retângulo em que ocorre o jogo.
    Rectangle container = { 50.0f, 50.0f, TELA_LARGURA - 60.0f, TELA_ALTURA - 250.0f };

    int Pontuacao = 0;
    int Melhor_Pontuacao;
    int vidas = 3;
    const char* nome_jogador = "Matheus";
    GameScreen currentScreen = LOGO;

    // É aqui em que todas as variáveis serão inicializadas.
    Color Cor_de_borda = RAYWHITE;
    int Contador_frames = 0;          // variável auxiliar, útil para contar frames.
    double tempo_inicio_jogo = 0.0;

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
                    tempo_inicio_jogo = GetTime(); // Start do cronometro
                    DrawRectangleLinesEx(container, 3, Cor_de_borda);
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
                    Desenhar_barra_status(Pontuacao,vidas, nome_jogador);
                    DrawRectangle(0, 40, TELA_LARGURA, TELA_ALTURA - 40,DARKBLUE);
                    DrawRectangleLinesEx(container, 3, Cor_de_borda);
                    DrawTriangle((Vector2){ TELA_LARGURA/4.0f *3.0f, 80.0f },
                    (Vector2){ TELA_LARGURA/4.0f *3.0f - 60.0f, 150.0f },
                    (Vector2){ TELA_LARGURA/4.0f *3.0f + 60.0f, 150.0f }, VIOLET);


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
    //Texture textura[TEXTURA_USADA] = { 0 };
    //textura[0] = LoadTexture("resources/Texture/BlueRedGreen_Spacecraft_V1.0(nave_menor).png");
    //Font fonte[FONTE_USADA] = { 0 };
    //fonte[0] = LoadFont("resources/fonts/alagard.png");

    CloseWindow();        // fechar a janela e abrir o contexto OpenGL.
    //--------------------------------------------------------------------------------------
    //funcao getch, usada para fazer a validação de dados.
    getch();
    return 0;
}

