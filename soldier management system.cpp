/* */


#include <iostream>
#include<string.h>
#include <fstream>
#include <cstring>
#include<algorithm>// This will include the algorithm library which defines the sort function that you are using in our code
using namespace std;

struct Soldier
{
float salary;
char name[25];
int age;
char gender[10];
char mother[20];
float height;
int id;
char appellation[20];
char marital[11];
char region[30];
Soldier *next;
Soldier *prev;
};struct Soldier *start=NULL;
struct Soldier *last=NULL;


//function to insert a soldier node at the end of the doubly linked list
void insertAtEnd()
{
    //allocate memory for a new soldier node
    Soldier *n=new Soldier();
    //prompt the user to enter soldier's name
    cout<<endl<<"Enter name of soldier"<<endl;
    cin>>n->name;
    //prompt the user to enter soldier's mother's name
    cout<<endl<<"Enter Mother name of soldier"<<endl;
    cin>>n->mother;
    //prompt the user to enter soldier's age
    cout<<endl<<"Enter age of soldier"<<endl;
    cin>>n->age;
    //prompt the user to enter soldier's militaryID
    cout<<endl<<"Enter militaryID of soldier"<<endl;
    cin>>n->id;
    //prompt the user to enter soldier's gender
    cout<<endl<<"Enter gender of soldier"<<endl;
    cin>>n->gender;
    //prompt the user to enter soldier's height
    cout<<endl<<"Enter height of soldier"<<endl;
    cin>>n->height;
    //prompt the user to enter soldier's salary
    cout<<endl<<"Enter salary of soldier"<<endl;
    cin>>n->salary;
    //prompt the user to enter soldier's rank
    cout<<endl<<"Enter rank of soldier"<<endl;
    cin>>n->appellation;
    //prompt the user to enter soldier's marriage status
    cout<<endl<<"Enter marriage status of soldier"<<endl;
    cin>>n->marital;
    //prompt the user to enter soldier's region
    cout<<"Enter region of soldier"<<endl;
    cin>>n->region;
    //set the next and previous pointers of the soldier node to NULL
    n->next=NULL;
    n->prev=NULL;
    //if the doubly linked list is empty
    if(start==NULL && last==NULL)  
    {
    //set the start and last pointers to the new node
    start=n;
    last=n;
    }
    else if(start!=NULL && last!=NULL) //if the doubly linked list is not empty
    {
        //set the previous pointer of the new node to the last node in the list
        n->prev=last;
        //set the next pointer of the last node in the list to the new node
        last->next=n;
        //set the next pointer of the new node to NULL
        n->next=NULL;
        //set the last pointer to the new node
        last=n;
    }

}



/* This function is used to insert soldier in the middle of the list.
   It takes the name of soldier after whom it is to be inserted and number of soldier to be inserted as input.
   Firstly, it creates a soldier pointer and then ask for details of soldier.
   Then it checks whether doubly linked list is empty or not.
   If list is empty, then it makes the pointer to the first and last node.
   else it search for node with given name in the list and insert the node after it.
   Finally, if the node is inserted at the last position, then it makes the last pointer to the newly inserted node.
*/
void insert_at_middle()
{
    string given_name;
    cout << "Enter the name after whom you want to insert: ";
    cin >> given_name;
    int p;
    cout << "How many soldiers do you want to register at middle? ";
    cin >> p;

    for (int i = 0; i < p; i++)
    {
      Soldier *h =new Soldier();

        cout<<"Enter name of soldier"<<endl;
        cin>>h->name;
        cout<<"Enter Mother name of soldier"<<endl;
        cin>>h->mother;
        cout<<"Enter age of soldier"<<endl;
        cin>>h->age;
        cout<<"Enter MilitaryId of soldier"<<endl;
        cin>>h->id;
        cout<<"Enter Gender of soldier"<<endl;
        cin>>h->gender;
        cout<<"Enter height of soldier"<<endl;
        cin>>h->height;
        cout<<"Enter salary of soldier"<<endl;
        cin>>h->salary;
        cout<<"Enter rank of soldier"<<endl;
        cin>>h->appellation;
        cout<<"Enter marital of soldier"<<endl;
        cin>>h->marital;
        cout<<"Enter region of soldier"<<endl;
        cin>>h->region;

        if (start == NULL && last == NULL) // is dll empty?
        {
            start = h;
            last = h;
        }
        else
        {
            Soldier  *temp;
            temp = start;
            while (temp != NULL && temp->name != given_name)
            {
                temp = temp->next;
            }

            if (temp == NULL) // given name not found
            {
                cout << "Given name not found in the list" << endl;
                return;
            }

            h->prev = temp;
            h->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = h;
            }
            temp->next = h;

            if (temp == last)
            {
                last = h;
            }
        }
    }
}

//Function to delete a node at the beginning of the doubly linked list 
void delete_at_beginning()
{
    //If the doubly linked list is empty
    if(start==NULL)
        cout<<"DLL is empty "<<endl;
    //If the doubly linked list has only one node
    else if(start->next==NULL)
        start=NULL;
    //If the doubly linked list has more than one node
    else
    {
        //Create a temp node to store the starting node
        Soldier *temp;
        temp=start;
        //Change the starting node to the next node
        start=start->next;
        //Make the previous of new start node as null
        start->prev=NULL;
        //Make the next of deleted node as null
        temp->next=NULL;
        //Delete the temp node
        delete temp;
    }
}



// Function to delete last node from a doubly linked list
void delete_at_end()
{
    // If list is empty
    if(start==NULL)
        cout<<"DLL is empty "<<endl;

    // If list contains only one node
    else if(start->next==NULL)
        start=NULL;

    // If list contains more than one node
    else
    {
        // Pointer to current node and previous node
        Soldier *current, *previous;
        current = start;

        // Traverse to the last node
        while(current->next != NULL)
            current = current->next;
        previous = current->prev; // set previous to second last node

        // Remove the last node from the list
        previous->next = NULL;
        current->prev = NULL;
        delete current; // delete the last node
    }
}


// Function to delete a node from the Doubly linked list by name
void delete_by_name()
{
    // Check if the list is empty
    if (start == NULL)
    {
        cout << "DLL is empty" << endl;
        return;
    }

    // Get the name to delete
    string name;
    cout << "Enter name to delete: ";
    cin >> name;

    // Traverse the list to search for the node
    Soldier *temp = start;
    while (temp != NULL && temp->name != name)
    {
        temp = temp->next;
    }

    // Check if the node was found
    if (temp == NULL)
    {
        cout << "Node with name " << name << " not found" << endl;
        return;
    }

    // Update links if the node is the first node
    if (temp == start)
    {
        start = temp->next;
    }

    // Update links from the previous node
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    // Update links from the next node
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    // Break links from the node being deleted
    temp->next = NULL;
    temp->prev = NULL;

    // Free the node
    delete temp;

    cout << "Node with name " << name << " deleted successfully" << endl;
}


// Function to delete a node from a doubly linked list by ID
void delete_by_id()
{
    if (start == NULL) // Check if DLL is empty
    {
        cout << "DLL is empty" << endl;
        return;
    }

    int id; // Store ID of node to delete
    cout << "Enter ID to delete: ";
    cin >> id;

    Soldier* temp = start; // Create a pointer to traverse through list
    while (temp != NULL && temp->id != id) // Iterate over list till ID is found or end is reached
    {
        temp = temp->next;
    }

    if (temp == NULL) // Check if ID wasn't found in list
    {
        cout << "Node with ID " << id << " not found" << endl;
        return;
    }

    if (temp == start) // Check if node to delete is the head node
    {
        start = temp->next; // Make the next node the head node
    }

    if (temp->prev != NULL) // Check if node to delete is not the head node
    {
        temp->prev->next = temp->next; // Connect the prev node to the next node
    }

    if (temp->next != NULL) // Check if node to delete is not the tail node
    {
        temp->next->prev = temp->prev; // Connect the next node to the prev node
    }

    temp->next = NULL; // Disconnect the node to delete from the list
    temp->prev = NULL; // Disconnect the node to delete from the list
    delete temp; // Delete the node

    cout << "Node with ID " << id << " deleted successfully" << endl; // Inform user of successful deletion
}


