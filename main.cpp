#include <iostream>
#include <raylib.h>
#include <raymath.h>

int main(int, char**) {
    // Initialize window and frame rate
    InitWindow(870, 512, "Learning C++");
    SetTargetFPS(300);

    // Load spries for the game
    Texture2D background = LoadTexture("./assets/sprites/background-day.png");
    if (background.id == 0) TraceLog(LOG_ERROR, "Failed to load background texture");
    Texture2D player = LoadTexture("./assets/sprites/yellowbird-upflap.png");
    if (player.id == 0) TraceLog(LOG_ERROR, "Failed to load player texture");

    SetTextureWrap(background, TEXTURE_WRAP_REPEAT);

    // Retrieve screen size
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    // Player setup
    Vector2 playerPosition = { 128, 256 };

    float yVelocity;

    const float playerJumpForce = -500.0f;
    const float gravity = 9.84f;
    const int playerRadius = 10;

    while (WindowShouldClose() == false)
    {
        // Start frame
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw tiled background in one call
        Rectangle backgroundRectangle = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };
        DrawTextureRec(background, backgroundRectangle, { 0, 0 }, WHITE);

        // Handle input and movement
        if (IsKeyPressed(KEY_SPACE)) {
            yVelocity = 0.0f;
            yVelocity += playerJumpForce;
        }

        yVelocity += gravity;
        
        // Update player position
        playerPosition.y += yVelocity * GetFrameTime();

        playerPosition.x += 0.0f * GetFrameTime();
        playerPosition.x = Clamp(playerPosition.x, playerRadius, screenWidth  - playerRadius);
        playerPosition.y = Clamp(playerPosition.y, playerRadius, screenHeight - playerRadius);

        // Draw player and debug info
        DrawTexture(player, playerPosition.x, playerPosition.y, WHITE);

        // End frame
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();
    return 0;
}