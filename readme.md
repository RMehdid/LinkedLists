# Projet-1 ASD3 

Reading this report you would find **algorithms** solving a modified version of a problem mentioned in the fifth exercise, the **steps** for implementing them and the **logic** behind them.

### Preparation de structure `Processus`

```
struct  processus {
	int id;
	int priority;
	char state;
	processus *next;
};
```
La structure `processus` définit un élément de liste chaînée de processus. Elle contient un champ `id` qui représente l'**identifiant** du processus, un champ `priority` qui représente la priorité du processus, un champ `state` qui représente l'état du processus (`E` pour en exécution, `P` pour en attente et `F` pour terminé) et un champ `next` qui est un pointeur vers le prochain élément de la liste. Cette structure est utilisée pour créer une liste chaînée de `processus`, dans laquelle chaque élément est une structure `processus` contenant les informations d'un processus.

### Preparation des fonctions d'insertion:
```
void  insertDebut(processus  *&head,  int  x,  int  y,  char  z){

	processus *nouv =  new processus;
	nouv->id = x;
	nouv->priority = y;
	nouv->next = head;
	nouv->state = z;
	head = nouv;
	
}

void  insertFin(processus  *&head,  int  x,  int  y,  char  z){
	if  (head ==  0){
		insertDebut(head, x, y, z);
	} else {
		processus *current = head;
		while  (current->next  !=  0){
			current =  current->next;
		}
		
		current->next  =  new processus;
		current->next->id  = x;
		current->next->priority  = y;
		current->next->state  = z;
		current->next->next  =  0;
	}
}
```

La fonction `insertDebut()` a pour but d'insérer un nouvel élément en début de liste chaînée de `processus`. La fonction prend en argument un pointeur vers la tête de la liste (passé en référence) et les valeurs de `id`, de `priority` et de `state` du processus à insérer. Un nouvel élément est créé et ses champs sont initialisés avec les valeurs passées en argument. Le nouvel élément est ensuite inséré en début de liste en mettant à jour le pointeur de la tête de la liste pour qu'il pointe vers le nouvel élément. 

