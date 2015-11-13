假设以下两个链表：
链表1：1->3->5
链表2：2->4->6
node *mergerecursive(node *head1,node *head2)
{
if(head1==NULL)
{
return head2;
}
if(head2==NULL)
{
return head1;
}
node *head=NULL;
if(head->data<head2->data)
{
head=head1;
head->next=mergerecursive(head1->next,head2);
}
else
{
head=head2;
head->next=mergerecursive(head1,head2->next);
}
return head;

}

  非递归方式合并：
例：已知两个单链表head1和head2各自有序升序排列，请把他们合并成一个连表并依然有序，并保留原来所有节点

因为head1和head2是有序的，所以只需要把较短链表的各个元素有序的插入到较长的链表之中就可以了
node *t_node(node *head,node *item)
{
node *p=head;
node *q=NULL;//始终指向p之前的节点
while(p->data<item->data&&p!=NULL)
{
q=p;
p=p->next;
}
if(p=head)插入到原头结点之前
{
item->next=p;
return item;
}
插入到p与q之间
q->next=item;
item->next=p;
return head;
}
合并单链表
node merge(node *head1,node *head2)
{
node *head;//合并后的头指针
node *p;
node *nextp;//指向p之后
if(head1==NULL)//一个链表为空返回另一个链表
{
return head2;
}
else if(head2==NULL)//一个链表为空返回另一个链表
{
return head1;
} 
两个链表都不为空
if(length(head1)>=length(head2))//length()函数测单链表的长度，函数的使用见我的博客
{
head=head1;
p=head2;
}
else
{
head=head2;
p=head1;
}
while(p!=NULL)
{
nextp=p->next;//
head=insert_node(head ,p);
p=nextp;//指向要插入的下一个节点
}
return head；
}