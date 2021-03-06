
//The aim is to create a Pong like game using raylib
//
// Functions to learn
//
//  void DrawRectangle(int posX, int posY, int width, int height, Color color); 
//  void DrawRectangleV(Vector2 position, Vector2 size, Color color); 
//  const char *TextFormat(const char *text, ...);
//  bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);  
//  -

#include "raylib.h"

int main(int argc, char const *argv[])
{
	int screenWidth = 800;
    int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Project1 - Testing");
    SetTargetFPS(30);
    float initballSpeedx = 5.0f;
    float initballSpeedy = 5.0f;

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    Vector2 ballSpeed = {-initballSpeedx, -initballSpeedy};
    int ballRadius = 10;


    Vector2 PlayerRecSize = { 40, 250 };
    
    
    Vector2 PlayerRecPos = { (float)screenWidth/10, (float)((screenHeight/2)-(PlayerRecSize.y/2)) };
    Vector2 PlayerRecPos2 = PlayerRecPos;
    PlayerRecPos2.x = PlayerRecPos.x+600;
    



    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
    	//if collision = false
    	
    	//Player rectangle movement
    	if (PlayerRecPos.y <= screenHeight && PlayerRecPos.y >= 0)
    	{

    		if (IsKeyDown(KEY_DOWN) && (PlayerRecPos.y != (screenHeight - PlayerRecSize.y) )) PlayerRecPos.y += 5;
    	}

    	if (PlayerRecPos.y <= screenHeight && PlayerRecPos.y >= 0)
    	{
    		if (IsKeyDown(KEY_UP) && (PlayerRecPos.y != 0)) PlayerRecPos.y -= 5;
    	}

    	//Ball movement
    	ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;
        if ((ballPosition.y >= GetScreenHeight() - ballRadius) || ballPosition.y <= 0+ballRadius)
        {
			ballSpeed.y *= -1.0f;
		}


        //Left Player collision
        //
        
		if (ballPosition.x + ballRadius == (PlayerRecPos.x+PlayerRecSize.x+2*ballRadius))
		{
			if ( ((ballPosition.y >= PlayerRecPos.y) && (ballPosition.y <= PlayerRecPos.y+PlayerRecSize.y))&&ballSpeed.x <0)
        	{
        		ballSpeed.x *= -1.0f;
                if (IsKeyDown(KEY_UP))
                {
                    ballSpeed.y += -5.0f;
                }else if (IsKeyDown(KEY_DOWN))
                {
                    ballSpeed.y += 5.0f;
                }
       		}
		}

        //top/bottom of paddle collision detection
        if ((ballPosition.x <= (PlayerRecPos.x+PlayerRecSize.x+2*ballRadius)) && ballPosition.x >= PlayerRecPos.x) 
        {
            if ( ((ballPosition.y + ballRadius > PlayerRecPos.y) && ballSpeed.y > 0) || ((ballPosition.y - ballRadius < PlayerRecPos.y+PlayerRecSize.y))&& ballSpeed.y < 0)
            {
                ballSpeed.y *= -1.0f;
            }
        }




        //Right Player Collision
        if (ballPosition.x + ballRadius == (PlayerRecPos2.x))
        {
            if ( ((ballPosition.y >= PlayerRecPos2.y) && (ballPosition.y <= PlayerRecPos2.y+PlayerRecSize.y))&&ballSpeed.x >0)
            {
                ballSpeed.x *= -1.0f;
                if (IsKeyDown(KEY_UP))
                {
                    ballSpeed.y += -5.0f;
                }else if (IsKeyDown(KEY_DOWN))
                {
                    ballSpeed.y += 5.0f;
                }
            }
        }
        




    	
    
                                                    
        


        
        PlayerRecPos2.y = PlayerRecPos.y;


    	BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("move the box up and down with arrow keys", 10, 380, 20, DARKGRAY);
            DrawText(TextFormat("X: %d", (int)PlayerRecPos.x), 400, 300, 20, RED);
            DrawText(TextFormat("Y: %d", (int)PlayerRecPos.y), 440, 320, 20, RED);
           
            DrawCircleV(ballPosition, ballRadius, MAROON);
            DrawRectangleV(PlayerRecPos, PlayerRecSize, MAROON);
            DrawRectangleV(PlayerRecPos2, PlayerRecSize, MAROON);
        EndDrawing();

        //
    }



	CloseWindow(); 
	return 0;
}