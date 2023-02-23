/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:08:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/08/25 17:56:33 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	<readline/readline.h>
# include	<readline/history.h>
# include	<signal.h>
# include	<dirent.h>

typedef enum s_token
{
	APPENDD,
	OUTFILEE,
}t_token;

typedef enum s_type
{
	NAADA,
	HERDO,
	INPU
}t_types;

typedef enum s_open
{
	ZERO,
	INFF,
	OUFF
}t_open;

typedef struct s_var
{
	char			*key;
	char			*value;
	int				len;
	char			*content;
	struct s_var	*next;
}	t_var;

typedef struct s_glo
{
	int				exit;
	int				k;
	int				ffdd;
}	t_glo;

typedef struct s_mini
{
	char			**inf;
	char			**ouf;
	char			**val;
	t_token			*otype;
	int				itype;
	char			**her;
	int				j;
	int				*open;
	int				op;
	int				oo;
	int				ii;
	int				hr;
	int				hflag;
	struct s_mini	*next;
}	t_mini;

typedef struct t_list
{
	char			*line;
	char			*line2;
	char			*valo;
	int				error;
	int				errorx;
	int				doll;
	int				ext;
	int				wn;
	int				l;
	int				k;
	int				i;
	t_var			*var;
	t_mini			*m;
	int				on;
	struct t_list	*nextt;
}	t_list;

typedef struct s_pipe
{
	char	**paths;
	char	*path;
	char	**envr;
	int		size;
	int		i;
	int		*pid_proc;
	int		*pip_fd;
	int		fd[2];
	int		save_inp_out[2];
}	t_pipe;

t_glo	g_glo;

void	han_her(int num);
t_pipe	*pi_init(t_pipe *pi, t_list *b);
void	signalat(void);
void	handler(int num);
void	freee_more(t_mini *m);
int		skip_quots(char *str, int i, char sign);
t_list	*qts_help(t_list *p);
int		check_piipe(t_list *p);
int		pr_wnb2(char *str, char c);
int		pr_wnbb(char *str, char c);
t_mini	*goto_last(t_mini *m);
t_mini	*addlast_node(t_mini **m, t_mini *new);
t_mini	*new_node(t_list *p);
char	*put_char(char *s, char c);
int		skip_space(char *str, int i);
int		check_cmd(char c, int i);
t_list	*grep_command(t_list *p);
t_list	*grep_files(t_list *p);
int		single_inqts(char *line);
int		double_inqts(char *line);
t_list	*qts_check(t_list *p);
int		struct_init(t_list *p);
t_list	*grep_files(t_list *p);
t_list	*grep_cmarg(t_list *p);
t_list	*grep_cmddd(t_list *p);
t_list	*grep_cmdqts(t_list *p);
t_list	*north_face(t_list *p);
t_list	*south_face(t_list *p);
t_list	*north_errors(t_list *p);
t_list	*south_errors(t_list *p);
t_list	*grep_file(t_list *p);
int		pr_strlen(char *str);
char	*pr_strdup( char *s1);
t_list	*pipe_pipe(t_list *p);
t_list	*l_quotes(t_list *p);
int		pr_counterr(char *str, char c);
int		pr_isalnum(int c);
t_list	*grep_dollar(t_list *p);
int		pr_strncmpp(char *str1, char *str2);
int		check_dollar(t_list *p, char *dollo);
t_list	*parser(t_var *var, t_list *p);
t_list	*dollar_init(t_list *p);
t_list	*dollar_init1(t_list *p);
t_list	*dollar_init2(t_list *p);
int		check_ffile(char c);
int		check_mfile(char c);
t_list	*struct_builtins(t_list *p, t_var *var);
int		*wnbb_beta(int *ij, char *str);
t_list	*struct_beta(t_list *p);
t_list	*dollar_help(t_list *p);
int		pr_alph(int c);
int		wnb_check(char *str, int *ij, char c);
t_list	*erorat(char *str, t_list *p);
t_list	*north_help(t_list *p, int type);
t_list	*north_help2(t_list *p, int type);
t_list	*north_help22(t_list *p);
t_list	*south_inpu(t_list *p);
t_list	*south_inpu2(t_list *p);
t_list	*south_herdo(t_list *p);
t_list	*south_herdo2(t_list *p);
t_list	*parser_v2(t_list *p);
t_mini	*sf_salaw(t_mini *tmp, t_list *p);
t_list	*south_north(t_list *p);
t_list	*dollar_init_h(t_list *p);
t_list	*dollar_init1_h(t_list *p);
t_list	*dollar_init2_h(t_list *p);
t_list	*grep_dollar_h(t_list *p);
int		check_dollar_h(t_list *p, char *dollo);
t_list	*dollar_help_h(t_list *p);
void	free_the_m(t_mini *m);
void	free_the_pi(t_pipe *p);

