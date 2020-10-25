

//func.h - #include "raylib.h"
#include "bin/func.h"


int main(int argc, char const *argv[])
{
	//raylib.h- screenWidth = 800 // screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Project1 - Testing");
    SetTargetFPS(60);
    //Player1/Player2
    int CurrentPlayer=1;
    int gamestate=0;
    int ScoreP1 = 0;
    int ScoreP2 = 0;
    int ScoreDraw = 0;
    //New Game Button
    Rectangle NewGameBtn = {(float)screenWidth-150, 50.0, 115,50 };
    Vector2 Scores = {(float)(screenWidth*0.8), (float)(screenHeight*0.6)};
    int Winner=0;
    
    //Rectangle struct x,y,width,height
    int ValidPlays[9] = {0,0,0
                        ,0,0,0
                        ,0,0,0};
                        
    //0 for empty playing field
    //2 for player1 -X
    //3 for player2 -O
    //99 for no play made(only in check function, not in this array)
    int CurrentMove=99;
    Vector2 MousePoint = {0,0};
    MousePoint = GetMousePosition();
    

    while (!WindowShouldClose())
    {
        if (WinningCheck(ValidPlays)!=1 && gamestate==1)
        {
            Winner=WinningCheck(ValidPlays);
            if (Winner == 2)
            {
                ScoreP1++;
            }else if (Winner == 3)
            {
                ScoreP2++;
            }else if (Winner == 4)
            {
                ScoreDraw++;
            }
            gamestate=0;
        }
        //Add winning increment/scoreboard
        //Output winner/Draw,etc

        if (CurrentMove != 99 && gamestate ==1)
        {
            if (CurrentPlayer==1)
            {
                ValidPlays[CurrentMove]=2;
                CurrentPlayer=2;
            }
            else if (CurrentPlayer==2)
            {
                ValidPlays[CurrentMove]=3;
                CurrentPlayer=1;
            }     
        }
        MousePoint = GetMousePosition();
        BeginDrawing();
            DrawPlayingField();
            CurrentMove = PlayingFieldBoxesCheck(MousePoint, ValidPlays, gamestate, CurrentPlayer);
            
            //Game Start Button
            DrawRectangleRec(NewGameBtn, RED);
            DrawText("New Game", NewGameBtn.x+10, NewGameBtn.y+(NewGameBtn.height/2-10), 20, LIGHTGRAY);
            DrawText("Wins", Scores.x, Scores.y, 35, BLACK );
            DrawText(TextFormat("X: %d", ScoreP1), Scores.x, Scores.y+40, 30, BLACK);
            DrawText(TextFormat("0: %d", ScoreP2), Scores.x, Scores.y+80, 30, BLACK);
            DrawText(TextFormat("TIE: %d", ScoreDraw), Scores.x, Scores.y+120, 30, BLACK);
            if (CheckCollisionPointRec(MousePoint, NewGameBtn))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    gamestate=1;
                    for (int i = 0; i < 9; i++)
                    {
                        ValidPlays[i]=0;
                    }
                }
            }
            
            //DrawFPS(screenWidth-100, screenHeight-50);
        EndDrawing();
    }
    


    
    
    CloseWindow();
    return 0;
}