

//func.h - #include "raylib.h"
#include "bin/func.h"

int main(int argc, char const *argv[])
{
	int screenWidth = 800;
    int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Project1 - Testing");
    SetTargetFPS(30);

    //Rectangle struct x,y,width,height
    Rectangle Rec;
    Rec = {0,1, (float)screenWidth, (float)screenHeight};
    


    while (!WindowShouldClose())
    {
        BeginDrawing();
        DrawRectangleLinesEx(Rec, 10, BLACK);


        EndDrawing();
    }
    


    
    
    CloseWindow();
    return 0;
}