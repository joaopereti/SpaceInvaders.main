#include "raylib.h"
#include <conio.h>
#include <stdio.h>
#include <string.h>
//------------------------------------------------------------------------------------------
// Estruturas e constantes(POR ENQUANTO).
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, FIM, LOAD_GAME } GameScreen;

typedef struct {
    int x,y;
}JOGADOR;

typedef struct{
    int x , y;
}INIMIGO;

typedef struct {
    int x,y;
}TIRO;

typedef struct {
    char nome_jogador[30];
    JOGADOR nave_jogador;
    INIMIGO nave_ini_tipo1,  nave_ini_tipo2,  nave_ini_tipo3;
    TIRO tiros_jogador[10];
    TIRO tiros_inimigo[10];
    int pontuacao;
    int numero_vidas;
    int num_tiros_jogador;
    int num_tiros_inimigo;
}ESTADO;

#define TELA_LARGURA 1000
#define TELA_ALTURA 600
#define TAMANHO_JOGADOR 20
#define LINHAS_JOGADOR 25
#define COLUNAS_JOGADOR 25
#define FONTE_USADA 0
#define TEXTURA_USADA 0
#define X_INICIAL 5
#define Y_INICIAL 5
#define LARGURA 800
#define ALTURA 500
#define TAMANHO_CELULA 30
#define QUANTIDADE_SAVES 10

//------------------------------------------------------------------------------------
// A main prнncipal.
//------------------------------------------------------------------------------------
//Manipulação de arquivo binário: Aqui, o jogo será aberto para escrita em modo binário.
int salvaEstado(char save_game[30], ESTADO estado_completo) {
    FILE *jogo_salvo;
    jogo_salvo = fopen("nome1.bin","wb");
    if (jogo_salvo == NULL) {
        printf("Houve um erro no carregamento do jogo, tente novamente! \n");
    }else {
    fwrite(&estado_completo, sizeof(ESTADO),1, jogo_salvo);
    estado_completo.nave_jogador;
    estado_completo.nave_ini_tipo1;
    estado_completo.nave_ini_tipo2;
    estado_completo.nave_ini_tipo3;
    estado_completo.pontuacao;
    estado_completo.numero_vidas;
    }
    fclose(jogo_salvo);
    return 0;
}
//Leitura do arquivo binário: Aqui, o arquivo será lido utilizando r + b.
int leEstado(char save_game[30], ESTADO *estado_completo) {
    FILE*jogo_salvo;
    jogo_salvo = fopen("nome1.bin","r + b");
    if (jogo_salvo == NULL) {
        printf("Houve um problema no carregamento do jogo, tente novamente! \n");
    }else {
    fread(estado_completo, sizeof(ESTADO),1, jogo_salvo);
    fclose(jogo_salvo);
    return 1;
    }
    fclose(jogo_salvo);
    return 0;
}

