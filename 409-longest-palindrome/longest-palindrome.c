int longestPalindrome(char* s) {
    int count[256] = {0};
    int sum = 0;
    int odd = 0;

    for(int i = 0; s[i] != '\0'; i++)
    {
        count[(unsigned char)s[i]]++;
    }

    for(int i = 0; i < 256; i++)
    {
        if(count[i] % 2 == 0)
        {
            sum += count[i];
        }
        else
        {
            sum += count[i] - 1;
            odd = 1;
        }
    }

    if(odd)
    {
        sum++;
    }

    return sum;
}