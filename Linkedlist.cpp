#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
    }
};


class LinkedList{
public:
    LinkedList() {
        head = NULL;
    }
    Node* CreateList();
    Node* addAtBeginning(int val);
    Node* insertNodeAtTail(int val);
    Node* insertNodeAtPosition(int val, int pos);
    void deleteNodebyposition(int val);
    Node* addBefore(int val, int item);
    Node* addAfter(int val, int item);
    Node* deletionbydata(int val);
    Node* reverse();
    void count();
    void search(int val);
    void SelectionSort();
    void display();

private:
    Node* head;
};


Node* LinkedList::CreateList(){
    int i,n,data;
        printf("Enter the number of nodes : ");
        scanf("%d",&n);
        head=NULL;
        if(n==0)
            return head;

        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        head=addAtBeginning(data);

        for(i=2;i<=n;i++)
        {
            printf("Enter the element to be inserted : ");
            scanf("%d",&data);
            head=insertNodeAtTail(data);
        }
    return head;
}


Node* LinkedList::addAtBeginning(int data){
    Node* temp;
    temp = new Node(data);
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}


Node* LinkedList::insertNodeAtTail(int data) {
    Node* temp;
    temp = new Node(data);
    temp->data = data;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return head;
    }
    else{
        Node* p;
        p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    return head;
}


Node* LinkedList::insertNodeAtPosition(int data, int position) {

    Node* temp;
    temp = new Node(data);
    temp->data = data;

    if (position == 1){
        temp->next = head;
        head = temp;
        return head;
    }

    Node* p;
    p = head;

    for (int i = 0; i < position-1 && p!=NULL ; i++)
        p = p->next;
    if (p == NULL)
        return head;

    else{
        temp->next = p->next;
        p->next = temp;
    }
    return head;
}


Node* LinkedList::addBefore(int data, int item){
    Node* temp;
    if(head==NULL){
        cout<<"List is Empty\n";
        return head;
    }
    //if we have to add before first node
    if(item == head->data){
        temp = new Node(data);
        temp->data = data;
        temp->next = head;
        head = temp;
        return head;
    }
    Node* p;
    p = head;
    while(p->next!=NULL){
        if(item==p->next->data){
            temp = new Node(data);
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            return head;
        }
        p = p->next;
    }
    cout<<item<<" "<<"not present in the list"<<"\n";
    return head;
}


Node* LinkedList::addAfter(int data, int item){
    Node* temp;
    if(head==NULL){
        cout<<"List is empty\n";
        return head;
    }
    Node* p;
    p = head;
    while(p!=NULL){
        if (item==p->data){
            temp = new Node(data);
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            return head;
        }
        p = p->next;
    }
    cout<<item<<" "<<"not present in the list"<<"\n";
    return head;
}


void LinkedList::deleteNodebyposition(int position) {
    if (head == NULL)
        return;

    Node* temp = head;
    if (position == 0){
        head = temp -> next;
        free(temp);
        return;
    }
        //Find the previous node of the node to be deleted
    for(int i=0; temp != NULL && i < position-1; i++)
        temp = temp -> next;

        //if position is more than the number of nodes
    if (temp == NULL || temp -> next == NULL)
        cout<<"Given index is more than the no. of nodes in the list\n\n";
        return ;

    Node* next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);  // Free memory

    temp->next = next;
}


Node* LinkedList::deletionbydata(int data){
   Node* temp;
   if(head==NULL) {
    cout<<"List is Empty\n";
    return head;
   }
   //Deleting the first node
   if(data==head->data){
    temp = head;
    head = head->next;
    free(temp);
    return head;
   }
   //Deletion in between or at the end
   Node* p;
   p = head;
   while(p->next!=NULL){
    if(p->next->data==data){
        temp = p->next;
        p->next = temp->next;
        free(temp);
        return head;
    }
    p = p->next;
   }
    cout<<data<<" "<<"not present in the list"<<"\n"<<"\n";
    return head;
}


