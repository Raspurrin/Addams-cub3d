# Libft 

### Index:
+ [The library](#the-library)
+ [Function comments](#function-comments)
+ [Mandatory function from the subject + bonus:](#mandatory-function-from-the-subject--bonus)
+ [Custom functions:](#custom-functions) 

## The library
I made my own library in which I recreated functions from the standard C library. For my school, we have to make everything from scratch, so we can learn from a low level, from the ground up. In further projects we are allowed to reuse this and we can keep adding our own custom functions to it, as well as other projects. 

In this project we learn about many concepts: creating a static library, using a makefile and a header, data type conversion, modulo, recursion, dynamic memory allocation, stack vs heap, char pointers vs char arrays, void pointers, memory functions, function pointers, file descriptors, 2D array or an array of strings, typecasting, guards, structs and linked lists.

## Doxygen comments

In my [header](https://github.com/Raspurrin/libft/blob/main/includes/libft.h) you can find descriptions of all the functions!
You can see these descriptions whenever you mouse over them. I highly recommend keeping your code well documented, so you can understand your code looking back on it years from now and someone else could potentially as well. 

<img src="https://user-images.githubusercontent.com/13866954/179558332-e459556f-263e-4af2-8714-00739c7a3739.png" height="120"/> <img src="https://user-images.githubusercontent.com/13866954/179558352-512cbaf7-ac23-423e-9999-29131349ae67.png" height="120"/>

## Mandatory function from the subject + bonus:
| String | Ascii check | Memory | Linked list | Write fd| Conversion |Function pointer| 
| --- | --- | --- | --- | --- | --- | -- |
| strchr | isalpha  | memchr |  lstnew | putchar_fd  | putnbr_fd | strmapi| 
| strrchr | isdigit  | memcmp  |  lstadd_front | putstr_fd | itoa | striteri| 
| strncmp | isalnum  |  memset |  lstsize | putendl_fd | atoi |
| strdup | isascii  | bzero | lstadd_back | | |
| strlcpy | isprint  | memcpy  | lstlast | | |
| substr | toupper | memmove |  strlcat | |
| strjoin |  tolower | calloc |  | | |
|  strtrim | | |  | | |
|  strnstr | | |  | | |
|  strlen | | |  | | |
|  split | | |  | | |

## Custom functions: 
+ **Free_2d_guard** - frees a 2D array and protects against double freeing. 
+ **Free_2d** - frees a 2D array. 
+ **abs** - converts a number to a positive if it's a negative number. 
+ **atoll** - converts a string to an integer, but in a long long format
+ **intlen** - counts the length of an integer
+ **isspace** - Checks whether the character is a white-space character (' ', '\n', '\t', '\v', '\f', '\r')
+ **pow** - calculates the power of a number. 
+ **realloc** - dynamically allocates something that was allocated previously, with a different size. 
+ **strlen_ignore** - Counts the length of a string, ignoring a specified character.
+ **wcount** - counts parts in a string, seperated by a specified delimiter. 
+ **getncount** - Counts the occurances of a specified char in a string. 
+ **print_2d_fd** - prints a 2D string on a specified file descriptor. 
+ I also include my get_next_line and printf in my library now. 
