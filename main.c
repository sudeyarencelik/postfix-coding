**2310206007 SUDE YAREN ÇELİK BİLGİSAYAR MÜHENDİSLİĞİ 2. ÖĞRETİM**
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        return -1;
    } else {
        return stack[top--];
    }
}

char peek() {
    return stack[top];
}

int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item, x;

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];
        if (isalnum(item)) {
            postfix[j++] = item;
        } 
        else if (item == '(') {
            push(item);
        } 
   
        else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } 
        else {
            while (top != -1 && precedence(peek()) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }


    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[] = "A+B*C-D/E";
    char postfix[MAX];

    printf("Infix Ifade: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Ifade: %s\n", postfix);

    return 0;

}
