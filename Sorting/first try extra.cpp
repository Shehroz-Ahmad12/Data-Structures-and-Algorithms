
void selection_sort(){
	int temp;
	
	int count=countNodes();	
	record *p=first;
	record *min_index;
	record *q=p;
	
	
	for (int i=0;i<count;i++){
		min_index=p;
		q=p->next;
		for(int j=i+1;j<count;j++){
			if(min_index->id>q->id){
				min_index=q;
					}
				q=q->next;
			}	
					
			temp=min_index->id;
			min_index->id=p->id;
			p->id=temp;
	
			p=p->next;
	}
}

void bubble_sort(){
	
	record *p=first;
	
	int count=countNodes();
	
	cout<<"\n\n Count: "<<count;		
	int temp;
	
	for(int i=0;i<count;i++){
		for(int j=0;j<count-i-1;j++){
			if(p->id>p->next->id){
				temp=p->id;
				p->id=p->next->id;
				p->next->id=temp;
	
			}	p=p->next;
		}
		p=first;
	}	
}



////////////////////////////

void selection_sort()
{
	int temp;
	
	record *i=first;
	record *min_index;
	record *p;
	
	
	for (i;i!=NULL;i=i->next){
		min_index=i;
	
		for(p=i->next;p!=NULL;p=p->next){
			if(p->id<min_index->id){
				min_index=p;
			}
}
		temp=min_index->id;
		min_index->id=i->id;
		i->id=temp;
}}



void bubble_sort(){
	
	record *p=first;
	record *q=first;
		
	int temp;
	
	for(p;p->next!=NULL;p=p->next){
		for(q;q!=p;q=q->next){
			if(q->id>q->next->id){
				temp=q->id;
				q->id=q->next->id;
				q->next->id=temp;
			}	
		}
		
	}	}
