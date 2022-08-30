/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dritsema <dritsema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 12:51:11 by dritsema      #+#    #+#                 */
/*   Updated: 2022/08/21 18:42:15 by dritsema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// ############### Array ###############

/**
 * @brief Takes a NULL terminated 2d array and returns
 * the amount of arrays in it.
 *
 * @param pointer The 2d array to measure.
 * @return The total "length" of the 2d array. */
int				ft_2darlen(void **pointer);

// ############### Ascii ###############

/**
 * @brief Tests for any character
 * for which ft_isalpha() or ft_isdigit() is true.
 * @param c The character to test.
 * @return 1 if 'c' is an alphanumerical character, 0 otherwise. */
int				ft_isalnum(int c);
/**
 * @brief Tests for any character for which
 * ft_isupper() or ft_islower() is true.
 * @param c The character to test.
 * @return 1 if 'c' is an alphabetical character, 0 otherwise. */
int				ft_isalpha(int c);
/**
 * @brief Tests for an ASCII character, which is
 * any character between 0 and decimal 127 inclusive.
 * @param c The character to test.
 * @return 1 if 'c' is an ASCII character, 0 otherwise. */
int				ft_isascii(int c);
/**
 * @brief Tests for a decimal digit character.
 * @param c The character to test.
 * @return 1 if 'c' is a decimal digit character, 0 otherwise. */
int				ft_isdigit(int c);
/**
 * @brief Tests for any printing character, including space.
 * @param c The character to test.
 * @return 1 if 'c' is a printable character, 0 otherwise. */
int				ft_isprint(int c);
/**
 * @brief Tests for whitespace characters.
 * @param c The character to test.
 * @return 1 if 'c' is a whitespace character, 0 otherwise. */
int				ft_iswhitespace(char c);

// ############### Convert ###############

/**
 * @brief The atoi() function converts the initial portion of the
 * string pointed to by str to int representation.
 * @param str The string to convert.
 * @return The converted integer value. */
int				ft_atoi(const char *str);
/**
 * @brief The ft_hextoi() function converts the initial portion of the
 * string pointed to by str, if its hexadecimal, to int representation.
 * Works for "0xFF" and "FF" formats.
 * @param str The string to convert.
 * @return The converted integer value. */
int				ft_hextoi(const char *str);
/**
 * @brief Allocates and returns a string representing the
 * integer received as an argument.
 * @param n The integer to convert.
 * @return The string representing the integer.
 * NULL if the allocation fails. */
char			*ft_itoa(int n);
/**
 * @brief Converts an upper-case letter to the corresponding lower-case letter.
 * @param c The character to convert.
 * @return If the argument is an upper-case letter, the function
 * returns the corresponding lower-case letter if there is one.
 * Otherwise, the argument is returned unchanged. */
int				ft_tolower(int c);
/**
 * @brief Converts a lower-case letter to the corresponding upper-case letter.
 * @param c The character to convert.
 * @return If the argument is a lower-case letter,
 * the function returns the corresponding upper-case letter if there is one.
 * Otherwise, the argument is returned unchanged. */
int				ft_toupper(int c);

// ############### get_next_line ###############

/**
 * @brief Returns a line read from a
 * file descriptor.
 * @param fd File descriptor to read from.
 * @return Newly allocated string containing the next line. */
char			*get_next_line(int fd);

// ############### List ###############

/**
 * @brief A basic linked list structure.
 * @param content Void pointer to the data contained in the list.
 * @param s_list Pointer to the next link in the list. */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
/**
 * @brief Adds the node ’lstnew’ at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list. */
void			ft_lstadd_back(t_list **lst, t_list *lstnew);
/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param lstnew The address of a pointer to the node to be added
 * to the list. */
void			ft_lstadd_front(t_list **lst, t_list *lstnew);
/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free().
 * Pointer to the list will be set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
 * the content of the node. */
void			ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief Takes a node, frees the memory of the node’s content
 * using the function ’del’ and then frees the node.
 * The memory of ’next’ will not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content. */
