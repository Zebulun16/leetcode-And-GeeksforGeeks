char findTheDifference(char* s, char* t) {
    char result = 0;
    for(int i=0;s[i] != '\0';i++)
    {
       result = result ^ s[i];
    }
    for(int j=0;t[j] != '\0';j++)
    {
       result = result ^ t[j];
    }
    return result;
}