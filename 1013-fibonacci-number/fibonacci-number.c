

int fib(int n){
    
    int first = 0,second = 1,temp =0,m=n;
    for(int i=0;i<n;i++)
    {
        temp = first + second;
        first = second;
        second = temp;
        
        
        
    }

    
    return first;

}