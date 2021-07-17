
void insertion_sort(){
	int temp;
	record *i;
	record *p;
	for(i=first->next;i!=NULL;i=i->next){
		temp=i->id;
		p=i;
		while(p!=NULL && p->prev->id>=temp){
			p->id=p->prev->id;
			p=p->prev;
		}
		p->id=temp;
	}}
