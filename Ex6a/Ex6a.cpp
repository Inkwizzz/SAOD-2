int replace(char ch_old, char ch_new) 
{
    int count = 0;
    {
        if (ch == ch_old) 
        {
            ch = ch_new;
            count++;
        }
    }
    return count;
}