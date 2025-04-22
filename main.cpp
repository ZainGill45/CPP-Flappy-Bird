#include <iostream>
#include <raylib.h>
#include <raymath.h>

int main(int, char**) {
// Initialize window and frame rate
    InitWindow(870, 512, "Learning C++");
    SetTargetFPS(300);

    // Load background texture and set wrap mode to repeat
    Texture2D background = LoadTexture("./assets/sprites/background-day.png");

    if (background.id == 0) {
        TraceLog(LOG_ERROR, "Failed to load background texture");
    }

    SetTextureWrap(background, TEXTURE_WRAP_REPEAT);

    // Retrieve screen size
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    // Player setup
    Vector2 playerPosition = { 128, 256 };
    float playerSpeed = 100.0f;
    int playerRadius = 10;

    while (WindowShouldClose() == false)
    {
        // Start frame
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw tiled background in one call
        Rectangle srcRec = { 0.0f, 0.0f, (float)screenWidth, (float)screenHeight };
        DrawTextureRec(background, srcRec, { 0, 0 }, WHITE);

        // Handle input and movement
        Vector2 inputVector = { 0, 0 };
        if (IsKeyDown(KEY_W)) inputVector.y -= 1;
        if (IsKeyDown(KEY_S)) inputVector.y += 1;
        if (IsKeyDown(KEY_A)) inputVector.x -= 1;
        if (IsKeyDown(KEY_D)) inputVector.x += 1;
        inputVector = Vector2Normalize(inputVector);

        // Update player position
        playerPosition.x += inputVector.x * playerSpeed * GetFrameTime();
        playerPosition.y += inputVector.y * playerSpeed * GetFrameTime();
        playerPosition.x = Clamp(playerPosition.x, playerRadius, screenWidth  - playerRadius);
        playerPosition.y = Clamp(playerPosition.y, playerRadius, screenHeight - playerRadius);

        // Draw player and debug info
        DrawCircle(playerPosition.x, playerPosition.y, playerRadius, RED);

        // Draw text to screen for debugging
        char debugText[32];
        snprintf(debugText, sizeof(debugText),
                 "(%.0f, %.0f)",
                 inputVector.x, inputVector.y);
        DrawText(debugText, 10, 5, 20, BLACK);

        // End frame
        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();
    return 0;
}