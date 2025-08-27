//Author: Jonathan Leibrant     Date: 8/26/2025
//Project: Add two numbers represented as linked lists
//Start Time: 3:23pm    End Time: 8/26/2025
//Suprisingly this solution works but i need to clean it up
#include<iostream>
using namespace std;


struct linkedNode{
    int a;
    linkedNode* b;
    linkedNode(int x) : a(x), b(nullptr){};
};


linkedNode* addNums(linkedNode* first, linkedNode* second){
    int sum, carry;
    carry = 0;
    sum = first->a + second->a;
    linkedNode *headPtr = new linkedNode(sum % 10);
    linkedNode *traversalNode = headPtr;
    while(first->b != nullptr && second->b != nullptr){
        carry = (sum - (sum % 10)) / 10;
        first = first->b;
        second = second->b;
        sum = first->a + second->a + carry;
        linkedNode *newNode = new linkedNode(sum % 10);
        traversalNode->b = newNode;
        traversalNode = traversalNode->b;
    }

    if(first->b == nullptr){
        while(second->b != nullptr){
            carry = (sum - (sum % 10))/10;
            second = second->b;
            sum = second->a + carry;
            linkedNode *newNode = new linkedNode(sum % 10);
            traversalNode->b = newNode;
            traversalNode = traversalNode->b; 
        }
    }else{
        while(first->b != nullptr){
            carry = (sum - (sum % 10))/10;
            first = first->b;
            sum = first->a + carry;
            linkedNode *newNode = new linkedNode(sum % 10);
            traversalNode->b = newNode;
            traversalNode = traversalNode->b; 
        }
    }

    while(carry != 0){
            carry = (carry - (carry % 10)) / 10;
            linkedNode *newNode = new linkedNode(carry % 10);
            traversalNode->b = newNode;
            traversalNode = traversalNode->b; 
    }

    return headPtr;
}

void printLinkedList(linkedNode* list){
    while(list->b != nullptr){
        cout << list->a;
        list = list->b;
    }
    cout << endl;
}

linkedNode* generateList(int num){
    linkedNode* headptr = new linkedNode(num % 10);
    linkedNode* traversal = headptr;

    while(num != 0){
        num = (num - (num % 10)) / 10;
        linkedNode* newNode = new linkedNode(num % 10);
        traversal->b = newNode;
        traversal = newNode;
    }

    return headptr;
}

int main(){
    printLinkedList(generateList(28881));

    printLinkedList(addNums(generateList(5), generateList(6)));
    printLinkedList(addNums(generateList(55), generateList(66)));
    printLinkedList(addNums(generateList(555), generateList(666)));


    return 0;
}
