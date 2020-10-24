

#include "raylib.h"


int main(int argc, char const *argv[])
{
    //Display declarations and init
    int screenWidth = 800;
    int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "Project1 - Testing");
    SetTargetFPS(30);

    //Camera setup
    Camera camera = { 0 };
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.type = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_FIRST_PERSON);

    //Variables declaration
    bool gamestate = 1;
    




    while (!WindowShouldClose())
    {
        //Game updates
        UpdateCamera(&camera); 

        BeginDrawing();
        //Graphic drawing frame by frame
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
            DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 100.0f, 100.0f }, BLACK); // Draw ground
            DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);
                
        EndMode3D();
        EndDrawing();
    }
    
    

    CloseWindow();
    return 0;
}
