/*
5. Explique por que o loop while(sucessor->esq != NULL) garante que
encontramos o sucessor imediato (o próximo valor em ordem crescente).
R- Pois ao utilizarmos, sucessor->esq != NULL verificamos se em sua esquerda(menor valor), não tem nenhum filho,
logo não tendo nenhum valor menor que ele, podendo obter o próximo valor crescente após ele chamando seu antecessor.
*/
