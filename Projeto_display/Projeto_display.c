//Bibliotecas base
#include <stdio.h>
#include <ctype.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

//Bibliotecas Criadas para o funcionamento do código
#include "display/ssd1306.h"//funções de manipulação do display
#include "display/font.h"//Fonte das letras apresentadas no display
#include "library/led_commands.h"//Funções para manipulação da matriz de LEDs
#include "library/numbers.h"//Fonte dos números apresentados na matriz de LEDs
#include "Projeto_display.pio.h"

//Definições
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define I2C_LINK 0x3C
#define MATRIZ5x5 7
#define BUT_A 5
#define BUT_B 6
#define BUT_JSTICK 22
#define DEBOUNCE_DELAY 200000 //200ms para o debouncing
#define LED_G 11
#define LED_B 12
bool led_g_state = false;//led verde começa desligado
bool led_b_state = false;//led azul começa desligado


// Variável de ocorrência para interrupção
static volatile uint32_t last_time_A = 0; // Armazena o tempo do última vez que o botão A foi pressionado (em microssegundos)
static volatile uint32_t last_time_B = 0; // Armazena o tempo do última vez que o botão A foi pressionado (em microssegundos)

//Rotina de interrupção
static void gpio_irq_handler(uint gpio,uint32_t events);



ssd1306_t ssd;
PIO pio;
uint sm;

int main()
{
    //Inicializa o i2c, inicializa a estrutura do display, limpa o display
    ssd1306_init_config_clean(&ssd, I2C_SCL,I2C_SDA,I2C_PORT,I2C_LINK);


    //inicializa PIO para a matriz de LEDs
    pio = pio0; 
    bool ok;
    //Inicializar transmissão PIO
    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));
    //configurações da PIO
    uint offset = pio_add_program(pio, &Projeto_display_program);
    sm = pio_claim_unused_sm(pio, true);
    Projeto_display_program_init(pio, sm, offset, MATRIZ5x5);


    //Inicializar funções da stdio
    stdio_init_all();

    //inicializar leds
    gpio_init(LED_G);
    gpio_set_dir(LED_G,GPIO_OUT);
    gpio_init(LED_B);
    gpio_set_dir(LED_B,GPIO_OUT);
    
    //inicializar botões
    gpio_init(BUT_A);
    gpio_set_dir(BUT_A,GPIO_IN);
    gpio_pull_up(BUT_A);
    gpio_init(BUT_B);
    gpio_set_dir(BUT_B,GPIO_IN);
    gpio_pull_up(BUT_B);
    gpio_init(BUT_JSTICK);
    gpio_set_dir(BUT_JSTICK,GPIO_IN);
    gpio_pull_up(BUT_JSTICK);
    


    //interrupção da gpio habilitada incrementar contagem
    gpio_set_irq_enabled_with_callback(BUT_A, GPIO_IRQ_EDGE_FALL, 1, &gpio_irq_handler);
    //interrupção da gpio habilitada decrementar contagem
    gpio_set_irq_enabled_with_callback(BUT_B, GPIO_IRQ_EDGE_FALL, 1, &gpio_irq_handler);
    //interrupção da gpio habilitada decrementar contagem
    gpio_set_irq_enabled_with_callback(BUT_JSTICK, GPIO_IRQ_EDGE_FALL, 1, &gpio_irq_handler);
    
    //A mensagem inicial mostra que os leds estão desligados
    ssd1306_draw_string(&ssd,"LED verde: off",10,10);
    ssd1306_draw_string(&ssd,"LED azul: off",10,20);
    ssd1306_send_data(&ssd);

    //Desenha um retângulo no display
    ssd1306_rect(&ssd, 3, 3, 122, 58, true,false);
    ssd1306_send_data(&ssd); // Atualiza o display
    
    //Programa Principal
    while (true) {
        if(stdio_usb_connected()){
            char c = getchar();
            
            if(isdigit(c)){
                //Escreve Número na matriz de leds
                print_number(c,pio,sm);
                //Mostra o caractere no display Oled
                ssd1306_draw_string(&ssd,"Caractere:",10,35);
                ssd1306_draw_char(&ssd,c,90,35);
                //Mensagem no monitor serial;
                printf("Caractere Enviado: %c.\n",c); 
            }else{
                //Apaga se houver algum número na matriz de LEDS
                print_number(CLEAN,pio,sm);
                //Mostra o caractere no display Oled
                ssd1306_draw_string(&ssd,"Caractere:",10,35);
                ssd1306_draw_char(&ssd,c,90,35);
                //Mensagem no monitor serial;
                printf("Caractere Enviado: %c.\n",c); 
            }
            ssd1306_send_data(&ssd);

        }
    }

}

//Rotina de interrupção
static void gpio_irq_handler(uint gpio,uint32_t events){
    
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if(gpio == BUT_A){
        // Verifica se passou tempo suficiente desde o última vez que o botão A foi pressionado
        if (current_time - last_time_A > (DEBOUNCE_DELAY)){ // tratamento de debouncing

            last_time_A = current_time;

            led_g_state = !led_g_state;//inverte estado do led

            gpio_put(LED_G,led_g_state);
            
            if(led_g_state){
                ssd1306_draw_string(&ssd,"LED verde: on ",10,10);
                //Mensagem no monitor serial;
                printf("LED verde: LIGADO.\n"); 
            }else{
                ssd1306_draw_string(&ssd,"LED verde: off",10,10);
                //Mensagem no monitor serial;
                printf("LED verde: DESLIGADO.\n"); 
            }
        }
    }        
    
    if(gpio == BUT_B){
        // Verifica se passou tempo suficiente desde o última vez que o botão B foi pressionado
        if (current_time - last_time_B > (DEBOUNCE_DELAY)){ // tratamento de debouncing

            last_time_B = current_time;

            led_b_state = !led_b_state;//inverte estado do led
            
            gpio_put(LED_B,led_b_state);
            
            if(led_b_state){
                ssd1306_draw_string(&ssd,"LED azul: on ",10,20);
                //Mensagem no monitor serial;
                printf("LED azul: LIGADO.\n"); 
            }else{
                ssd1306_draw_string(&ssd,"LED azul: off",10,20);
                //Mensagem no monitor serial;
                printf("LED azul: DESLIGADO.\n");
            }
        }
    }  
    ssd1306_send_data(&ssd); // Atualiza o display
    if(gpio == BUT_JSTICK){
        print_number(CLEAN,pio,sm);//limpar matriz de leds
        ssd1306_fill(&ssd, false); // Limpa o display
        ssd1306_send_data(&ssd); // Atualiza o display
        printf("Reiniciando a placa em modo de gravação.\n");
        reset_usb_boot(0,0);
        }
}
