#include "raylib.h"
#include "raymath.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "2.5D Environment");

    // Player Initial Position in World Space
    Vector3 playerPosition = { 0.0f, 0.5f, 0.0f }; // Y is 0.5f to be on top of the grid plane (1.0f high cube spawns half in the ground half above apparently)

    // Player Screen Space Position
    Vector2 playerScreenPosition = { 0.0f, 0.0f };

    // Player Name
    const char* playerName = "Negus";

    // Camera Initial Position
    float cameraOffset = 10.0f;
    Vector3 cameraPosition = Vector3AddValue(playerPosition, cameraOffset);

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = cameraPosition; // Camera position
    camera.target = playerPosition;   // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f }; // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;               // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; // Camera projection type

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        // Handle player input and move the player
        if (IsKeyDown(KEY_W)) playerPosition.z -= 0.5f;
        if (IsKeyDown(KEY_S)) playerPosition.z += 0.5f;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 0.5f;
        if (IsKeyDown(KEY_D)) playerPosition.x += 0.5f;


        // Update camera position based on player position
        camera.target = playerPosition;
        camera.position = Vector3AddValue(playerPosition, cameraOffset);

        // Calculate cube screen space position (with a little offset to be in top)
        playerScreenPosition = GetWorldToScreen(Vector3{ playerPosition.x, playerPosition.y + 2.5f, playerPosition.z }, camera);

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Draw the player cube
                DrawCube(playerPosition, 1.0f, 1.0f, 1.0f, DARKBLUE);

                DrawGrid(100, 1.0f);

            EndMode3D();

            DrawText(playerName, playerScreenPosition.x - MeasureText(playerName, 20) / 2.0, playerScreenPosition.y, 20, BLACK);
            DrawFPS(10, 10);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
