#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

#define NOT_SORTED 0
#define SORTED 1
#define SUCCESS 1
#define FAIL 0
#define TRUE 1
#define FALSE 0

typedef struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_linkedlist
{
	struct s_node *head;
	struct s_node *tail;
	int size;
} t_linkedlist;

typedef struct s_all
{
	t_linkedlist *stackA;
	t_linkedlist *stackB;
	int arr[1000];
	int size;
	int flag;
} t_all;

typedef struct s_number
{
	int a;
	int b;
	int c;
	int i;
	int j;
	int ra_call;
	int rb_call;
	int pa_call;
	int pb_call;
	int pivot;
} t_num;

char **ft_malloc_error(char **dst);
int ft_count_words(const char *s, char c);
char **ft_size_words(const char *s, char c, char **dst, int i);
void ft_do(const char *s, char **dst, char c, int i);
char **ft_split(const char *s, char c);
int ft_isdigit(char *s);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlen(const char *str);
char *ft_strjoin(char const *s1, char const *s2);
int ft_atoi(const char *str, int *flag);

void lstinit(t_linkedlist *lst);
t_node *lstnew(int data);
void add(t_node *currNode, t_node *newNode);
t_node *getLast(t_linkedlist *lst);
t_node *getFirst(t_linkedlist *lst);
void addFront(t_linkedlist *lst, t_node *newNode);
void addBack(t_linkedlist *lst, t_node *new_node);
void addNIndex(t_linkedlist *lst, t_node *new_node, int n);
int count(t_linkedlist lst);
t_node *search(t_node *head, const int data);
void showAll(t_node *head);
int delOne(t_linkedlist *lst, t_node *del);
int delFront(t_linkedlist *lst);
void delLast(t_linkedlist *lst);
void delSearch(t_linkedlist *lst, const int data);
void delAll(t_linkedlist *lst);

void exceptional_AB(t_linkedlist *stackA, t_linkedlist *stackB, int r);
void exceptional_BA(t_linkedlist *stackA, t_linkedlist *stackB, int r);
void checkDouble(t_all *all, int i, int j, int c);
void error_type(int flag);
int parse_numbers(int ac, char **av, t_all *all);
int is_sorted(t_linkedlist *stack, int r);
int is_empty(t_all *all);

void only_threeNumber(t_linkedlist *stackA);
void only_fourNumber(t_linkedlist *stackA, t_linkedlist *stackB);
void only_fiveNumber(t_all *all);
void two_number(t_linkedlist *stackA);
void threeNumber(t_linkedlist *stackA);
void threeNumber2(t_linkedlist *stack, t_num *var_ptr);
void fourNumber(t_linkedlist *stackA, t_linkedlist *stackB);
void fiveNumber(t_linkedlist *stackA, t_linkedlist *stackB);
void A_to_B(t_all *all, int r);
void B_to_A(t_all *all, int r);

int max(int a, int b);
int min(int a, int b);
int min_five(t_linkedlist *stack, int r);
int max_five(t_linkedlist *stack);
void find_two_low_nb(t_all *all, t_num *tmp);
void bubble_sort(t_all *all, int r);
int select_pivot(t_all *all, t_linkedlist *stack, int r);
void number_init(t_num *number);

void sa(t_linkedlist *stackA);
void sb(t_linkedlist *stackB);
void ss(t_linkedlist *stackA, t_linkedlist *stackB);
void ra(t_linkedlist *stackA);
void rb(t_linkedlist *stackB);
void rr(t_linkedlist *stackA, t_linkedlist *stackB);
void rra(t_linkedlist *stackA);
void rrb(t_linkedlist *stackB);
void rrr(t_linkedlist *stackA, t_linkedlist *stackB);
void pa(t_linkedlist *stackA, t_linkedlist *stackB);
void pb(t_linkedlist *stackA, t_linkedlist *stackB);

#endif
