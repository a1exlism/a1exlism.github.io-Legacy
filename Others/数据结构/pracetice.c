struct node
{
	int date;
	int *next;
}node;
node *mergerecursive(node *head1, node *head2 ){
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	node head == NULL;	//定义临时存储区,设为NULL避免野指针
	if(head1->data<head2->data)
	{
		head = head1;	//复制地址
		head->next = mergerecursive(head1->next, head2);
	}
	return head;	//返回struct node的指针
}