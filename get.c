int get_bit(unsigned long int n, unsigned int index)
{
   if (index >= sizeof(unsigned long int) * 8)
        return -1;
    return (n & (1UL << index)) != 0;
}
