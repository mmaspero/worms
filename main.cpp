#define ERROR -1
#define QUIT_GAME -1


#include <stdio.h>
#include <allegro5/allegro.h>

bool keys []= {false,false,false,false,false,false}; //arreglo con el estado de cada key

enum GAME_KEYS
{
    KEY_LEFT,
    KEY_RIGHT,
    KEY_UP,
    KEY_A,
    KEY_D,
    KEY_W
};//Sirve para identificar la posiscion de cada tecla en el arreglo 'keys'

    
const float FPS = 60;

    
int main(int argc, char **argv)
{
    
//Inicializacion de allegro
    
        ALLEGRO_EVENT_QUEUE *event_queue = NULL;
        

        if(!al_init()) {
            fprintf(stderr, "failed to initialize allegro!\n");
            return ERROR;
        }
        
        if(!al_install_keyboard()) {
            fprintf(stderr, "failed to initialize keyboard!\n");
            return ERROR;
        }
        
        
        ALLEGRO_TIMER* Arrows = al_create_timer(0.1);
        if(!Arrows) {
            fprintf(stderr, "failed to create timer!\n");
            return ERROR;
        }
        
        ALLEGRO_TIMER* Keys = al_create_timer(0.1);
        if(!Keys) {
            fprintf(stderr, "failed to create timer!\n");
            return ERROR;
        }
        
        
        event_queue = al_create_event_queue();
        if(!event_queue) {
            fprintf(stderr, "failed to create event_queue!\n");
            al_uninstall_keyboard;
            al_destroy_timer(Arrows);
            al_destroy_timer(Keys);

            
            return ERROR;
        }
        
     
        al_register_event_source(event_queue, al_get_timer_event_source(Arrows));
        
        al_register_event_source(event_queue, al_get_timer_event_source(Keys));
        
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        
        al_start_timer(Arrows);
        
        al_start_timer(Keys);
        
        ALLEGRO_EVENT ev;
        
        
        int TickCounterArrow = 0;
        
        int TickCouonterKeys = 0;
        
        bool BlockArrows = false;
        
        bool BlockKeys = false;
        
        
        do
        {
            bool evento = al_get_next_event (event_queue, &ev);
            
            if (ev!= al_no_event)
            {
                dispatch (&ev);
            }
        }
        
        while(ev!= DISPLAY_CLOSE)
            
        al_destroy_timer(Keys);
        al_destroy_timer(Arrows);
        al_uninstall_keyboard
        al_destroy_event_queue(event_queue);
        
        return QUIT_GAME;
        
}
    
    
    
