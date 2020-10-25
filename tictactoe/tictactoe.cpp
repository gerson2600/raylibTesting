

//func.h - #include "raylib.h"
#include "bin/func.h"


int main(int argc, char const *argv[])
{
	//raylib.h- screenWidth = 800 // screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Project1 - Testing");
    SetTargetFPS(60);

    //Rectangle struct x,y,width,height
    Vector2 MousePoint = {0,0};
    MousePoint = GetMousePosition();
    


    while (!WindowShouldClose())
    {
        MousePoint = GetMousePosition();
        BeginDrawing();
            PlayingFieldBoxesCheck(MousePoint);
            DrawPlayingField();


            DrawFPS(screenWidth-100, screenHeight-50);
            
            


        EndDrawing();
    }
    


    
    
    CloseWindow();
    return 0;
}