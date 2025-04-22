#include <iostream>
#include <raylib.h>
#include <raymath.h>

int main(int, char**) {
    // Initialize window and frame rate
    InitWindow(870, 512, "Learning C++");
    SetTargetFPS(300);

    // Load spries for the game
    const Texture2D BACKGROUND_TEXTURE = LoadTexture("./assets/sprites/background-day.png");
    if (BACKGROUND_TEXTURE.id == 0) TraceLog(LOG_ERROR, "Failed to load background texture");
    const Texture2D GAMEOVER_TEXTURE = LoadTexture("./assets/sprites/gameover.png");
    if (GAMEOVER_TEXTURE.id == 0) TraceLog(LOG_ERROR, "Failed to load gameOver texture");
    const Texture2D PLAYER_TEXTURE = LoadTexture("./assets/sprites/yellowbird-upflap.png");
    if (PLAYER_TEXTURE.id == 0) TraceLog(LOG_ERROR, "Failed to load player texture");

    SetTextureWrap(BACKGROUND_TEXTURE, TEXTURE_WRAP_REPEAT);

    const int SCREEN_WIDTH = GetScreenWidth();
    const int SCREEN_HEIGHT = GetScreenHeight();
    int CENTERED_GAMEOVER_TEXTURE_X_POSITION = (SCREEN_WIDTH * 0.5f) - (GAMEOVER_TEXTURE.width * 0.5f);
    int CENTERED_GAMEOVER_TEXTURE_Y_POSITION = (SCREEN_HEIGHT * 0.5f) - (GAMEOVER_TEXTURE.height * 0.5f);

    const float PLAYER_JUMP_FORCE = -700.0f;
    const float GRAVITY = 9.84f;
    const int PLAYER_SIZE = 25;

    Vector2 playerPosition = { 128, 256 };
    float yVelocity = 0;
    bool gameOver = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Rectangle backgroundRectangle = { 0.0f, 0.0f, (float)SCREEN_WIDTH, (float)SCREEN_HEIGHT };
        DrawTextureRec(BACKGROUND_TEXTURE, backgroundRectangle, { 0, 0 }, WHITE);

        if (IsKeyPressed(KEY_SPACE)) {
            yVelocity = 0.0f;
            yVelocity += PLAYER_JUMP_FORCE;
        }

        yVelocity += GRAVITY;
        
        playerPosition.y += yVelocity * GetFrameTime();

        if (playerPosition.y <= 0 || playerPosition.y >= SCREEN_HEIGHT - PLAYER_SIZE) {
            DrawTexture(GAMEOVER_TEXTURE, CENTERED_GAMEOVER_TEXTURE_X_POSITION, CENTERED_GAMEOVER_TEXTURE_Y_POSITION, WHITE);
            playerPosition.y = Clamp(playerPosition.y, 0, SCREEN_HEIGHT - PLAYER_SIZE);
            gameOver = true;
        }

        DrawTexture(PLAYER_TEXTURE, playerPosition.x, playerPosition.y, WHITE);

        EndDrawing();
    }

    UnloadTexture(BACKGROUND_TEXTURE);
    CloseWindow();
    return 0;
}