//This function prints the maximum age of a soldier from a linked list
void max_age()
   {
       struct Soldier *h=start; //Declare a pointer to the start of the list
    float m=0;
     while(h!=NULL)
     {
        if(h->age>m) //if the age of the current soldier is greater than m,
        {
          m=h->age; //m becomes the age of the current soldier
        }

         h=h->next; //move to the next soldier in the list
     }
     cout<<"maximum age is "<<m; //print the maximum age
   }


//This function deletes the Soldier node with the highest age value
void delete_max_age()
   {
       struct Soldier *x=NULL; //Declaring a pointer to a Soldier node
       struct Soldier *h=start; //Declaring a pointer to the start of the linked list
    float m=0; //Declaring a float to store the highest age value
     while(h!=NULL) //Looping through the linked list until the end
     {
        if(h->age>m) //Comparing the age of the current Soldier node to the m variable
        {
          m=h->age; //If the current Soldier node age is higher than the m variable, set the m variable to the current Soldier node age
        }

         h=h->next; //Move to the next Soldier node in the list
     }
        x=start; //Set x to the start of the linked list
     struct Soldier *temp; //Declaring a pointer to a Soldier node
     while(x!=NULL) //Looping through the linked list until the end
        {
        if(x->age==m&&x==start) //If the current Soldier node age is equal to m and is the start node of the linked list
               {
               temp=x; //Set temp to the current Soldier node
               x=x->next; //Move to the next Soldier node in the list
               start=x; //Set start to the current Soldier node
               x->prev=NULL; //Set the prev of the current Soldier node to NULL as it is now the start
               temp->next=NULL; //Set the next of the temp Soldier node to NULL 
               delete temp; //Delete the temp Soldier node
               }
    else if(x->age==m&&x==last) //If the current Soldier node age is equal to m and is the last node of the linked list
           {
               temp=x; //Set temp to the current Soldier node
               x=x->prev; //Move to the previous Soldier node in the list
               last=x; //Set last to the current Soldier node
               x->next=NULL; //Set the next of the current Soldier node to NULL as it is now the last
               temp->prev=NULL; //Set the prev of the temp Soldier node to NULL 
               delete temp; //Delete the temp Soldier node
           }
    else if((x->age==m)&&(x!=start || x!=last)) //If the current Soldier node age is equal to m and is not the start or last node of the linked list
              {
               temp=x; //Set temp to the current Soldier node
               x=x->next; //Move to the next Soldier node in the list
               temp->prev->next=x; //Set the next of the previous Soldier node to the current Soldier node
               x->prev=temp->prev; //Set the prev of the current Soldier node to the previous Soldier node of the temp Soldier node
               temp->next=NULL; //Set the next of the temp Soldier node to NULL 
               temp->prev=NULL; //Set the prev of the temp Soldier node to NULL 
               delete temp; //Delete the temp Soldier node
               }
           else //If the Soldier node age does not equal to m
           {
               x=x->next; //Move to the next Soldier node in the list
           }

        }
   }

//function to find the minimum age in the list of Soldiers 
void min_age()
{
     int r=start->age; //this is the minimum age set initially to the first soldier's age
   struct Soldier *d=start; //creating a Soldier type pointer to iterate
   do
   {
     if(d->age<r) //check if the current soldier's age is less than the minimum age set
     {
         r=d->age; //if yes, set the minimum age to the new value
     }
     d=d->next; //go to the next soldier in the list
}while(d!=NULL); //while the current soldier is not the last
cout<<"minimum age is "<<r; //output the minimum age found
}

//function to delete the soldier with the minimum age
void delete_min_age()
{
     int r=start->age; //this is the minimum age set initially to the first soldier's age
   struct Soldier *d=start; //creating a Soldier type pointer to iterate
   do
   {
     if(d->age<r) //check if the current soldier's age is less than the minimum age set
     {
         r=d->age; //if yes, set the minimum age to the new value
     }
     d=d->next; //go to the next soldier in the list
}while(d!=NULL); //while the current soldier is not the last

struct Soldier *temp; //creating a temporary pointer of Soldier type
struct Soldier *x=start; //creating a Soldier type pointer and setting it to the start of the list

//loop to delete the soldier with the minimum age
while(x!=NULL)
        {
        if(x->age==r&&x==start) //if the minimum age is found and the soldier is the first in the list
               {
               temp=x; //set the temporary pointer to the soldier
               x=x->next; //iterate the pointer
               start=x; //set the start pointer to the current position
               x->prev=NULL; //set the previous pointer of the current position to null
               temp->next=NULL; //set the next pointer of the soldier to null
               delete temp; //delete the soldier
               }
    else if(x->age==r&&x==last) //if the minimum age is found and the soldier is the last in the list
           {
               temp=x; //set the temporary pointer to the soldier
               x=x->prev; //iterate the pointer
               last=x; //set the last pointer to the current position
               x->next=NULL; //set the next pointer of the current position to null
               temp->prev=NULL; //set the previous pointer of the soldier to null
               delete temp; //delete the soldier
           }
    else if((x->age==r)&&(x!=start || x!=last)) //if the minimum age is found and the soldier is in the middle of the list
              {
               temp=x; //set the temporary pointer to the soldier
               x=x->next; //iterate the pointer
               temp->prev->next=x; //set the next pointer of the previous soldier to the current position
               x->prev=temp->prev; //set the previous pointer of the current position to the previous soldier
               temp->next=NULL; //set the next pointer of the soldier to null
               temp->prev=NULL; //set the previous pointer of the soldier to null
               delete temp; //delete the soldier
               }
           else
           {
               x=x->next; //iterate the pointer
           }

        }

}

void average_salary()
{
    float sum=0;
    float t=0;
    struct Soldier *j=start;
    do
    {
        sum=(sum+(j->salary));
        t=t+1;
        j=j->next;
    }while(j!=NULL);
    float average=(sum/t);
    cout<<"the average salary is   "<<average<<endl;
}
void average_age()
{

    float total=0;
    float tt=0;
    struct Soldier *ru=start;
    do
    {
        total=(total+(ru->age));
        tt=tt+1;
        ru=ru->next;
    }while(ru!=NULL);
    float _average=(total/tt);
    cout<<"the average age is   "<<_average<<endl;
}


void delete_node()
{
    Soldier *d=NULL;
    Soldier *temp=start;
    int nod,j=1;
    cout<<"enter the n^th node to delete\n";
    cin>>nod;
    while(temp!=NULL)
    {
        if(j==nod&&nod==1)
        {
            d=temp;
            temp=temp->next;
            temp->prev=NULL;
            d->next=NULL;
            start=temp;
            delete d;
            break;
        }
        if(j==nod&&temp->next==NULL)
        {
            d=temp;
            temp=temp->prev;
            temp->next=NULL;
            last=temp;
            d->next=NULL;
            d->prev=NULL;
            delete d;
            break;
        }
        if(j==nod)
        {
        d=temp;
            temp=temp->next;
            temp->prev=d->prev;
            d->prev->next=temp;
            d->prev=NULL;
            d->next=NULL;
            delete d;
            break;

        }
        j++;
     temp=temp->next;
    }

}