void imprimeMatriz(char matriz[LINHAS_JOGADOR][COLUNAS_JOGADOR]){
    int x;
    int y;
    ESTADO a;

    for (int i = 0; i < LINHAS_JOGADOR; i++){
        for(int j = 0; j < COLUNAS_JOGADOR; j++){
            x = X_INICIAL + TAMANHO_JOGADOR * j;
            y = Y_INICIAL + TAMANHO_JOGADOR * i;
            if (matriz[i][j] == ' '){
            }else if (matriz[i][j] == '#' && a.pontuacao<=200){
                 DrawRectangle(x, y, TAMANHO_JOGADOR, TAMANHO_JOGADOR, ORANGE);
                 DrawRectangle(x-10, y, TAMANHO_JOGADOR, TAMANHO_JOGADOR, ORANGE);
                 DrawRectangle(x, y+10, TAMANHO_JOGADOR, TAMANHO_JOGADOR, ORANGE);
                 DrawRectangle(x, y-10, TAMANHO_JOGADOR, TAMANHO_JOGADOR, ORANGE);
            }else if (matriz[i][j] == '#' && a.pontuacao>200 && a.pontuacao<=500){
                 DrawRectangle(x, y, TAMANHO_JOGADOR, TAMANHO_JOGADOR, ORANGE);
                 DrawRectangle(x-20, y, TAMANHO_JOGADOR+20, TAMANHO_JOGADOR+20, ORANGE);
                 DrawRectangle(x, y+20, TAMANHO_JOGADOR+20, TAMANHO_JOGADOR+20, ORANGE);
                 DrawRectangle(x, y-20, TAMANHO_JOGADOR+20, TAMANHO_JOGADOR+20, ORANGE);
            }else if (matriz[i][j] == '#' && a.pontuacao>500){
                 DrawRectangle(x, y, TAMANHO_JOGADOR, TAMANHO_JOGADOR, ORANGE);
                 DrawRectangle(x-40, y, TAMANHO_JOGADOR+40, TAMANHO_JOGADOR+40, ORANGE);
                 DrawRectangle(x, y+40, TAMANHO_JOGADOR+40, TAMANHO_JOGADOR+40, ORANGE);
                 DrawRectangle(x, y-40, TAMANHO_JOGADOR+40, TAMANHO_JOGADOR+40, ORANGE);
            }else{
                DrawRectangle(x, y, TAMANHO_JOGADOR, TAMANHO_JOGADOR, GRAY);
                DrawRectangle(x+10, y, TAMANHO_JOGADOR, TAMANHO_JOGADOR, GRAY);
                DrawRectangle(x, y+10, TAMANHO_JOGADOR, TAMANHO_JOGADOR, GRAY);
                DrawRectangle(x, y-10, TAMANHO_JOGADOR, TAMANHO_JOGADOR, GRAY);
            }
            if(matriz[i][j] == '#'&& matriz[i][j] == '+'){
                a.numero_vidas--;
            }
        }
    }
}


void Desenhar_barra_status(int pontuacao, int vidas, const char*nome){
    //Fundo
    DrawRectangle(0, 0, TELA_LARGURA,40, BLACK);

    // Textos da barra de status
    DrawText(TextFormat("Nome: %s", nome), 20, 10, 20, RAYWHITE);
    DrawText(TextFormat("Pontuacao: %d", pontuacao), 200, 10, 20, RAYWHITE);
    DrawText("Dificuldade", 400, 10, 20, GREEN);  // Modo de dificuldade
    DrawText(TextFormat("Tempo: %.1f", GetTime()), 600, 10, 20, RAYWHITE);  // Cronфmetro
    DrawText(TextFormat("Vidas: %i", vidas), 800, 10, 20, RAYWHITE);


}


int moveInimigo(char matriz[LINHAS_JOGADOR][COLUNAS_JOGADOR],INIMIGO *pi,int x, int y){
    struct INIMIGO;


    matriz[pi->y][pi->x] = ' ';

    int direcao = GetRandomValue(0, 4);

    switch (direcao) {
        case 0:
            if (y > 0){
                y--;
            }
            break;
        case 1:
            if (y < LINHAS_JOGADOR - 1) {
                y++;
            }
            break;
        case 2:
            if (x > 0) {
                x--;
            }
            break;
        case 3:
            if (x < COLUNAS_JOGADOR - 1) {
            x++;
            }
            break;
    }

    matriz[y][x] = '#';
    pi->x = x;
    pi->y = y;

}

int atirar(ESTADO *estado,int quem_foi,int x,int y){

//quem_foi: 1 para nave jogador, 2 para nave inimiga

int x_tela = X_INICIAL + TAMANHO_JOGADOR * x;
int y_tela = Y_INICIAL + TAMANHO_JOGADOR * y;


    if(quem_foi==1){
        if(estado->num_tiros_jogador<10){
            TIRO novoTiro = {x_tela,y_tela};
            estado->tiros_jogador[estado->num_tiros_jogador] = novoTiro;
            estado->num_tiros_jogador++;
        }
    } else if(quem_foi==2){
        if(estado->num_tiros_inimigo<10){
            TIRO novoTiro = {x, y};
            estado->tiros_inimigo[estado->num_tiros_inimigo] = novoTiro;
            estado->num_tiros_inimigo++;
        }

    }

}