void			ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list. */
void			ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return Last node of the list. */
t_list			*ft_lstlast(t_list *lst);
/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.  Creates a new
 * list resulting of the successive applications of
 * the function ’f’.  The ’del’ function is used to
 * delete the content of a node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete
 * the content of a node if needed.
 * @return The new list.
 * NULL if the allocation fails. */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
/**
 * @brief Allocates and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL.
 * @param content The content to create the node with.
 * @return The new node. */
t_list			*ft_lstnew(void *content);
/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list */
int				ft_lstsize(t_list *lst);

// ############### Memory ###############

/**
 * @brief Writes n zeroed bytes to the string s. If n is zero, do nothing.
 * @param s String to write to.
 * @param n Amount to write. */
void			ft_bzero(void *s, size_t n);
/**
 * @brief Allocates enough space for count objects that are size bytes
 * of memory each and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero.
 * @param count Amount of objects to allocate.
 * @param size Byte size of objects to allocate.
 * @return Pointer to newly allocated memory. */
void			*ft_calloc(size_t count, size_t size);
/**
 * @brief Locates the first occurrence of c
 * (converted to an unsigned char) in string s.
 * @param s The string to search through.
 * @param c The character to look for.
 * @param n The amount of bytes to check.
 * @return Pointer to the byte located,
 * or NULL if no such byte exists within n bytes. */
void			*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief Compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n Amount of bytes to compare.
 * @return Zero if the two strings are identical,
 * otherwise returns the difference between the first two differing bytes.
 * Zero-length strings are always identical. */
int				ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief Copies n bytes from memory area src to memory area dst.
 * If dst and src overlap, behavior is undefined (Try ft_memmove).
 * @param dst The memory to copy to.
 * @param src The memory to copy from.
 * @param n The amount of bytes to copy.
 * @return The original value of dst (pointer). */
void			*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * @brief Copies len bytes from string src to string dst.
 * The two strings may overlap;
 * the copy is always done in a non-destructive manner.
 * @param dst The memory to copy to.
 * @param src The memory to copy from.
 * @param len The amount of bytes to copy.
 * @return The original value of dst (pointer). */
void			*ft_memmove(void *dst, const void *src, size_t len);
/**
 * @brief Writes len bytes of value c
 * (converted to an unsigned char) to the string b.
 * @param b The string to write to.
 * @param c The value to write with.
 * @param len The amount of bytes to write.
 * @return The pointer b. */
void			*ft_memset(void *b, int c, size_t len);

// ############# Miscellaneous #############

/**
 * @brief Returns the absolute value of an integer.
 *
 * @param num integer to get value from.
 * @return unsigned int corresponding to absolute value. */
unsigned int	ft_abs(int num);
/**
 * @brief Counts the amount of decimal digits in an integer.
 * This can be used to determine how many bytes an integer
 * would take if you convert it to an ascii string.
 * @param num The integer to count the digits for.
 * @return The amount of decimal digits in the integer.
 */
int				ft_numlen(int num);

// ############### ft_printf ###############

/**
 * @brief A function that mimic's the original printf().
 * But with far less features.
 * @param s The string to parse.
 * @param ... The individual arguments to insert into the string.
 * @return The amount of characters printed. */
int				ft_printf(const char *s, ...);

// ############### Put ###############

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write. */
void			ft_putchar_fd(char c, int fd);
/**
 * @brief Outputs the string ’s’ to the given file descriptor
 * followed by a newline.
 * @param s The string to output.
 * @param fd The file descriptor on which to write. */
void			ft_putendl_fd(char *s, int fd);
/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write. */
void			ft_putnbr_fd(int n, int fd);
/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write. */
void			ft_putstr_fd(char *s, int fd);

// ############### String ###############

/**
 * @brief Allocates and returns an array of strings obtained
 * by splitting ’s’ using the character ’c’ as a delimiter.
 * The array must end with a NULL pointer.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails. */
