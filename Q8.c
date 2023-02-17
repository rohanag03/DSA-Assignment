#include <stdio.h>
#include <stdlib.h>
int visit_1034[30] = {0};
int v_1034[30] = {0};


typedef struct node
{
    int data;
    struct node *prev;
    struct node *link;
} node;


typedef struct queue
{
    struct node *rr;
    struct node *fr;
} que;


int dequeue_1034(que *q)
{
    node *temp;
    if (q->rr != NULL)
    {
        temp = q->rr;
        int d = temp->data;
        q->rr = temp->prev;
        if (q->rr != NULL)
            q->rr->link = NULL;
        else
            q->fr = NULL;
        return d;
    }
    return 0;
}


void enqueue_1034(int ch, que *q)
{
    node *nnode;
    nnode = (node *)malloc(sizeof(node));
    nnode->data = ch;
    nnode->link = NULL;
    nnode->prev = NULL;
    if (q->fr == NULL)
    {
        q->fr = nnode;
        q->rr = nnode;
    }
    else
    {
        nnode->link = q->fr;
        q->fr->prev = nnode;
        q->fr = nnode;
    }
}


void display_1034(que *q)
{
    node *temp;
    temp = q->fr;
    while (temp != NULL)
    {
        printf(" %c", temp->data);
        temp = temp->link;
    }
}


void dfs_1034(int t, int a[30][30], int n)
{
    int i, j;
    printf("%d->", t);
    visit_1034[t - 1] = 1;
    for (i = 0; i < n; i++)
    {
        if (a[t - 1][i] == 1 && visit_1034[i] == 0)
        {
            dfs_1034(i + 1, a, n);
        }
    }
}


void bfs_1034(int t, int a[30][30], int n, que *q)
{
    int i, j;
    printf("%d->", t);
    int temp;
    enqueue_1034(t, q);
    v_1034[t - 1] = 1;
    while (q->fr != NULL)
    {
        temp = dequeue_1034(q);
        for (i = 0; i < n; i++)
        {
            if (a[temp - 1][i] == 1 && v_1034[i] == 0)
            {
                enqueue_1034(i + 1, q);
                printf("%d->", i + 1);
                v_1034[i] = 1;
            }
        }
    }
}

int main(void)
{
    printf("Enter number of vertices:\n");
    int n, i, j, e, p, q;
    scanf("%d", &n);
    int a[20][20];
    for (i = 0; i < n; i++)
    {
        visit_1034[i] = 0;
        for (j = 0; j < n; j++)

        {
            a[i][j] = 0;
        }
    }
    printf("Enter number of edges:\n");
    scanf("%d", &e);
    printf("\nEnter 1 for undirected graph and 0 for directed graph:");
    int t;
    scanf("%d", &t);
    for (i = 0; i < e; i++)
    {
        printf("Enter edge vertex(p,q):\n");
        scanf("%d%d", &p, &q);
        a[p - 1][q - 1] = 1;
        if (t == 1)
            a[q - 1][p - 1] = 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Enter Element from where you want to start dfs and bfs:");
    int d;
    scanf("%d", &d);
    printf("\n DFS:\n");
    dfs_1034(d, a, n);
    que q1;
    q1.fr = q1.rr = NULL;
    printf("\n BFS:\n");
    bfs_1034(d, a, n, &q1);
    return 0;
}