void moverTIROS(ESTADO *estado){
    for(int i=0; i< estado ->num_tiros_jogador; i++){
        estado -> tiros_jogador[i].x += 5;

        if(estado->tiros_jogador[i].x>TELA_LARGURA){
            for(int j=i; j< estado->num_tiros_jogador-1; j++){
                estado->tiros_jogador[j] = estado -> tiros_jogador[j+1];
            }
            estado->num_tiros_jogador--;
            i--;
        }
    }

    for(int i=0; i< estado ->num_tiros_inimigo; i++){
        estado -> tiros_inimigo[i].x -= 3;

        if(estado->tiros_inimigo[i].x<0){
            for(int j=i; j< estado->num_tiros_inimigo-1; j++){
                estado->tiros_inimigo[j] = estado -> tiros_inimigo[j+1];
            }
            estado->num_tiros_inimigo--;
            i--;
        }
    }

}


int main(void){

    // Inicializaзгo
    //--------------------------------------------------------------------------------------
    char nome[30];
    ESTADO estado_lido;
    FILE *arquivo_mestre;
    char matriz[LINHAS_JOGADOR][COLUNAS_JOGADOR];
    for (int i = 0; i < LINHAS_JOGADOR; i++) {
        for (int j = 0; j < COLUNAS_JOGADOR; j++) {
            matriz[i][j] = ' ';
        }
    }

    //NAVE_JOGADOR coordenadas//
    int x_jogador = 3;
    int y_jogador = 3;
    matriz[y_jogador][x_jogador] = '+';
    INIMIGO inimigo = {150, 5};
    TIRO tiro= {};
    matriz[inimigo.y][inimigo.x] = '#';
    int i;

    InitWindow(TELA_LARGURA,TELA_ALTURA, "Space Invaders");
    //O Retвngulo em que ocorre o jogo.
    Rectangle container = { 50.0f, 50.0f, TELA_LARGURA - 60.0f, TELA_ALTURA - 250.0f };

    int Pontuacao = 0;
    int Melhor_Pontuacao;
    int vidas = 3;
    const char* nome_jogador = "Matheus";
    GameScreen currentScreen = GAMEPLAY;
    ESTADO estado;
    estado.num_tiros_jogador = 0;
    estado.num_tiros_inimigo = 0;

    // Й aqui em que todas as variбveis serгo inicializadas.
    Color Cor_de_borda = RAYWHITE;
    int Contador_frames = 0;          // variбvel auxiliar, ъtil para contar frames.
    double tempo_inicio_jogo = 0.0;

    SetTargetFPS(60);               // Apontar quantos frames serгo usados.
    double currentTimeInSeconds;
    double lastTimeInSeconds = GetTime();

    int tiroX, tiroY;
    int x = 0, y=0;


    //--------------------------------------------------------------------------------------
    currentScreen = LOGO;
    // Laзo de repetiзгo principal do jogo.
    while (!WindowShouldClose()) {    // Detectar quando a tela serб fechada, apertando esc.
            int x;
            int y;
            matriz[y_jogador][x_jogador] = '+';

            if(currentScreen==GAMEPLAY){
                DrawRectangle(x, y, TAMANHO_CELULA, TAMANHO_CELULA, GRAY);
           //     if (IsKeyPressed(KEY_RIGHT)){
             //       if(x_jogador<LINHAS_JOGADOR){
               //         matriz[y_jogador][x_jogador] = ' ';
                 //       x_jogador += 1;
                   //     matriz[y_jogador][x_jogador] = '+';
                    //}
                //}
            //    if (IsKeyPressed(KEY_LEFT)){
             //       if(x_jogador>0){
               //         matriz[y_jogador][x_jogador] = ' ';
                 //       x_jogador -= 1;
                   //     matriz[y_jogador][x_jogador] = '+';
                    //}
               // }
                if (IsKeyPressed(KEY_UP)||IsKeyPressed(KEY_W)||IsKeyPressed('w')) {
                    if(y_jogador>0){
                        matriz[y_jogador][x_jogador] = ' ';
                        y_jogador -= 1;
                        matriz[y_jogador][x_jogador] = '+';
                    }
                }
                if (IsKeyPressed(KEY_DOWN)||IsKeyPressed('s')||IsKeyPressed(KEY_S)){
                    if(y_jogador<COLUNAS_JOGADOR){
                        matriz[y_jogador][x_jogador] = ' ';
                        y_jogador += 1;
                        matriz[y_jogador][x_jogador] = '+';
                    }
                }

                if (IsKeyPressed(KEY_SPACE)){
                    atirar(&estado,1,x_jogador,y_jogador);
                }

                moverTIROS(&estado);

                currentTimeInSeconds = GetTime();
                if (currentTimeInSeconds - lastTimeInSeconds >= 0.4){
                    moveInimigo(matriz, &inimigo, inimigo.x, inimigo.y);
                    if(GetRandomValue(0,100)<20){
                         int x_tiro =  X_INICIAL + TAMANHO_JOGADOR * inimigo.x;
                         int y_tiro = Y_INICIAL + TAMANHO_JOGADOR*inimigo.y;
                         atirar(&estado,2,x_tiro,y_tiro);
                    }
                    lastTimeInSeconds = currentTimeInSeconds;
                }

            }

        //----------------------------------------------------------------------------------
            switch (currentScreen){
                case LOGO:
                // atualizar as variбveis da tela do Logo aqui.

                    Contador_frames++;    // contar a quantidade de frames.

                // Carregar a tela por 2 segundos, para assim ir А tela do tнtulo do jogo.
                    if (Contador_frames > 120){
                        currentScreen = TITLE;
                    }
                break;

                case TITLE:

                // Atualizar as variбveis da tela do Tнtulo aqui.

                // Pressionar a letra 'n' para comeзar o novo jogo. Matheus, podemos comeзar a tela de novo jogo aqui.
                    if (IsKeyPressed(KEY_N) || IsGestureDetected(GESTURE_TAP)){
                        currentScreen = GAMEPLAY;
                        tempo_inicio_jogo = GetTime(); // Start do cronometro
                        //DrawRectangleLinesEx(container, 3, Cor_de_borda);
                    }else if (IsKeyPressed(KEY_Q)) {
                              CloseWindow();
                              return 0;
                    }else if(IsKeyPressed(KEY_C)) {
                    currentScreen = LOAD_GAME;
                    }

                break;

                case GAMEPLAY:

                // Atualizar as variбveis da tela da jogabilidade(gameplay) aqui.

                // Press enter to change to ENDING screen
                    if (IsKeyPressed(KEY_R) || IsGestureDetected(GESTURE_TAP)){
                        currentScreen = FIM;
                    }
                break;

            case FIM:
                // Atualizar variбveis do menu de fim de jogo aqui.
                // Pressionar a letra 'r' para retornar ao menu principal.
                if (IsKeyPressed(KEY_R) || IsGestureDetected(GESTURE_TAP)){
                    currentScreen = TITLE;
                }
            break;

            case LOAD_GAME:
                // Atualizar variбveis do menu de fim de jogo aqui.
                // Pressionar a letra 'r' para retornar ao menu principal.
                if (IsKeyPressed(KEY_R) || IsGestureDetected(GESTURE_TAP)){
                    currentScreen = TITLE;
                }
            break;

            }
        //----------------------------------------------------------------------------------

        // Desenhar o jogo.
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen){
                case LOGO:
                    // O logo do jogo й iniciado aqui.
                    DrawText("SPACE INVADERS - o jogo.", 20, 20, 40, LIGHTGRAY);
                    DrawText("Espere um momento...", 290, 220, 20, GRAY);

                break;

                case TITLE:
                    // O tнtulo do jogo, junto com o menu principal, vai aqui.
                    DrawRectangle(0, 0, TELA_LARGURA, TELA_ALTURA, BLACK);
                    DrawText("SPACE INVADERS", 20, 20, 40, YELLOW);
                    DrawText("Novo Jogo(n)", 120, 230, 20, YELLOW);
                    DrawText("Carregar Jogo(c)", 120, 250, 20, YELLOW);
                    DrawText("Top 10(t)", 120, 270, 20, YELLOW);
                    DrawText("Sair (q)", 120, 290, 20, YELLOW);
                 break;

                case GAMEPLAY:
                    // A tela de novo jogo comeзa aqui.
                    DrawRectangle(0, 0, TELA_LARGURA, TELA_ALTURA, PURPLE);
                    DrawText("TELA DE JOGO", 20, 20, 40, MAROON);
                    Desenhar_barra_status(Pontuacao,vidas, nome_jogador);
                    DrawRectangle(0, 40, TELA_LARGURA, TELA_ALTURA - 40,DARKBLUE);
                    DrawRectangleLinesEx(container, 3, Cor_de_borda);
                    for(i=0; i< estado.num_tiros_jogador;i++){
                        DrawRectangle(estado.tiros_jogador[i].x,estado.tiros_jogador[i].y,4,10, GRAY);
                    }
                    for(i=0; i< estado.num_tiros_inimigo;i++){
                        DrawRectangle(estado.tiros_inimigo[i].x,estado.tiros_inimigo[i].y,4,10, ORANGE);
                    }
                    imprimeMatriz(matriz);
                break;

                case FIM:
                    // retorna para a tela do tнtulo.
                DrawRectangle(0, 0, TELA_LARGURA, TELA_ALTURA, BLACK);
                DrawText("JOGO PARADO: retornando ao menu principal...", 20, 20, 40, YELLOW);
                break;
                //*******Aqui que será carregado o jogo********
                case LOAD_GAME:
                    DrawRectangle(0, 0, TELA_LARGURA, TELA_ALTURA, BLACK);
                    DrawText("Escolha em qual save deseja jogar-", 20, 20, 40, YELLOW);
                    DrawText("Escrever o nome do jogador:", 50, 50, 50, YELLOW);
                    salvaEstado(nome, estado_lido);
                    ESTADO estadolido;
                    if(leEstado("nome1.bin",&estadolido));
                    int key = GetCharPressed();
                    while (key > 0)
                    {
                    if ((key >= 32) && (key <= 125) && (strlen(nome) < 19))
                    {
                        nome[strlen(nome)] = (char)key;
                        nome[strlen(nome) + 1] = '\0';
                    }
                    key = GetCharPressed();
                    }
                    if (IsKeyPressed(KEY_BACKSPACE) && strlen(nome > 0))
                    {
                        nome[strlen(nome) - 1] = '\0';
                    }

                    if (IsKeyPressed(KEY_ENTER) && strlen(nome) >= 3)
                    {
                        DrawText("%s \n",nome, 70, 70, 70, YELLOW);
                    }


            }

        EndDrawing();
    }
        //----------------------------------------------------------------------------------

        // Desinicializaзгo
    //--------------------------------------------------------------------------------------

   // Aqui irб todos os dados relacionados а texturas, aъdios e fontes de escrita.
    //Texture textura[TEXTURA_USADA] = { 0 };
    //textura[0] = LoadTexture("resources/Texture/BlueRedGreen_Spacecraft_V1.0(nave_menor).png");
    //Font fonte[FONTE_USADA] = { 0 };
    //fonte[0] = LoadFont("resources/fonts/alagard.png");

  //--------------------------------------------------------------------------------------
    //funcao getch, usada para fazer a validaзгo de dados.
    getch();

    CloseWindow();        // fechar a janela e abrir o contexto OpenGL.

    return 0;



}

