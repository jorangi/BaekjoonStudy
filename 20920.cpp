#include <stdio.h>
#include <malloc.h>

#define MY_SIZE 100003

struct node {
  char word[11];
  int count;
  node *next;
};

node * hashtable[MY_SIZE];

int my_strlen(char *str)
{
  char *c = str;
  while(*c) c++;
  return c-str;
}

void my_strcpy(char *dst, char *src)
{
  while(*dst++ = *src++);
}

int my_strcmp(char *s1, char *s2)
{
  while(*s1 && (*s1 == *s2))
  {
    s1++; s2++;
  }
  return *s1-*s2;
}

unsigned int make_hash(char *str)
{
  unsigned int h = 5381;
  while(*str)
    h = ((h<<5)+h) + *str++;
  return h % MY_SIZE;
}

node* find_hash(char *str, unsigned int h)
{
  node *p = hashtable[h];
  while(p)
  {
    if(my_strcmp(p->word, str) == 0)
      return p;
    else
      p = p->next;
  }
  return NULL;
}

int insert_hash(char *str)
{
  unsigned int h = make_hash(str);
  node *p = find_hash(str, h);
  if(p == NULL)
  {
    node *n = (node*)malloc(sizeof(node));
    n->count = 1;
    my_strcpy(n->word, str);
    n->next = hashtable[h];
    hashtable[h] = n;
    return 1;
  }
  else
  {
    p->count++;
    return 0;
  }
}

int get_count_hash(char *str)
{
  unsigned int h = make_hash(str);
  node *p = find_hash(str, h);
  return p->count;
}

char temp[100001][11];

int my_compare(char *s1, char *s2)
{
  int c1 = get_count_hash(s1);
  int c2 = get_count_hash(s2);
  if(c1 != c2) return c2-c1;

  int l1 = my_strlen(s1);
  int l2 = my_strlen(s2);
  if(l1 != l2) return l2-l1;

  return my_strcmp(s1, s2);
}

void merge(char list[][11], int left, int mid, int right)
{
  int i=left, j=mid+1, idx=left;

  while(i<=mid && j<=right)
  {
    if(my_compare(list[i], list[j]) <= 0)
      my_strcpy(temp[idx++], list[i++]);
    else
      my_strcpy(temp[idx++], list[j++]);
  }
  while(i<=mid)
    my_strcpy(temp[idx++], list[i++]);
  while(j<=right)
    my_strcpy(temp[idx++], list[j++]);
  for(i=left; i<=right; i++)
    my_strcpy(list[i], temp[i]);
}

void mergesort(char list[][11], int left, int right)
{
  if(left<right)
  {
    int mid = (left+right)/2;
    mergesort(list, left, mid);
    mergesort(list, mid+1, right);
    merge(list, left, mid, right);
  }
}

int main()
{
  int N, M;
  int i;
  char str[11];
  char result[100001][11];
  int idx = 0;

  scanf("%d %d", &N, &M);
  for(i=0; i<N; i++)
  {
    scanf("%s", str);
    if(my_strlen(str) >= M)
    {
      if(insert_hash(str) == 1)
        my_strcpy(result[idx++], str);
    }
  }

  mergesort(result, 0, idx-1);

  for(i=0; i<idx; i++)
    printf("%s\n", result[i]);

  return 0;
}