void delete_by_sex()
   {
       struct Soldier *x=start;
     struct Soldier *temp;
     string m;
     cout<<"enter sex to delete by sex "<<endl;
     cin>>m;
     while(x!=NULL)
        {
        if(x->gender==m&&x==start)
               {
               temp=x;
               x=x->next;
               start=x;
               x->prev=NULL;
               temp->next=NULL;
               delete temp;
               }
    else if(x->gender==m&&x==last)
           {
               temp=x;
               x=x->prev;
               last=x;
               x->next=NULL;
               temp->prev=NULL;
               delete temp;
           }
    else if((x->gender==m)&&(x!=start || x!=last))
              {
               temp=x;
               x=x->next;
               temp->prev->next=x;
               x->prev=temp->prev;
               temp->next=NULL;
               temp->prev=NULL;
               delete temp;
               }
           else
           {
               x=x->next;
           }

        }
   }


void delete_by_appellation()
   {
       struct Soldier *x=start;
     struct Soldier *temp;
     string m;
     cout<<"enter appellation to delete by appellation "<<endl;
     cin>>m;
     while(x!=NULL)
        {
        if(x->appellation==m&&x==start)
               {
               temp=x;
               x=x->next;
               start=x;
               x->prev=NULL;
               temp->next=NULL;
               delete temp;
               }
    else if(x->appellation==m&&x==last)
           {
               temp=x;
               x=x->prev;
               last=x;
               x->next=NULL;
               temp->prev=NULL;
               delete temp;
           }
    else if((x->appellation==m)&&(x!=start || x!=last))
              {
               temp=x;
               x=x->next;
               temp->prev->next=x;
               x->prev=temp->prev;
               temp->next=NULL;
               temp->prev=NULL;
               delete temp;
               }
           else
           {
               x=x->next;
           }

        }
   }


void delete_by_salary()
   {
       struct Soldier *x=start;
     struct Soldier *temp;
     float m;
     cout<<"enter salary to delete by salary "<<endl;
     cin>>m;
     while(x!=NULL)
        {
        if(x->salary==m&&x==start)
               {
               temp=x;
               x=x->next;
               start=x;
               x->prev=NULL;
               temp->next=NULL;
               delete temp;
               }
    else if(x->salary==m&&x==last)
           {
               temp=x;
               x=x->prev;
               last=x;
               x->next=NULL;
               temp->prev=NULL;
               delete temp;
           }
    else if((x->salary==m)&&(x!=start || x!=last))
              {
               temp=x;
               x=x->next;
               temp->prev->next=x;
               x->prev=temp->prev;
               temp->next=NULL;
               temp->prev=NULL;
               delete temp;
               }
           else
           {
               x=x->next;
           }

        }
   }


void delete_by_age()
   {
       struct Soldier *x=start;
     struct Soldier *temp;
     int m;
     cout<<"enter age to delete by age "<<endl;
     cin>>m;
     while(x!=NULL)
        {
        if(x->age==m&&x==start)
               {
               temp=x;
               x=x->next;
               start=x;
               x->prev=NULL;
               temp->next=NULL;
               delete temp;
               }
    else if(x->age==m&&x==last)
           {
               temp=x;
               x=x->prev;
               last=x;
               x->next=NULL;
               temp->prev=NULL;
               delete temp;
           }
    else if((x->age==m)&&(x!=start || x!=last))
              {
               temp=x;
               x=x->next;
               temp->prev->next=x;
               x->prev=temp->prev;
               temp->next=NULL;
               temp->prev=NULL;
               delete temp;
               }
           else
           {
               x=x->next;
           }

        }
   }


void delete_by_region()
   {
       struct Soldier *x=start;
     struct Soldier *temp;
     string m;
     cout<<"enter region to delete by region "<<endl;
     cin>>m;
     while(x!=NULL)
        {
        if(x->region==m&&x==start)
               {
               temp=x;
               x=x->next;
               start=x;
               x->prev=NULL;
               temp->next=NULL;
               delete temp;
               }
    else if(x->region==m&&x==last)
           {
               temp=x;
               x=x->prev;
               last=x;
               x->next=NULL;
               temp->prev=NULL;
               delete temp;
           }
    else if((x->region==m)&&(x!=start || x!=last))
              {
               temp=x;
               x=x->next;
               temp->prev->next=x;
               x->prev=temp->prev;
               temp->next=NULL;
               temp->prev=NULL;
               delete temp;
               }
           else
           {
               x=x->next;
           }

        }
   }


void delete_by_marital_status()
   {
       struct Soldier *x=start;
     struct Soldier *temp;
     string m;
     cout<<"enter marital status to delete by marital status "<<endl;
     cin>>m;
     while(x!=NULL)
        {
        if(x->marital==m&&x==start)
               {
               temp=x;
               x=x->next;
               start=x;
               x->prev=NULL;
               temp->next=NULL;
               delete temp;
               }
    else if(x->marital==m&&x==last)
           {
               temp=x;
               x=x->prev;
               last=x;
               x->next=NULL;
               temp->prev=NULL;
               delete temp;
           }
    else if((x->marital==m)&&(x!=start || x!=last))
              {
               temp=x;
               x=x->next;
               temp->prev->next=x;
               x->prev=temp->prev;
               temp->next=NULL;
               temp->prev=NULL;
               delete temp;
               }
           else
           {
               x=x->next;
           }

        }
   }


void delete_by_mother_name()
   {
       struct Soldier *x=start;
     struct Soldier *temp;
     string m;
     cout<<"enter mother name to delete by mother name "<<endl;
     cin>>m;
     while(x!=NULL)
        {
        if(x->mother==m&&x==start)
               {
               temp=x;
               x=x->next;
               start=x;
               x->prev=NULL;
               temp->next=NULL;
               delete temp;
               }
    else if(x->mother==m&&x==last)
           {
               temp=x;
               x=x->prev;
               last=x;
               x->next=NULL;
               temp->prev=NULL;
               delete temp;
           }
    else if((x->mother==m)&&(x!=start || x!=last))
              {
               temp=x;
               x=x->next;
               temp->prev->next=x;
               x->prev=temp->prev;
               temp->next=NULL;
               temp->prev=NULL;
               delete temp;
               }
           else
           {
               x=x->next;
           }

        }
   }


void delete_by_height()
   {
       struct Soldier *x=start;
     struct Soldier *temp;
     float m;
     cout<<"enter height to delete height "<<endl;
     cin>>m;
     while(x!=NULL)
        {
        if(x->height==m&&x==start)
               {
               temp=x;
               x=x->next;
               start=x;
               x->prev=NULL;
               temp->next=NULL;
               delete temp;
               }
    else if(x->height==m&&x==last)
           {
               temp=x;
               x=x->prev;
               last=x;
               x->next=NULL;
               temp->prev=NULL;
               delete temp;
           }
    else if((x->height==m)&&(x!=start || x!=last))
              {
               temp=x;
               x=x->next;
               temp->prev->next=x;
               x->prev=temp->prev;
               temp->next=NULL;
               temp->prev=NULL;
               delete temp;
               }
           else
           {
               x=x->next;
           }

        }
   }