Node* LinkedList::reverse(){
    Node* prev = NULL;
    Node* ptr = head;
    Node* nxt = NULL;
    while(ptr != NULL){
        // store nxt
        nxt = ptr->next;
        // reverse the current node pointer
        ptr->next = prev;
        // move pointers one position ahead
        prev = ptr;
        ptr = nxt;
    }
    head = prev;
    return head;
}


void LinkedList::count()
{
	Node *p;
	int cnt=0;
	p=head;
	while(p!=NULL)
	{
		p=p->next;
		cnt++;
	}
	printf("Number of elements are %d\n",cnt);
}

void LinkedList::search(int item)
{
	Node *p=head;
	int pos=1;
	while(p!=NULL)
	{
		if(p->data==item)
		{
			printf("Item %d found at position %d\n",item,pos);
			return;
		}
		p=p->next;
		pos++;
	}
	printf("Item %d not found in list\n",item);
}


void LinkedList::display(){
    Node* p;
    if (head == NULL){
        cout<<"List is empty \n";
    }
    p = head;
    cout<<"List is :-  ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl<<"\n";
}


void LinkedList::SelectionSort(){
    Node* p;
    Node* q;
    int temp;
    for(p=head; p->next!=NULL; p = p->next){
        for(q = p->next; q!=NULL; q = q->next){
            if(p->data > q->data){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}


int main()
{
    LinkedList* list = new LinkedList();
    int choice,item, pos;
    while(1)
    {
        cout<<"Choose which operation you want to perform: \n";
        cout<<"1.Create List\n";
        cout<<"2.Insert at beginning\n";
        cout<<"3.Insert at end\n";
        cout<<"4.Insert at position\n";
        cout<<"5.Delete by position\n";
        cout<<"6.Delete by data\n";
        cout<<"7.Add Before\n";
        cout<<"8.Add After\n";
        cout<<"9.Reverse the list\n";
        cout<<"10.Search\n";
        cout<<"11.Count\n";
        cout<<"12.Selection Sort\n";
        cout<<"13.Quit\n";
        cout<<"Enter your choice : ";
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            list->CreateList();
            list->display();
            break;
        case 2 :
            printf("Input the element for insertion : ");
            scanf("%d",&item);
            list->addAtBeginning(item);
            list->display();
            break;
        case 3 :
            printf("Input the element for insertion : ");
            scanf("%d",&item);
            list->insertNodeAtTail(item);
            list->display();
            break;
        case 4 :
            printf("Input the element for insertion : ");
            scanf("%d",&item);
            printf("Enter the position where you want to enter the element: ");
            scanf("%d",&pos);
            list->insertNodeAtPosition(item, pos);
            list->display();
            break;
        case 5 :
            printf("Position where you want to delete element is : ");
            scanf("%d", &pos);
            list->deleteNodebyposition(pos);
            list->display();
            break;
        case 6 :
            printf("Element you want to delete is : ");
            scanf("%d", &item);
            list->deletionbydata(item);
            list->display();
            break;
        case 7 :
            printf("Input the element for insertion : ");
            scanf("%d",&item);
            printf("Enter the element before which you want to enter the element: ");
            scanf("%d",&pos);
            list->addBefore(item, pos);
            list->display();
            break;
        case 8 :
            printf("Input the element for insertion : ");
            scanf("%d",&item);
            printf("Enter the element after which you want to enter the element: ");
            scanf("%d",&pos);
            list->addAfter(item, pos);
            list->display();
            break;
        case 9:
            list->reverse();
            list->display();
            break;
        case 10:
            printf("Enter the element you want to search: ");
            scanf("%d", &item);
            list->search(item);
            list->display();
            break;
        case 11:
            list->count();
            break;
        case 12:
            list->SelectionSort();
            list->display();
            break;
        case 13:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    cout<<"\n";
    }
    return 0;
}
