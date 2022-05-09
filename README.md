# mc504-projeto2
Projeto 2 da disciplina de MC504, 1s2022.

Paulo Henrique da Fonseca 138995
Raniery Rodrigues da silva 223849
Guilherme Henrique Pascon 235980

PROBLEMA:
Uma loja de patins cuja demanda é muito alta, precisa de um sistema para controlar sua prateleira de produtos à venda, fazer seu controle de vendas e o controle de volume de sua produção.

SOLUÇÃO:
Foi implementado um programa onde assim que um produto é produzido, ele é contabilizado na lista de fabricação e depois é disponibilizado na prateleira e assim que é vendido é retirado da prateleira e contabilizado na lista de vendidos. 
A parte que produz e a parte que vende são duas threads que rodam simultaneamente com o método de semáforo.

OBS: O código está na branch master
