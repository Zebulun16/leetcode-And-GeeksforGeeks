typedef struct
{
    long long key;
    int freq;
    int used;
} Entry;

int hashIndex(long long key, int capacity)
{
    long long index = key % capacity;

    if(index < 0)
        index += capacity;

    return (int)index;
}

int getFrequency(Entry *map, int capacity, long long key)
{
    int index = hashIndex(key, capacity);

    while(map[index].used)
    {
        if(map[index].key == key)
            return map[index].freq;

        index = (index + 1) % capacity;
    }

    return 0;
}

void insert(Entry *map, int capacity, long long key)
{
    int index = hashIndex(key, capacity);

    while(map[index].used && map[index].key != key)
    {
        index = (index + 1) % capacity;
    }

    if(map[index].used)
    {
        map[index].freq++;
    }
    else
    {
        map[index].key = key;
        map[index].freq = 1;
        map[index].used = 1;
    }
}
int subarraySum(int* nums, int numsSize, int k) {
    int capacity = 2 * numsSize + 3;

    Entry *map = calloc(capacity, sizeof(Entry));

    if(map == NULL)
        return 0;

    long long sum = 0;
    int count = 0;

    // Store initial prefix sum
    insert(map, capacity, 0);

    for(int i = 0; i < numsSize; i++)
    {
        sum += nums[i];

        // Find previous prefix sum
        count += getFrequency(map, capacity, sum - k);

        // Store current prefix sum
        insert(map, capacity, sum);
    }

    free(map);

    return count;
}