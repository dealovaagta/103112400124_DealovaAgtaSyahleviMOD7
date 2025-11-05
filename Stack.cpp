#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop(Stack &S) {
    if (!isEmpty(S)) {
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, S.info[S.top]);
        pop(S);
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    if (isEmpty(S)) {
        push(S, x);
        return;
    }

    // Simpan elemen sementara di stack lain jika lebih kecil
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] < x) {
        push(temp, S.info[S.top]);
        pop(S);
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, temp.info[temp.top]);
        pop(temp);
    }
}

void getInputStream(Stack &S) {
    cout << "Masukkan angka (akhiri dengan Enter kosong): ";
    string line;
    getline(cin, line);

    for (char c : line) {
        if (isdigit(c)) {
            push(S, c - '0');
        }
    }
}
