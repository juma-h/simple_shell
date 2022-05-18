char   *strchr_any(char *string, char *chars);
char   *quote_val(char *val, int add_quotes);
int     check_buffer_bounds(int *count, int *len, char ***buf);
void    free_buffer(int len, char **buf);