char			**ft_split(char const *s, char c);
/**
 * @brief locates the first occurrence of c
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered to be
 * part of the string; therefore if c is `\0',
 * the function locates the terminating `\0'.
 * @param s The string to look through.
 * @param c The character to locate.
 * @return Pointer to the located character,
 * or NULL if the character does not appear in the string. */
char			*ft_strchr(const char *s, int c);
/**
 * @brief Allocates sufficient memory for a copy of the string s1,
 * does the copy, and returns a pointer to it.
 * The pointer may subsequently be used as an argument to the function free().
 * @param s1 The string to copy.
 * @return Pointer to the copied string. */
char			*ft_strdup(const char *s1);
/**
 * @brief Applies the function ’f’ on each character of the string 's',
 * passing its index as first argument.
 * Each character is passed by address to ’f’ to be modified if necessary.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character. */
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief Allocates and returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’.
 * Frees 's1' before returning.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char			*ft_strjoin_free(char *s1, char const *s2);
/**
 * @brief Allocates and returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails. */
char			*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Appends string src to the end of dst.
 * It will append at most dstsize - strlen(dst) - 1 characters.
 * It will then NUL-terminate,
 * unless dstsize is 0 or the original dst string was longer than dstsize.
 * If the src and dst strings overlap, the behavior is undefined.
 * @param dst The string to add upon.
 * @param src The string to append.
 * @param dstsize The allocated size of dst.
 * @return The total length of the string to be created.
 * (This may differ from the size of the string actually created) */
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
/**
 * @brief Copies up to dstsize - 1 characters from the string src to dst,
 * NUL-terminating the result if dstsize is not 0.
 * @param dst The memory to copy to.
 * @param src The string to copy.
 * @param dstsize The size of the dst memory.
 * @return The total length of the string to be created.
 * (This may differ from the size of the string actually created) */
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**
 * @brief The ft_strlen() function computes the length of the string s.
 * @param s The string to measure.
 * @return size_t The length of the string. */
size_t			ft_strlen(const char *s);
/**
 * @brief Applies the function ’f’ to each character of the string ’s’,
 * and passing its index as first argument to create a new string (with malloc)
 * resulting from successive applications of ’f’
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails. */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Lexicographically compare the null-terminated strings s1 and s2.
 * compares not more than n characters.
 * Designed for comparing strings rather than binary data,
 * characters that appear after a `\0' character are not compared.
 * @param s1 First String to compare against the second.
 * @param s2 Second string to compare against the first.
 * @param n The length to compare them.
 * @return An integer greater than, equal to, or less than 0,
 * according as the string s1 is greater than, equal to,
 * or less than the string s2.  The comparison is done using
 * unsigned characters. */
int				ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief Locates the first occurrence of the null-terminated string
 * needle in the string haystack,
 * where not more than len characters are searched.
 * Characters that appear after a `\0' character are not searched.
 * @param haystack The 'haystack' to look through.
 * @param needle The 'needle' to find.
 * @param len The length to look through.
 * @return Pointer to the first occurence in haystack. */
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
/**
 * @brief Locates the first occurrence of c
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered
 * to be part of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.
 * @param s The string to search through.
 * @param c The character to find.
 * @return Pointer to the located character,
 * or NULL if the character does not appear in the string. */
char			*ft_strrchr(const char *s, int c);
/**
 * @brief Allocates and returns a copy of ’s1’ with the characters specified
 * in ’set’ removed from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param s2 The reference set of characters to trim.
 * @return The trimmed string.
 * NULL if the allocation fails. */
char			*ft_strtrim(char const *s1, char const *s2);
/**
 * @brief Allocates and returns a substring
 * from the string ’s’.
 * The substring begins at index ’start’ and is of
 * maximum size ’len’.
 * @param s The string to make a substring from.
 * @param start The starting index in string 's'.
 * @param len The maximum length of the substring to return.
 * @return The newly created substring of 's'. */
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif /* LIBFT_H */
