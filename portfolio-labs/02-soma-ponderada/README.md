# Laboratório 02 — reconstruir uma soma ponderada

Este exercício usa somente [`weighted_sum.c`](weighted_sum.c), criado para este
fork. O projeto REA pertence ao [upstream morluto/rea](https://github.com/morluto/rea).
O objetivo é reconhecer no binário um ciclo que percorre quatro bytes e soma
cada valor multiplicado pela sua posição, começando em 1.

## 1. Compilar e executar no Windows

Abra PowerShell nesta pasta e use um compilador C nativo x86-64. Escolha uma
opção:

```powershell
# Developer PowerShell do Visual Studio
cl /nologo /Od /Zi /Fe:weighted_sum.exe weighted_sum.c
```

```powershell
# GCC do MinGW-w64
gcc -O0 -g -o weighted_sum.exe weighted_sum.c
```

Execute `./weighted_sum.exe`. O valor esperado é `weighted_sum = 30`, pois
`1×1 + 2×2 + 3×3 + 4×4 = 30`. Os ficheiros de compilação são ignorados pelo
Git. Consulte os [pré-requisitos de REA/Ghidra no Windows](../../docs/windows-ghidra-p0.md)
e a configuração do [laboratório 01](../01-funcao-secreta/README.md#2-preparar-rea-e-ghidra).

## 2. Investigar com REA

Antes de consultar novamente o fonte, tente responder: há um ciclo? Quantos
elementos entram na função? Onde acontece a multiplicação? Use:

```powershell
$alvo = (Resolve-Path .\weighted_sum.exe).Path
rea doctor --provider ghidra --json
rea analyze $alvo --provider ghidra --json
rea search $alvo "weighted_sum" --provider ghidra --json
rea function $alvo weighted_sum --provider ghidra --json
```

Se o símbolo `weighted_sum` não estiver disponível, procure a função chamada
por `main` no inventário do `analyze` e consulte-a pelo endereço. Os comandos
e opções estão no [guia da CLI](../../docs/cli.md#native-analysis).

## 3. Criar um relatório próprio

Copie o [modelo](../MODELO-RELATORIO.md) e registe os comandos executados, o
nome ou endereço encontrado, um trecho curto do resultado, a interpretação e
as limitações. Só então compare com o código fonte. O compilador pode
transformar o ciclo, sobretudo se ativar otimizações; uma saída esperada não
prova, por si só, que o pseudocódigo terá a mesma estrutura do C.

Analise apenas este artefacto criado para o exercício. Não use o projeto para
contornar autenticação, licenças ou proteções, nem para inspecionar software de
terceiros sem autorização.
