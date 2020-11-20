#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void display()
{
    struct node *ptr = head;
    if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

    while(ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int count()
{
    struct node *ptr = head;
    int count = 0;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void search(int item)
{
    struct node *ptr = head;
    int pos = 1;
    while(ptr != NULL)
    {
        if(ptr->data == item)
        {
            printf("Item %d found at position %d\n",item,pos);
			return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Item %d not found in list\n",item);
}

struct node *add_at_beg(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    head=temp;
    return head;
}

struct node *add_at_end(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = data;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;     
    }
    ptr->next = temp;   
    temp->next = NULL;
    return head;
}

struct node *add_after(int data, int item)  // item is the element after which we want to add 
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    while(ptr != NULL)
    {
        if(ptr->data == item)
        {
            temp->data = data;
            temp->next = ptr->next;
            ptr->next = temp;
            return head;
        }
        ptr = ptr->next;
    }
    printf("%d not present in the list\n",item);
	return head;
}

struct node *add_before(int data, int item)
{
    struct node *tmp,*p;
	if(head == NULL )
	{
		printf("List is empty\n");
		return head;
	}	
	/*If data to be inserted before first node*/
	if(item==head->data)
	{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->data=data;
		tmp->next=head;
		head=tmp;
		return head;
	}	
	p=head;
	while(p->next!=NULL) 
	{
		if(p->next->data==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->data=data;
			tmp->next=p->next;
			p->next=tmp;
			return head;
		}
		p=p->next;
	}
	printf("%d not present in the list\n",item);
	return head;
}

struct node *add_at_pos(int data, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    temp->data = data;
    if(pos == 1)
    {
        temp->next = head;
        head = temp;
        return head;    
    }
    for(int i=0; i<pos-1 && ptr!=NULL; i++)
    {
        ptr = ptr->next;
    }
    if(ptr==NULL)
    {
        printf("There are less than %d elements\n",pos);
    }
    else
    {
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return head;
}

struct node *del(int data)
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty\n");
		return head;
    }

    // deletion of first node
    if(head->data == data)
    {
        temp = head;
        head=head->next;
        free(temp);
        return head;
    }

    struct node *ptr = head;
    while(ptr->next!=NULL)
    {
        if(ptr->next->data == data)
        {
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            return head;
        }
        ptr = ptr->next;
    }
    printf("Element %d not found\n",data);
	return head;
}

struct node *reverse()
{
    struct node *prev, *ptr, *next;
    prev = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
    return head;
}

struct node *sort()
{
    struct node *curr, *next;
    int size = count();
    int k = size;
    for(int i=0; i<size-1; i++, k--)
    {
        curr = head;
        next = head->next;

        for(int j=1; j<k; j++)
        {
            if(curr->data > next->data)
            {
                int temp = curr->data;
                curr->data = next->data;
                next->data = temp;
            }
            curr = curr->next;
            next = next->next;
        }
    }
    return head;
}

struct node *create_ll()
{
    int n, data;
    printf("Enter the number of nodes : ");
	scanf("%d",&n);
	head = NULL;
	if(n==0)
		return head;

    printf("Enter the element to be inserted : ");
	scanf("%d", &data);
	head = add_at_beg(data);

	for(int i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d", &data);
		head = add_at_end(data);	
	}
	return head;
}

int main()
{
int choice, data, item, pos, c;
		
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Count\n");
		printf("4.Search\n");
		printf("5.Add to empty list / Add at beginning\n");
		printf("6.Add at end\n");
		printf("7.Add after node\n");
		printf("8.Add before node\n");
		printf("9.Add at position\n");
		printf("10.Delete\n");
		printf("11.Reverse\n");
		printf("12.Sort\n");
        printf("13.Quit\n\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
		 case 1:
			head = create_ll();
			break;
		 case 2:
			display();
			break;
		 case 3:
			c = count();
            printf("No. of elements: %d \n", c);
			break;
		 case 4:
			printf("Enter the element to be searched : ");
			scanf("%d", &data);
			search(data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d", &data);
			head = add_at_beg(data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d", &data);
			head = add_at_end(data);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d", &data);
			printf("Enter the element after which to insert : ");
			scanf("%d", &item);
			head = add_after(data,item);
			break;
		 case 8:
			printf("Enter the element to be inserted : ");
			scanf("%d", &data);
			printf("Enter the element before which to insert : ");
			scanf("%d", &item);
			head = add_before(data,item);
			break;
		 case 9:
			printf("Enter the element to be inserted : ");
			scanf("%d", &data);
			printf("Enter the position at which to insert : ");
			scanf("%d", &pos);
			head = add_at_pos(data,pos);
			break;
		 case 10:
			printf("Enter the element to be deleted : ");
			scanf("%d", &data);
			head = del(data);	
			break;
		 case 11:
			head = reverse();
			break;
         case 12:
            head = sort();
            break;
		 case 13:
			 exit(1);
		 default:
			 printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/ 