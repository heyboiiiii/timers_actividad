#include <stdio.h>
#include "pico/stdlib.h"

int count=0;

bool cambiar_est_gpio6(){
  // Conmuto LED
    gpio_put(6, !gpio_get(6));
    return true;
}
bool cambiar_est_gpio7(){
  // Conmuto LED
    gpio_put(7, !gpio_get(7));
    return true;
}
bool cambiar_est_gpio8(){
  // Conmuto LED
    gpio_put(8, !gpio_get(8));
    return true;
}
bool cambiar_est_gpio9(){
  // Conmuto LED
    gpio_put(9, !gpio_get(9));
    return true;
}

bool cambiar_est_gpio(struct repeating_timer *t){
    //primera funcion comprobamos que gpio activar segun la vez que se entra a la interrupcion
    cambiar_est_gpio6();
    if(count==2){
        cambiar_est_gpio7();
    }if(count==4){
        cambiar_est_gpio8();
    }if(count==8){
        cambiar_est_gpio9();
        count=0;
    }
    count++;
    return true;
}

int main() {
  // Habilito GPIO9,8,7,6
    gpio_init(9);gpio_init(8);gpio_init(7);gpio_init(6);
    // Configuro GPIO9,8,7,6como salida
    gpio_set_dir(9, true);gpio_set_dir(8, true);gpio_set_dir(7, true);gpio_set_dir(6, true);
    // Creo una variable que guarda el estado del Timer
    struct repeating_timer timer;
    // Disparo una alarma cada 500 ms
    add_repeating_timer_ms(250, cambiar_est_gpio, NULL, &timer);
    // Bucle vacio
    while(1);
    return 0;
}