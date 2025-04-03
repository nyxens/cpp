#include<iostream>
using namespace std;
struct Node{
    int value;
    int d;
    Node* p;
    Node* l;
    Node* s;
};
Node* create(int s){
    Node* x=new Node();
    x->value=s;
    x->d=0;
    x->p=x->l=x->s=NULL;
    return x;
}
Node* mergetree(Node*a1,Node*a2){
    if(a1->value>a2->value)
       swap(a1,a2);
    a2->p=a1;
    a2->s=a1->l;
    a1->l=a2;
    a1->d++;
    return a1;
}
Node* merge(Node* a1,Node* a2){
    if(a1==NULL)
      return a2;
    if(a2==NULL)
       return a1;
    if(a1->d<=a2->d){
        a1->s=merge(a1->s,a2);
        return a1;
    }
    else{
        a2->s=merge(a1,a2->s);
        return a2;
    }
}
Node* mergeheap(Node* a1,Node* a2){
    Node* m=merge(a1,a2);
    if(m==NULL)
       return NULL;
    Node* prevalue;
    Node* next;
    Node* cur;
    cur=m;
    next=m->s;
    prevalue=NULL;
    while(next!=NULL){
        if(cur->d!=next->d||next->s!=NULL&&next->s->d==cur->d){
            prevalue=cur;
            cur=next;
        }
        else{
            if(cur->value<=next->value){
                cur->s=next->s;
                cur=mergetree(cur,next);
            }
            else{
                if(prevalue==NULL)
                  m=next;
                else
                    prevalue->s=next;
                    next=mergetree(next,cur);
                    cur=next;
            }
        }
        next=cur->s;
    }
    return m;
}
Node* insert(Node* r,int s){
     Node*n=create(s);
     return mergeheap(r,n);
}
void displayTree(Node* n){
    if(n==NULL)
      return;
       cout<<n->value<<" ";
    displayTree(n->l);
    displayTree(n->s);
}

int main(){
    Node* root=NULL;
    root=insert(root,12);
    //root=insert(root,6);
    root=insert(root,7);
    //root=insert(root,8);
    root=insert(root,25);
    displayTree(root);
}