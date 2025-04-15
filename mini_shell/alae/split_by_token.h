#ifndef SPLIT_BY_TOKEN_H
#define SPLIT_BY_TOKEN_H

typedef struct s_split_data
{
	char		*s;
	char		*sep;
	char		*special_sep;
	char		ch;
	int			i;
	int			first_time;
}				t_split_data;

#endif