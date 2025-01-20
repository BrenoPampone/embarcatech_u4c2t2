#include <stdio.h>
#include "pico/stdlib.h"

// Declaração de Variáveis e Portas
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER_PIN 21

void play_buzzer(uint freq, uint duration_ms) {
    uint period = 1000000 / freq;  // Período em microssegundos
    uint half_period = period / 2;  // Meio período para alternar

    uint cycles = (duration_ms * 1000) / period;
    for (uint i = 0; i < cycles; i++) {
        gpio_put(BUZZER_PIN, true);
        sleep_us(half_period);  // Manter o sinal HIGH
        gpio_put(BUZZER_PIN, false);
        sleep_us(half_period);  // Manter o sinal LOW
    }
}

void Ciclo() {
    gpio_put(LED_GREEN, true);
    gpio_put(LED_BLUE, false);
    gpio_put(LED_RED, false);
    sleep_ms(1000);
    gpio_put(LED_GREEN, false);
    gpio_put(LED_BLUE, true);
    gpio_put(LED_RED, false);
    sleep_ms(1000);
    gpio_put(LED_GREEN, false);
    gpio_put(LED_BLUE, false);
    gpio_put(LED_RED, true);
    sleep_ms(1000);
    gpio_put(LED_GREEN, false);
    gpio_put(LED_BLUE, false);
    gpio_put(LED_RED, false);
    sleep_ms(1000);
    gpio_put(LED_GREEN, true);
    gpio_put(LED_BLUE, true);
    gpio_put(LED_RED, true);
    sleep_ms(500);
    gpio_put(LED_GREEN, false);
    gpio_put(LED_BLUE, false);
    gpio_put(LED_RED, false);
    sleep_ms(1000);

    // Emitir som do buzzer (1000 Hz por 2 segundos)
    play_buzzer(1000, 2000);
}

int main() {
    // Inicializar GPIOs
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    while (true) {
        Ciclo();
    }
}
