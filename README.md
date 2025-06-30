
# 🎸 Lollapalufla - Sistema de Gestão de Bandas (C++)

Este é um projeto em C++ com interface no terminal (TUI) para gerenciar bandas participantes de um festival fictício. O sistema permite cadastrar, buscar, remover bandas e salvar os dados em arquivo.

## ✅ Requisitos

### Linux
- `g++` (GCC)
- `make`

Instale com:

```bash
sudo apt update
sudo apt install build-essential
```

### Windows (usando MSYS2)
- [MSYS2](https://www.msys2.org/) instalado
- Terminal: **MSYS2 MinGW 64-bit** aberto
- Pacotes:
```bash
pacman -Syu       # Atualizar tudo
pacman -S make mingw-w64-x86_64-gcc
```

> Obs: Use o terminal `MINGW64`, não o MSYS shell simples.

---

## 🚀 Compilando e Executando

No terminal (Linux ou MSYS2):

```bash
make run
```

> Isso irá compilar `index.cpp` e `functions.cpp`, gerar o executável `main` e executá-lo.

---

## 🧹 Limpando arquivos temporários

```bash
make clean
```

---

## 🛠️ Estrutura do Projeto

```
├── index.cpp           # Arquivo principal
├── functions.cpp       # Funções auxiliares
├── functions.h         # Cabeçalho
├── Makefile            # Script de compilação
└── README.md           # Este arquivo
```

---

## ❗ Observações

- Evite rodar o projeto dentro de pastas do **OneDrive**, pois isso pode gerar erros de permissão ao compilar.
- Em terminais Windows, use **MSYS2 + Mingw64**, não o CMD nem o PowerShell.
- Se o menu interativo com setas não funcionar corretamente, maximize a janela ou use terminal compatível com ANSI.

---

## 👨‍💻 Autores

Bruno dos Santos Custódio
Gabriel Carvalho Batista
Mateus Nogueira dos Santos 


Projeto para disciplina de **Introdução aos Algoritmos**  Turma:10B.