//I'm here =============>

void	cpy_env(t_var **t_env, t_var **t_exp, char **env);
void	update_pwd_env_exp(t_var **env, t_var **exp);
void	ft_update_old_exp(t_var **var);
void	ft_update_exp(t_var **var);

//Utils export
int		check_name_key(char *key);
int		is_existed(t_var **list, char *key);
void	write_again(t_var **list, char *key, char *value);
void	search_key(t_var **list, char *key_val);
void	print_exp(t_var *tmp);
void	sort_env(t_var **t_exp);
void	key_value_only_equal(t_var **t_env, t_var **t_exp, char *key_val);
void	key_value_plus_equal_in(t_var **list, char *key_val);
int		key_value_plus_equal(t_var **t_env, t_var **t_exp, \
char *key_val, int len);

//Utils Builtins
void	no_need_proccess(t_pipe *pi, t_list *b, t_var **t_env, t_var **t_exp);
void	ft_is_directory(char *value);
void	need_new_proccess(t_var **var, t_pipe *pi, t_list *b);

//Get_Paths
char	*cmdwpath(t_var **var, t_list *b);
void	ft_close(t_pipe *pi);

//File ft_builtins
void	builtins(t_var **t_env, t_var **t_exp, t_list *b);
int		check_builtins(char *cmd);
int		other_cmds(t_pipe *pi, t_list *b, t_var **t_env, t_var **t_exp);
void	my_envr(t_var **t_env, t_pipe *pi);

//Her_doc
int		her_doc(t_list *b, t_pipe *pi, t_var *t_env);

//Pipex
int		ft_multiple_node(t_pipe *pi, t_list *b, t_var **t_env, t_var **t_exp);
void	ft_one_node(t_pipe *pi, t_list *b, t_var **t_env, t_var **t_exp);
int		ft_connect_proccess(t_pipe *pi);

//Redirection
int		count_files(char **files);
int		ft_redirection(t_var **t_env, t_pipe *pi, t_list *b);

//Builtins
void	ft_echo(t_list *b);
void	ft_cd(t_list *b, t_var **t_env, t_var **exp);
char	*ft_pwd(void);
void	ft_env(t_var **var);
void	ft_exit(t_list *b);
void	ft_unset(t_var **t_env, t_var **t_exp, t_list *b);
void	ft_export(t_var **t_env, t_var **t_exp, t_list *b);

//Execution
void	execution(t_var **t_env, t_var **t_exp, t_list *b);

//Utils libft
void	ft_err(char *minishell, char *name, char *msg, int exit);
void	ft_putstr_fd(char *s, int fd);
int		ft_isalpha(int c);
int		ft_isalphanum(int c);
char	*ft_itoa(int n);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
char	**ft_split(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_len(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);
t_var	*ft_lstnew(char *content);
void	ft_lstadd_back(t_var **lst, t_var *new);
void	ft_lstadd_front(t_var **lst, t_var *new);
t_var	*ft_lstlast(t_var *lst);
int		ft_lstsize(t_mini *m);
void	delete_node_in_list(t_var **list, char *key);

void	the_free(char **str);
void	free_the_m(t_mini *m);
int		herror(char *str);
char	*ft_access(char **str);
char	*one_line(char *path, char *str, char *sstr);

// get Path
char	*get_pathss(t_var *env, char *cmd);
void	key_value(t_var **t_env, t_var **t_exp, char *key_val);
void	ft_first_and_last_nodes(t_pipe *pi, t_list *b);
void	ft_middle_nodes(t_pipe *pi, t_list *b);
int		ft_strncmp( char *str1, char *str2, size_t n);

void	free_e(t_var **var);

#endif