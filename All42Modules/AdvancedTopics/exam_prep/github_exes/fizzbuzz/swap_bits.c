unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	result;
	int		i;
	unsigned char	left;
	unsigned char	right;

	i = 0;
	result = 0;
	while (i < 4)
	{
		left = (octet >> (4 + i)) & 1;
		right = (octet >> i) & 1;
		result |= (left << i);
		result |= (right << (4 + i));
		i++;
	}
	return (result);
}

unsigned char	swap_bits(unsigned char octet)
{
    unsigned char result;
    unsigned char left;
    unsigned char right;
    int i;

    i = 0;
    result = 0;
    while(i < 4)
    {
        left = (octet >> (4 + i)) & 1;
        right = (octet >> i) & 1;
        result |= (left << i);
        result |= (right << (4 + i));
        i++;
    }
    return (result);
}