# Laboratório 01 — descobrir uma função aritmética

**Autoria:** exemplo educativo criado para o fork `MatheusPaixao2210/reverse`.
O [REA](https://github.com/morluto/rea) e o seu código original são trabalho
upstream. O único alvo deste laboratório é o programa [`secret.c`](secret.c),
incluído aqui para permitir verificar cada conclusão no código fonte.

## Objetivo

Compilar um programa C próprio, observar a sua saída e usar REA com Ghidra para
encontrar a função `secret`. Comparar o pseudocódigo com a expressão original
`x * 7 + 3`. A análise de um binário compilado pode mostrar nomes diferentes
ou uma expressão algébrica equivalente.

## 1. Compilar no Windows

Abra o PowerShell na pasta deste laboratório. Use **uma** das opções:

**Visual Studio Build Tools (Developer PowerShell):**

```powershell
cl /nologo /Od /Zi /Fe:secret.exe secret.c
```

**GCC (MinGW-w64):**

```powershell
gcc -O0 -g -o secret.exe secret.c
```

Escolha um compilador nativo x86-64. As opções `/Od` e `-O0` reduzem
otimizações para facilitar a comparação; `/Zi` e `-g` incluem informação de
depuração quando disponível. O binário gerado fica apenas na sua máquina e é
ignorado pelo Git. Execute-o:

```powershell
.\secret.exe
.\secret.exe 2
```

Saída esperada: `secret(5) = 38` e `secret(2) = 17`.

## 2. Preparar REA e Ghidra

Instale o REA com `npm install --global rea-agents` e use uma instalação local
de Ghidra e de um JDK compatível. O REA não instala Ghidra nem Java. O suporte
Ghidra no Windows tem requisitos específicos (Windows x64, NTFS local e PE
nativo); confirme-os no [guia Windows do projeto](../../docs/windows-ghidra-p0.md).
No mesmo PowerShell, ajuste os caminhos à sua instalação:

```powershell
$env:GHIDRA_INSTALL_DIR = "C:\caminho\para\ghidra"
$env:JAVA_HOME = "C:\caminho\para\jdk"
rea doctor --provider ghidra --json
rea providers --json
```

Se o diagnóstico indicar que o provedor não está disponível, resolva os
pré-requisitos indicados antes de continuar. Para usar um agente via MCP,
`rea setup` mostra as alterações de configuração propostas; veja também o
[guia de instalação](../../docs/installation.md). Este laboratório pode ser
feito apenas com a CLI.

## 3. Analisar o binário próprio

```powershell
$alvo = (Resolve-Path .\secret.exe).Path
rea analyze $alvo --provider ghidra --json
rea search $alvo "secret" --provider ghidra --json
rea function $alvo secret --provider ghidra --json
```

Procure a função `secret` nos resultados. Se o nome não aparecer (por exemplo,
se o compilador remover símbolos), use o inventário de funções retornado por
`analyze` e procure uma rotina aritmética chamada por `main`. Consulte
`rea function --help` e [os comandos nativos](../../docs/cli.md#native-analysis)
para investigar a função encontrada pelo endereço. Cada comando da CLI inicia
um processo novo, por isso uma análise pode ser repetida entre chamadas.

## 4. Registar observações

Preencha um pequeno relatório seu com:

| Pergunta | O que procurar |
| --- | --- |
| O programa funciona? | Saídas 38 e 17 para entradas 5 e 2. |
| Onde está a função? | Nome ou endereço mostrado pelo REA, com referência ao resultado. |
| Qual é a transformação? | Multiplicação por 7 e soma de 3, ou cálculo equivalente. |
| O que é incerto? | Nome ausente, diferenças do compilador ou limites do pseudocódigo. |

Compare as observações com `secret.c`. Separe no relatório **evidência**
(saída e resultado do REA) de **inferência** (a sua interpretação). O objetivo
é demonstrar o método e os seus limites, não apenas copiar o pseudocódigo.

Use apenas este programa criado para o exercício. Não analise software de
terceiros sem autorização nem tente contornar autenticação, licenças ou
proteções.
