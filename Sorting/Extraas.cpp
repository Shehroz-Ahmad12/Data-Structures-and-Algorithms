void selectionRecursive(int size,int i,int j){
	int min_index;
	int temp;
	if(i==size){
		return;
	}
	else{		
		min_index=i; 
		j++;
		selRec2(size,i,j,min_index);
	}
		temp=arr[min_index];
		arr[min_index]=arr[i];
		arr[i]=temp;
		i++;
		j=0;
		selectionRecursive(size,i,j);
	
}

void selRec2(int size,int i,int j,int min_index){
	if(j==size){
		return;
	}
	else{
		if (arr[j]<arr[min_index]){
			min_index=j;
		}
		j++;			
		selRec2(size,i,j,min_index);
	}
}





/*
void recursiveBubble(int size,int i,int j){
	if (i==size-1){
		return;
	}
	else{			
			recBub2(size,i,j);
			i++;j=0;
			recursiveBubble(size,i,j);
	}	
}


void recBub2(int size,int i,int j){
	if(j==size-i){
		return;
	}	
	else{
		if(arr[j]>arr[j+1]){
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
		j++;
		recBub2(size,i,j);
		}
	}
*/



/*
void recursionBubble(int size,int i,int j){
	if (i==size-1){
		return;
	}
	else{	
		if(j==size-i){
		return;
	}	
	else{
		if(arr[j]>arr[j+1]){
			int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
		j++;
		recursionBubble(size,i,j);
		}		
			
		i++;j=0;
		recursionBubble(size,i,j);
	}	
}
*/




/*
void insertionRecursive(int size, int i,int j){
	int temp;
	if(i==size){
		return;
	}
	else{
		temp=arr[i];
		j=i-1;
		if(j<0 || arr[j]<temp){
			return;
			}
		else{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
}
*/

/*

void insertionRecursion(int size,int i, int j){
	int temp;
	if(i==size){
		return;
	}
	else{
		temp=arr[i];
		//j=i-1;
		if (temp<arr[j]){
			j=searchInsertion(size,i,0);
			arr[j]=temp;	
		}
		i++;
		j=i;
		insertionRecursion(size,i,j);
	}	
}

int searchInsertion(int size,int i,int j){
	int min;
	if (j==i){
		return min;
	}
	else{
		if(arr[i]<arr[j])
		{
			min=j;
			shift(i,min);
			return min;
		}
		j++;
		searchInsertion(size,i,j);
			
		}}

void shift(int i,int min){
	if (min==i){
		return;
	}
	else{
		shift(i,min+1);
		arr[min+1]=arr[min];
	}
}
*/
