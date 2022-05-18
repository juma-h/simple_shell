char *wordlist_to_str(struct word_s *word);
void delete_char_at(char *str, size_t index);
int is_name(char *str);
size_t find_closing_quote(char *data);
size_t find_closing_brace(char *data);
char *substitute_str(char *s1, char *s2, size_t start, size_t end);
int substitute_word(char **pstart, char **p, size_t len, char *(func)(char *), int add_quotes);
