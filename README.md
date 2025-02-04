# SEMÁFORO NO RASPBERRY PI PICO W

# Visão geral do programa
Durante intervalos de 3 segundos, esse código ativa sequencialmente LEDs conectados a um Raspberry Pi Pico W, imitando um semáforo. Ele faz isso por meio de um array contendo todos os pinos de LEDs dispostos na ordem em que devem ser ligados. A cada 3 segundos, o cursor segue essa ordem, ligando o LED atual e desligando o anterior da sequência. Para garantir que a sequência e a rotina reinicie, o cursor volta ao início do array.

# Como usar?
Para usar o programa apresentado, deve se utilizar ou a plataforma [Wokwi](https://wokwi.com/) ou um microcontrolador Raspberry Pi Pico W, ao utilizar em ambos, com os devidos cuidados:
    
* 3 LEDs (Vermelho, Amarelo, Verde)
* 3 Resistores (330 Ohm, um para cada LED)
  
Após a conexão nos respectivos pinos (disponíveis e alteráveis nas variáveis do código), basta:

* No [Wokwi](https://wokwi.com/), adicionar o código presente em "semaforo.c" na simulação e rodar
* No Raspberry Pi Pico W, compilar o código "semaforo.c" em um arquivo de extensão .uf2 e carregar na memória flash do dispositivo. A compilação pode ser feita através da extensão Raspberry Pi Pico, presente no [Visual Studio Code](https://code.visualstudio.com/), ou da forma que desejar

Com o programa rodando, será possível observar os LEDs ligando e desligando, de forma semelhante a um semáforo
