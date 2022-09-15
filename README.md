# Projeto Urna Eletrônica

Este projeto tem o intuito de simular a experiência de voto da urna eletrônica.

# Tecnologias Utilizadas
- C++
- GCC (Compiler)


# Como compilar?

Rodar esse comando no terminal aberto no mesmo diretorio

`gcc UrnaEletronicaProj.cpp -lwinmm -o UrnaEletronicaProj.exe`

Para compilar no programa DevC++ é preciso ir em `Tools > Compiler Options` e adicionar a segunte linha para a chamada do linker:

`-static-libgcc -lwinmm`