void search_by_name()
 {
     struct Soldier *temp=start;
     string nam;
     cout<<"enter name to search by name"<<endl;
     cin>>nam;


     int i=0;
     while(temp!=NULL)
     {
         if((temp->name)==nam)
         {
             i++;

             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"salary="<<temp->salary<<endl<<"gender="<<temp->gender<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;
             cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

 }
void search_by_id()
{
    struct Soldier *temp=start;
     int id_no;
     cout<<"enter id number to search by id number"<<endl;
     cin>>id_no;


     int i=0;
     while(temp!=NULL)
     {
         if((temp->id)==id_no)
         {
             i++;
             cout<<"soldier"<<i<<endl;


cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"salary="<<temp->salary<<endl<<"gender="<<temp->gender<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;
             cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

}
void search_by_age()

{
struct Soldier *temp=start;
     int ag;
     cout<<"enter age to search by age"<<endl;
     cin>>ag;


     int i=0;
     while(temp!=NULL)
     {
         if((temp->age)==ag)
         {
             i++;
             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"salary="<<temp->salary<<endl<<"gender="<<temp->gender<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;

cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }
}
void search_by_sex()
{
    struct Soldier *temp=start;
     string s;
     cout<<"enter gender to search by sex"<<endl;
     cin>>s;
     int i=0;
     while(temp!=NULL)
     {
         if((temp->gender)==s)
         {
             i++;
             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"salary="<<temp->salary<<endl<<"gender="<<temp->gender<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;
             cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

}


void search_by_salary()
{
    struct Soldier *temp=start;
     float sa;
     cout<<"enter the amount of salary to search by salary"<<endl;
     cin>>sa;
     int i=0;
     while(temp!=NULL)
     {
         if((temp->salary)==sa)
         {
             i++;
             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"salary="<<temp->salary<<endl<<"gender="<<temp->gender<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;
             cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

}
void search_by_region()
{
    struct Soldier *temp=start;
     string r;
     cout<<"enter region to search by region"<<endl;
     cin>>r;
     int i=0;
     while(temp!=NULL)
     {
         if((temp->region)==r)
         {
             i++;
             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"salary="<<temp->salary<<endl<<"gender="<<temp->gender<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;
             cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

}


void search_by_mother_name()
{
    struct Soldier *temp=start;
     string m;
     cout<<"enter mother name to search by mother name"<<endl;
     cin>>m;
     int i=0;
     while(temp!=NULL)
     {
         if((temp->mother)==m)
         {
             i++;
             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"salary="<<temp->salary<<endl<<"gender="<<temp->gender<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;
             cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;


cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

}
void search_by_height()
{
    struct Soldier *temp=start;
     string h;
     cout<<"enter height to search by height"<<endl;
     cin>>h;
     int i=0;
     while(temp!=NULL)
     {
         if((temp->gender)==h)
         {
             i++;
             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"salary="<<temp->salary<<endl<<"gender="<<temp->gender<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;


cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

}


void search_by_marital()
{
    struct Soldier *temp=start;
     string mr;
     cout<<"enter marital status to  search_by_marital status"<<endl;
     cin>>mr;
     int i=0;
     while(temp!=NULL)
     {
         if((temp->marital)==mr)
         {
             i++;

             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"gender="<<temp->gender<<endl<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;
             cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

}
void search_by_appellation()
{
    struct Soldier *temp=start;
     string ap;
     cout<<"enter appellation to search search_by_appellation"<<endl;
     cin>>ap;
     int i=0;
     while(temp!=NULL)
     {
         if((temp->appellation)==ap)
         {
             i++;

             cout<<"soldier"<<i<<endl;
             cout<<"name="<<temp->name<<endl<<"id_number="<<temp->id<<endl<<"gender="<<temp->gender<<endl<<endl<<"salary="<<temp->salary<<endl<<"age="<<temp->age<<endl;
             cout<<"region="<<temp->region<<endl<<"appellation="<<temp->appellation<<endl<<"marital status="<<temp->marital<<endl;
             cout<<"mother name="<<temp->mother<<endl<<"height="<<temp->height<<endl;
         }
         temp=temp->next;
     }

}

void insert_at_beginning()
{
Soldier *n=new Soldier();
    cout<<endl<<"Enter name of soldier"<<endl;
    cin>>n->name;
    cout<<endl<<"Enter Mother name of soldier"<<endl;
    cin>>n->mother;
    cout<<endl<<"Enter age of soldier"<<endl;
    cin>>n->age;
    cout<<endl<<"Enter militaryID of soldier"<<endl;
    cin>>n->id;
    cout<<endl<<"Enter gender of soldier"<<endl;
    cin>>n->gender;
    cout<<endl<<"Enter height of soldier"<<endl;
    cin>>n->height;
    cout<<endl<<"Enter salary of soldier"<<endl;
    cin>>n->salary;
    cout<<endl<<"Enter rank of soldier"<<endl;
    cin>>n->appellation;
    cout<<endl<<"Enter marriage status of soldier"<<endl;
    cin>>n->marital;
    cout<<endl<<"Enter region of the soldier"<<endl;
    cin>>n->region;

    n->next=NULL;
    n->prev=NULL;
    if(start==NULL && last==NULL)  //is dll empty?
    {
    start=n;
    last=n;
    }
else if(start!=NULL && last!=NULL)
{
 n->next=start;
 start->prev=n;
 start=n;
}

}


void max_salary()
{
    struct Soldier *h=start;
    float m=0;
     while(h!=NULL)
     {
        if(h->salary>m)
        {
          m=h->salary;
        }

         h=h->next;
     }
     cout<<"maximum salary is"<<m<<endl;
}
void min_salary()
{
    float r=start->salary;
   struct Soldier *d=start;
   do
   {
     if(d->salary<r){
         r=d->salary;
     }
     d=d->next;
}while(d!=NULL);
cout<<"minimum salary is"<<r<<endl;
}
void displayForward()
{
    cout<<"displaying all soldiers and their data registered in the system"<<endl;
    int i=0;
    struct Soldier *temp=start;
    while(temp!=NULL)
    {
        i++;
      cout<<endl<<"___________soldier: "<<i<<"______________" << endl;
        cout<<"name="<<temp->name<<endl;
        cout<<"mother name="<<temp->mother<<endl;
        cout<<"age="<<temp->age << endl;
        cout<<"id number="<<temp->id<<endl;
        cout<<"gender="<<temp->gender<<endl;
        cout<<"height="<<temp->height<<endl;
        cout<<"salary="<<temp->salary<<endl;
        cout<<"appellation="<<temp->appellation<<endl;
        cout<<"marital status="<<temp->marital<< endl;
        cout<<"region="<<temp->region<<endl;
        cout<<endl<<"__________________________"<<endl;
        temp=temp->next;
    }
}


void display_backward(Soldier *last)
{
    if(last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Soldier *temp = last;
    while(temp != NULL)
    {
        cout << "Name: " << temp->name << endl;
        cout << "Mother: " << temp->mother << endl;
        cout << "Age: " << temp->age << endl;
        cout << "ID: " << temp->id << endl;
        cout << "Gender: " << temp->gender << endl;
        cout << "Height: " << temp->height << endl;
        cout << "Salary: " << temp->salary << endl;
        cout << "Appellation: " << temp->appellation << endl;
        cout << "Marital Status: " << temp->marital << endl;
        cout << "Region: " << temp->region << endl;
        cout << endl;
        temp = temp->prev;
    }
}

void displayTopSoldiersByAge() {
    int n;
    cout << "Enter the number of top soldiers to display: ";
    cin >> n;
    Soldier* current = start;
    while (current != NULL) {
        int count = 0;
        Soldier* temp = current;
        while (temp != NULL) {
            if (temp->age > current->age) {
                count++;
            }
            temp = temp->next;
        }
        if (count < n) {
            cout << "Name: " << current->name << endl;
            cout << "Age: " << current->age << endl;
            cout << "Gender: " << current->gender << endl;
            cout << "Salary: " << current->salary << endl;
            cout << "ID: " << current->id << endl;
        }
        current = current->next;
    }
}




// Function to display soldiers with the minimum heights in increasing order
 void displayMinHeight5soldiers(Soldier* start)
 { if (start == NULL)
 { cout << "List is empty\n"; return; }
 Soldier* current = start;
 Soldier* min_heights[5] = { NULL };
 while (current != NULL)
{ for (int i = 0; i < 5; i++)
 { if (min_heights[i] == NULL || current->height < min_heights[i]->height)
{ for (int j = 5; j > i; j--) { min_heights[j] = min_heights[j - 1]; }
min_heights[i] = current;
 break; }
} current = current->next; }
 cout << "Soldiers with the 3 minimum heights:\n";
for (int i = 0; i < 5; i++)
{ if (min_heights[i] != NULL)
{ cout << "Name: " << min_heights[i]->name << "\n";
 cout << "Height: " << min_heights[i]->height << "\n";
cout << "------------------------\n";
}
}
 }
void displayTop20SoldiersByAge()
{ int count = 0;

    Soldier*current = start;
 while (current != NULL && count < 20)
{ Soldier* maxSoldier = current;
Soldier* temp = current->next;
 while (temp != NULL)
{ if (temp->age > maxSoldier->age)
{ maxSoldier = temp; }
temp = temp->next; }
cout <<"name:"<<maxSoldier->name<<endl;
cout<<"age:" <<maxSoldier->age << endl;
cout<< "salary:"<<maxSoldier->salary<< endl;
cout<< "appellation:"<<maxSoldier->appellation << endl;
cout<<"marital status:"<< maxSoldier->marital<< endl;
cout<<"gender:" <<maxSoldier->gender << endl;
cout<< "region:"<<maxSoldier-> region<< endl;
current = maxSoldier->next;
 count++; } }


void displayTop10SoldiersBysalary()
{ int count = 0; Soldier* current = start;
 while (current != NULL && count < 10)
{ Soldier* maxSoldier = current;
Soldier* temp = current->next;
 while (temp != NULL)
{ if (temp->salary > maxSoldier->salary)
{ maxSoldier = temp; }
temp = temp->next; }
cout <<"name:"<<maxSoldier->name<<endl;
cout<<"age:" <<maxSoldier->age << endl;
cout<< "salary:"<<maxSoldier->salary<< endl;
cout<< "appellation:"<<maxSoldier->appellation << endl;
cout<<"marital status:"<< maxSoldier->marital<< endl;
cout<<"gender:" <<maxSoldier->gender << endl;
cout<< "region:"<<maxSoldier-> region<< endl;
current = maxSoldier->next;
 count++; } }


void displayTop7SoldiersById()
{ int count = 0; Soldier* current = start;
 while (current != NULL && count < 7)
{ Soldier* maxSoldier = current;
Soldier* temp = current->next;
 while (temp != NULL)
{ if (temp->id > maxSoldier->id)
{ maxSoldier = temp; }
temp = temp->next; }
cout <<"name:"<<maxSoldier->name<<endl;
cout<<"age:" <<maxSoldier->age << endl;
cout<< "salary:"<<maxSoldier->salary<< endl;
cout<< "appellation:"<<maxSoldier->appellation << endl;
cout<<"marital status:"<< maxSoldier->marital<< endl;
cout<<"gender:" <<maxSoldier->gender << endl;
cout<< "region:"<<maxSoldier-> region<< endl;
current = maxSoldier->next;
 count++; } }







void displayTop10Name() {
              if (start == NULL) {
               cout << "No soldiers registered yet." << endl;
              return;
                      }

              Soldier* current = start;
                 string names[10];
                   int i = 0;

       // Find top 5 names in alphabetical order
             while (current != NULL) {
                   if (i < 10) {
                 names[i] = current->name;
                     i++;
                     } else {
                       sort(names, names+5);
                         for (int j = 0; j < 10; j++) {
                       if (current->name < names[j]) {
                    names[j] = current->name;
                     break;
                            }
      }
    }
    current = current->next;
  }

  // Display top 15 names in alphabetical order
  cout << "Top 15 names in alphabetical order: " << endl;
  sort(names, names+15);
  for (int i = 0; i < 15; i++) {
    cout << i+1 << ". " << names[i] << endl;
  }
}


















void writeSoldiersToFile() {
    ofstream file("soldiers.txt");
    Soldier* current = start;
    while (current != NULL) {
        file << "Name: "<< current->name << endl;
        file << "Mother's Name: " << current->mother << endl;
        file << "Age: " << current->age << endl;
        file << "Gender: " << current->gender << endl;
        file << "Height: " << current->height << endl;
        file << "Salary: " << current->salary << endl;
        file << "ID: " << current->id << endl;
        file << "Appellation: " << current->appellation << endl;
        file << "Marital Status: " << current->marital << endl;
        file << "Region: " << current->region << endl;
        current = current->next;
    }
    file.close();
    cout << "Soldiers information has been written to file." << endl;
}

int countSoldiers()
{   int count = 0;
    Soldier* current = start;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int countSoldiersByAge(int age)
{   int count = 0;
    Soldier* current = start;
    while (current != NULL)
    {   if (current->age == age)
        {
            count++;
        }

        current = current->next;
    }
    return count;
}



void updateSoldierById(int id)
{   Soldier* current = start;
    while (current != NULL)
    {   if (current->id == id)
        {  cout<<endl<<"Enter name of soldier"<<endl;
           cin>>current->name;
           cout<<endl<<"Enter Mother name of soldier"<<endl;
           cin>>current->mother;
           cout<<endl<<"Enter age of soldier"<<endl;
           cin>>current->age;
           cout<<endl<<"Enter militaryID of soldier"<<endl;
           cin>>current->id;
           cout<<endl<<"Enter gender of soldier"<<endl;
           cin>>current->gender;
           cout<<endl<<"Enter height of soldier"<<endl;
           cin>>current->height;
           cout<<endl<<"Enter salary of soldier"<<endl;
           cin>>current->salary;
           cout<<endl<<"Enter rank of soldier"<<endl;
           cin>>current->appellation;
           cout<<endl<<"Enter marriage status of soldier"<<endl;
           cin>>current->marital;
           cout<<endl<<"Enter region of the soldier"<<endl;
           cin>>current->region;
            cout << "Soldier's information has been updated." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Soldier not found." << endl;
}




void sortByGender() {
    for (Soldier* i = start; i != NULL; i = i->next) {
        for (Soldier* j = i->next; j != NULL; j = j->next) {
            if (i->gender > j->gender) {
                swap(i->name, j->name);
                swap(i->mother, j->mother);
                swap(i->age, j->age);
                swap(i->gender, j->gender);
                swap(i->height, j->height);
                swap(i->salary, j->salary);
                swap(i->id, j->id);
                swap(i->appellation, j->appellation);
                swap(i->marital, j->marital);
                swap(i->region, j->region);
            }
        }
    }
}







void sortByRegion() {
    for (Soldier* i = start; i != NULL; i = i->next) {
        for (Soldier* j = i->next; j != NULL; j = j->next) {
            if (i->region > j->region) {
                swap(i->name, j->name);
                swap(i->mother, j->mother);
                swap(i->age, j->age);
                swap(i->gender, j->gender);
                swap(i->height, j->height);
                swap(i->salary, j->salary);
                swap(i->id, j->id);
                swap(i->appellation, j->appellation);
                swap(i->marital, j->marital);
                swap(i->region, j->region);
            }
        }
    }
}


void sortByHeight() {
    for (Soldier* i = start; i != NULL; i = i->next) {
        for (Soldier* j = i->next; j != NULL; j = j->next) {
            if (i->height > j->height) {
                swap(i->name, j->name);
                swap(i->mother, j->mother);
                swap(i->age, j->age);
                swap(i->gender, j->gender);
                swap(i->height, j->height);
                swap(i->salary, j->salary);
                swap(i->id, j->id);
                swap(i->appellation, j->appellation);
                swap(i->marital, j->marital);
                swap(i->region, j->region);
            }
        }
    }
}









void sortSoldiersByAge()
{   Soldier* current = start;
    Soldier* temp;
    while (current != NULL)
    {   temp = current->next;
        while (temp != NULL)
        {   if (temp->age < current->age)
            {   swap(temp->age, current->age);
                swap(temp->name, current->name);
                swap(temp->mother, current->mother);
                swap(temp->gender, current->gender);
                swap(temp->height, current->height);
                swap(temp->salary, current->salary);
                swap(temp->id, current->id);
                swap(temp->appellation, current->appellation);
                swap(temp->marital, current->marital);
                swap(temp->region, current->region);
            }
            temp = temp->next;
        }

        current = current->next;
    }
    cout << "Soldiers have been sorted by age." << endl;
}

void sortSoldiersBySalary()
{   Soldier* current = start;
    Soldier* temp;
    while (current != NULL)
    {   temp = current->next;
        while (temp != NULL)
        {   if (temp->salary > current->salary)
            {   swap(temp->age, current->age);
                swap(temp->name, current->name);
                swap(temp->mother, current->mother);
                swap(temp->gender, current->gender);

                swap(temp->height, current->height);
                swap(temp->salary, current->salary);
                swap(temp->id, current->id);
                swap(temp->appellation, current->appellation);
                swap(temp->marital, current->marital);
                swap(temp->region, current->region);
            }
            temp = temp->next;
        }
        current = current->next;
    }
    cout << "Soldiers have been sorted by salary." << endl;
}
void sortSoldiersById()
{   Soldier* current = start;
    Soldier* temp;
    while (current != NULL)
    {   temp = current->next;
        while (temp != NULL)
        {   if (temp->id < current->id)
            {   swap(temp->age, current->age);
                swap(temp->name, current->name);
                swap(temp->mother, current->mother);
                swap(temp->gender, current->gender);
                swap(temp->height, current->height);
                swap(temp->salary, current->salary);
                swap(temp->id, current->id);
                swap(temp->appellation, current->appellation);
                swap(temp->marital, current->marital);
                swap(temp->region, current->region);
            }
            temp = temp->next;
        }
        current = current->next;
    }
    cout << "Soldiers have been sorted by ID." << endl;
}

// Function to sort the soldiers by name
void sortSoldiersByName(Soldier*& start) {
    // Use bubble sort algorithm
    bool swapped = true;
    while (swapped) {
        swapped = false;
        Soldier* curr = start;
        while (curr->next != nullptr) {
            if (strcmp(curr->name, curr->next->name) > 0) {
                // Swap the soldiers
                swapped = true;
                Soldier* temp = curr->next;
                curr->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = curr;
                }
                temp->prev = curr->prev;
                temp->next = curr;
                if (curr->prev != nullptr) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }
                curr->prev = temp;
                curr = temp;
            }
            curr = curr->next;
        }
    }  cout << "Soldiers have been sorted by their name successfully:enter 3 to display srted one ." << endl;
}













// Function to sort the soldiers by mother name;
void sortSoldiersBymothername(Soldier*& head) {
    // Use bubble sort algorithm
    bool swapped = true;
    while (swapped) {
        swapped = false;
        Soldier* curr = start;
        while (curr->next != nullptr) {
            if (strcmp(curr->mother, curr->next->mother) > 0) {
                // Swap the soldiers
                swapped = true;
                Soldier* temp = curr->next;
                curr->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = curr;
                }
                temp->prev = curr->prev;
                temp->next = curr;
                if (curr->prev != nullptr) {
                    curr->prev->next = temp;
                } else {
                    head = temp;
                }
                curr->prev = temp;
                curr = temp;
            }
            curr = curr->next;
        }
    }  cout << "Soldiers have been sorted by their mother name successfully:enter 3 to display srted one ." << endl;
}


// Function to sort the soldiers by appellation
void sortSoldiersByappellation(Soldier*& head) {
    // Use bubble sort algorithm
    bool swapped = true;
    while (swapped) {
        swapped = false;
        Soldier* curr = start;
        while (curr->next != nullptr) {
            if (strcmp(curr->appellation, curr->next->appellation) > 0) {
                // Swap the soldiers
                swapped = true;
                Soldier* temp = curr->next;
                curr->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = curr;
                }
                temp->prev = curr->prev;
                temp->next = curr;
                if (curr->prev != nullptr) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }
                curr->prev = temp;
                curr = temp;
            }
            curr = curr->next;
        }
    }  cout << "Soldiers have been sorted by their appellation successfully:enter 3 to display srted one ." << endl;
}






 // Function to sort the soldiers by marital status
void sortSoldiersmaritalStatus(Soldier*& start) {
    // Use bubble sort algorithm
    bool swapped = true;
    while (swapped) {
        swapped = false;
        Soldier* curr = start;
        while (curr->next != nullptr) {
            if (strcmp(curr->marital, curr->next->marital) > 0) {
                // Swap the soldiers
                swapped = true;
                Soldier* temp = curr->next;
                curr->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = curr;
                }
                temp->prev = curr->prev;
                temp->next = curr;
                if (curr->prev != nullptr) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }
                curr->prev = temp;
                curr = temp;
            }
            curr = curr->next;
        }
    }  cout << "Soldiers have been sorted by marital status successfully:enter 3 to display sorted one ." << endl;
}





    // Function to sort the soldiers by gender
void sortSoldiersBygender(Soldier*& head) {
    // Use bubble sort algorithm
    bool swapped = true;
    while (swapped) {
        swapped = false;
        Soldier* curr = start;
        while (curr->next != nullptr) {
            if (strcmp(curr->gender, curr->next->gender) > 0) {
                // Swap the soldiers
                swapped = true;
                Soldier* temp = curr->next;
                curr->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = curr;
                }
                temp->prev = curr->prev;
                temp->next = curr;
                if (curr->prev != nullptr) {
                    curr->prev->next = temp;
                } else {
                    start = temp;
                }
                curr->prev = temp;
                curr = temp;
            }
            curr = curr->next;
        }
    }  cout << "Soldiers have been sorted by their gender successfully" << endl;
}


//This function counts the number of soldiers in a linked list with given height
int countSoldiersByheight(int height)
{   int count = 0; //initialize the counter
    Soldier* current = start; //set the current soldier to the first soldier in the list
    while (current != NULL) //iterate through the list until the end
    {   if (current->height == height) //if the height of the current soldier matches the given height
        {
            count++; //increment the counter
        }

        current = current->next; //move to the next soldier in the list
    }
    return count; //return the number of soldiers with the given height
}








// This function returns the number of Soldiers in a given region 
int countSoldiersByRegion(char region[])
{   int count = 0;
    Soldier* current = start; //pointer to the first soldier in the list
    while (current != NULL)
    {   if (strcmp(current->region, region) == 0) //compare the given region to the region of current soldier
        {
            count++; //if the regions match, increment count
        }
        current = current->next; //go to the next soldier in the list
    }
    return count;
}


//This function counts the number of soldiers in the linked list with a given name
int countSoldiersByname(char name[])
{   int count = 0; //variable to store the count
    Soldier* current = start; // Variable for traversing the linked list
    while (current != NULL)
    {   if (strcmp(current->name, name) == 0)
        {
            count++;  //Incrementing count if it matches
        }
        current = current->next;  //Moving to the next soldier
    }
    return count;  // Returning the count
}







//This function counts the number of soldiers in the linked list with a given gender
int countSoldiersBygender(char gender[])
{   int count = 0;   //variable to store the count
    Soldier* current = start;    // Variable for traversing the linked list
    while (current != NULL)
    {   if (strcmp(current->gender, gender) == 0)
        {
            count++;    //Incrementing count if it matches
        }
        current = current->next;  //Moving to the next soldier
    }
    return count;    // Returning the count
}







//This function counts the number of soldiers in the linked list with a given appellation
int countSoldiersByappellation(char appellation[])
{   int count = 0;  //variable to store the count
    Soldier* current = start;      // Variable for traversing the linked list
    while (current != NULL)
    {   if (strcmp(current->appellation, appellation) == 0)
        {
            count++;  //Incrementing count if it matches
        }
        current = current->next;    //Moving to the next soldier
    }
    return count;     // Returning the count
}








//This function counts the number of soldiers in the linked list with a given marital status
int countSoldiersBymaritalStatus(char maritalStatus[])
{   int count = 0;    // Variable to store the count
    Soldier* current = start; // Variable for traversing the linked list
    while (current != NULL)
    {   if (strcmp(current->marital, maritalStatus) == 0) // Checking if the marital status of the current soldier matches the given one
        {
            count++;  //Incrementing count if it matches
        }
        current = current->next;  // Moving to the next soldier
    }
    return count; // Returning the count
}



/* This function will count and return the number of soldier in the list whose salary is equal to the 'salary' argument. 
It will traverse the list until the 'current' pointer is pointing to NULL and for every node of the list it will check if the salary of the soldier matches with the 'salary' argument. 
If it matches, it will increase the 'count' variable by 1.
*/
int countSoldiersBysalary(int salary)
{   int count = 0;
    Soldier* current = start;
    while (current != NULL)
    {   if (current->salary ==salary)
        {
            count++;
        }

        current = current->next;
    }
    return count;
}


/*
This function counts the number of soldiers in the linked list whose mother's name matches the input name.

Input: mothername - a string indicating the mother's name

Output: an integer indicating the number of soldiers whose mother's name matches the input
*/
int countSoldiersBymotherName(char mothername[])
{   int count = 0;
    Soldier* current = start;
    while (current != NULL)
    {   if (strcmp(current->mother,mothername) == 0)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}



// acceptSoldierData() reads in data from a text file and creates a linked list with it.
// The data for each Soldier is stored in a struct with the same name, and each node of the 
// list is a Soldier struct.
Soldier* acceptSoldierData() {
    string filename;
    cout << "Enter the filename of the text file containing people data: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return NULL;
    }

    Soldier* start = NULL; //pointer to the start of the list
    Soldier* current = NULL; //pointer to keep track of the current node in the list
    while(!file.eof()) { //using end of file(eof()) if not at end of file, continue reading
        Soldier* n = new Soldier; //create a new Soldier struct
        file >> n->name; //read in data from file and store it in the struct
        file >> n->mother;
        file >> n->age;
        file >> n->id;
        file >> n->gender;
        file >> n->height;
        file >> n->salary;
        file >> n->appellation;
        file >> n->marital;
        file >> n->region;
        n->prev = NULL; //set the current node's 'prev' pointer to NULL
        n->next = start; //set the current node's 'next' pointer to the start of the list
        if (start != NULL) { //if start is not NULL, set the 'prev' pointer of the first node in the list to the current node
            start->prev = n;
        }
        start= n; //set 'start' to the current node
   }

    file.close(); //close the file
    return start; //return pointer to the start of the list
}

int main()
{

cout<<endl<<"            WELCOME TO DATA STRUCTURE AND ALGORITHM" << endl;
cout<<"             @@@@   @@@@   @@@@  @@@@@  @@@@  @@@@  @@@@@"<<endl;
cout<<"             @  @   @  @   @  @    @    @     @       @"<<endl;
cout<<"             @@@@   @@@@   @  @    @    @@@   @       @"<<endl;
cout<<"             @      @ @    @  @    @    @     @       @"<<endl;
cout<<"             @      @  @   @@@@  @@@    @@@@  @@@@    @"<<endl<<endl;
cout<<endl<<"            Soldier management system" << endl<<endl;




     int choice,inser,disp,srt,srch,del,cal,up,cnt;
    A:
    do {
        cout<<"Choice '1'to register"<<endl;
        cout<<"Choice '2'to Display"<<endl;
        cout<<"Choice '3'to sort"<<endl;
        cout<<"Choice '4'to Search by attributes "<<endl;
        cout<<"Choice '5'to Delete by attributes"<<endl;
        cout<<"Choice '6'to perform calculations"<<endl;
        cout<<"Choice '7'to update"<<endl;
        cout<<"Choice '8'to Count"<<endl;
        cout<<"Choice '9'to write to file"<<endl;
        cout<<"Choice '0'to Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>choice;
switch(choice)
{
      case 1:
        cout<<"choice '1' insert at the beginning of the linked list by reading from notepad file"<<endl;
        cout<<"choice '2' insert at end "<<endl;
        cout<<"choice '3' insert at middle"<<endl;
        cout<<"choice '4' insert at the beginning from keyboard"<<endl;
        cout<<"Choice '0'to return to menu"<<endl;
        cin>>inser;
        switch(inser)
            {
            case 1:
                 start=acceptSoldierData();
                 break;
            case 2:
                 cout<<"how many soldiers do you want to register"<<endl;
                 int n;
                 cin>>n;
                 for(int i=0;i<n;i++)
                 insertAtEnd();
                 break;
            case 3:
                 insert_at_middle();
                 break;
            case 4:
                 cout<<"how many soldiers do you want to register"<<endl;
                 int k;
                 cin>>k;
                 for(int i=0;i<k;i++)
                 insert_at_beginning();
                 break;
            case 0:
              goto A;
              break;
       default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;

            }
            break;

  case 2:
        cout << "choice '1' to Display Top Soldiers"<<endl;
        cout << "choice '2' to Display Soldiers forward"<<endl;
        cout << "choice '3' to Display Soldiers Backward"<<endl;
        cout << "choice '4' to Display 5 soldiers with minimum height"<<endl;
        cout << "choice '5' to Display top 20 soldiers by age "<<endl;
        cout << "choice '6' to Display top 10 Soldiers by salary"<<endl;
        cout << "choice '7' to Display top 10 names"<<endl;
        cout << "choice '8' to Display top 7 soldiers by ID"<<endl;
        cout<<"Choice '0'to return to menu"<<endl;

        cin>>disp;
        switch(disp)
        {
            case 1:
                  displayTopSoldiersByAge();
                  break;
            case 2:
                  displayForward();
                  break;
            case 3:
                last = start;
             while(last->next != NULL)
              {
               last = last->next;
              }
              display_backward(last);

/*This code first sets the last pointer to the last node of the linked list and then calls the displayBackward function with the last pointer as an argument.
                 display_backward();*/
                  break;
            case 4:
                displayMinHeight5soldiers(start);
                break;
            case 5:
                 displayTop20SoldiersByAge();
                break;
            case 6:
                displayTop10SoldiersBysalary();
                break;
            case 7:
                displayTop10Name();
                break;
            case 8:
                displayTop7SoldiersById();
                break;


            case 0:
              goto A;
              break;
       default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;

        }
        break;

  case 3:
        cout<<"choice '1' to sort by name "<<endl;
        cout<<"choice '2' to sort by mother name"<<endl;
        cout<<"choice '3' to sort by appellation"<<endl;
        cout<<"choice '4' to sort by marital status"<<endl;
        cout<<"choice '5' to sort by gender"<<endl;
        cout<<"choice '6' to Sort by Age"<<endl;
        cout<<"choice '7' to Sort by Salary"<<endl;
        cout<<"choice '8' to Sort by ID"<<endl;
        cout<<"choice '9' to sort by height"<<endl;
        cout<<"choice '10' to sort by region"<<endl;
        cout<<"Choice '0'to return to menu"<<endl;
        cin>>srt;
        switch(srt)
        {
        case 1:
              sortSoldiersByName(start);
              break;
        case 2:
              sortSoldiersBymothername(start);
              break;
        case 3:
              sortSoldiersByappellation(start);
              break;
        case 4:
              sortSoldiersmaritalStatus(start);
               break;
        case 5:
              sortSoldiersBygender(start);
              break;
        case 6:
              sortSoldiersByAge();
              break;
        case 7:
              sortSoldiersBySalary();
              break;
        case 8:
              sortSoldiersById();
              break;
        case 9:
              sortByHeight();
               break;
        case 10:
              sortByRegion();
               break;
        case 0:
              goto A;
              break;
       default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;

        }
         break;
  case 4:
        cout<<"choice '1' to search by name"<<endl;
        cout<<"choice '2' to search by IDNO "<<endl;
        cout<<"choice '3' to search by sex"<<endl;
        cout<<"choice '4' to search by region"<<endl;
        cout<<"choice '5' to search by salary"<<endl;
        cout<<"choice '6' to search by age "<<endl;
        cout<<"choice '7' to search by appellation"<<endl;
        cout<<"choice '8' to search by mother name "<<endl;
        cout<<"choice '9' to search by height"<<endl;
        cout<<"choice '10' to search by marital status"<<endl;
        cout<<"Choice '0'to return to menu"<<endl;
        cin>>srch;
        switch(srch)
        {
        case 1:
                search_by_name();
                break;
        case 2:
                search_by_id();
                break;
        case 3:
                search_by_sex();
                break;
        case 4:
                search_by_region();
                break;
        case 5:
                search_by_salary();
                break;
        case 6:
                search_by_age();
                break;
        case 7:
                search_by_appellation();
                break;
        case 8:
                search_by_mother_name();
                break;
        case 9:
                search_by_height();
                break;
        case 10:
                search_by_marital();
                break;
        case 0:
              goto A;
              break;
       default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;
        }
        break;
 case 5:
        cout<<"choice '1' to delete the first element of the linked list"<<endl;
        cout<<"choice '2' to delete the last element of the linked list"<<endl;
        cout<<"choice '3' to delete by name"<<endl;
        cout<<"choice '4' to delete by IDNO "<<endl;
        cout<<"choice '5' to delete by sex"<<endl;
        cout<<"choice '6' to delete by region"<<endl;
        cout<<"choice '7' to delete by salary"<<endl;
        cout<<"choice '8' to delete by age "<<endl;
        cout<<"choice '9' to delete by appellation"<<endl;
        cout<<"choice '10' to delete by mother name "<<endl;
        cout<<"choice '11' to delete by height"<<endl;
        cout<<"choice '12' to delete by marital status"<<endl;
        cout<<"choice '13' to delete maximum age "<<endl;
        cout<<"choice '14' to delete minimum age "<<endl;
        cout<<"choice '15' to delete nth node"<<endl;
        cout<<"Choice '0'to return to menu"<<endl;
        cin>>del;
        switch(del)
        {
        case 1:
            delete_at_beginning();
            break;
        case 2:
            delete_at_end();
            break;
        case 3:
            delete_by_name();
            break;
        case 4:
            delete_by_id();
            break;
        case 5:
            delete_by_sex();
            break;
        case 6:
            delete_by_region();
            break;
        case 7:
            delete_by_salary();
            break;
        case 8:
            delete_by_age();
            break;
        case 9:
            delete_by_appellation();
            break;
        case 10:
            delete_by_mother_name();
            break;
        case 11:
            delete_by_height();
            break;
        case 12:
            delete_by_marital_status();
            break;

        case 13:
            delete_max_age();
            break;
        case 14:
            delete_min_age();
            break;
        case 15:
            delete_node();
            break;
        case 0:
              goto A;
              break;
       default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;

        }
        break;
case 6:
        cout<<"choice '1' to find maximum age "<<endl;
        cout<<"choice '2' to find minimum age "<<endl;
        cout<<"choice '3' to calculate average age"<<endl;
        cout<<"choice '4' to find maximum salary"<<endl;
        cout<<"choice '5' to find minimum salary"<<endl;
        cout<<"choice '6' to calculate average salary"<<endl;
        cout<<"Choice '0'to return to menu"<<endl;
        cin>>cal;
        switch(cal)
        {
        case 1:
            max_age();
            break;
        case 2:
            min_age();
            break;
        case 3:
            average_age();
            break;
        case 4:
            max_salary();
            break;
        case 5:
            min_salary();
            break;
        case 6:
            average_salary();
            break;

        case 0:
              goto A;
              break;
       default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;

        }
        break;
case 7:
        cout << "choice '1' to Update Soldier"<<endl;
        cin>>up;
        switch(up)
        {
        case 1:
            int id;
            cout << "Enter ID: ";
            cin >> id;
            updateSoldierById(id);
            break;
       case 0:
              goto A;
              break;
       default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;
        }

        break;
case 8:
        cout<<"choice '1' to count by height "<<endl;
        cout<<"choice '2' to count by name"<<endl;
        cout<<"choice '3' to count by gender"<<endl;
        cout<<"choice '4' to count by appellation "<<endl;
        cout<<"choice '5' to count by marital status "<<endl;
        cout<<"choice '6' to count by mother name "<<endl;
        cout<<"choice '7' to count by salary "<<endl;
        cout<<"choice '8' to Count total Soldiers"<<endl;
        cout<<"choice '9' to Count Soldiers by Age"<<endl;
        cout<<"choice '10' to Count Soldiers by Region"<<endl;
        cout<<"Choice '0'to return to menu"<<endl;
        cin>>cnt;
        switch(cnt)
        {
        case 1:
              int height;
              cout<<"height";
              cin>>height;
              cout << "Soldiers with height " << height << ": " <<countSoldiersByheight(height)<<endl;
              break;
        case 2:
              char name[20];
              cout<<" enter name of soldier";
              cin>>name;
              cout << "Soldiers with name " << name << ": " <<countSoldiersByname(name)<<endl;
              break;
        case 3:
              char gender[10];
              cout<<"Enter gender";
              cin>>gender;
              cout << "Soldiers with gender" << gender << ": " <<countSoldiersBygender(gender)<<endl;
              break;
        case 4:
              char appellation[10];
              cout<<"enter appellation";
              cin>>appellation;
              cout<<"Soldiers with appellation =" <<appellation<<countSoldiersByappellation(appellation)<<endl;
              break;
        case 5:
             char marital[10];
             cout<<" enter marital status";
             cin>>marital;
             cout << "Soldiers w/c is " << marital << ": " <<countSoldiersBymaritalStatus(marital)<<endl;
             break;
        case 6:
             char mothername[10];
             cout<<"enter soldiers mother name";
             cin>>mothername;
             cout<<"Soldiers with mother name"<<mothername<< ": "
             <<countSoldiersBymotherName(mothername)<<endl;
             break;

        case 7:
              int salary;
              cout<<"enter salary";
              cin>>salary;
              cout << "Soldiers with salary " << salary << ": " <<countSoldiersBysalary(salary)<<endl;
              break;

        case 8:
            cout << "Total Soldiers: " << countSoldiers() << endl;
            break;
        case 9:
            int age;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Soldiers of Age " << age << ": " << countSoldiersByAge(age) << endl;
            break;
        case 10:
            char region[20];
            cout << "Enter Region: ";
            cin >> region;
            cout << "Soldiers in " << region << ": " << countSoldiersByRegion(region) << endl;
            break;
       case 0:
              goto A;
              break;
       default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;

        }
        break;
case 9:
        writeSoldiersToFile();
        break;

case 0:
        break;
default:
            cout << "Invalid Choice." << endl;
            goto A;
            break;

}

    }
    while (choice != 0);
    return 0;
}
