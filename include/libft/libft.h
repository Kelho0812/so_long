/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorteixe <jorteixe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:47 by jorteixe          #+#    #+#             */
/*   Updated: 2023/11/03 14:16:39 by jorteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

long			ft_atoi_change(const char *str);

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}	t_list;

//Adds a new element to the beginning of a linked list 
//and updates the list pointer to point to the new element.
void			ft_lstadd_front(t_list **lst, t_list *new);
//Creates and returns a new linked list node with the given content.
t_list			*ft_lstnew(void *content);
//Calculates and returns the number of elements in a linked list.
int				ft_lstsize(t_list *lst);
//Returns a pointer to the last element of a linked list.
t_list			*ft_lstlast(t_list *lst);
//Deletes a single element from a linked list, 
//invoking the provided 'del' function to free its content.
void			ft_lstdelone(t_list *lst, void (*del)(void*));
//Adds a new element to the end of a linked list and 
//updates the list pointer to include the new element.
void			ft_lstadd_back(t_list **lst, t_list *new);
//Frees and removes all elements from a linked list 
//while applying the provided 'del' function
//to each element's content.
void			ft_lstclear(t_list **lst, void (*del)(void*));
//Iterates through a linked list and 
//applies the provided 'f' function to each element.
void			ft_lstiter(t_list *lst, void (*f)(void *));
//Creates a new linked list by applying the 
//provided 'f' function to each element in the original
//list, and the 'del' function is used to delete
//any allocated content in case of an error.
t_list			*ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *));
//Converts an integer 'n' to a string and returns the resulting character array.
char			*ft_itoa(int n);
//Appends a string 'src' to the end of another string 'dst', 
//ensuring that the total length does not exceed the specified 'size'. 
//It then returns the total length of the concatenated strings.
unsigned int	ft_strlcat(char *dst, const char *src, size_t size);
//Copies a string 'src' to another string 'dst', 
//ensuring that it does not exceed the specified 'size'. 
//It returns the length of the source string, 
//which can be useful for error checking.
unsigned int	ft_strlcpy(char *dst, const char *src, size_t size);
//Splits a string 's' into an array of substrings 
//based on the delimiter 'c' and returns a pointer to that array.
char			**ft_split(char const *s, char c);
//Trims characters specified in the 'set' from the 
//beginning and end of the string 's1', 
//returning a new string with leading and trailing characters removed.
char			*ft_strtrim(char const *s1, char const *set);
//Copies 'n' bytes from the source 'src' to the destination 'dest'.
void			*ft_memcpy(void *dest, const void *src, size_t n);
//Sets the first 'n' bytes of memory pointed to by 's' to the value 'c'.
void			*ft_memset(void *s, int c, size_t n);
//Searches the first 'n' bytes of memory
//pointed to by 's' for the character 'c' 
//and returns a pointer to the first occurrence, or 'NULL' if not found.
void			*ft_memchr(const void *s, int c, size_t n);
//Safely copies 'n' bytes from the source 'src' to the destination 'dest', even
//if the source and destination memory areas overlap.
void			*ft_memmove(void *dest, const void *src, size_t n);
//Allocates memory for an array of 'nmemb' elements, each of 
//'size' bytes, and initializes them to zero.
void			*ft_calloc(size_t nmemb, size_t size);
//Searches for the first occurrence of character 'c' in the string 
//'s' and returns a pointer to that character, or 'NULL' if not found.
char			*ft_strchr(const char *s, int c);
//Searches for the first occurrence of the substring 'to_find' 
//in the string 'str', considering at most 'n' characters,
//and returns a pointer to the substring if found, or 'NULL' if not found.
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
//Searches for the last occurrence of character 'c' in the string 
//'s' and returns a pointer to that character, or 'NULL' if not found.
char			*ft_strrchr(const char *s, int c);
//Duplicates the string 's' and returns a pointer to a newly 
//allocated memory block containing the duplicated string.
char			*ft_strdup(const char *s);
//Creates a new substring from the string s, starting at 
//the specified 'start' index and extending for a maximum of 'len' characters.
//It returns a pointer to the newly created substring.
char			*ft_substr(char const *s, unsigned int start, size_t len);
//Concatenates two strings, 's1' and 's2', and returns a 
//new string containing the combined content.
char			*ft_strjoin(char const *s1, char const *s2);
//Applies the function 'f' to each character in the string 's', 
//providing the character's index,
//and returns a new string containing the changed characters.
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//Calculates and returns the length of the string 'str'.
size_t			ft_strlen(const char *str);
//Converts a string 'str' to an integer and returns the resulting integer 
//value.
int				ft_atoi(const char *str);
//Checks if the given integer 'n' represents an alphanumeric character 
//and returns a non-zero value if true, or zero if false.
int				ft_isalnum(int n);
//Checks if the given integer 'n' represents an alphabetic character
// and returns a non-zero value if true, or zero if false.
int				ft_isalpha(int n);
//Checks if the given integer 'n' represents an ASCII character and 
//returns a non-zero value if true, or zero if false.
int				ft_isascii(int n);
//Checks if the given integer 'n' represents a digit character and 
//returns a non-zero value if true, or zero if false.
int				ft_isdigit(int n);
//Checks if the given integer n represents a printable character 
//(a character that is visible and can be printed),
//and returns a non-zero value if true, or zero if false.
int				ft_isprint(int n);
//Compares the first 'n' bytes of memory in two memory blocks, 's1' and 's2',
// and returns an integer representing their comparison result.
int				ft_memcmp(const void *s1, const void *s2, size_t n);
//Compares the first 'n' characters of two strings, 's1' and 's2', and returns
// an integer representing their comparison result.
int				ft_strncmp(const char *s1, const char *s2, size_t n);
//Converts the character 'ch' to its lowercase equivalent if it is an uppercase 
//letter, otherwise returns the character unchanged.
int				ft_tolower(int ch);
//Converts the character ch to its uppercase equivalent if it is a lowercase
// letter, otherwise returns the character unchanged.
int				ft_toupper(int ch);
//Sets the first 'n' bytes of memory pointed to by 's' to zero (null bytes).
void			ft_bzero(void *s, size_t n);
//Writes the character 'c' to the file descriptor 'fd'.
void			ft_putchar_fd(char c, int fd);
//Writes the string 's' to the file descriptor 'fd',
// NO newline is written at the end.
void			ft_putstr_fd(char *s, int fd);
// Writes the string 's' followed by a newline 
//character to the file descriptor 'fd'.
void			ft_putendl_fd(char *s, int fd);
//Writes the integer 'n' to the file descriptor 'fd'.
void			ft_putnbr_fd(int n, int fd);
//Applies the function 'f' to each character in the string 's', 
//providing the character's index as the first argument to the function.
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif