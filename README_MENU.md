# Menu Pokemon Battle Game

Este é um menu simples para o jogo de batalha Pokemon que permite montar sua party e iniciar batalhas.

## Funcionalidades

### 1. Montar Party
- Escolha até 6 Pokemon da lista disponível
- Cada Pokemon vem com moves compatíveis com seus tipos
- Os stats são calculados automaticamente baseado no nível

### 2. Ver Party Atual
- Visualize todos os Pokemon na sua party
- Veja informações detalhadas como nível, HP, tipos e ataques

### 3. Iniciar Batalha
- Escolha entre 8 oponentes diferentes:
  - **Bruno**: Especialista em Pokemon de luta
  - **Agatha**: Especialista em Pokemon fantasma
  - **Lance**: Especialista em Pokemon dragão e lendários
  - **Red**: O campeão com uma party balanceada
  - **Lyra**: Especialista em Pokemon água e fogo
  - **Silver**: Especialista em Pokemon escuros
  - **Blaine**: Especialista em Pokemon fogo
  - **Erika**: Especialista em Pokemon planta

## Como Compilar

### Windows (PowerShell/CMD)
```bash
make -f Makefile_menu
```

### Linux/Mac
```bash
make -f Makefile_menu
```

## Como Executar

Após compilar, execute:
```bash
./menu_pokemon
```

## Como Jogar

1. **Primeiro, monte sua party** (opção 1)
   - Escolha Pokemon da lista numerada
   - Digite 0 para parar de adicionar Pokemon
   - Você precisa de pelo menos 1 Pokemon

2. **Verifique sua party** (opção 2)
   - Confirme se todos os Pokemon estão corretos

3. **Inicie uma batalha** (opção 3)
   - Escolha seu oponente
   - Durante a batalha:
     - Escolha seus ataques
     - Troque Pokemon quando necessário
     - Acompanhe o HP de ambos os lados

## Sistema de Batalha

O sistema de batalha utiliza todas as funções existentes em `batalha.cpp`:

- **Cálculo de dano** com tipos, críticos e variação aleatória
- **Sistema de velocidade** para determinar quem ataca primeiro
- **Troca de Pokemon** automática quando um desmaia
- **Interface interativa** para escolher ataques

## Arquivos Utilizados

- `batalha.cpp` e `batalha.h`: Sistema de batalha principal
- `Pokedex.cpp`: Lista de Pokemon disponíveis
- `Moves.cpp`: Lista de ataques
- `Pokemon.cpp`: Classe Pokemon
- `Tipagem.cpp`: Sistema de tipos e vantagens

## Funções Criadas

O menu utiliza principalmente as funções existentes, mas também usa:

- `criarPokemonComMoves()`: Cria Pokemon com moves compatíveis
- `criarPartyOponente()`: Cria party específica para cada oponente

Estas funções já existem em `batalha.cpp` e são reutilizadas pelo menu.
