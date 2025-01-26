/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:34:53 by hshi-yun          #+#    #+#             */
/*   Updated: 2025/01/26 18:43:44 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./libft/libft.h"

/*
    Reference: https://www.programiz.com/dsa/quick-sort
*/

void    swap(int *a, int *b)
{
    int     temporary;

    temporary = *a;
    *a = *b;
    *b = temporary;
}

int     partition(int array[], int low, int high)
{
    int     pivot;
    int     i;
    int     j;
    
    pivot = array[high];
    i = low - 1;
    j = low;
    while (j < high)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
        j++;
    }
    swap(&array[i + 1], &array[high]);
    return (i+1);
}

void    quick_sort(int array[], int low, int high)
{
    int     pivot_element;
    
    if (low < high)
    {
        pivot_element = partition(array, low, high);
        quick_sort(array, low, pivot_element - 1);
        quick_sort(array, pivot_element + 1, high);    
    }
}