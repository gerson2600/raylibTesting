//func.h

#include "raylib.h"


int screenWidth = 640;
int screenHeight = 480;
int borderwidth = 20;
int initposX= 40; 
int initposY= 40;
int RecLength= 400;
int RecWidth= 25;
float Boxsize = (RecLength/3)-(RecWidth/2);
float XOwidth = 10.0;

// bool CheckCollisionPointRec(Vector2 point, Rectangle rec);
// void DrawRectangleV(Vector2 position, Vector2 size, Color color); 
// void DrawRectangle(int posX, int posY, int width, int height, Color color);
// void DrawFPS(int posX, int posY);
// void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);
// void DrawCircle(int centerX, int centerY, float radius, Color color); 



void DrawX(float PosX, float PosY)
{
    float p = 20;
    Vector2 StartPos1 = {PosX+p,PosY+p};
    Vector2 EndPos1 = {PosX-p+Boxsize,PosY+Boxsize-p};
    Vector2 StartPos2 = {PosX+p,PosY+Boxsize-p};
    Vector2 EndPos2 = {PosX-p+Boxsize,PosY+p};
    DrawLineEx(StartPos1, EndPos1, XOwidth, RED);
    DrawLineEx(StartPos2, EndPos2, XOwidth, RED);
}
void DrawO(float PosX, float PosY)
{
    float p = 15;
    int centerX = PosX + (Boxsize/2.2);
    int centerY = PosY + (Boxsize/2.2);
    float radius = (Boxsize/2)-p;
    DrawCircle(centerX,centerY, radius, BLUE);
    DrawCircle(centerX,centerY, radius-XOwidth, WHITE);
}

int PlayingFieldBoxesCheck(Vector2 MousePoint, int ValidPlays[9], int gamestate, int currentplayer)
{
    // 1 | 2 | 3
    // 4 | 5 | 6
    // 7 | 8 | 9

    int clicked=99;
    ClearBackground(WHITE);
    Rectangle WhiteBox = {(float)initposX,(float)initposY, (float)RecLength, (float)RecLength};
    Rectangle Box[9];
    Box[0] = {(float)initposX, (float)initposY , Boxsize,Boxsize };
    Box[1] = {(float)initposX+(RecLength/2)-((Boxsize-RecWidth/2)/2) , (float)initposY  , Boxsize-(RecWidth/2),Boxsize };
    Box[2] = {(float)initposX+RecLength-Boxsize , (float)initposY  , Boxsize,Boxsize };

    Box[3] = {(float)initposX , (float)initposY+(RecLength/2)-((Boxsize-RecWidth/2)/2)  , Boxsize,Boxsize-(RecWidth/2) };
    Box[4] = {(float)initposX+(RecLength/2)-((Boxsize-RecWidth/2)/2) , (float)initposY+(RecLength/2)-((Boxsize-RecWidth/2)/2)  , Boxsize-(RecWidth/2),Boxsize-(RecWidth/2)};
    Box[5] = {(float)initposX+RecLength-Boxsize , (float)initposY+(RecLength/2)-((Boxsize-RecWidth/2)/2)  , Boxsize,Boxsize-(RecWidth/2) };

    Box[6] = {(float)initposX , (float)initposY+RecLength-Boxsize  , Boxsize,Boxsize };
    Box[7] = {(float)initposX+(RecLength/2)-((Boxsize-RecWidth/2)/2) , (float)initposY+RecLength-Boxsize  , Boxsize-(RecWidth/2),Boxsize };
    Box[8] = {(float)initposX+RecLength-Boxsize , (float)initposY+RecLength-Boxsize  , Boxsize,Boxsize };
    
    //DrawRectangleRec(WhiteBox, WHITE);
    if (gamestate==1)
    { 
        for (int i = 0; i < 9; i++)
        {
            if (CheckCollisionPointRec(MousePoint, Box[i]) && ValidPlays[i]==0)
            {
                if (currentplayer==1)
                {
                    DrawRectangleRec(Box[i], RED);
                }else if (currentplayer==2)
                {
                    DrawRectangleRec(Box[i], BLUE);
                }
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    clicked = i;
                }
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (ValidPlays[i]==2)
        {
            //Draw X's
            DrawX((float)Box[i].x,(float)Box[i].y);

        }else if (ValidPlays[i]==3)
        {
            //Draw O's
            DrawO((float)Box[i].x,(float)Box[i].y);

        }
    }
    return clicked;
}

void DrawPlayingField()
{
    //One rectangle for the border, 4 for the playing field to create the #
    

    Rectangle Border, Mid1,Mid2,Mid3,Mid4;
    Border = {0,0, (float)screenWidth, (float)screenHeight};

    DrawRectangleLinesEx(Border, borderwidth, BLACK);
    DrawRectangle((RecLength/3)-(RecWidth/2)+initposX, initposY, RecWidth, RecLength, BLACK);
    DrawRectangle((RecLength*0.666-(RecWidth/2)+initposX), initposY, RecWidth, RecLength,BLACK);
    DrawRectangle(initposX, ((RecLength/3)-(RecWidth/2)+initposY), RecLength, RecWidth, BLACK);
    DrawRectangle(initposX, ((RecLength*0.666-(RecWidth/2)+initposY)), RecLength, RecWidth, BLACK);

}

int WinningCheck(int VP[9])
{
    //check for grouping of equal values
    // 1 | 2 | 3        0|1|2
    // 4 | 5 | 6        3|4|5
    // 7 | 8 | 9        6|7|8

    // 1-2-3 // 4-5-6 // 7-8-9
    // 1-4-7 // 2-5-8 // 3-6-9
    // 1-5-9 // 3-5-7
    int check=1;
    int RemainingPlays=0;
    //1=game running
    //2-player1 win
    //3-player2 win
    //4=Draw

    if      (VP[0]!=0 &&  (VP[0]==VP[1] && VP[1]==VP[2]) ) {check = VP[0];}
    else if (VP[3]!=0 &&  (VP[3]==VP[4] && VP[4]==VP[5]) ) {check = VP[3];}
    else if (VP[6]!=0 &&  (VP[6]==VP[7] && VP[7]==VP[8]) ) {check = VP[6];}

    else if (VP[0]!=0 &&  (VP[0]==VP[3] && VP[3]==VP[6]) ) {check = VP[0];}
    else if (VP[1]!=0 &&  (VP[1]==VP[4] && VP[4]==VP[7]) ) {check = VP[1];}
    else if (VP[2]!=0 &&  (VP[2]==VP[5] && VP[5]==VP[8]) ) {check = VP[2];}

    else if (VP[0]!=0 &&  (VP[0]==VP[4] && VP[4]==VP[8]) ) {check = VP[0];}
    else if (VP[2]!=0 &&  (VP[2]==VP[4] && VP[4]==VP[6]) ) {check = VP[2];}
    for (int i = 0; i < 9; i++)
    {
        if (VP[i]==0)
        {
            RemainingPlays++;
        }
    }
    if (RemainingPlays==0)
    {
        check =4;
    }
    
    


    return check;
    
}


