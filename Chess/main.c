#include <stdio.h>
#include <stdlib.h>
#include "board.c"

//rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR

int main(){
	printf("hello\n");
	allegroinit();
	fenparser("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
	al_flip_display();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30);
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
	while(1){
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_TIMER){
			drawboard();
			boardupdate();
			redraw = true;
		}	
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			al_destroy_display(display);
			al_destroy_timer(timer);
			al_uninstall_system();
			return 0;
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
			drawboard();
			boardupdate();
			calculatemoves();
			boardupdate();
		}
		if(redraw && al_is_event_queue_empty(event_queue)){
			al_flip_display();
			redraw = false;
		}
		piecemove(5,6,5,5);
		boardupdate();
	}
	return 0;
}