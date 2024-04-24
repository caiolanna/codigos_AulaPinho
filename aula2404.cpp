//AULA 22/04/2024 ESTRUTURA DE DADOS.
#include <iostream>

using namespace std;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void insertAfter(Node**, int);
void insertBefore(Node*, int);
void deleteNote(Node**, Node*);
void displayList(Node*);

int main()
{
    Node* head = nullptr;
    displayList(head);
    cout << "================================================" << endl;
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 7);
    insertEnd(&head, 10);
    insertEnd(&head, 13);
    displayList(head);
    cout << "================================================" << endl;
    insertBefore(head, 20);

    displayList(head);


    return 0;
}

Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}


void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista Vazia: N�o � possivel realizar displayList" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: N�o � possivel realizar displayList" << endl;
    }

    Node* temp = node;

    cout << "PayLoad: ";

    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    //newNode->prtPrev = nullptr;

    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;

        return;
    }

    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    //newNode->prtNext = nullptr;

    if (*head == nullptr)
    {
        //newNode->prtNext = nullptr;
        (*head) = newNode;
        return;
    }

    Node* temp = (*head);

    //PERCORREMOS A LISTA ATE O FIM
    while(temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev = temp; //NEW NODE APONTA PARA O FIM DA LISTA.
    temp->ptrNext = newNode;
}

void insertAfter(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location � NULL" << endl;
        return;
    }

    Node* newNode = createNode(iPayload);

    // CORRIGIR N� A SER INSERITO
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;

    // CORRIGIR PONTO DE INSER��O
    ptrLocation->ptrNext = newNode;

    if(newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

void insertBefore(Node* ptrLocation, int iPayload)
{

    cout << ptrLocation << endl;

    if (ptrLocation == nullptr)
    {
        cout << "Location � NULL" << endl;
        return;
    }

    Node* newNode = createNode(iPayload);
    newNode->ptrNext = ptrLocation;
    newNode->ptrPrev = ptrLocation->ptrPrev;
    ptrLocation->ptrPrev = newNode;
    if(ptrLocation->ptrPrev != nullptr)
    {
        ptrLocation->ptrPrev->ptrNext = newNode;
    }else
    {
        ptrLocation = newNode;
    }

}

void deleteNote(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "N�o foi poss�vel remover." << endl;
        return;
    }

    //CASO ptrDelete SEJA O PRIMEIRO ELEMENTO DA LISTA.
    if (*head == ptrDelete) (*head) = ptrDelete->ptrNext;

    //CASO ptrDelete N�O SEJA O �LTIMO N�.
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

    //CASO ptrDelete N�O SEJA O PRIMEIRO N�.
    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;


    free(ptrDelete);
}

//EXERC�CIO 1. Elabore a fun��o void insertBefore(Node*, int);
//EXERC�CIO 2. Elabore a fun��o void deleteNodebyValue(Node**, int);
//EXERC�CIO 3. Elabore a fun��o Node* searchNodebyValue(Node**, int);
