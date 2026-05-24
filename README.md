# ALGORITMOS DE DISPERSÃO

Estudo comparativo sobre colisões em funções de dispersão (hashing) utilizando implementações em C++ com abordagens linear e multiplicativa.

O objetivo deste repositório não é apresentar algoritmos criptográficos completos, mas analisar estruturalmente como pequenas alterações matemáticas modificam significativamente o comportamento de uma função hash.

A proposta surgiu a partir da observação prática de um problema recorrente no ensino inicial de estruturas de dados: muitos estudantes compreendem o funcionamento sintático de um algoritmo, mas ainda possuem dificuldade em perceber como a modelagem matemática influencia diretamente aspectos como dispersão, ocupação do espaço numérico e incidência de colisões.

O projeto compara duas estratégias distintas de hashing:
- uma implementação baseada em soma ponderada linear;
- uma implementação multiplicativa inspirada em modelos recorrentes de dispersão semelhantes ao DJB2.

Embora ambas sejam relativamente simples do ponto de vista estrutural, o comportamento produzido por cada abordagem apresenta diferenças significativas.

---

## Objetivo

O projeto busca demonstrar experimentalmente:
- como colisões ocorrem;
- como diferentes modelos matemáticos afetam a dispersão;
- como a ocupação do espaço numérico interfere na distribuição dos resultados;
- como pequenas alterações algorítmicas podem modificar profundamente a eficiência de uma função hash.

Além da implementação dos algoritmos, o repositório também realiza testes automatizados utilizando grandes conjuntos de combinações de caracteres, permitindo observar quantitativamente o comportamento de cada abordagem.

---

## Implementação Linear

A primeira implementação utiliza uma estratégia baseada em soma ponderada de caracteres.

Cada símbolo da string:
1. é convertido para seu valor ASCII;
2. é multiplicado por um peso associado à posição;
3. é acumulado em um valor numérico final.

Estruturalmente, o algoritmo segue um modelo semelhante a:

```cpp
hash += caractere * peso;
```

Essa abordagem apresenta crescimento linear e dispersão limitada, produzindo maior incidência de colisões quando grandes volumes de combinações são processados.

---

## Implementação Multiplicativa

A segunda implementação utiliza uma abordagem multiplicativa recorrente inspirada em algoritmos clássicos de dispersão, particularmente no modelo DJB2 desenvolvido por Dan Bernstein.

O processamento segue uma estrutura semelhante a:

```cpp
hash = (hash * 35) + caractere;
```

Nesse modelo, o valor anterior do hash participa diretamente do próximo cálculo, fazendo com que cada caractere influencie todas as operações subsequentes do processamento.

O resultado é uma dispersão significativamente mais ampla, com menor incidência de colisões e melhor ocupação do espaço numérico disponível.

---

## Comparação Estrutural

A principal diferença entre os modelos não está na complexidade visual do código, mas na estrutura matemática utilizada durante o processamento.

A implementação linear realiza apenas somas sucessivas.

A implementação multiplicativa introduz crescimento recorrente, ampliando significativamente a sensibilidade à ordem dos caracteres e reduzindo a proximidade estatística entre diferentes entradas.

Essa comparação permite observar, de forma prática, como mudanças relativamente pequenas em um algoritmo podem produzir impactos expressivos em:
- distribuição numérica;
- incidência de colisões;
- dispersão;
- eficiência estrutural.

---

## Sobre colisões

Uma colisão ocorre quando entradas diferentes produzem o mesmo valor hash.

Em sistemas finitos, colisões são inevitáveis. O objetivo de uma boa função de dispersão não é eliminá-las completamente, mas reduzir sua incidência e distribuir os resultados da maneira mais uniforme possível.

Os programas presentes neste repositório permitem observar experimentalmente esse comportamento por meio do processamento automatizado de grandes conjuntos de combinações de caracteres.

---

## Estrutura do projeto

O repositório contém:
- implementações das funções hash;
- programas de geração de combinações;
- análise de colisões;
- armazenamento estatístico dos resultados;
- comparações entre modelos de dispersão.

---

## Compilação

Exemplo utilizando `g++`:

```bash
g++ programa.cpp -o programa
```

Execução:

```bash
./programa
```

---

## Observação importante

As implementações presentes neste projeto possuem finalidade acadêmica e experimental.

Embora funções hash sejam amplamente utilizadas em autenticação, assinaturas digitais e verificação de integridade, os algoritmos deste repositório não substituem funções criptográficas modernas destinadas à proteção de credenciais.

Sistemas reais utilizam algoritmos específicos como:
- bcrypt;
- Argon2;
- PBKDF2.

---

## Considerações finais

Mais do que comparar implementações em C++, este projeto procura evidenciar como a modelagem matemática influencia diretamente o comportamento computacional de um algoritmo.

Em muitos casos, alterações aparentemente pequenas na estrutura matemática produzem impactos significativamente maiores do que mudanças complexas na aparência do código.
