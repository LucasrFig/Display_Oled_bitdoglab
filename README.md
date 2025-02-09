────────────────────────────────────────────────────────  
# PROJETO - DISPLAY OLED BIT DOG LAB
(SUB GRUPO 6)  
**Aluno: Lucas Ricardo de Lima Figueiredo** 

──────────────────────────────────────────────────────────────────────  
## OBJETIVO DO PROJETO  
──────────────────────────────────────────────────────────────────────  

O objetivo deste projeto é treinar com as interfaces de comunicação UART e I2C, para gerar textos no display Oled, além de trabalhar em conjunto com outros conceitos do raspberry SDK e eletrônica, como interrupções, debouncing, manipulação de uma matriz de LEDs em série etc. 

──────────────────────────────────────────────────────────────────────  
## FUNCIONALIDADES DO PROJETO  
──────────────────────────────────────────────────────────────────────  

Comandos do código:

**Botão A 'ON/OFF led verde':** Alterna o valor do LED verde em ligado ou desligado;

**Botão B 'ON/OFF led azul':** Alterna o valor do LED azul em ligado ou desligado;

**Botão JoyStick 'Bootloader':** Apaga a matriz de LEDs e Display Oled e põe a placa em modo de gravação (BootLoader);

**Envio de Caracteres (UART):** Envia caracteres por meio do Monitor Serial do VSCode(Via comunicação UART). O caractere enviado será exibido no display Oled. Caso o caractere enviado seja um digito, o mesmo irá ser representado dentro da matriz de LEDs 5x5 (endereçáveis) WS2812.



──────────────────────────────────────────────────────────────────────  
## TECNOLOGIAS UTILIZADAS  
──────────────────────────────────────────────────────────────────────  
- Linguagem: C;
- Microcontrolador: Raspberry Pi Pico (RP2040);

──────────────────────────────────────────────────────────────────────  
## COMO EXECUTAR O PROJETO
──────────────────────────────────────────────────────────────────────  
- **Clone o Repositório:**
  git clone [https://github.com/LucasrFig/Display_Oled_bitdoglab.git](https://github.com/LucasrFig/Display_Oled_bitdoglab.git)
  
- **Compile o Código:**
  Utilize o ambiente de desenvolvimento VS Code. 
  Instalar extensão: Raspberry Pi Pico.

- **Carregue na Raspberry Pi Pico:**
  Conecte a Raspberry Pi Pico em modo de boot.
  Copie o arquivo .uf2 gerado para a unidade de armazenamento da Pico.

──────────────────────────────────────────────────────────────────────  
## VÍDEO DO PROJETO  
────────────────────────────────────────────────────────────────────── 
https://drive.google.com/file/d/1Gb_0adODkKjGXGmCGPVWAEQB9rqtqTtM/view?usp=sharing

