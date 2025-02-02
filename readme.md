# Tarefa: Contador Numérico em Matriz de Leds 5x5

## Descrição do projeto:

Nessa tarefa foi desenvolvido um sistema usando a **Raspberry Pi Pico W** e dois botões integrados na placa de desenvolvimento **BitDogLab** para controlar uma
**matriz de LEDs RGB WS2812 (5x5)**, assim como um único led vermelho. O projeto também foi implementado no simulador **Wokwi**.

### Funcionalidades implementadas:
- ## 10 desenhos na matriz de leds, representando os números de 0 a 9.
- ## Adição de um ao contador se pressionado o botão A (se o número for 9, o contador volta ao 0).
- ## Subtração de um ao contador se pressionado o botão B (se o número for 0, o contador volta ao 9).
- ## O led vermelho localizado na Gpio 13 pisca continuamente 5 vezes por segundo.

O sistema foi projetado e testado tanto no simulador integrado ao vscode quanto na placa física.

## 🖥️ Tecnologias Utilizadas

- **Hardware**:  
  - Raspberry Pi Pico W   
  - Matriz de LEDs RGB WS2812 (5x5)  
  - Botões A e B

- **Software**:  
  - VS Code com a extensão **Raspberry Pi Pico**  
  - Simulador **Wokwi**  [Wokwi](https://wokwi.com/)
  - SDK do Raspberry Pi Pico
 
  ## 🚀 Como Executar o Projeto

1. Clone este repositório:
   ```sh
   git clone https://github.com/C10UD42/animacoes_matriz.git
   ```
2. Abra o projeto no VS Code.

3. Certifique-se de que a extensão **Raspberry Pi Pico** e  **Wokwi** estão instaladas e configuradas corretamente.

4. Clique no ícone da extensão da Pico<br>
![image](https://github.com/user-attachments/assets/50e67d09-305d-4850-b8da-fd3910362124)

5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/b9a76eab-a696-4100-92fd-32764b95abe3)

  - Selecione o caminho do projeto<br>
  ![image](https://github.com/user-attachments/assets/31668104-e7e6-43fb-9ae6-4ca4f9168b25)

6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/ab20136b-703e-4047-8eba-567b4feddf0a)

7. Se desejar testar no simulador, abra o arquivo diagram.json e inicie a simulação. <br>
![image](https://github.com/user-attachments/assets/d573b1c5-f4b6-4e1a-b02c-cb939b5a6817)

## Fluxograma: 

![image](https://github.com/user-attachments/assets/4aa59e30-8b99-4fc7-bd46-7118476201e4)

## Demonstração em vídeo:

- Simulação no wokwi integrado ao vscode: https://youtu.be/juQ9ukYXG3s
- Teste na placa BitDogLab: https://youtube.com/shorts/uQWNnUlu7IU?si=DB455f1qjnWi0sOi

  Desenvolvido por Claudemir da Silva Santos, matrícula tic370101518
