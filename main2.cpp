#include <stdio.h>
#include <allegro5/allegro.h>
#define ERROR -1
void dispatcher(ALLEGRO_EVENT &ev);
const int SCREEN_W = 640;
const int SCREEN_H = 480;

enum MYKEYS {
	KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_A, KEY_D, KEY_W
};

bool key[] = { false, false, false, false, false, false };
bool doexit = false;

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return ERROR;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return ERROR;
	}


	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		return ERROR;

	}
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");

		al_destroy_display(display);

		return ERROR;
	}


	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));



	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		dispatcher(ev);

	}


	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

void dispatcher (ALLEGRO_EVENT &ev)
{

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			case ALLEGRO_KEY_A:
				key[KEY_A] = true;
				break;
			case ALLEGRO_KEY_D:
				key[KEY_D] = true;
				break;
			case ALLEGRO_KEY_W:
				key[KEY_W] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			case ALLEGRO_KEY_A:
				key[KEY_A] = false;
				break;
			case ALLEGRO_KEY_D:
				key[KEY_D] = false;
				break;
			case ALLEGRO_KEY_W:
				key[KEY_W] = false;
				break;
			}
		}

}

