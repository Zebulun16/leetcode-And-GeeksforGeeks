bool isPalindrome(int x) {
    unsigned int ans = x;
    long long rev = 0;
    while(x)
    {
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    if(ans == rev)
        return true;
    else
        return false;
}