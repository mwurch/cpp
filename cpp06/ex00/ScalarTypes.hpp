#ifndef SCALARTYPES_HPP
#define SCALARTYPES_HPP

typedef enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

typedef struct s_info
{
		char	c;
		int		i;
		float	f;
		double	d;
		type	type;

} t_info;

#endif