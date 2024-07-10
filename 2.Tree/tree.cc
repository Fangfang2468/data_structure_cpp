#include <array>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>


#define MAX_NODE 10


typedef struct TreeNode
{
    int key;
    struct TreeNode *lchild, *rchild;
} Node;


// 初始化二叉树节点
Node* getNewNode(int key)
{   
    Node* p = (Node*)malloc(sizeof(Node));
    p-> key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

// 清除二叉树节点
void clear(Node* root)
{
    if(root == NULL) return;

    clear(root-> lchild);
    clear(root-> rchild);
    free(root);

    return;
}

// 随机插入节点
Node* insert(Node* root, int key)
{
    if(root == NULL)    return getNewNode(key);

    if(rand() % 2)  root-> lchild = insert(root-> lchild, key);
    else            root-> rchild = insert(root-> rchild, key);

    return root;
}

// 广度优先遍历
std::array<Node*, MAX_NODE + 5> queue; 
int head, tail;

void bfs(Node* root)
{
    head = tail = 0;
    queue.at(tail++) = root;

    while (head < tail) 
    {
        Node* node = queue.at(head);

        printf("\nnode : %d", node-> key);

        if(node-> lchild) {
            queue.at(tail++) = node-> lchild;
            printf("\t%d->%d(left)\n", node-> key, node-> lchild-> key);

        }
            
        if(node-> rchild) {
            queue.at(tail++) = node-> rchild;
            printf("\t%d->%d(right)\n", node-> key, node-> rchild-> key);
        }
            

        head++;

    }
}

// 深度优先遍历
int tot = 0;
void dfs(Node* root)
{
    if(root == NULL)    return;

    int start, end;
    tot += 1;
    start = tot;

    if(root-> lchild)   dfs(root-> lchild);
    if(root-> rchild)   dfs(root-> rchild);

    tot += 1;
    end = tot;

    printf("%d : [%d, %d]\n", root-> key, start, end);

    return;
}


class Tree
{

};

int main()
{
    srand(time(0));

    Node* root = NULL;

    for (int i = 0; i < MAX_NODE; i++) 
    {
        root = insert(root, rand() % 100);
    }


    std::cout << "\n\n---- 广度遍历 ----" << "\n";
    bfs(root);

    std::cout << "\n\n---- 深度遍历 ----" << "\n";
    dfs(root);

    return 0;
}