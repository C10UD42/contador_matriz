//Declaração das bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"
#include "numeros.h"
#include <stdint.h>
#include <stdbool.h>

#define IS_RGBW false
#define NUM_PIXELS 25
#define WS2812_PIN 7

const uint led_pin_red   = 13; //Led rgb vermelho
const uint button_A = 5; // Botão A = 5
const uint button_B = 6; //Botão B = 6

uint8_t led_r = 150; // Intensidade do vermelho
uint8_t led_g = 0; // Intensidade do verde
uint8_t led_b = 150; // Intensidade do azul

uint8_t current_number = 0;

bool* numeros[10] = {numeroZero, numeroUm, numeroDois, numeroTres, numeroQuatro, numeroCinco, numeroSeis, numeroSete, numeroOito, numeroNove};

static inline void put_pixel(uint32_t pixel_grb)
{
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b)
{
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

void set_one_led(uint8_t number, uint8_t r, uint8_t g, uint8_t b)
{
    // Define a cor com base nos parâmetros fornecidos
    uint32_t color = urgb_u32(r, g, b);

    // Define todos os LEDs com a cor especificada
    for (int i = 0; i < NUM_PIXELS; i++)
    {
        if (numeros[number][i])
        {
            put_pixel(color); // Liga o LED com um no buffer
        }
        else
        {
            put_pixel(0);  // Desliga os LEDs com zero no buffer
        }
    }
}

bool debouncing(){
    //implementar o debouncing
    static uint32_t last_time = 0;
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - last_time < 200) {
        return false;
    }
    last_time = current_time;
    return true;

}

void gpio_irq_handler(uint gpio, uint32_t events)
{
    if (!debouncing()) 
        return;

    if(gpio == button_A)
        if(current_number == 9){
            current_number = 0;
        }
        else{
            current_number++;
        }
    printf("Contador: %d\n", current_number);

    
    if(gpio == button_B)
        if(current_number == 0){
            current_number = 9;
        }
        else{
            current_number--;
        }
    printf("Contador: %d\n", current_number);
}

void blink_led_vermelho(){
    gpio_put(led_pin_red, true);
    sleep_ms(100);
    gpio_put(led_pin_red, false);
    sleep_ms(100);
}

int main()
{
    stdio_init_all();
    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &contador_matriz_program);

    contador_matriz_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    gpio_init(led_pin_red);              // Inicializa o pino do LED
    gpio_set_dir(led_pin_red, GPIO_OUT); // Configura o pino como saída
    
    gpio_init(button_A);
    gpio_set_dir(button_A, GPIO_IN); // Configura o pino como entrada
    gpio_pull_up(button_A);

    gpio_init(button_B);
    gpio_set_dir(button_B, GPIO_IN); // Configura o pino como entrada
    gpio_pull_up(button_B);

    gpio_set_irq_enabled_with_callback(button_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(button_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    while (true)
    {
        set_one_led(current_number, led_r, led_g, led_b);
        blink_led_vermelho();
        sleep_ms(100);
    }

    return 0;
}
