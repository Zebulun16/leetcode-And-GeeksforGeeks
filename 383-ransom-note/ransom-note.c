bool canConstruct(char* ransomNote, char* magazine) {
    int count[256] = {0};
    int i;

    for(i = 0; magazine[i] != '\0'; i++)
    {
        count[(unsigned char)magazine[i]]++;
    }

    for(i = 0; ransomNote[i] != '\0'; i++)
    {
        if(count[(unsigned char)ransomNote[i]] == 0)
        {
            return false;
        }

        count[(unsigned char)ransomNote[i]]--;
    }

    return true;
}