La fonction `insertFin()` a pour but d'insérer un nouvel élément en fin de liste chaînée de processus. La fonction prend en argument un pointeur vers la tête de la liste (passé en référence) et les valeurs de`'id`, de `priority` et de `state` du processus à insérer. Si la liste est vide, alors la fonction `insertDebut()` est appelée pour insérer le nouvel élément en début de liste. Sinon, un pointeur `current` parcourt la liste jusqu'à arriver à la fin de la liste. Un nouvel élément est alors créé et inséré en fin de liste en mettant à jour le pointeur de l'élément précédent pour qu'il pointe vers le nouvel élément.

## 1 - Construction des tableaux

```
void  creation(processus  *&D,  int  n){
	int x, y;
	char state;
	for  (int i =  0; i < n; i++){
		cout <<  "Enter Id["  << i +  1  <<  "] =";
		cin >> x;
		cout <<  "Enter priority["  << i +  1  <<  "] =";
		cin >> y;
		cout <<  "Enter state e for in execution, p for pending and f for finished["  << i +  1  <<  "] =";
		cin >> state;
		while  (state != 'E' && state != 'P' && state != 'F'){
			cout <<  "\t\t\tERROR \ne for in execution,p for pending,f for finished\n  ";
			cout << "Enter state ["  << i +  1  <<  "] =";
			cin >> state;
		}
		insertFin(D, x, y, state);
		cout << endl;
	}
}
```

La fonction `creation()` a pour but de créer une liste chaînée de processus en demandant à l'utilisateur de saisir les informations de chaque `processus`. La fonction prend en argument un pointeur vers la tête de la liste (passé en référence) et un entier indiquant le nombre de processus à créer. Pour chaque processus, la fonction demande à l'utilisateur de saisir `id`, `priority` et `state` du processus. Si l'état saisi par l'utilisateur n'est pas valide (`E`, `P` ou `F`), alors un message d'erreur est affiché et l'utilisateur est invité à saisir à nouveau `state`. Une fois que les informations du processus ont été saisies, la fonction `insertFin()` est appelée pour insérer le processus en fin de liste.

## 2 - Affichage des listes

```
void  afficher(processus  *&D){
	processus *current = D;
	
	if  (current ==  0)
		cout <<  "*----------Empty list----------*\n";
	else
		while  (current !=  0){
			cout <<  "Id={"  <<  current->id  <<  "}\t";
			cout <<  "priority={"  <<  current->priority  <<  "}\t";
			cout <<  "state={"  <<  current->state  <<  "}\t";
			cout <<  "\n";
			current =  current->next;
		}
}
```

La fonction `afficher()` a pour but d'afficher le contenu d'une liste chaînée de processus. La fonction prend en argument un pointeur vers la tête de la liste (passé en référence). Un pointeur `current` est initialisé à la tête de la liste. Si la liste est vide (si le pointeur `current` vaut 0), alors un message indiquant que la liste est vide est affiché. Sinon, la fonction parcourt chaque élément de la liste en utilisant le pointeur `current` et affiche `id`, `priority` et `state` de chaque processus. Ensuite, le pointeur `current` passe à l'élément suivant de la liste jusqu'à ce que tous les éléments aient été parcourus.

### Preparation de fonction de suppression 

```
void  supprimer(processus  *&head){
	processus *sup;
	while  (head !=  0){
		sup = head;
		head =  head->next;
		delete sup;
	}
}
```
La fonction `supprimer()` nous permet de desallouer notre `processus` de la memoire.

## 3 - Inversion des listes

```
void  InverserList(processus  *&D){
	processus *current = D;
	processus *l =  0;
	
	while  (current !=  0){
		insertDebut(l,  current->id,  current->priority,  current->state);
		current =  current->next;
	}
	
	supprimer(D);
	D = l;
}
```

La fonctions `InverserList()` prend un pointeur vers une liste linéaire de type `processus` et modifie la liste en place pour inverser son ordre.  La fonction accomplie cela en parcourant la liste, en créant une nouvelle liste avec les éléments dans l'ordre inverse, puis en supprimant la liste d'origine.

Voici une ventilation de ce que fait la fonction :

Le pointeur `current` est initialisé à la tête de la liste d'origine.
Le pointeur l est initialisé à `nullptr`. Cela sera utilisé pour garder une trace de la tête de la nouvelle liste.
La fonction entre dans une boucle qui continue jusqu'à ce que courant soit nullptr.
La fonction appelle `insertDebut()` avec `l`, `current->id`, `current->priority` et `current->state` comme arguments.
Le pointeur `current` est mis à jour pour pointer vers l'élément suivant dans la liste d'origine.
La fonction appelle `supprimer()` avec `D` comme argument.
La fonction définit la valeur de D à la tête de la nouvelle liste, qui est `l`. Cela `inverse` efficacement l'ordre de la liste d'origine.

## 5 - Déplacement de priorité majeur en tête

```
void  maxprio(processus  *&head){
	processus *current = head;
	processus *max = head;
	processus *pred;
	do{
		if  (current->priority  >  max->priority){
			max = current;
		}
		current =  coucurrentrant->next;
	}  while  (current !=  0);
	
	if  (max != head){
		current = head;
		pred = head;
		while  (current->next  !=  0){
			if  (current->next  == max){
				pred = current;
				break;
			} else {
				current =  current->next;
			}
		}

		// linking the previous processus of next one;
		pred->next  =  max->next;
	
		// linking the node with the head;
		max->next  = head;
	
		// puting the node as the new head;
		head = max;
	}
}
```

La fonction `maxprio()` permet de parcourir la liste pour chercher le `processus` qui contient la priorité maximale et puis le déplacer en tête de la liste.

La fonction initialise d'abord un pointeur nommé `current` pour pointer vers le premier nœud, et un autre pointeur nommé `max` pour pointer également vers le premier nœud. Il initialise également un pointeur nommé `pred` à null.

La fonction entre ensuite dans une `boucle` qui parcourt la liste linéaire, en commençant par le premier `processus`, et compare la priorité de chaque `processus` à la priorité du `processus` maximum actuel, qui est stockée dans `max`. Si la priorité du `processus` actuel est supérieure à la priorité du `processus` maximum, `max` est mis à jour pour pointer vers le `processus` actuel.

Une fois la `boucle` terminée, la fonction vérifie si `max` pointe vers le premier `processus`. Si ce n'est pas le cas, la fonction effectue certaines opérations pour réorganiser la liste linéaire afin que le `processus` pointé par max devienne le nouveau `processus` de début.

Tout d'abord, la fonction définit `current` pour pointer vers le premier `processus` et `pred` pour pointer vers le premier `processus`. Il entre ensuite dans une autre boucle qui parcourt la liste linéaire jusqu'à ce qu'il trouve le `processus` précédant le `processus` pointé par max. Lorsqu'il trouve ce `processus`, il met à jour `pred` pour qu'il pointe vers lui et sort de la boucle.

La fonction effectue alors les opérations suivantes :

Définit le champ `next` de `pred` sur le champ `next` de `max`
Définit le champ `next` de `max` pour pointer vers le premier `processus`
Définit le premier pointeur pour pointer vers le `processus` max
Enfin, la fonction ne renvoie rien.

## 6 - Suppression des processus qui ont l'état `Finished`

```
void  suppetatT(processus  *&D){
	processus *current;
	processus *pred;
	processus *tete;
	current = D;
	tete = D;
	while  (current !=  0){
		if  (current->state  ==  'f'){
			if  (current == tete){
				tete =  tete->next;
				current =  current->next;
			} else {
				pred->next  =  current->next;
				current =  current->next;
			}
		} else {
			pred = current;
			current =  current->next;
		}
	}
	D = tete;
}
```
La fonction `suppetatT()` a pour but de supprimer tous les éléments de liste linéaire de `processus` ayant un état `F` (terminé). La fonction prend en argument un pointeur vers la tête de la liste (passé en référence). Trois pointeurs `current`, `pred` et `tete` sont initialisés. `current` parcourt chaque élément de la liste et `pred` pointe vers l'élément précédent de `current`. `tete` est initialisée avec la valeur de la tête de la liste et est utilisée pour mettre à jour la tête de la liste lorsqu'un élément est supprimé. Si l'élément courant a un état `F`, alors s'il s'agit de la tête de la liste, la tête est mise à jour pour pointer vers son élément suivant et `current` est mis à jour pour pointer vers son élément suivant. Sinon, le pointeur `pred` est mis à jour pour pointer vers l'élément suivant de `current` et `current` est mis à jour pour pointer vers son élément suivant. Si l'élément courant n'a pas un état `F`, alors `pred` prend la valeur de `current` et `current` passe à l'élément suivant de la liste jusqu'à ce que tous les éléments aient été parcourus. Enfin, la tête de la liste est mise à jour avec la valeur de `tete`.


# Main

```
int  main(){
	cout <<  "\n";
	cout <<  "\t\t\t\t\t\t\t-----------------------------projet ASD1-----------------------------\n";
	// Initialization des variables;
	int Nproces, M, val;
	// Lecture nombre de processus;
	cout <<  "Enter number of processes: ";
	cin >> Nproces;
	processus **L =  new processus *[Nproces];
	
	for  (int i =  0; i < Nproces; i++){
		L[i]  =  0;
		cout <<  "Enter the array size ["  << i +  1  <<  "] : ";
		cin >> M;
		creation(L[i], M);
	}
	
	// Premier affichage;
	cout <<  "\n";
	cout <<  "\nEntered array:\n";
	for  (int i =  0; i < Nproces; i++){
		cout <<  "--------------L["  << i +  1  <<  "]--------------\n";
		afficher(L[i]);
	}
	
	// Inversion des listes
	cout <<  "\n";
	cout <<  "\nArray with reversed lists:\n";
	for  (int i =  0; i < Nproces; i++){
		InverserList(L[i]);
	}
	
	// Affichage apres inversion;
	for  (int i =  0; i < Nproces; i++){
		cout <<  "--------------L["  << i +  1  <<  "]--------------\n";
		afficher(L[i]);
	}
	cout <<  "\n";
	cout <<  "\nArray of ordered lists by priority:\n";
	for  (int i =  0; i < Nproces; i++){
		maxprio(L[i]);
		cout <<  "--------------L["  << i +  1  <<  "]--------------\n";
		afficher(L[i]);
	}
	
	cout << endl <<  "deleting all etat T processus..."  << endl;
	for  (int i =  0; i < Nproces; i++){
		suppetatT(L[i]);
		cout <<  "--------------L["  << i +  1  <<  "]--------------\n";
		afficher(L[i]);
	}
	
	cout <<  "\n";
	cout <<  "\t\t\t\t\t\t\t-----------------------------END OF MAIN-----------------------------\n";
	for  (int i =  0; i <  5; i++){
		cout <<  "\n";
	}
	return  0;
}
```

Ce **programme** gère des listes de de type `processus`. Il commence par demander à l'utilisateur combien de listes de processus il y a, puis demande à l'utilisateur de saisir la taille de chaque liste et de saisir les valeurs de chaque `processus` de chaque liste. Il affiche ensuite les listes de processus initiales. 

Le programme effectue ensuite l'opération d'**inversion** de chaque liste de `processus`, puis **affiche** à nouveau les listes inversées. Le programme **trie** ensuite chaque liste par **ordre de priorité** des processus et affiche à nouveau les listes triées. 

Enfin, le programme **supprime tous** les processus ayant un état `T` de chaque liste et **affiche** à nouveau les listes avec ces processus supprimés.
