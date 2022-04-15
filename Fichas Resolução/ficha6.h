#define Max 10

struct staticQueue {
	int front;
	int length;
	int values [Max];
};
typedef struct staticQueue *SQueue;

struct dinQueue {
	int size;
	int front;
	int length;
	int *values;
};
typedef struct dinQueue *DQueue;

struct staticStack {
	int sp; //Aponta para a próxima posição livre
    int values [Max];   //Array com os elementos que se encontram na stack 
};
typedef struct staticStack *SStack;

struct dinStack {
	int size;
	int sp;
	int *values;
};
typedef struct dinStack *DStack;

void SinitQueue (SQueue q);
int  SisEmptyQ  (SQueue q);
int  Senqueue   (SQueue q, int x);
int  Sdequeue   (SQueue q, int *x);
int  Sfront     (SQueue q, int *x);
void ShowSQueue (SQueue q);

void DinitQueue (DQueue q);
int  DisEmptyQ  (DQueue q);
int  Denqueue   (DQueue q, int x);
int  Ddequeue   (DQueue q, int *x);
int  Dfront     (DQueue q, int *x);
void ShowDQueue (DQueue q);


void SinitStack (SStack s);
int  SisEmpty (SStack s);
int  Spush (SStack s, int x);
int  Spop (SStack s, int *x);
int  Stop (SStack s, int *x);
void ShowSStack (SStack s);

void DinitStack (DStack s);
int  DisEmpty (DStack s);
int  Dpush (DStack s, int x);
int  Dpop (DStack s, int *x);
int  Dtop (DStack s, int *x);
void ShowDStack (DStack s);
