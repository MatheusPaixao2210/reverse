# Projeto: Laboratórios de Engenharia Reversa com REA

Esta pasta reúne exercícios educativos criados para o fork de
`MatheusPaixao2210/reverse`. O projeto REA, incluindo `src/`, `bridge/`,
`docs/` e a CLI, foi criado e é mantido originalmente por
[morluto/rea](https://github.com/morluto/rea). Estes laboratórios são uma
contribuição separada do fork; não representam funcionalidades novas do REA.

| Laboratório | Objetivo | Artefacto analisado |
| --- | --- | --- |
| [01 — função aritmética em C](01-funcao-secreta/README.md) | Identificar uma fórmula simples | `secret.c`, criado neste fork |
| [02 — soma ponderada em C](02-soma-ponderada/README.md) | Reconstruir um ciclo e a ordem das operações | `weighted_sum.c`, criado neste fork |

## Como usar o projeto

1. Compile e execute cada programa seguindo o README do laboratório.
2. Inspecione **apenas o executável que acabou de criar** com REA/Ghidra.
3. Copie o [modelo de relatório](MODELO-RELATORIO.md) para cada exercício e
   preencha-o com as suas próprias observações. Não atribua ao REA conclusões
   que não aparecem na saída.
4. Compare o pseudocódigo com o fonte e registe diferenças entre compiladores
   ou níveis de otimização. Publique os relatórios de texto; mantenha os
   executáveis fora do Git.

O resultado de portfólio é a sequência verificável **hipótese → comando →
evidência → conclusão → limitação**, acompanhada do código do alvo criado para
o exercício.

## Próximos passos de portfólio

1. Publicar relatórios preenchidos depois de executar os dois laboratórios.
2. Compilar uma variante com otimizações e comparar os resultados.
3. Criar novos exercícios apenas com programas próprios ou com autorização
   explícita para análise.

Não usar estes materiais para contornar autenticação, licenças ou proteções.
