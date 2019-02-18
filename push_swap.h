/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:02:39 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/18 15:22:56 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{
	int		*nums;
	int		numbers_currently_in;
	char	name;
}				t_stack;

typedef struct	s_mode
{
	_Bool	debug_enabled;
	_Bool	colors_enabled;
}				t_mode;

# define BUFF_SIZE 1

char			*add_instruction(char *current, char *new);
t_stack			*build_stack_from_args(int *argc, char **argv, t_mode *mode);
void			clear_stack(t_stack *s);
void			clear_stacks(t_stack *a, t_stack *b);
void			clear_string_array(int size, char **tab);
long			ft_atol(char *str);
int				get_median(t_stack *stack, int nbelem);
void			get_mode(int *argc, char **argv, t_mode *mode);
int				get_next_line_single_fd(const int fd, char **line);
t_stack			*initialize_empty_stack(int size);
_Bool			is_sorted(t_stack *stack);
int				ok_to_keep_parting(t_stack *stack, int med, int nb,
					_Bool right);
void			optimize_commands(char **commands);
_Bool			perform_command(char *command, t_stack *a_stack,
					t_stack *b_stack);
_Bool			perform_swaps(char *command, t_stack *a_stack,
					t_stack *b_stack);
_Bool			perform_rotations(char *command, t_stack *a_stack,
					t_stack *b_stack);
void			push_from_to(t_stack *from, t_stack *to);
int				quicksort_left(t_stack *a_stack, t_stack *b_stack, int nb,
					char **commands);
int				quicksort_right(t_stack *a_stack, t_stack *b_stack, int nb,
					char **commands);
void			rotate_stack(t_stack *stack, short direction);
void			sort_little_stack(t_stack *a_stack, t_stack *b_stack,
					char **commands);
int				get_word_count(char const *s, char c);
void			swap_stack_top(t_stack *stack);

#endif
