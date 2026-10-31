char* minWindow(char* s, char* t) {
    int required = strlen(t);
    int l = 0,r = 0,start;
    int min = INT_MAX;
    int formed = 0;

    int frequency[256] = {0};
    for(int i=0;t[i] != '\0';i++)
    {
        frequency[(unsigned char)t[i]]++;
    }

    if(required == 0 || strlen(s) < required)
        return "";

    while(s[r] != '\0')
    {
        unsigned char ch = s[r];

        if(frequency[ch] > 0)
        {
            formed++;
        }
        
        frequency[ch]--;
        r++;

        while(formed == required)
        {
            int len = r - l;
            

            if(len < min)
            {
                min = len;
                start = l;
            }

            unsigned char leftchar = s[l];

            frequency[leftchar]++;
            if(frequency[leftchar] > 0)
            {
                formed--;
            }
            l++;
        }
   
    }
    if(min == INT_MAX)
        return "";

   
    char *res = malloc((min + 1) * sizeof(char));

    if (res == NULL)
        return NULL;

    strncpy(res, s + start, min);
    res[min] = '\0';

    return res;

}