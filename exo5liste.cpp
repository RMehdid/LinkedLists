#include <iostream>
using namespace std;
struct processus
{
  int id;
  int priority;
  char state;
  processus *next;
};
void insertDebut(processus *&head, int x, int y, char z)
{
  processus *nouv = new processus;
  nouv->id = x;
  nouv->priority = y;
  nouv->next = head;
  nouv->state = z;
  head = nouv;
}
void insertFin(processus *&head, int x, int y, char z)
{
  if (head == 0)
  {
    insertDebut(head, x, y, z);
  }
  else
  {
    processus *current = head;
    while (current->next != 0)
    {
      current = current->next;
    }
    current->next = new processus;
    current->next->id = x;
    current->next->priority = y;
    current->next->state = z;
    current->next->next = 0;
  }
}
void creation(processus *&D, int n)
{
  int x, y;
  char state;
  for (int i = 0; i < n; i++)
  {
    cout << "Enter Id[" << i + 1 << "] =";
    cin >> x;
    cout << "Enter priority[" << i + 1 << "] =";
    cin >> y;
    cout << "Enter state e for in execution, p for pending and f for finished[" << i + 1 << "] =";
    cin >> state;

    while (state != 'E' && state != 'P' && state != 'F')
    {
        cout << "\t\t\tERROR \ne for in execution,p for pending,f for finished\n ";
        cout << "Enter state [" << i + 1 << "] =";
        cin >> state;
    }

    insertFin(D, x, y, state);
    cout << endl;
  }
}
void afficher(processus *&D)
{
  processus *current = D;
  if (current == 0)
    cout << "*----------Empty list----------*\n";
  else
    while (current != 0)
    {
      cout << "Id={" << current->id << "}\t";
      cout << "priority={" << current->priority << "}\t";
      cout << "state={" << current->state << "}\t";
      cout << "\n";
      current = current->next;
    }
}
void supprimer(processus *&head)
{
  processus *sup;
  while (head != 0)
  {
    sup = head;
    head = head->next;
    delete sup;
  }
}
void InverserList(processus *&D)
{
  processus *current = D;
  processus *l = 0;
  while (current != 0)
  {
    insertDebut(l, current->id, current->priority, current->state);
    current = current->next;
  }
  supprimer(D);
  D = l;
}

void maxprio(processus *&head)
{
  processus *current = head;
  processus *max = head;
  processus *pred;

  do
  {
    if (current->priority > max->priority)
    {
      max = current;
    }

    current = coucurrentrant->next;

  } while (current != 0);

  if (max != head)
  {
    current = head;
    pred = head;

    while (current->next != 0)
    {
      if (current->next == max)
      {
        pred = current;
        break;
      }
      else
      {
        current = current->next;
      }
    }

    // linking the previous processus of next one;
    pred->next = max->next;

    // linking the node with the head;
    max->next = head;

    // puting the node as the new head;
    head = max;
  }
}

void suppetatT(processus *&D)
{
  processus *current;
  processus *pred;
  processus *tete;
  current = D;
  tete = D;

  while (current != 0)
  {

    if (current->state == 'f')
    {
      if (current == tete)
      {
        tete = tete->next;
        current = current->next;
      }
      else
      {
        pred->next = current->next;
        current = current->next;
      }
    }
    else
    {
      pred = current;
      current = current->next;
    }
  }
  D = tete;
}
int main()
{
  cout << "\n";
  cout << "\t\t\t\t\t\t\t-----------------------------projet ASD1-----------------------------\n";
  // Initialization des variables;
  int Nproces, M, val;
  // Lecture nombre de processus;
  cout << "Enter number of processes: ";
  cin >> Nproces;
  processus **L = new processus *[Nproces];
  for (int i = 0; i < Nproces; i++)
  {
    L[i] = 0;
    cout << "Enter the array size [" << i + 1 << "] : ";
    cin >> M;
    creation(L[i], M);
  }
  // Premier affichage;
  cout << "\n";
  cout << "\nEntered array:\n";
  for (int i = 0; i < Nproces; i++)
  {
    cout << "--------------L[" << i + 1 << "]--------------\n";
    afficher(L[i]);
  }

  // Inversion des listes
  cout << "\n";
  cout << "\nArray with reversed lists:\n";
  for (int i = 0; i < Nproces; i++)
  {
    InverserList(L[i]);
  }

  // Affichage apres inversion;
  for (int i = 0; i < Nproces; i++)
  {
    cout << "--------------L[" << i + 1 << "]--------------\n";
    afficher(L[i]);
  }

  cout << "\n";
  cout << "\nArray of ordered lists by priority:\n";
  for (int i = 0; i < Nproces; i++)
  {
    maxprio(L[i]);
    cout << "--------------L[" << i + 1 << "]--------------\n";
    afficher(L[i]);
  }
  cout << "\n";
  cout << "\nEnter the priority value to delete: ";
  cin >> val;
  for (int i = 0; i < Nproces; i++)
  {
    suppVal(L[i], val);
    cout << "--------------L[" << i + 1 << "]--------------\n";
    afficher(L[i]);
  }

  cout << endl
       << "deleting all etat T processus..." << endl;

  for (int i = 0; i < Nproces; i++)
  {
    suppetatT(L[i]);
    cout << "--------------L[" << i + 1 << "]--------------\n";
    afficher(L[i]);
  }
  cout << "\n";
  cout << "\t\t\t\t\t\t\t-----------------------------this is ELON MUSK!!!-----------------------------\n";
  for (int i = 0; i < 5; i++)
  {
    cout << "\n";
  }
  return 0;
}