void dispatch (*ALLEGRO_EVENT ev)
{
        
    //KEY DOWN EVENTS
        
    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_LEFT && BlockArrows == false)
        {
            key[KEY_LEFT] = true;
                
            BlockArrows = true;
 
            TickCounterArrow = al_get_timer_count(Arrows);
                
            //toggle o start moving w1
                
        }
        

        if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT && BlockArrows == false)
        {
            key[KEY_RIGHT] = true;
            
            BlockArrows = true;
            
            TickCounterArrow = al_get_timer_count(Arrows);
            
            //toggle o start moving w1
            
        }
    
        if (event.keyboard.keycode == ALLEGRO_KEY_UP && BlockArrows == false)
        {
            key[KEY_UP] = true;
                
            BlockArrows = true;
                
            TickCounterArrow = al_get_timer_count(Arrows);
                
            //start jumping w1
                
        }

        if (event.keyboard.keycode == ALLEGRO_KEY_D && BlockKeys == false)
        {
            key[KEY_D] = true;
                
            BlockKeys = true;
                
            TickCounterKeys = al_get_timer_count(Arrows);
                
            //start moving w2
                
        }
            
        if (event.keyboard.keycode == ALLEGRO_KEY_A && BlockKeys == false)
        {
            key[KEY_A] = true;
                
            BlockKeys = true;
                
            TickCounterKeys = al_get_timer_count(Arrows);
                
            //start moving w2
                
        }

        if (event.keyboard.keycode == ALLEGRO_KEY_W && BlockKeys == false)
        {
            key[KEY_W] = true;
                
            BlockKeys = true;
                
            TickCounterKeys = al_get_timer_count(Arrows);
                
            //start jumping w2
                
        }
           
    }
            
          
            
            //KEY UP EVENTS
            
    else if (event.type == ALLEGRO_EVENT_KEY_UP)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_LEFT)
        {
            key[KEY_LEFT] = false;
                    
            BlockArrows = false;
                    
            //Stop moving w1
                    
        }
                
        if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
        {
            key[KEY_RIGHT] = false;
                    
            BlockArrows = false;
                    
            //Stop moving w1
                    
        }
                
            
        if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {

            key[KEY_UP] = false;
                    
            BlockArrows = false;
                    
            //Stop jumping w1
        }
                
                
        if (event.keyboard.keycode == ALLEGRO_KEY_D)
        {
            key[KEY_D] = false;
                    
            BlockKeys = false;
                    
            //Stop moving w2
        }
                
        if (event.keyboard.keycode == ALLEGRO_KEY_W)
        {
            key[KEY_W] = false;
                    
            BlockKeys = false;
                    
            //Stop jumping w2
        
        }

        if (event.keyboard.keycode == ALLEGRO_KEY_A)
        {
            key[KEY_A] = false;
                    
            BlockKeys = false;
                    
            //Stop moving w2
        }
    }
                
                
    //TIMER EVENTS
                            
                            
    else if (event.type == ALLEGRO_EVENT_TIMER)
    {
        if (keys[KEY_LEFT]==true)
        {
            if (al_get_timer_count(Arrows) <= TickCounterArrow + 1)
            {
                //toggle w1
            }
            else if (al_get_timer_count(Arrows) > TickCounterArrow + 1 && al_get_timer_count(Arrows) < TickCounterArrow + 10)
            {
                //walk w1
                
            }
            else
            {
                TickCounterArrow = al_get_timer_count(Arrows);
            }
        }
        
        if (keys[KEY_RIGHT]==true)
        {
            if (al_get_timer_count(Arrows) <= TickCounterArrow + 1)
            {
                //toggle w1
            }
            else if (al_get_timer_count(Arrows) > TickCounterArrow + 1 && al_get_timer_count(Arrows) < TickCounterArrow + 10)
            {
                //walk w1
                
            }
            else
            {
                TickCounterArrow = al_get_timer_count(Arrows);
            }
        }
        
        if (keys[KEY_UP]==true)
        {
            if (al_get_timer_count(Arrows) <= TickCounterArrow + 1)
            {
                //nada
            }
            else if (al_get_timer_count(Arrows) > TickCounterArrow + 1 && al_get_timer_count(Arrows) < TickCounterArrow + 10)
            {
                //jump w1
                
            }
            else
            {
                TickCounterArrow = al_get_timer_count(Arrows);
            }
        }
        
        if (keys[KEY_A]==true)
        {
            if (al_get_timer_count(Keys) <= TickCounterKeys + 1)
            {
                //toggle w2
            }
            else if (al_get_timer_count(Keys) > TickCounterKeys + 1 && al_get_timer_count(Keys) < TickCounterKeys + 10)
            {
                //move w2
                
            }
            else
            {
                TickCounterKeys = al_get_timer_count(Keys);
            }
        }
        
        if (keys[KEY_D]==true)
        {
            if (al_get_timer_count(Keys) <= TickCounterKeys + 1)
            {
                //toggle w2
            }
            else if (al_get_timer_count(Keys) > TickCounterKeys + 1 && al_get_timer_count(Keys) < TickCounterKeys + 10)
            {
                //move w2
                
            }
            else
            {
                TickCounterKeys = al_get_timer_count(Keys);
            }
        }
        
        if (keys[KEY_W]==true)
        {
            if (al_get_timer_count(Keys) <= TickCounterKeys + 1)
            {
                //nada
            }
            else if (al_get_timer_count(Keys) > TickCounterKeys + 1 && al_get_timer_count(Keys) < TickCounterKeys + 10)
            {
                //move w2
                
            }
            else
            {
                TickCounterKeys = al_get_timer_count(Keys);
            }
        }
        
    }

}
            
