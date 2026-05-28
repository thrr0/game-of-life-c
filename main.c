#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void render();
void init_grid();
void update();
int count_neighbors(int i, int j);

#define WIDTH 100
#define HEIGHT 100

int current[WIDTH][HEIGHT];
int next[WIDTH][HEIGHT];


int main(void) {
    //raylib
    InitWindow(800, 600, "Game of Life");
    SetTargetFPS(60);
    //grid
    init_grid();

    while (!WindowShouldClose()) {
        update();
        BeginDrawing();
        render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void render(){
    for(int i = 0;i < WIDTH; i++){
        for(int j = 0; j<HEIGHT; j++){
            DrawRectangle(i * 8, j * 8, 8 , 8, current[i][j] != 0 ? WHITE : BLACK);
        }
    }
}

void init_grid(){
    srand(time(NULL));

    for(int i = 0;i < WIDTH; i++){
        for(int j = 0; j<HEIGHT; j++){
            next[i][j] = rand() % 2;
        }
    }

    memcpy(current, next, HEIGHT * WIDTH * sizeof(int)); 
}

int count_neighbors(int i, int j){
    int neighbors = 0;

    for (int shifted_i = i-1; shifted_i <= i+1; shifted_i++) {
        if(shifted_i < 0 || shifted_i >= WIDTH){ 
            continue;
        }

        for (int shifted_j = j-1; shifted_j <= j+1; shifted_j++) {

            if(shifted_i == i && shifted_j == j){
                continue;
            }
            if(shifted_j < 0 || shifted_j >= HEIGHT){
                continue;
            }

            if(current[shifted_i][shifted_j] != 0){
                neighbors++;
            }

        }
    }
    return neighbors;
}

void update(){
    for(int i=0; i < WIDTH; i++){
        for(int j=0; j < HEIGHT; j++){
            int neighbors = count_neighbors(i, j);
            if(current[i][j] != 0){
                if(neighbors >= 2 && neighbors <= 3){
                    next[i][j] = 1;
                }else{
                    next[i][j] = 0;
                }
            }else if (neighbors == 3){
                next[i][j] =1;
            }
        }
    }

    memcpy(current, next, WIDTH * HEIGHT * sizeof(int));
}
