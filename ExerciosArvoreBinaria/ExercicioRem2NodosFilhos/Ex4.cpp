/*
4. O código usa filho->valor = sucessor->valor e depois free(sucessor). Por
que essa estratégia é geralmente preferida em vez de desvincular o nó
original e ajustar todos os ponteiros de seus filhos e pais?
R- É preferida, pois se o nó original ajustar todos os ponteiros de seus filhos e pais, aquele que foi alterado,
 será perdido, ficará na memória e não consiguirá dar free, acumulando lixo de memória, além de poder perder a estrutura
 também
*/
