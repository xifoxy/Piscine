/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:30:36 by sgang             #+#    #+#             */
/*   Updated: 2020/07/15 21:47:42 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int dp[3];
	int idx;
	int ret;

	dp[0] = 1;
	dp[1] = 1;
	if (index < 3)
		return (index < 0 ? -1 : 1);
	
	idx = 2;
	while (++idx <= index)
	{
		dp[2] = dp[1] + dp[0];
		dp[0] = dp[1];
		dp[1] = dp[2];
	}
	return (dp[2]);
}
