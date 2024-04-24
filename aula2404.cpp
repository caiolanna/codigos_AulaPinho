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
void insertBefore(Node**, int);
void deleteNote(Node**, Node*);
void deleteNodebyValue(Node**, int);
void displayList(Node*);
Node* searchNodebyValue(Node**, int);

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

    cout << "Inserindo o elemento 20 antes do primeiro" << endl;

    insertBefore(&head, 20);

    displayList(head);

    cout << "================================================" << endl;

    cout << "Inserindo o elemento 50 antes do terceiro elemento" << endl;

    insertBefore(&(head -> ptrNext -> ptrNext), 50);

    displayList(head);

    cout << "================================================" << endl;

    cout << "Procurando o elemento 3" << endl;

    Node* ptrEscolhido = searchNodebyValue(&head, 3);

    cout << "O elemento escolhido é: " << ptrEscolhido -> iPayload << endl;

    cout << "================================================" << endl;

    cout << "Procurando o elemento 12 (inexistente)" << endl;

    ptrEscolhido = searchNodebyValue(&head, 12);

    cout << "================================================" << endl;

    cout << "Removendo o elemento 20" << endl;

    deleteNodebyValue(&head, 20);

    displayList(head);

    cout << "================================================" << endl;

    cout << "Removendo o elemento 13" << endl;

    deleteNodebyValue(&head, 13);

    displayList(head);

    cout << "================================================" << endl;

    cout << "Removendo o elemento 1" << endl;

    deleteNodebyValue(&head, 1);

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
        cout << "displayList: lista vazia" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "displayList: node esta no meio ou no fim da lista." << endl;
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
        cout << "insertAfter: localizacao nula" << endl;
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

void insertBefore(Node** ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr || *ptrLocation == nullptr)
    {
        cout << "insertBefore: localizacao nula" << endl;
        return;
    }

    Node* newNode = createNode(iPayload);

    newNode -> ptrNext = (*ptrLocation);

    newNode -> ptrPrev = (*ptrLocation) -> ptrPrev;

    if((*ptrLocation)->ptrPrev != nullptr)
    {
        (*ptrLocation)->ptrPrev->ptrNext = newNode;
        (*ptrLocation)-> ptrPrev = newNode;
    }
    else
    {   
        (*ptrLocation)-> ptrPrev = newNode;
        *ptrLocation = newNode;
    }
}

void deleteNote(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "deleteNote: nao foi possivel remover" << endl;
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

Node* searchNodebyValue(Node** head, int iPayLoad){

    if (*head == nullptr)
    {
        cout << "searchNodebyValue: lista vazia" << endl;
        return nullptr;
    }

    Node* current = *head;

    while (current != nullptr)
    {
        if (current->iPayload == iPayLoad)
        {
            return current; // Retorna o ponteiro para o nó com o valor desejado
        }
        current = current->ptrNext;
    }

    cout << "searchNodebyValue: elemento nao encontrado" << endl;

    return nullptr;
}

void deleteNodebyValue(Node** head, int iPayLoad)
{
    Node* ptrDeletar = searchNodebyValue(head, iPayLoad);

    deleteNote(head, ptrDeletar);

    return;
}

//EXERC�CIO 1. Elabore a fun��o void insertBefore(Node*, int);
//EXERC�CIO 2. Elabore a fun��o void deleteNodebyValue(Node**, int);
//EXERC�CIO 3. Elabore a fun��o Node* searchNodebyValue(Node**, int);
