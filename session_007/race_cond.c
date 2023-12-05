Found easy way to introduce race - where x is global 

static void *
my_thread(void *data)
{
        while(1) {
                int expected = x + 1;
                x++;
                if (expected != x) {
                        printf("X(%d) is not expected(%d)\n", x, expected);
                        exit(0);
                }
        }

        return NULL;
}
