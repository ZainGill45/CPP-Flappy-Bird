#include <iostream>
#include <raylib.h>
#include <raymath.h>

int main(int, char**) {
    InitWindow(1280, 720, "Leaning C++");
    SetTargetFPS(300);

    Vector2 playerPosition = { 400, 300 };

    float playerSpeed = 100;

    int playerRadius = 10;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        int screenWidth = GetScreenWidth();
        int screenHeight = GetScreenHeight();

        Vector2 inputVector = { 0, 0 };

        if (IsKeyDown(KEY_W)) inputVector.y += -1;
        if (IsKeyDown(KEY_S)) inputVector.y += 1;
        if (IsKeyDown(KEY_D)) inputVector.x += 1;
        if (IsKeyDown(KEY_A)) inputVector.x += -1;

        inputVector = Vector2Normalize(inputVector);

        playerPosition.x += inputVector.x * playerSpeed * GetFrameTime();
        playerPosition.y += inputVector.y * playerSpeed * GetFrameTime();

        playerPosition = { Clamp(playerPosition.x, 0 + playerRadius , screenWidth - playerRadius), Clamp(playerPosition.y, 0 + playerRadius, screenHeight - playerRadius) };

        DrawCircle(playerPosition.x, playerPosition.y, playerRadius, RED);

        char debugText[32];
        snprintf(debugText, sizeof(debugText), "(%.0f, %.0f)", inputVector.x, inputVector.y);
        DrawText(debugText, 10, 32, 20, BLACK);

        DrawFPS(10, 5);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}