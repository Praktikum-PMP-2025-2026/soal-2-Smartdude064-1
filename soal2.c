/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 - Dynamic Structures
 *   Hari dan Tanggal    : Selasa, 5 Mei 2026
 *   Nama (NIM)          : Faiz Azmi Irwan (13224040)
 *   Nama File           : prak_soal2.c
 *   Deskripsi           : 
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 1000

typedef struct {
    char data[max];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;  
}

void push(Stack *s, char c) {
    if (s->top < max - 1) {
        s->top++;
        s->data[s->top] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        char pop_char = s->data[s->top];
        s->top--;
        return pop_char;
    }
    return '\0';
}

int peek(Stack *s) {
    if (s->top >= 0) {
        char peek_char = s->data[s->top];
        if (peek_char == ')') {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int count = 0;
    char input[max];
    Stack kurung, temp;

    initStack(&kurung);
    initStack(&temp);

    scanf("%[^\n]", input);
    int string_length = strlen(input);

    for (int i = 0; i < string_length; i++) {
        push(&kurung, input[i]);
    }

    /*for (int i = 0; i < string_length; i++) {
        printf("%d", peek(&kurung));
        pop(&kurung);
    }
    printf("\n");*/

    while (isEmpty(&kurung) != 1) {
        int n = 0;
        if (peek(&kurung) == 0) {
            pop(&kurung);
            while (peek(&kurung) == 0 && isEmpty(&kurung) != 1) {
                push(&temp, pop(&kurung));
                n++;
            }
            pop(&kurung);
        } else {
            pop(&kurung);
            count++;
        }
        for (int i = 0; i < n; i++) {
            push(&kurung, pop(&temp));
        }
        
    }
    count++;

    printf("%d\n", count);
    int output = string_length - count;
    printf("%d\n", output);

    return 0;
}
