//func.h

#include "raylib.h"
int screenWidth = 640;
int screenHeight = 480;
int borderwidth = 20;
int initposX= 40.0f; 
int initposY= 40.0f;
int RecLength= 400;
int RecWidth= 25;

//bool CheckCollisionPointRec(Vector2 point, Rectangle rec);
//void DrawRectangleV(Vector2 position, Vector2 size, Color color); 
//void DrawRectangle(int posX, int posY, int width, int height, Color color);
//void DrawFPS(int posX, int posY);

int PlayingFieldBoxesCheck(Vector2 MousePoint)
{
    int check=0;
    Rectangle WhiteBox = {0,0, (float)screenWidth, (float)screenHeight};
    Rectangle Box1 = {(float)initposX, (float)initposY , (float)((RecLength/3)-(RecWidth/2)),(float)(RecLength/3-(RecWidth/2)) };
    if (CheckCollisionPointRec(MousePoint, Box1))
    {
        DrawRectangleRec(Box1, RED);
    }else
    {
        DrawRectangleRec(WhiteBox, WHITE);
    }
    
    return check;
}

void DrawPlayingField(void)
{
    //One rectangle for the border, 4 for the playing field to create the #
    

    Rectangle Border, Mid1,Mid2,Mid3,Mid4;
    Border = {0,0, (float)screenWidth, (float)screenHeight};

    DrawRectangleLinesEx(Border, borderwidth, BLACK);
    DrawRectangle((RecLength/3)-(RecWidth/2)+initposX, initposY, RecWidth, RecLength, BLUE);
    DrawRectangle((RecLength*0.666-(RecWidth/2)+initposX), initposY, RecWidth, RecLength, RED);
    DrawRectangle(initposX, ((RecLength/3)-(RecWidth/2)+initposY), RecLength, RecWidth, BLACK);
    DrawRectangle(initposX, ((RecLength*0.666-(RecWidth/2)+initposY)), RecLength, RecWidth, BLACK);


    
}

