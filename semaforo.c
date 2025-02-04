#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_COUNT 3

// Pinos dos LEDs e array armazenando cada um na ordem de um semáforo
const uint led_red_pin = 13;
const uint led_yellow_pin = 12;
const uint led_green_pin = 11;
const uint led_pins[] = {led_red_pin, led_yellow_pin, led_green_pin};

// Buffer que armazena a posição no array do LED que está ligado
static volatile uint8_t ledAtual = 0;

// Headers de função
void inicializar_leds();
bool repeating_timer_callback(struct repeating_timer *t);

int main()
{
    inicializar_leds();

    // Definição do temporizador de repetição de 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    stdio_init_all();

    while (true) 
    {   
        // Indica qual LED está ligado pelo monitor serial
        printf("LED ligado: ");
        switch(led_pins[ledAtual])
        {
            case led_red_pin:
                printf("VERMELHO\n");
                break;
            case led_yellow_pin:
                printf("AMARELO\n");
                break;
            case led_green_pin:
                printf("VERDE\n");
                break;
        }
        sleep_ms(1000);
    }
}

// Inicializa os pinos dos LEDs
void inicializar_leds()
{   
    uint curr_pin;
    for (int i = 0; i < LED_COUNT; i++)
    {   
        // Obter pino atual
        curr_pin = led_pins[i];

        // Inicializar e definir direção do pino
        gpio_init(curr_pin);
        gpio_set_dir(curr_pin, GPIO_OUT);

        // Garantir que apenas o LED definido comece ligado (Por padrão, o vermelho)
        if (i == ledAtual)
        {
            gpio_put(curr_pin, 1);
        }
        else
        {
            gpio_put(curr_pin, 0);
        }
    }
}

// Função do temporizador
bool repeating_timer_callback(struct repeating_timer *t)
{   
    // Desligar LED atual
    gpio_put(led_pins[ledAtual], 0);

    // Atualizar buffer para o próximo LED no array e ligá-lo
    ledAtual++;
    if (ledAtual == LED_COUNT)
    {
        ledAtual = 0;
    }
    gpio_put(led_pins[ledAtual], 1);
    
    printf("Sinal alterado!\n");

    // Repetir temporizador
    return true;
}
