# BH1750-RP2040-RP3050

## Como obter este módulo (via workspace principal)

Recomendado clonar o repositório raiz (monorepo), que já inclui este módulo como submódulo e resolve dependências automaticamente:

```bash
git clone --recurse-submodules https://github.com/RapportTecnologia/Sensores_e_Atuadores_do_Kit_BitDogLab.git Sensores_e_Atuadores_do_KIT
cd Sensores_e_Atuadores_do_KIT
git submodule update --init --recursive
```

Atualizar submódulos (para trazer últimas revisões quando configurado):

```bash
git submodule update --remote --merge --recursive
```

Se optar por clonar apenas este repositório diretamente, será necessário ajustar manualmente dependências e caminhos (ex.: bibliotecas comuns em `../I2C` ou mocks em `../RP-Pico-Mock`). O uso via monorepo é o caminho recomendado.

## Visão Geral

Driver e exemplos para o sensor de luminosidade BH1750 nos microcontroladores RP2040/RP2350 usando Pico SDK e I2C.

## Estrutura do projeto

```
BH1750-RP2040-RP3050/
├─ CMakeLists.txt
├─ Doxyfile
├─ BH1750/          # headers/implementação do driver
│  ├─ bh1750.h
│  └─ bh1750.cpp
└─ docs/            # documentação (Doxygen)
```

## Pré-requisitos

- Pico SDK 2.1.x configurado (PICO_SDK_PATH)
- CMake 3.13+
- Toolchain ARM (gcc/clang) compatível

## Como compilar

```bash
mkdir -p build && cd build
cmake ..
cmake --build . --parallel
```

O artefato `.uf2` (se houver exemplo) será gerado em `build/`.

## Documentação

Gerar documentação local (requer Doxygen):

```bash
doxygen Doxyfile
```

Saída HTML em `docs/html/index.html`.

## Licença

Consulte o arquivo `LICENSE` na raiz do repositório principal para os termos aplicáveis a este módulo.

## Autores e Colaboradores

- Carlos Delfino — consultoria@carlosdelfino.eti.br — GitHub: [@carlosdelfino](https://github.com/carlosdelfino)
