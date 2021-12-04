#define ALLEGRO_UNSTABLE
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>

#define NONE 0
#define KING 1
#define PAWN 2
#define KNIGHT 3
#define BISHOP 4
#define ROOK 5
#define QUEEN 6
#define WHITE 8
#define BLACK 16
#define INDIC 25

int board[63];
int board2[63];
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT ev;
ALLEGRO_TIMER* timer;
bool redraw;
int switcher;
int xx;
int yy;

int drawpiece(int piecechoice,int x,int y);

int drawboard();

int pxtocell(int x,int y);

int boardupdate();

int calculatemoves(){
	int x,y;
	if(switcher == 1){
		for(int i = 0;i < 64;i++){
			if(board[i] == INDIC){
				board[i] = board2[i];
				switcher = 0;
			}
		}
		boardupdate();
		return 0;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | PAWN)){
		for(int i = 0;i < 64;i++){
			board2[i] = board[i];
		}
		board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 8] = INDIC; 
		board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 16] = INDIC;
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | PAWN)){
		for(int i = 0;i < 64;i++){
			board2[i] = board[i];
		}
		board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 8] = INDIC; 
		board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 16] = INDIC;
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | KING)){
		for(int i = 0;i < 64;i++){
			board2[i] = board[i];
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)-1)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx-1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 1] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)+1)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx+1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 1] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)-9)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx-1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 9] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)+9)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx+1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 9] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)-7)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx+1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 7] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)+7)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx-1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 7] = INDIC; 
		}
		board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 8] = INDIC; 
		board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 8] = INDIC; 
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | KING)){
		for(int i = 0;i < 64;i++){
			board2[i] = board[i];
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)-1)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx-1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 1] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)+1)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx+1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 1] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)-9)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx-1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 9] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)+9)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx+1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 9] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)-7)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx+1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 7] = INDIC; 
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y)+7)% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((xx-1) == x){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 7] = INDIC; 
		}
		board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 8] = INDIC; 
		board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 8] = INDIC; 
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | KNIGHT)){
		for(int i = 0;i < 64;i++){
			board2[i] = board[i];
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)-15) - ((pxtocell(ev.mouse.x,ev.mouse.y)-15) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy-2) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 15] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)+15) - ((pxtocell(ev.mouse.x,ev.mouse.y)+15) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy+2) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 15] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)-17) - ((pxtocell(ev.mouse.x,ev.mouse.y)-17) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy-2) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 17] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)+17) - ((pxtocell(ev.mouse.x,ev.mouse.y)+17) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy+2) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 17] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)-6) - ((pxtocell(ev.mouse.x,ev.mouse.y)-6) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy-1) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 6] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)+6) - ((pxtocell(ev.mouse.x,ev.mouse.y)+6) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy+1) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 6] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)-10) - ((pxtocell(ev.mouse.x,ev.mouse.y)-10) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy-1) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 10] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)+10) - ((pxtocell(ev.mouse.x,ev.mouse.y)+10) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy+1) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 10] = INDIC; 
		}
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | KNIGHT)){
		for(int i = 0;i < 64;i++){
			board2[i] = board[i];
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)-15) - ((pxtocell(ev.mouse.x,ev.mouse.y)-15) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy-2) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 15] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)+15) - ((pxtocell(ev.mouse.x,ev.mouse.y)+15) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy+2) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 15] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)-17) - ((pxtocell(ev.mouse.x,ev.mouse.y)-17) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy-2) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 17] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)+17) - ((pxtocell(ev.mouse.x,ev.mouse.y)+17) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy+2) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 17] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)-6) - ((pxtocell(ev.mouse.x,ev.mouse.y)-6) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy-1) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 6] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)+6) - ((pxtocell(ev.mouse.x,ev.mouse.y)+6) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy+1) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 6] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)-10) - ((pxtocell(ev.mouse.x,ev.mouse.y)-10) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy-1) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) - 10] = INDIC; 
		}
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)+10) - ((pxtocell(ev.mouse.x,ev.mouse.y)+10) % 8)) / 8;
		pxtocell(ev.mouse.x,ev.mouse.y);
		if((yy+1) == y){
			 board[(pxtocell(ev.mouse.x,ev.mouse.y)) + 10] = INDIC; 
		}
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | ROOK)){
		for(int i = 0;i < 64;i++){
			board2[i] = board[i];
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		for(int i = 0;i < 8;i++){
			if(i != x){
				board[(y*8) + i] = INDIC;
			}
		}
		for(int j = 0;j < 8;j++){
			if(j != y){
				board[(j*8) + x] = INDIC;
			}
		}
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | ROOK)){
		for(int i = 0;i < 64;i++){
			board2[i] = board[i];
		}
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		for(int i = 0;i < 8;i++){
			if(i != x){
				board[(y*8) + i] = INDIC;
			}
		}
		for(int j = 0;j < 8;j++){
			if(j != y){
				board[(j*8) + x] = INDIC;
			}
		}
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (BLACK | BISHOP)){
		for(int i = 0;i < 64;i++){
			if(board[i] == INDIC){
				board[i] = NONE;
			}
			board2[i] = board[i];
		}
		int i = 0;
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		for (int i = 0; i < 8; ++i)
		{
			if((((y+i)*8)+x+i) != (pxtocell(ev.mouse.x,ev.mouse.y))){
				board[((y+i)*8)+x+i] = INDIC;
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			if((((y+i)*8)+x+i) != (pxtocell(ev.mouse.x,ev.mouse.y))){
				board[((y+i)*8)+x-i] = INDIC;
			}
			if((x - i) == 0){
				printf("%d %d %d %d %d\n",yy,y,i,((y+i)*8)+x+i,x-i);
				break;
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			if((((y-i)*8)+x-i) > 0){
				if((((y+i)*8)+x+i) != (pxtocell(ev.mouse.x,ev.mouse.y))){
					board[((y-i)*8)+x-i] = INDIC;
				}
			}
			if((x - i) == 0){
				printf("%d %d %d %d %d\n",yy,y,i,((y+i)*8)+x+i,x-i);
				break;
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			if((((y-i)*8)+x+i) > 0){
				if((((y+i)*8)+x+i) != (pxtocell(ev.mouse.x,ev.mouse.y))){
					board[((y-i)*8)+x+i] = INDIC;
				}
			}
			if((x + i) == 7){
				printf("%d %d %d %d %d\n",yy,y,i,((y+i)*8)+x+i,x-i);
				break;
			}
		}
		switcher = 1;
	}
	if(board[pxtocell(ev.mouse.x,ev.mouse.y)] == (WHITE | BISHOP)){
		for(int i = 0;i < 64;i++){
			if(board[i] == INDIC){
				board[i] = NONE;
			}
			board2[i] = board[i];
		}
		int i = 0;
		y = ((pxtocell(ev.mouse.x,ev.mouse.y)) - ((pxtocell(ev.mouse.x,ev.mouse.y)) % 8)) / 8;
		x = ((pxtocell(ev.mouse.x,ev.mouse.y))% 8);
		pxtocell(ev.mouse.x,ev.mouse.y);
		for (int i = 0; i < 8; ++i)
		{
			if((((y+i)*8)+x+i) != (pxtocell(ev.mouse.x,ev.mouse.y))){
				board[((y+i)*8)+x+i] = INDIC;
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			if((((y+i)*8)+x+i) != (pxtocell(ev.mouse.x,ev.mouse.y))){
				board[((y+i)*8)+x-i] = INDIC;
			}
			if((x - i) == 0){
				printf("%d %d %d %d %d\n",yy,y,i,((y+i)*8)+x+i,x-i);
				break;
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			if((((y-i)*8)+x-i) > 0){
				if((((y+i)*8)+x+i) != (pxtocell(ev.mouse.x,ev.mouse.y))){
					board[((y-i)*8)+x-i] = INDIC;
				}
			}
			if((x - i) == 0){
				printf("%d %d %d %d %d\n",yy,y,i,((y+i)*8)+x+i,x-i);
				break;
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			if((((y-i)*8)+x+i) > 0){
				if((((y+i)*8)+x+i) != (pxtocell(ev.mouse.x,ev.mouse.y))){
					board[((y-i)*8)+x+i] = INDIC;
				}
			}
			if((x + i) == 7){
				printf("%d %d %d %d %d\n",yy,y,i,((y+i)*8)+x+i,x-i);
				break;
			}
		}
		switcher = 1;
	}
	return 0;
}

int pxtocell(int x,int y){
	if(x < 44 && x > 0){
		xx = 0;
	}
	if(x < 88 && x > 44){
		xx = 1;
	}
	if(x < 132 && x > 88){
		xx = 2;
	}
	if(x < 176 && x > 132){
		xx = 3;
	}
	if(x < 220 && x > 176){
		xx = 4;
	}
	if(x < 264 && x > 220){
		xx = 5;
	}
	if(x < 308 && x > 264){
		xx = 6;
	}
	if(x < 352 && x > 308){
		xx = 7;
	}
	if(y < 44 && y > 0){
		yy = 0;
	}
	if(y < 88 && y > 44){
		yy = 1;
	}
	if(y < 132 && y > 88){
		yy = 2;
	}
	if(y < 176 && y > 132){
		yy = 3;
	}
	if(y < 220 && y > 176){
		yy = 4;
	}
	if(y < 264 && y > 220){
		yy = 5;
	}
	if(y < 308 && y > 264){
		yy = 6;
	}
	if(y < 352 && y > 308){
		yy = 7;
	}
	return ((yy*8)+xx);
}

int piecemove(int fx,int fy,int dx,int dy){
	board[((dy-1)*8)+(dx-1)] = board[((fy-1)*8)+(fx-1)];
	board[((fy-1)*8)+(fx-1)] = NONE;
	return 0;
}

int boardupdate(){
	int x = 0;
	int y = 0;
	drawboard();
	for(int i = 0;i < 64;i++){
		if(board[i] == NONE){
			x = x + 1;
		}
		if(board[i] == (BLACK | KING)){
			drawpiece((BLACK | KING),x,y);
			x = x + 1;
		}
		if(board[i] == (BLACK | QUEEN)){
			drawpiece((BLACK | QUEEN),x,y);
			x = x + 1;
		}
		if(board[i] == (BLACK | PAWN)){
			drawpiece((BLACK | PAWN),x,y);
			x = x + 1;
		}
		if(board[i] == (BLACK | KNIGHT)){
			drawpiece((BLACK | KNIGHT),x,y);
			x = x + 1;
		}
		if(board[i] == (BLACK | BISHOP)){
			drawpiece((BLACK | BISHOP),x,y);
			x = x + 1;
		}
		if(board[i] == (BLACK | ROOK)){
			drawpiece((BLACK | ROOK),x,y);
			x = x + 1;
		}
		if(board[i] == (WHITE | KING)){
			drawpiece((WHITE | KING),x,y);
			x = x + 1;
		}
		if(board[i] == (WHITE | QUEEN)){
			drawpiece((WHITE | QUEEN),x,y);
			x = x + 1;
		}
		if(board[i] == (WHITE | ROOK)){
			drawpiece((WHITE | ROOK),x,y);
			x = x + 1;
		}
		if(board[i] == (WHITE | BISHOP)){
			drawpiece((WHITE | BISHOP),x,y);
			x = x + 1;
		}
		if(board[i] == (WHITE | KNIGHT)){
			drawpiece((WHITE | KNIGHT),x,y);
			x = x + 1;
		}
		if(board[i] == (WHITE | PAWN)){
			drawpiece((WHITE | PAWN),x,y);
			x = x + 1;
		}
		if(board[i] == (INDIC)){
			drawpiece((INDIC),x,y);
			x = x + 1;
		}
		if(x >= 8){
			x = 0;
			y = y + 1;
		}
	}
	return 0;
}

int drawboard(){
	ALLEGRO_BITMAP *background = NULL;
	background = al_load_bitmap("chessboard-empty.png");
	al_draw_bitmap(background,0,0,0);
	al_destroy_bitmap(background);
	return 0;
}

int fenparser(char *fenstring){
	int i = 0;
	int x = 0;
	int y = 0;
	while(1){
		if(fenstring[i] == '\0'){
			return 0;
		}
		if(fenstring[i] == '1'){
			x = x + 1;
		}
		if(fenstring[i] == '2'){
			x = x + 2;
		}
		if(fenstring[i] == '3'){
			x = x + 3;
		}
		if(fenstring[i] == '4'){
			x = x + 4;
		}
		if(fenstring[i] == '5'){
			x = x + 5;
		}
		if(fenstring[i] == '6'){
			x = x + 6;
		}
		if(fenstring[i] == '7'){
			x = x + 7;
		}
		if(fenstring[i] == '8'){
			x = 0;
		}
		if(fenstring[i] == '/'){
			y = y + 1;
			x = 0;
		}
		if(fenstring[i] == 'k'){
			drawpiece((BLACK | KING),x,y);
			board[(y*8)+x] = (BLACK | KING);
			x = x + 1;
		}
		if(fenstring[i] == 'q'){
			drawpiece((BLACK | QUEEN),x,y);
			board[(y*8)+x] = (BLACK | QUEEN);
			x = x + 1;
		}
		if(fenstring[i] == 'r'){
			drawpiece((BLACK | ROOK),x,y);
			board[(y*8)+x] = (BLACK | ROOK);
			x = x + 1;
		}
		if(fenstring[i] == 'n'){
			drawpiece((BLACK | KNIGHT),x,y);
			board[(y*8)+x] = (BLACK | KNIGHT);
			x = x + 1;
		}
		if(fenstring[i] == 'b'){
			drawpiece((BLACK | BISHOP),x,y);
			board[(y*8)+x] = (BLACK | BISHOP);
			x = x + 1;
		}
		if(fenstring[i] == 'p'){
			drawpiece((BLACK | PAWN),x,y);
			board[(y*8)+x] = (BLACK | PAWN);
			x = x + 1;
		}
		if(fenstring[i] == 'K'){
			drawpiece((WHITE | KING),x,y);
			board[(y*8)+x] = (WHITE | KING);
			x = x + 1;
		}
		if(fenstring[i] == 'Q'){
			drawpiece((WHITE | QUEEN),x,y);
			board[(y*8)+x] = (WHITE | QUEEN);
			x = x + 1;
		}
		if(fenstring[i] == 'R'){
			drawpiece((WHITE | ROOK),x,y);
			board[(y*8)+x] = (WHITE | ROOK);
			x = x + 1;
		}
		if(fenstring[i] == 'N'){
			drawpiece((WHITE | KNIGHT),x,y);
			board[(y*8)+x] = (WHITE | KNIGHT);
			x = x + 1;
		}
		if(fenstring[i] == 'B'){
			drawpiece((WHITE | BISHOP),x,y);
			board[(y*8)+x] = (WHITE | BISHOP);
			x = x + 1;
		}
		if(fenstring[i] == 'P'){
			drawpiece((WHITE | PAWN),x,y);
			board[(y*8)+x] = (WHITE | PAWN);
			x = x + 1;
		}
		i++;
	}
	return 0;
}

int allegroinit(){
	if(!al_init()) {
        	fprintf(stderr, "failed to initialize allegro!\n");
        	return -1;
	}
	al_init_image_addon();
	al_install_mouse();
	display = al_create_display(352,352);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	drawboard();
	for(int i = 0;i < 64;i++){
		board[i] = (NONE);
	}
	return 0;
}

int drawpiece(int piecechoice,int x,int y){
	ALLEGRO_BITMAP *piece = NULL;
	if(piecechoice == (WHITE | QUEEN)){
		piece = al_load_bitmap("sprites/whitequeen.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (WHITE | KING)){
		piece = al_load_bitmap("sprites/whiteking.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (WHITE | ROOK)){
		piece = al_load_bitmap("sprites/whiterook.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (WHITE | KNIGHT)){
		piece = al_load_bitmap("sprites/whiteknight.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (WHITE | BISHOP)){
		piece = al_load_bitmap("sprites/whitebishop.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (WHITE | PAWN)){
		piece = al_load_bitmap("sprites/whitepawn.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (BLACK | PAWN)){
		piece = al_load_bitmap("sprites/blackpawn.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (BLACK | QUEEN)){
		piece = al_load_bitmap("sprites/blackqueen.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (BLACK | KING)){
		piece = al_load_bitmap("sprites/blackking.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (BLACK | KNIGHT)){
		piece = al_load_bitmap("sprites/blackknight.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (BLACK | BISHOP)){
		piece = al_load_bitmap("sprites/blackbishop.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (BLACK | ROOK)){
		piece = al_load_bitmap("sprites/blackrook.png");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	if(piecechoice == (INDIC)){
		piece = al_load_bitmap("sprites/indicator.jpg");
		al_draw_bitmap(piece,(x*44),(y*44),0);
		al_destroy_bitmap(piece);
	}
	return 0;
}


