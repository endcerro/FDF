/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:12:27 by edal--ce          #+#    #+#             */
/*   Updated: 2021/08/02 17:21:53 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void draw(t_contr *contr)
{

}

void plotLineLow(t_contr *contr, int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0)
    {    
    	yi = -1;
        dy = -dy;
    }

    int D = (2 * dy) - dx;
    int y = y0;

    int x = x0;
    while (x < x1)
    {
    	printf("Sending %d %d\n", x, y);
    	p_px(contr, x, y, 0x00FF00);
    	if (D > 0)
    	{
    		y = y + yi;
            D = D + (2 * (dy - dx));
    	}
        else
            D = D + 2 * dy;
    	++x;
    }
}
void plotLineHigh(t_contr *contr, int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if (dx < 0)
    {
    	xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = x0;

    int y = y0;
    while (y < y1)
    {
    	printf("Sending %d %d\n", x, y);
    	p_px(contr, x, y, 0x00FF00);
        if (D > 0)
		{
		    x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else
            D = D + 2 * dx;
        ++y;
    }       
}


void line(t_contr *contr, int x0, int y0, int x1, int y1)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			plotLineLow(contr, x1, y1, x0, y0);
		else
			plotLineLow(contr, x0, y0, x1, y1);
	}
    else
    {
        if (y0 > y1)
            plotLineHigh(contr, x1, y1, x0, y0);
        else
            plotLineHigh(contr, x0, y0, x1, y1);
    }
}

int		mouse_(int btn, int x, int y, t_contr *contr)
{
	static int ox = -1;
	static int oy = -1;

	if (ox == -1)
	{
		ox = x;
		oy = y;
		p_px(contr, x, y, 0x00FF00);
	}
	else
	{
		line(contr, ox, oy, x, y);
		ox	= -1;
		oy 	= -1;
	}
	
	printf("Click on %d %d\n", x, y);
}